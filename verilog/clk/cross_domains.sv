
// Practicing crossing clock domains

module cross_clk_domains #(

    parameter DATA_LEN = 16,
    parameter FIFO_DEPTH = 8192,
    parameter CLK_1_FREQ = 125000000, // 125MHz
    parameter CLK_2_FREQ = 50000000   // 50MHz

) (
    input logic clk_1,
    input logic clk_2,
    input logic read_en,
    input logic write_en,
    input logic [DATA_LEN - 1:0] data_in,
    output logic [DATA_LEN - 1:0] data_out

);

    // Assume clk_1 is the clock freq writing data (125MHz -> Ethernet PHY)
    // Assume clk_2 is the clock freq reading data (50MHz -> UART TX)
    // Assume Ethernet (input) packet size of 1024 bytes ~ 1KB
    // Assume data_rate = 1
    // Assume T_burst = 4 us

    logic fifo_full;
    logic fifo_empty;
    logic [3:0] read_pointer, write_pointer;

    // Depth of FIFO = (write_freq - read_freq) * T_burst * data_rate
    //               = (125MHz - 50MHz) * 4us * 1
    //               ~= 300 words --> 512, 16-bit regs
    logic [FIFO_DEPTH - 1:0] fifo;

    write_pointer = 0;
    read_pointer = 0;
    always_ff @(posedge clk1) begin
        if (write_en) begin
            fifo[write_pointer + DATA_LEN - 1 : write_pointer] <= data_in;
            write_pointer <= (write_pointer + 16) % FIFO_DEPTH;
            // Reset write pointer at somepoint
        end else begin
            fifo <= fifo;
        end
    end

    always_ff @(posedge clk2) begin
        data_out <= fifo[read_pointer + DATA_LEN - 1 : read_pointer];
        read_pointer <= (read_pointer + 16) % FIFO_DEPTH;
    end



endmodule



