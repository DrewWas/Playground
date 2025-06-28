
`timescale 1ns/10ps

module tb;

    parameter DATA_WIDTH = 16;
    parameter M = 32;
    typedef logic signed [(2 * DATA_WIDTH) + $clog2(M) - 1:0] mat_elem;
    logic clk, reset;
    // For PRNG (FIGURE THIS OUT!!)... Matrices are NOT updating
    initial void'($urandom(32'hDEADBEEF));
    int rows, cols, cols2;

    // For each test
    // 1. Generate two random matrices and compute their matmul
    // 2. Run those two random matrices through matmul.sv
    // 3. Compare matmul.sv output and generated output

    always #5 clk = ~clk;
    mat_elem mat1 [M-1:0][M-1:0];
    mat_elem mat2 [M-1:0][M-1:0];
    mat_elem outmat [M-1:0][M-1:0];

    matmul matmul (
        .clk(clk), 
        .reset(reset), 
        .mat1(mat1), 
        .mat2(mat2), 
        .outmat(outmat)
        );

    initial begin
        
        // Initialize

        // Test 0x0 * 0x0 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("\nTest 1: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        // run DUT with inputs 
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);
        // assert 

        // Test 32x32 * 32x32 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 2: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);

        // Test 2x2 * 2x2 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 3: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);

        // Test 32x32 * 32x32 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 5: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);

        // Test 32x16 * 16x32 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 6: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);

        // Test 16x32 * 32x16 matmul
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 7: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);

        // Test 13x17 * 17x19 matmul (odd rows and cols)
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 8: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);

        // Test 32x16 * 32x16 matmul (should error)
        rows = 32;
        cols = 32;
        cols2 = 32;
        $display("Test 9: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        $display("\n"); // Delete in a sec
        reference_matrix(rows, cols, cols2, mat1, mat2, outmat);
        reset = 1;
        #10
        reset = 0;
        print_matrix("REFERENCE MATRIX", M, M, outmat);


        // Final asserts and messages



        $finish;
    end




    // Fill test matrices 
    function automatic void generate_mat 
    (input int n,m, ref mat_elem mat[M-1:0][M-1:0]);
        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < m; j++) begin
                mat[i][j] = mat_elem'($urandom_range(0,3)); // THIS IS WHY NOT RANDOM
            end
        end

        print_matrix("Input Matrix", n, m, mat);

    endfunction

    // Compute the reference matrix 
    function automatic void reference_matrix
    (input int n, m, q,
    input mat_elem mat1 [M-1:0][M-1:0], 
    input mat_elem mat2 [M-1:0][M-1:0], 
    ref mat_elem mat[M-1:0][M-1:0]);

        // n = rows1
        // m = cols1/rows2
        // q = cols2

        for (int i = 0; i < n; i++) begin
            for (int j = 0; j < q; j++) begin
                mat_elem sum = 0;
                for (int k = 0; k < m; k++) begin
                    sum += mat1[i][k] * mat2[k][j];
                end
                mat[i][j] = mat_elem'(sum);
            end
        end

        print_matrix("Output Matrix", n, q, mat);

    endfunction



    // Helper task to print the matrices. Shamelessly copied from chat
    task automatic print_matrix
    (input string        title,
    input int           rows, cols,
    input mat_elem     mat [M-1:0][M-1:0] );

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


