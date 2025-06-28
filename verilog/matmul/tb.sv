
`timescale 1ns/10ps

module tb;

    parameter DATA_WIDTH = 16;
    parameter M = 32;
    typedef logic signed [(2 * DATA_WIDTH) + $clog2(M) - 1:0] mat_elem;
    logic clk, reset;
    // For PRNG (FIGURE THIS OUT!!)... Matrices are NOT updating
    initial void'($urandom(32'hDEADBEEF));
    int rows, cols, cols2;
    int test_number;

    // For each test
    // 1. Generate two random matrices and compute their matmul
    // 2. Run those two random matrices through matmul.sv
    // 3. Compare matmul.sv output and generated output

    always #5 clk = ~clk;
    mat_elem mat1 [M-1:0][M-1:0];
    mat_elem mat2 [M-1:0][M-1:0];
    mat_elem outmat [M-1:0][M-1:0];
    mat_elem refmat [M-1:0][M-1:0];

    matmul matmul (
        .clk(clk), 
        .reset(reset), 
        .mat1(mat1), 
        .mat2(mat2), 
        .outmat(outmat)
        );

    localparam RUN_LATENCY = M          // load 32 words
                          + $clog2(M)+3 // dot_product pipeline
                          + M*M;     // worst-case STORE loops


    initial begin
        
        // Initialize
        $display("RUN LATENCY: %0d", RUN_LATENCY);
        rows = 32; cols = 32; cols2 = 32;

        // Test 0x0 * 0x0 matmul
        test_number = 1;
        $display("\nTest 1: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 32x32 * 32x32 matmul
        test_number = 2;
        $display("Test 2: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 2x2 * 2x2 matmul
        test_number = 2;
        $display("Test 3: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 32x32 * 32x32 matmul
        test_number = 3;

        $display("Test 5: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 32x16 * 16x32 matmul
        test_number = 4;
        $display("Test 6: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 16x32 * 32x16 matmul
        test_number = 5;
        $display("Test 7: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 13x17 * 17x19 matmul (odd rows and cols)
        test_number = 6;
        $display("Test 8: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);

        // Test 32x16 * 32x16 matmul (should error)
        test_number = 7;
        $display("Test 9: ");
        generate_mat(rows,cols, mat1);
        generate_mat(cols,cols2, mat2);
        reference_matrix(rows, cols, cols2, mat1, mat2, refmat);
        reset = 1; #10; reset = 0;
        repeat(100000) @(posedge clk);
        print_matrix("MODULE OUTPUT MATRIX", M, M, outmat);
        compare_matrices(outmat, refmat, test_number);


        // Final asserts and messages



        $finish;
    end


    function automatic void compare_matrices
    (ref mat_elem original_mat[M-1:0][M-1:0],
    ref mat_elem testing_mat[M-1:0][M-1:0],
    int test_number
    );
        for (int i = 0; i < M; i++) begin
            for (int j = 0; j < M; j++) begin
                if (original_mat[i][j] != testing_mat[i][j])
                $fatal("Test #%0d failed!", test_number);
            end
        end
        $display("Both Matrices equal! | TEST PASSED!");
    endfunction



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
        //int LIM = 32;

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



