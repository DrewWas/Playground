
// Practicing crossing clock domains
`timescale 1ns/1ps // Remove after testing !!
import conversionFunctions::*;

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

    logic [PNTR_WIDTH:0] read_pointer, write_pointer; // MSB is fifo full/empty

    // Depth of FIFO = (write_freq - read_freq) * T_burst * data_rate
    //               = (125MHz - 50MHz) * 4us * 1
    //               ~= 300 words --> 512, 16-bit regs
    logic [DATA_LEN - 1:0] fifo [FIFO_DEPTH - 1:0];
    
    always_ff @(posedge wr_clk) begin
        if (reset) begin
            write_pointer <= '0;
            write_pointer_gray <= '0;
        end else if (write_en && !fifo_full) begin
            fifo[write_pointer[PNTR_WIDTH - 1:0]] <= data_in; // This might be wrong
            write_pointer <= write_pointer + 1;
            write_pointer_gray <= bin2gray(write_pointer + 1);
        end
    end

    always_ff @(posedge rd_clk) begin
        if (reset) begin
            read_pointer <= '0;
            read_pointer_gray <= '0;
        end else if (read_en && !fifo_empty) begin
            data_out <= fifo[read_pointer[PNTR_WIDTH - 1:0]]; // This might be wrong
            read_pointer <= read_pointer + 1;
            read_pointer_gray <= bin2gray(read_pointer + 1);
        end
    end

    // Bin -> Gray code encoding/decoding logic & clk crossing
    logic [PNTR_WIDTH:0] write_pointer_gray;
    logic [PNTR_WIDTH:0] read_pointer_gray;
    logic [PNTR_WIDTH:0] read_pointer_gray_sync1, read_pointer_gray_wrclk;
    logic [PNTR_WIDTH:0] write_pointer_gray_sync1, write_pointer_gray_rdclk;

    always_ff @(posedge rd_clk) begin
        if (reset) begin
            write_pointer_gray_sync1 <= '0;
            write_pointer_gray_rdclk <= '0;
        end else begin
            write_pointer_gray_sync1 <= write_pointer_gray;
            write_pointer_gray_rdclk <= write_pointer_gray_sync1;
        end
    end

    always_ff @(posedge wr_clk) begin
        if (reset) begin
            read_pointer_gray_sync1 <= '0;
            read_pointer_gray_wrclk <= '0;
        end else begin
            read_pointer_gray_sync1 <= read_pointer_gray;
            read_pointer_gray_wrclk <= read_pointer_gray_sync1;
        end

    end

    // Combinationally check if FIFO is full/empty
    logic [PNTR_WIDTH:0] read_pointer_bin_wrclk, write_pointer_bin_rdclk;
    assign read_pointer_bin_wrclk = gray2bin(read_pointer_gray_wrclk);
    assign write_pointer_bin_rdclk = gray2bin(write_pointer_gray_rdclk);

    always_comb begin
        fifo_empty = (read_pointer == write_pointer_bin_rdclk);
        // Read more about this and actually understand it
        fifo_full = (write_pointer == {!read_pointer_bin_wrclk[PNTR_WIDTH], read_pointer_bin_wrclk[PNTR_WIDTH - 1:0]});
        //fifo_full = (write_pointer_bin_rdclk == FIFO_DEPTH);
    end

endmodule



