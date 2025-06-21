
// Practicing crossing clock domains

module async_fifo #(

    parameter DATA_LEN = 16,
    parameter FIFO_DEPTH = 512,
    parameter PNTR_WIDTH = $clog2(FIFO_DEPTH)

) (
    input logic wr_clk,
    input logic rd_clk,
    input logic read_en,
    input logic write_en,
    input logic reset,
    input logic [DATA_LEN - 1:0] data_in,
    output logic fifo_full,
    output logic fifo_empty,
    output logic [DATA_LEN - 1:0] data_out

);

    // Assume wr_clk 125MHz -> Ethernet PHY
    // Assume rd_clk 50MHz -> UART TX
    // Assume Ethernet (input) packet size of 1024 bytes ~ 1KB
    // Assume data_rate = 1
    // Assume T_burst = 4 us

    logic fifo_full;
    logic fifo_empty;
    logic [PNTR_WIDTH:0] read_pointer, write_pointer;

    // Depth of FIFO = (write_freq - read_freq) * T_burst * data_rate
    //               = (125MHz - 50MHz) * 4us * 1
    //               ~= 300 words --> 512, 16-bit regs
    logic [DATA_LEN - 1:0] fifo [FIFO_DEPTH - 1:0];
    
    always_ff @(posedge wr_clk) begin
        if (reset) begin
            write_pointer <= '0;
        end else if (write_en && !fifo_full) begin
            fifo[write_pointer[PNTR_WIDTH - 1:0]] <= data_in;
            write_pointer <= write_pointer + 1;
        end
    end

    always_ff @(posedge rd_clk) begin
        if (reset) begin
            read_pointer <= '0;
        end else if (read_en && !fifo_empty) begin
            data_out <= fifo[read_pointer[PNTR_WIDTH - 1:0]];
            read_pointer <= read_pointer + 1;
        end
    end


endmodule



