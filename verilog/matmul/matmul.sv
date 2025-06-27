
`timescale 1ns/10ps

module matmul #(
    parameter DATA_WIDTH=16,
    parameter MAX_N = 32, 
    parameter MAX_M = 32,
    
    parameter MAX_J = 32,
    parameter MAX_K = 32
) (

    input logic clk,
    input logic reset,
    input logic signed [DATA_WIDTH-1:0] mat1 [MAX_N-1:0][MAX_M-1:0],
    input logic signed [DATA_WIDTH-1:0] mat2 [MAX_J-1:0][MAX_K-1:0],
    output logic signed [DATA_WIDTH-1:0] outmat [MAX_M-1:0][MAX_J-1:0]

);


    //assign outmat = 16'd0;

endmodule




// Make a new module that takes in two vectors and returns the dot product 

// Use FFs to meet timing. Don't use an insane amount of logic 


module dot_product(
    input logic [DATA_WIDTH-1:0] vectorA [MAX_N-1:0],
    input logic [DATA_WIDTH-1:0] vectorB [MAX_M-1:0],
    output logic [DATA_WIDTH-1:0] outval
);





endmodule 

