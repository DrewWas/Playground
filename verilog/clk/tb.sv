
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

    // Test 3s logics 
    logic [PNTR_WIDTH:0] start_read_pointer, start_write_pointer, end_read_pointer, end_write_pointer;
    logic start_fifo_flag, end_fifo_flag;

    // Test 4s logics 
    shortint scratch;


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
        $display("Test %0d: Read when empty", test_num);

        // Initialize signals 
        wr_clk = 0;
        rd_clk = 0;
        reset = 1;
        write_en = 0;
        read_en = 0;
        data_in = 0;

        #10 reset = 0;
        repeat(3) @(posedge rd_clk);

        // Capture initial signals 
        start_pointer = dut.read_pointer;
        fifo_flag = dut.fifo_empty;
        $display("Current read pointer: %0d", start_pointer);
        $display("Current fifo_empty flag: %0d", fifo_flag);

        // Attempt to read
        $display("Attempting to read");
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
        $display("Pointers and Flags equal! | TEST PASSED!\n");
        read_en = 0;


        // Test reset -----------------------------------------------------------
        test_num = 3;
        $display("Test %0d: Test Reset", test_num);

        // Initialize signals 
        wr_clk = 0;
        rd_clk = 0;
        reset = 1;
        write_en = 0;
        read_en = 0;
        data_in = 0;

        #10 reset = 0;

        // Write a bunch of shit to the fifo
        write_en = 1;
        for (shortint i = 0; i <= 100; i++) begin
            data_in = i;
            @(posedge wr_clk);
        end
        write_en = 0;

        // Check pointers and that it is not full
        start_read_pointer = dut.read_pointer;
        start_write_pointer = dut.write_pointer;
        start_fifo_flag = dut.fifo_empty;
        $display("Read pointer after writes: %0d", start_read_pointer);
        $display("Write pointer after writes: %0d", start_write_pointer);
        $display("FIFO_EMPTY flag after writes: %0d", start_fifo_flag);
        assert(start_write_pointer != 0)else $fatal("Write pointer did not advance");
        assert(!start_fifo_flag) else $fatal("fifo_empty still high after writes");

        // Reset
        reset = 1;
        repeat (3) @(posedge wr_clk);
        repeat (3) @(posedge rd_clk);
        reset = 0;

        // Check pointers are reset 
        end_read_pointer = dut.read_pointer;
        end_write_pointer = dut.write_pointer;
        end_fifo_flag = dut.fifo_empty;
        $display("Read pointer after reset: %0d", end_read_pointer);
        $display("Write pointer after reset: %0d", end_write_pointer);
        $display("FIFO_EMPTY flag after reset: %0d", end_fifo_flag);

        // Add asserts real quick and end of test message
        assert(end_read_pointer  == 0)    else $fatal("Read pointer not cleared");
        assert(end_write_pointer  == 0)    else $fatal("Write pointer not cleared");
        assert(end_fifo_flag == 1)   else $fatal("fifo_empty not high after reset");
        $display("Read and Write pointers reset to 0! | TESET PASSED!");


        // Test pointer wrap around -------------------------------------------
        test_num = 4;
        $display("\nTest %0d: Pointer wrap around", test_num);

        // Initialize signals 
        wr_clk = 0;
        rd_clk = 0;
        reset = 1;
        write_en = 0;
        read_en = 0;
        data_in = 0;
        data_out = 0;

        // Write 512 words  (values 0 … 511) -> expect fifo_full = 1
        reset = 0;
        write_en = 1;
        for (shortint i = 0; i <= FIFO_DEPTH; i++) begin
            data_in = i;
            @(posedge wr_clk);
        end 
        $display("FIFO FULL: %0d", dut.fifo_full);
        $display("Write pointer: %0d", dut.write_pointer);
        $display("-----------------------");
        write_en = 0;

        // Read  512 words  (check order) -> expect fifo_empty = 1
        read_en = 1;
        for (shortint i = 0; i <= FIFO_DEPTH; i++) begin
            @(posedge rd_clk);
            if (i < 10 || i > 500) begin // Only check last 500
                $display("Data out = %0d ", dut.data_out);
            end
            if (i == 30) begin
                $display("..."); // Just to show intermediary ...
            end
        end
        read_en = 0;
        $display("FIFO EMPTY: %0d", dut.fifo_empty);
        $display("Read pointer: %0d", dut.read_pointer);
        $display("-----------------------");

        // Write another 512 (512 … 1023)        -> full again
        write_en = 1;
        for (shortint i = 0; i <= FIFO_DEPTH; i++) begin
            data_in = i;
            @(posedge wr_clk);
        end 
        $display("Write pointer: %0d", dut.write_pointer);
        $display("FIFO FULL: %0d", dut.fifo_full);
        $display("-----------------------");
        write_en = 0;
        
        // Read another 512 (check order)        -> empty again
        read_en = 1;
        for (shortint i = 0; i <= FIFO_DEPTH; i++) begin
            @(posedge rd_clk);
                scratch = dut.data_out;
        end
        read_en = 0;
        $display("FIFO EMPTY: %0d", dut.fifo_empty);
        $display("Read pointer: %0d", dut.read_pointer);
        $display("FIFO FULL: %0d", dut.fifo_full);
        $display("-----------------------\n");

        // Final assertions on pointers and flags 
        if (!dut.fifo_empty || dut.fifo_full) begin
            $display("FIFO still full or not empty | TEST FAILED! ");
        end else if (dut.read_pointer != 0 || dut.write_pointer != 0) begin
            $display("Pointer Error | TEST FAILED!");
        end else begin
            $display("TEST PASSED!\n");
        end

        $finish;
    end

    
endmodule;



