module tb;

    logic clk;
    logic reset;
    logic [7:0] vector_a [7:0];
    logic [7:0] vector_b [7:0];
    integer test_num;
    logic [18:0] vector_out, expected;

    dot_product dut (
        .clk(clk),
        .reset(reset),
        .vector_a(vector_a),
        .vector_b(vector_b),
        .vector_out(vector_out)
    );


    initial clk = 0;
    always #5 clk = ~clk;

    initial begin

        // Test 1
        test_num = 1;
        $display("\nTest #%0d: All Zeros", test_num);
        load_vectors(
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0
        );
        expected = 19'd0;
        @(posedge clk);
        run_test();

        // Test 2
        test_num = 2;
        $display("Test #%0d: All 255s", test_num);
        load_vectors(
            255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255
        );
        expected = 520200;
        @(posedge clk);
        run_test();

        // Test 3
        test_num = 3;
        $display("Test #%0d: Mismatch", test_num);
        load_vectors(
            255,0,255,0,255,0,255,0,
            0,255,0,255,0,255,0,255
        );
        expected = 0;
        @(posedge clk);
        run_test();

        // Test 4
        test_num = 4;
        $display("Test #%0d: Half Zeros", test_num);
        load_vectors(
            100,100,100,100,100,100,100,100,
            0,0,0,0,0,0,0,0
        );
        expected = 0;
        @(posedge clk);
        run_test();

        // Test 5
        test_num = 1;
        $display("Test #%0d: All Ones", test_num);
        load_vectors(
            1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1
        );
        expected = 8;
        @(posedge clk);
        run_test();


        // Test 6
        test_num = 6;
        $display("Test #%0d: Adding Up", test_num);
        load_vectors(
            1,2,3,4,5,6,7,8,
            1,2,3,4,5,6,7,8
        );
        expected = 204;
        @(posedge clk);
        run_test();


        // Test 7
        test_num = 7;
        $display("Test #%0d: Decimals", test_num);
        load_vectors(
            1,2,3,4,5,6,7,8,
            10,20,30,40,50,60,70,80
        );
        expected = 2040;
        @(posedge clk);
        run_test();


        // Test 8
        test_num = 8;
        $display("Test #%0d: Identity", test_num);
        load_vectors(
            1,0,0,0,0,0,0,0,
            1,0,0,0,0,0,0,0
        );
        expected = 1;
        @(posedge clk);
        run_test();

        $display("\n   ========================= ALL TEST FINISHED =========================\n");
        $finish;
    end

    task load_vectors (
        input [7:0] a0, a1, a2, a3, a4, a5, a6, a7,
                    b0, b1, b2, b3, b4, b5, b6, b7
    );
        begin
            vector_a[0] = a0;
            vector_a[1] = a1;
            vector_a[2] = a2;
            vector_a[3] = a3;
            vector_a[4] = a4;
            vector_a[5] = a5;
            vector_a[6] = a6;
            vector_a[7] = a7;

            vector_b[0] = b0;
            vector_b[1] = b1;
            vector_b[2] = b2;
            vector_b[3] = b3;
            vector_b[4] = b4;
            vector_b[5] = b5;
            vector_b[6] = b6;
            vector_b[7] = b7;

            $display("Vector A: [%0d, %0d, %0d, %0d, %0d, %0d, %0d, %0d]",
                   a0, a1, a2, a3, a4, a5, a6, a7);
            $display("Vector B: [%0d, %0d, %0d, %0d, %0d, %0d, %0d, %0d]",
                   b0, b1, b2, b3, b4, b5, b6, b7);
        end
    endtask

    task run_test ();
        begin
            #20;
            
            $display("Expected: %0d | Got: %0d", expected, vector_out);

            if (vector_out == expected) begin
                $display("Test #%0d Passed!\n", test_num);
            end
            else begin
                $display("Test #%0d Failed\n", test_num);
            end
        end

    endtask



endmodule



