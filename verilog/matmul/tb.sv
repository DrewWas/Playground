
`timescale 1ns/10ps
//import testing_packages::*;

module tb;

    parameter DATA_WIDTH = 16;
    parameter MAX_N=256, MAX_M=256, MAX_J=256, MAX_K=256;
    typedef logic signed [DATA_WIDTH-1:0] element_t;
    logic clk, reset;
    // For PRNG (FIGURE THIS OUT!!)... Matrices are NOT updating
    initial void'($urandom(32'hDEADBEEF));

    // For each test
    // 1. Generate two random matrices and compute thier matmul
    // 2. Run those two random matrices through matmul.sv
    // 3. Compare matmul.sv output and generated output

    always #5 clk = ~clk;
    element_t mat1 [MAX_N-1:0][MAX_M-1:0];
    element_t mat2 [MAX_J-1:0][MAX_K-1:0];
    element_t outmat [MAX_M-1:0][MAX_J-1:0];

    initial begin
        
        // Initialize

        // Test 0x0 * 0x0 matmul
        $display("\nTesting 0x0 * 0x0 MATMUL: ");
        generate_mat(6,5, mat1);
        generate_mat(5,3, mat2);
        $display("\n\n"); // Delete in a sec
        reference_matrix(6,5,3, mat1, mat2, outmat);

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
                mat[i][j] = element_t'($urandom_range(0,3));
            end
        end

        $display("\n=== Input Matrix (%0dx%0d) ===", n, m);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < m; j++) begin
                $write(" %0d ", mat[i][j]);
            end
            $display("");   // newline at end of row
        end
    endfunction

    // Compute the reference matrix 
    function automatic void reference_matrix
    (input int n, m, q,
    input element_t mat1 [MAX_N-1:0][MAX_M-1:0], 
     input element_t mat2 [MAX_J-1:0][MAX_K-1:0], 
     ref element_t mat[MAX_N-1:0][MAX_M-1:0]);

    // n = rows1
    // m = cols1/rows2
    // q = cols2

        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < q; j++) begin
                int sum = 0;
                for (int k = 0; k < m; k++) begin
                    sum += mat1[i][k] * mat2[k][j];
                end
                mat[i][j] = element_t'(sum);
            end
        end

        $display("\n=== Output Matrix (%0dx%0d) ===", n, q);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < q; j++) begin
            $write(" %0d ", mat[i][j]);
            end
            $display("");   // newline at end of row
        end

    endfunction


endmodule 

// FIGURE OUT WHY SYNTHESIS TAKES SO FUCKING LONG!!!!


