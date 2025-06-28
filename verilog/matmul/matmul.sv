
`timescale 1ns/10ps

module matmul #(
    parameter DATA_WIDTH=16,
    parameter MAX_N = 32, 
    parameter MAX_M = 32,
    
    parameter MAX_J = 32,
    parameter MAX_K = 32
) (

    input logic clk,
    input logic reset,
    input logic signed [DATA_WIDTH-1:0] mat1 [MAX_N-1:0][MAX_M-1:0],
    input logic signed [DATA_WIDTH-1:0] mat2 [MAX_J-1:0][MAX_K-1:0],
    output logic signed [DATA_WIDTH-1:0] outmat [MAX_M-1:0][MAX_J-1:0]

);


    //assign outmat = 16'd0;

endmodule




// Make a new module that takes in two vectors and returns the dot product 

// Use FFs to meet timing. Don't use an insane amount of logic 


module dot_product(
    input clk, 
    input reset,
    input logic valid_in,
    input logic [DATA_WIDTH-1:0] vectorA [MAX_N-1:0],
    input logic [DATA_WIDTH-1:0] vectorB [MAX_N-1:0],
    output logic valid_out,
    output logic [(DATA_WIDTH * 2) + $clog2(MAX_N) - 1:0] outval
);


    logic [(DATA_WIDTH * 2) - 1 : 0] prods [MAX_N];
    logic val0, val1, val2, val3;

    always_comb begin
        for (int i = 0; i < MAX_N; i++) begin
            prods[i] = vectorA[i] * vectorB[i];
        end
    end

    localparam SUM_WIDTH = (2 * DATA_WIDTH) + $clog2(MAX_N);
    logic signed [SUM_WIDTH - 1:0] sums0 [MAX_N / 2];


    // Pipelined only for 32bit vectors
    // ------- COLLAPSE THIS INTO ONE GENERATE STATEMENT ---------------
    always_ff @(posedge clk) begin
        if (reset) begin
            sums0 <= '0;
            val0 <= 1'b0;
        end else begin
            for (int i = 0; i < MAX_N / 2; i++) begin
                sums0[i] <= prods[i * 2] + prods[(i * 2) + 1];
            end
            val0 <= valid_in;
        end
    end

    // Add 16 sums
    logic signed [SUM_WIDTH - 1:0] sums1 [MAX_N / 4];
    always_ff @(posedge clk) begin
        if (reset) begin
            sums1 <= '0;
            val1 <= 1'b0;
        end else begin
            for (int i = 0; i < MAX_N / 4; i++) begin
                sums1[i] <= sums0[i * 2] + sums0[(i * 2) + 1];
            end
            val1 <= val0;
        end
    end


    // Add 8 sums
    logic signed [SUM_WIDTH - 1:0] sums2 [MAX_N / 8];
    always_ff @(posedge clk) begin
        if (reset) begin
            sums2 <= '0;
            val2 <= 1'b0;
        end else begin
            for (int i = 0; i < MAX_N / 8; i++) begin
                sums2[i] <= sums1[i * 2] + sums1[(i * 2) + 1];
            end
            val2 <= val1;
        end
    end
    
    // Add 4 sums
    logic signed [SUM_WIDTH - 1:0] sums3 [MAX_N / 16];
    always_ff @(posedge clk) begin
        if (reset) begin
            sums3 <= '0;
            val3 <= 1'b0;
        end else begin
            for (int i = 0; i < MAX_N / 16; i++) begin
                sums3[i] <= sums2[i * 2] + sums2[(i * 2) + 1];
            end
            val3 <= val2;
        end
    end

    // Add 2 sums
    always_ff @(posedge clk) begin
        if (reset) begin
            outval <= '0;
            valid_out <= 1'b0;
        end else begin
            outval <= sums3[0] + sums3[1];
            valid_out <= val3;
        end
    end



endmodule 






