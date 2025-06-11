module registers #(
    parameter WIDTH = 32;
) (

    input logic clk,
    input logic reset,
    input logic write_en,
    input logic [WIDTH - 1:0] write_data,
    input logic [4:0] write_addr, read1_addr, read2_addr, // 8 could change 
    output logic [WIDTH - 1:0] read1_data, read2_data

);

    // Create 32 independent 32 bit wide registers 
    logic [WIDTH - 1:0] registers [WIDTH - 1:0];


    // Asynchronous read
    always_comb begin
        read1_data = registers[read1_addr];
        read2_data = registers[read2_addr];
    end


    // Synchronous write 
    always @(posedge clk) begin

        if (reset) begin
            // Reset all registers to 0
            for (int i = 0; i < WIDTH; i++) begin
                registers[i] <= 32'd0;
            end

        end else if (write_en) begin
            // Otherwise update addr to write_data
            registers[write_addr] <= write_data;
        end
    end



endmodule



