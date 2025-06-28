
`timescale 1ns/10ps

module tb;

    parameter DATA_WIDTH = 16;
    parameter M = 32;
    typedef logic signed [DATA_WIDTH-1:0] element_t;
    logic clk, reset;
    // For PRNG (FIGURE THIS OUT!!)... Matrices are NOT updating
    initial void'($urandom(32'hDEADBEEF));
    int rows, cols, cols2;

    // For each test
    // 1. Generate two random matrices and compute their matmul
    // 2. Run those two random matrices through matmul.sv
    // 3. Compare matmul.sv output and generated output

    always #5 clk = ~clk;
    element_t mat1 [M-1:0][M-1:0];
    element_t mat2 [M-1:0][M-1:0];
    element_t outmat [M-1:0][M-1:0];

    initial begin
        
        // Initialize

        // Test 0x0 * 0x0 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("\nTesting 0x0 * 0x0 MATMUL: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        // run DUT with inputs 
        // assert 

        // Test 1x1 * 1x1 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 1x1 * 1x1 MATMUL: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);


        // Test 2x2 * 2x2 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 2x2 * 2x2 MATMUL: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);

        // Test 32x32 * 32x32 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 256x256 * 256x256 MATMUL: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);

        // Test 32x16 * 16x32 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 256x128 * 128x256 MATMUL: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);

        // Test 16x32 * 32x16 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 128x256 * 256x128 MATMUL: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);

        // Test 13x17 * 17x19 matmul (odd rows and cols)
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 13x17 * 17x19 MATMUL (should error): ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);

        // Test 32x16 * 32x16 matmul (should error)
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Testing 256x100 * 256x100 MATMUL (should error): ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);


        // Final asserts and messages



        $finish;
    end




    // Fill test matrices 
    function automatic void generate_mat 
    (input int n,m, ref element_t mat[M-1:0][M-1:0]);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < m; j++) begin
                mat[i][j] = element_t'($urandom_range(0,3)); // THIS IS WHY NOT RANDOM
            end
        end

        print_matrix("Input Matrix", n, m, mat);

    endfunction

    // Compute the reference matrix 
    function automatic void reference_matrix
    (input int n, m, q,
    input element_t mat1 [M-1:0][M-1:0], 
    input element_t mat2 [M-1:0][M-1:0], 
    ref element_t mat[M-1:0][M-1:0]);

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

        print_matrix("Output Matrix", n, q, mat);

    endfunction

    // Helper task to print the matrices. Shamelessly copied from chat
    task automatic print_matrix
    (input string        title,
    input int           rows, cols,
    input element_t     mat [M-1:0][M-1:0] );

        int LIM = 5;  

        $display("\n=== %s (%0dx%0d) ===", title, rows, cols);

        // rows
        for (int i = 0; i < rows; i++) begin
            if (i == LIM && rows > LIM) begin 
            $display(" ...    ");  
            i = rows - 5; // jump to last 26th
            continue;
            end

            // cols
            for (int j = 0; j < cols; j++) begin
            if (j == LIM && cols > LIM) begin
                $write(" ...");  // col spacer
                j = cols - 5;
                continue;
            end
            $write(" %0d", mat[i][j]);
            end
            $display("");
        end
    endtask



endmodule 

// FIGURE OUT WHY SYNTHESIS TAKES SO FUCKING LONG!!!!


