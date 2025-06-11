
module imem #(
    parameter instruct_size = 4,
    parameter num_instructs = 512
) (
    input logic clk,
    input logic reset,
    input logic [instruct_size - 1:0] addr,
    input logic read_en,
    output logic [instruct_size - 1:0] read_instruction 
    
);


    // Instruction memory held in 512, 4-bit regs
    logic [instruct_size - 1:0] instructions [num_instructs - 1:0];


    always_ff @(posedge clk) begin

        if (reset) begin
            for (int i = 0; i < num_instructs; i++) begin
                instructions[i] <= {instruct_size{1'b0}};
            end
        end else if (read_en) begin
            read_instruction <= instructions[addr]; 
        end

    end




endmodule


