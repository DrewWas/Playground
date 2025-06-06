module tb;

    input clk;
    input reset;
    input [7:0] vector_a [7:0];
    input [7:0] vector_b [7:0];
    output [18:0] vector_out;

    dot_product dut (
        .clk(clk),
        .reset(reset),
        .vector_a(vector_a),
        .vector_b(vector_b),
        .vector_out(vector_out)
    );


    initial 



endmodule