
module pc #(
    parameter REG_WIDTH = 9,
    parameter START_ADDR = 9'd0,
    parameter INSTRUCTION_OFFSET = 4   // Instructions only 4 bytes (32 bits)
)
(
    input logic clk,
    input logic reset,
    input logic [REG_WIDTH - 1:0] branch_target,
    input logic branch_taken,
    output logic [REG_WIDTH - 1:0] next_instruction_addr
);

    logic [REG_WIDTH - 1:0] pc_reg;


    always_ff @(posedge clk) begin
        if (reset) begin
            pc_reg <= START_ADDR;
        end else if (branch_taken) begin
            pc_reg <= branch_target;
        end else begin
            pc_reg <= pc_reg + INSTRUCTION_OFFSET;
        end
    end

    assign next_instruction_addr = pc_reg;



endmodule





