
`timescale 1ns/10ps

module matmul #(
    parameter DATA_WIDTH=16,
    parameter N = 256, 
    parameter M = 256,
    
    parameter J = 256,
    parameter K = 256
) (

    input logic clk,
    input logic reset,
    input logic signed [DATA_WIDTH-1:0] mat1 [N-1:0][M-1:0],
    input logic signed [DATA_WIDTH-1:0] mat2 [J-1:0][K-1:0],
    output logic signed [DATA_WIDTH-1:0] outmat [M-1:0][J-1:0]

);


    //assign outmat = 16'd0;

endmodule




// Make a new module that takes in two vectors and returns the dot product 

// Use FFs to meet timing. Don't use an insane amount of logic 


module dot_product(

);



endmodule 

