
module ALU #(

    parameter DATA_IN_WIDTH = 32;
    parameter OP_CODE_WIDTH = 4;
    parameter DATA_OUT_WIDTH = 64;

) (
    input logic [DATA_IN_WIDTH - 1:0] scalar_a, scalar_b,
    input logic [OP_CODE_WIDTH - 1:0] op_code,
    output logic [DATA_OUT_WIDTH-1:0] alu_out
);

    // Compute alu_out from opcode
    always_comb begin

        case (op_code)
            4'b0000 : alu_out = scalar_a + scalar_b;
            4'b0001 : alu_out = scalar_a - scalar_b;
            4'b0010 : alu_out =  scalar_a * scalar_b;
            4'b0011 : alu_out = (scalar_b != 0) ? (scalar_a / scalar_b) : {DATA_OUT_WIDTH{1'b0}};
            4'b0100 : alu_out = scalar_a << scalar_b[4:0];
            4'b0101 : alu_out = scalar_a >> scalar_b[4:0];
            4'b0110 : alu_out = {DATA_OUT_WIDTH{(scalar_a && scalar_b)}};
            4'b0111 : alu_out = {DATA_OUT_WIDTH{(scalar_a || scalar_b)}};
            4'b1000 : alu_out = scalar_a & scalar_b;
            4'b1001 : alu_out = scalar_a | scalar_b;
            4'b1010 : alu_out = scalar_a ^ scalar_b;
            4'b1011 : alu_out = ~(scalar_a & scalar_b);
            4'b1100 : alu_out = ~(scalar_a | scalar_b);
            4'b1101 : alu_out = ~(scalar_a ^ scalar_b);
            4'b1110 : alu_out = (scalar_a > scalar_b) ? {DATA_OUT_WIDTH{1'b1}} : {DATA_OUT_WIDTH{1'b0}};
            4'b1111 : alu_out = (scalar_a < scalar_b) ? {DATA_OUT_WIDTH{1'b1}} : {DATA_OUT_WIDTH{1'b0}};
            default : alu_out = {DATA_OUT_WIDTH{1'b0}};
        endcase
    end



endmodule





