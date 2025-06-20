
// Practicing crossing clock domains

module cross_clk_domains #(

    parameter DATA_LEN = 16

) (
    input logic clk_1,
    input logic clk_2,
    input logic read_en,
    input logic write_en,
    input logic [DATA_LEN - 1:0] data_in,
    output logic [DATA_LEN - 1:0] data_out

);

    // Assume clk_1 is the clock freq writing data 
    // Assume clk_2 is the clock freq reading data

    




endmodule



