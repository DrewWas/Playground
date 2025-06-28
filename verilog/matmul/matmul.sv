
`timescale 1ns/10ps

module matmul #(
    parameter DATA_WIDTH=16,
    parameter N = 32,
    parameter M = 32, 
    parameter Q = 32
) (

    input logic clk,
    input logic reset,
    input logic signed [DATA_WIDTH-1:0] mat1 [N-1:0][M-1:0],
    input logic signed [DATA_WIDTH-1:0] mat2 [M-1:0][Q-1:0],
    output logic signed [(2 * DATA_WIDTH) + $clog2(M) - 1:0] outmat [N-1:0][Q-1:0]

);

    // Staging buffers (buffer one mat1 row and one mat2 col)
    logic signed [DATA_WIDTH - 1 : 0] staging_rows [M - 1 : 0];
    logic signed [DATA_WIDTH - 1 : 0] staging_cols [M - 1 : 0];

    // Control flow logic 
    localparam IDLE=2'd0, LOAD=2'd1, RUN=2'd2, STORE=2'd3;
    logic [1:0] state;
    int row, col;
    logic dp_start, dp_done;
    logic signed [(2 * DATA_WIDTH) + $clog2(M) - 1:0] dp_result;

    // Dot product instnace 
    dot_product #(
        .DATA_WIDTH(DATA_WIDTH),
        .M(M)

    ) compute (
        .clk(clk),
        .reset(reset),
        .valid_in(dp_start),
        .vectorA(staging_rows[row]), // See if you have to index
        .vectorB(staging_cols[col])  // See if you have to index
        .valid_out(dp_done),
        .outval(dp_result)
    );


    // FSM sequence


    //assign outmat = 16'd0;

endmodule








module dot_product #(
    parameter DATA_WIDTH=16,
    parameter M = 32
) (
    input clk, 
    input reset,
    input logic valid_in,
    input logic [DATA_WIDTH-1:0] vectorA [MAX_N-1:0],
    input logic [DATA_WIDTH-1:0] vectorB [MAX_N-1:0],
    output logic valid_out,
    output logic [(DATA_WIDTH * 2) + $clog2(MAX_N) - 1:0] outval
);


    logic [(DATA_WIDTH * 2) - 1 : 0] prods [M-1:0];
    logic val0, val1, val2, val3;

    always_comb begin
        for (int i = 0; i < M; i++) begin
            prods[i] = vectorA[i] * vectorB[i];
        end
    end

    localparam SUM_WIDTH = (2 * DATA_WIDTH) + $clog2(M);
    logic signed [SUM_WIDTH - 1:0] sums0 [M / 2];


    // Pipelined only for 32bit vectors
    // ------- COLLAPSE THIS INTO ONE GENERATE STATEMENT ---------------
    always_ff @(posedge clk) begin
        if (reset) begin
            sums0 <= '0;
            val0 <= 1'b0;
        end else begin
            for (int i = 0; i < M / 2; i++) begin
                sums0[i] <= prods[i * 2] + prods[(i * 2) + 1];
            end
            val0 <= valid_in;
        end
    end

    // Add 16 sums
    logic signed [SUM_WIDTH - 1:0] sums1 [M / 4];
    always_ff @(posedge clk) begin
        if (reset) begin
            sums1 <= '0;
            val1 <= 1'b0;
        end else begin
            for (int i = 0; i < M / 4; i++) begin
                sums1[i] <= sums0[i * 2] + sums0[(i * 2) + 1];
            end
            val1 <= val0;
        end
    end


    // Add 8 sums
    logic signed [SUM_WIDTH - 1:0] sums2 [M / 8];
    always_ff @(posedge clk) begin
        if (reset) begin
            sums2 <= '0;
            val2 <= 1'b0;
        end else begin
            for (int i = 0; i < M / 8; i++) begin
                sums2[i] <= sums1[i * 2] + sums1[(i * 2) + 1];
            end
            val2 <= val1;
        end
    end
    
    // Add 4 sums
    logic signed [SUM_WIDTH - 1:0] sums3 [M / 16];
    always_ff @(posedge clk) begin
        if (reset) begin
            sums3 <= '0;
            val3 <= 1'b0;
        end else begin
            for (int i = 0; i < M / 16; i++) begin
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






