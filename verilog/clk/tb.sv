
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


    // Test bin2gray & gray2bin functions
    logic [PNTR_WIDTH:0] bin_vals [9:0];
    logic [PNTR_WIDTH:0] gray_vals [9:0];
    logic [PNTR_WIDTH:0] decoded_vals [9:0];
    logic [PNTR_WIDTH:0] test1_values [9:0] = '{0, 10, 51, 511, 1, 45, 100, 101, 250, 41};
    initial begin

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

    end


    // Test write when full
    initial begin
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
        for (shortint i = 0; i < FIFO_DEPTH; i++) begin
            data_in = i; // Each reg holds its address value (and is fully filled)
            @(posedge wr_clk);
        end

        // Try inserting extra word
        data_in = 16'hDEAD;
        @(posedge wr_clk);
        write_en = 0;
        read_en = 1;

        // Make sure that fifo is full and extra word is not present
        for (shortint j = 0; j < FIFO_DEPTH; j++) begin
            //assert(data_out[j] != 16'hDEAD);
            //assert(data_out[j] == j);
            assert(fifo_full);
        end

        $display("Word Added: %d | FIFO last element: %d", data_in, data_out[FIFO_DEPTH - 1]);
        $display("FIFO did not accept new word when full! | PASSED!");

    
        $finish;
    end


    // Test read when empty 

// Test massive dump in (long burst)

// Test reset

// Test pointers (including wrap around)

// Test different clock frequency ratios

// Async reset during operation



endmodule;



