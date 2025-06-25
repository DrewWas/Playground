

module matmul #(
    parameter N = 256;
    parameter M = 256,
    
    parameter J = 256,
    parameter K = 256
) (

    input logic clk,
    input logic reset,
    input logic [N-1:0] mat1 [M-1:0],
    input logic [J-1:0] mat2 [K-1:0],
    output logic [M-1:0] outmat [J:0]
    
);




endmodule




// Make a new module that takes in two vectors and returns the dot product 

// Use FFs to meet timing. Don't use an insane amount of logic 


module dot_product(
    input logic []

);



endmodule 

