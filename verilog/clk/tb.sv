
`timescale 1ns/1ps
import conversionFunctions::*;

module tb;

    parameter DATA_LEN = 16;
    parameter FIFO_DEPTH = 512;
    parameter PNTR_WIDTH = $clog2(FIFO_DEPTH);
    logic wr_clk, rd_clk, read_en, write_en, reset, fifo_full, fifo_empty;
    logic [DATA_LEN - 1:0] data_in, data_out;
    integer test_num;

    async_fifo dut (
        .wr_clk(wr_clk),
        .rd_clk(rd_clk),
        .read_en(read_en),
        .write_en(write_en),
        .reset(reset),
        .data_in(data_in),
        .fifo_full(fifo_full),
        .fifo_empty(fifo_empty),
        .data_out(data_out)
    );

    // Clocks 
    always #5 wr_clk = ~wr_clk;
    always #7 rd_clk = ~rd_clk;

    // Test 0s logics
    logic [PNTR_WIDTH:0] bin_vals [9:0];
    logic [PNTR_WIDTH:0] gray_vals [9:0];
    logic [PNTR_WIDTH:0] decoded_vals [9:0];
    logic [PNTR_WIDTH:0] test1_values [9:0] = '{0, 10, 51, 511, 1, 45, 100, 101, 250, 513};

    // Test 2s logics
    logic [PNTR_WIDTH:0] start_pointer = dut.read_pointer;
    logic fifo_flag = dut.fifo_empty;






    initial begin
        // Test bin2gray & gray2bin functions ----------------------------------
        test_num = 0;
        $display("\nTest %0d: bin2gray", test_num);

        // Initialize test vals and compute gray code 
        for (int i = 0; i < 10; i++) begin
            bin_vals[i] = test1_values[i];
            gray_vals[i] = bin2gray(bin_vals[i]);
            decoded_vals[i] = gray2bin(gray_vals[i]);
        end

        // Test conversion was correct
        for (int i = 0; i < 10; i++) begin
            if (bin_vals[i] == decoded_vals[i]) begin
                $display("bin%0d = %b | gray%0d = %b | decoded%0d = %b | PASSED!", i, bin_vals[i], i, gray_vals[i], i, decoded_vals[i]);
            end else begin
                $display("Test %0d failed", i);
            end
        end

        // Test write when full ------------------------------------------------
        test_num = 1;
        $display("\nTest %0d: Write when full", test_num);

        // Initialize signals 
        wr_clk = 0;
        rd_clk = 0;
        reset = 1;
        write_en = 0;
        read_en = 0;
        data_in = 0;

        // Apply reset and fill up FIFO 
        #10 reset = 1;
        #10 reset = 0;
        write_en = 1;
        for (shortint i = 0; i <= FIFO_DEPTH; i++) begin
            data_in = i; 
            @(posedge wr_clk);
        end
        if (fifo_full) begin
            $display("FIFO Full!");
        end


        // Try inserting extra word
        data_in = 16'hDEAD;
        $display("Attempting to write: %0d", data_in);
        @(posedge wr_clk);
        write_en = 0;
        read_en = 1;

        // Read through the fifo (which frees space) and make sure 
        // That 0xDEAD wasn't inserted anywhere and that each value = its fifo addr
        for (shortint k = 0; k <= FIFO_DEPTH; k++) begin
            @(posedge rd_clk);
            if (dut.data_out === 16'hDEAD) begin
                $fatal("Overflow word appeared – test FAILED");
            end
            if (dut.data_out !== k) begin
                $fatal("Data mismatch at %0d: got %0d", k, dut.data_out);
            end
            if (k < 10 || k > 500) begin // Only check last 500
                $display("data_out = %0d ", dut.data_out);
            end
            if (k == 30) begin
                $display("..."); // Just to show intermediary ...
            end
        end
        read_en = 0;

        $display("Overflow-on-full test PASSED\n");


        // Test read when empty ------------------------------------------------
        test_num = 2;
        $display("\nTest %0d: Read when empty", test_num);

        // Initialize signals 
        wr_clk = 0;
        rd_clk = 0;
        reset = 1;
        write_en = 0;
        read_en = 0;
        data_in = 0;

        #10 reset = 0;

        // Capture initial signals 
        $display("Current read pointer: %0d", start_pointer);
        $display("Current fifo_empty flag: %0d", fifo_flag);

        // Attempt to read
        $display("\nAttempting to read\n");
        read_en = 1;
        repeat(5) @(posedge rd_clk);

        // Make sure pointer/flag is the same
        if (dut.read_pointer !== start_pointer) begin
            $display("Start Pointer: %0d | End Pointer: %0d", start_pointer, dut.read_pointer);
            $fatal("Read pointer advanced on empty read!");
        end
        if (!dut.fifo_empty) begin
            $display("Start Flag: %0d | End Flag: %0d", fifo_flag, dut.fifo_empty);
            $fatal("fifo_empty de-asserted during empty read!");
        end

        $display("Current read pointer: %0d", dut.read_pointer);
        $display("Current fifo_empty flag: %0d", dut.fifo_empty);
        $display("Pointers and Flags equal! | TEST PASSED!");
        read_en = 0;

        $finish;
    end

// Test massive dump in (long burst)

// Test reset

// Test pointers (including wrap around)

// Test different clock frequency ratios

// Async reset during operation


    
endmodule;



