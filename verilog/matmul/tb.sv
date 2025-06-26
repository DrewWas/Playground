
`timescale 1ns/10ps

module tb;


    localparam N=256, M=256, J=256, K=256;
    localparam DATA_WIDTH=16; // Each matrix element 16bits 
    logic clk, reset;
    logic [N-1:0] mat1 [M-1:0];
    logic [J-1:0] mat2 [K-1:0];
    logic [M-1:0] outmat [J-1:0];    

    always #5 clk = ~clk;


    matmul dut (
        .clk(clk),
        .reset(reset),
        .mat1(mat1),
        .mat2(mat2),
        .outmat(outmat)
    );

    initial begin

        // Test 0x0 * 0x0 matmul
        

        // Test 1x1 * 1x1 matmul
        $display("\nTesting 1x1 * 1x1 MATMUL: ");
        

        // Test 2x2 * 2x2 matmul

        // Test 256x256 * 256x256 matmul

        // Test 256*128 * 128x256 matmul

        // Test 128x256 * 256x128 matmul

        // Test 100x100 * 50x50 matmul (should error)

        // Test 256x100 * 256x100 matmul (should error)

        // Test 256x256 identity * 256x256 matmul


        // Final asserts and messages


        $finish;
    end


endmodule 

