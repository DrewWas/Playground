
`timescale 1ns/10ps
//import testing_packages::*;

module tb;

    parameter DATA_WIDTH = 16;
    parameter MAX_N=256, MAX_M=256, MAX_J=256, MAX_K=256;
    typedef logic signed [DATA_WIDTH-1:0] element_t;
    logic clk, reset;

    // For each test
    // 1. Generate two random matrices and compute thier matmul
    // 2. Run those two random matrices through matmul.sv
    // 3. Compare matmul.sv output and generated output

    always #5 clk = ~clk;
    // element_t mat1 [MAX_N-1:0][MAX_M-1:0];
    // element_t mat2 [MAX_J-1:0][MAX_K-1:0];
    element_t mat1 [MAX_N-1:0][MAX_M-1:0];
    element_t mat2 [MAX_N-1:0][MAX_M-1:0];

    initial begin
        
        // Initialize

        // Test 0x0 * 0x0 matmul
        $display("\nTesting 0x0 * 0x0 MATMUL: ");
        generate_mat(5,17, mat1);
        generate_mat(17,9, mat2);

        //matmul #(.N(0), .M(0), .J(0), .K(0)) dutZEROS ();

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




    // Fill test matrices 
    function automatic void generate_mat 
    (input int n,m, ref element_t mat[MAX_N-1:0][MAX_M-1:0]);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < m; j++) begin
                mat[i][j] = element_t'($urandom_range(0,9));
            end
        end

        $display("\n=== mat1 (%0dx%0d) ===", m, n);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < m; j++) begin
            $write(" %0d ", mat[i][j]);
            end
            $display("");   // newline at end of row
        end
    endfunction

    // Compute the reference (correct )


endmodule 

