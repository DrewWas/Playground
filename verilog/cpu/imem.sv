
module imem #(
    parameter instruct_size = 4,
    parameter num_instructs = 512,
    parameter addr_width = $clog2(num_instructs)
) (
    input logic clk,
    input logic [addr_width - 1:0] addr,
    output logic [instruct_size - 1:0] read_instruction 
    
);


    // Instruction memory held in 512, 4-bit regs
    logic [instruct_size - 1:0] instructions [num_instructs - 1:0];


    // Load in the memory file 
    // ENSURE program.hex IS THE CORRECT SIZE!
    initial begin
        $readmemh("program.hex", instructions);
    end


    // Synchronous 1-cycle latency mem read
    always_ff @(posedge clk) begin
        read_instruction <= instructions[addr];
    end


endmodule


