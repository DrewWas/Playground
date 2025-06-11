module registers #(
    parameter WIDTH = 32,
    parameter NUM_REGS = 32
) (

    input logic clk,
    input logic reset,
    input logic write_en,
    input logic [WIDTH - 1:0] write_data,
    input logic [4:0] write_addr, read1_addr, read2_addr, // 8 could change 
    output logic [WIDTH - 1:0] read1_data, read2_data

);

    // Create 32 independent 32 bit wide registers 
    logic [WIDTH - 1:0] registers [NUM_REGS - 1:0];


    // Asynchronous read
    always_comb begin
        // Block reads from reg[0] to comply w RISC-V standards
        read1_data = (read1_addr == 5'b0) ? {WIDTH{1'b0}} : registers[read1_addr];
        read2_data = (read2_addr == 5'b0) ? {WIDTH{1'b0}} : registers[read2_addr];
    end


    // Synchronous write 
    always @(posedge clk) begin

        if (reset) begin
            // Reset all registers to 0
            for (int i = 0; i < NUM_REGS; i++) begin
                registers[i] <= {WIDTH{1'b0}};
            end

        end else if (write_en && (write_addr != 5'd0)) begin
            // Otherwise update addr to write_data
            // Block writes to reg[0] to comply w RISC-V standards
            registers[write_addr] <= write_data;
        end
    end



endmodule



