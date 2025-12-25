`timescale 1ns/1ps


module tb;


// Inputs
logic clk = 0;
logic reset;
logic in_valid;
logic [7:0] input_pixel;

// Outputs
logic out_valid;
logic [7:0] output_pixel;

main #(
    .IMG_W(8),
    .IMG_H(6),
) dut (
    .clk(clk), .reset(reset), .input_pixel(input_pixel), .in_valid(in_valid),
    .out_valid(out_valid), .output_pixel(output_pixel)
)

always #5 clk = ~clk;


initial begin
    reset = 1;
    #20;
    reset = 0;

    input_pixel = 8'd100

end



endmodule 


