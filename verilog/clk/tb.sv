
`timescale 1ns/1ps
import conversionFunctions::*;

module tb;

    parameter DATA_LEN = 16;
    parameter FIFO_DEPTH = 512;
    parameter PNTR_WIDTH = $clog2(FIFO_DEPTH);
    logic wr_clk, rd_clk, read_en, write_en, reset, fifo_full, fifo_empty;
    logic [DATA_LEN - 1:0] data_in, data_out;
    integer test_num;


// Test bin2gray & gray2bin functions
    logic [PNTR_WIDTH-1:0] bin_vals [9:0];
    logic [PNTR_WIDTH-1:0] gray_vals [9:0];
    logic [PNTR_WIDTH-1:0] decoded_vals [9:0];
    logic [PNTR_WIDTH-1:0] test1_values [9:0] = '{0, 10, 51, 511, 1, 45, 100, 101, 250, 41};
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

        $finish;

    end

// Test at multiple different clks for both read and write 

// Test full

// Test empty

// Test massive dump in (long burst)

// Test reset

// Test pointers

// Test different clock frequency ratios

// Test write when full

// Test read when empty 

// Async reset during operation


endmodule;

