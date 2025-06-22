
`timescale 1ns/1ps

package conversionFunctions;

    parameter int WIDTH = 9;

    // Binary -> Gray Function
    function logic [WIDTH-1:0] bin2gray(input logic [WIDTH-1:0] b);
        return (b >> 1) ^ b;
    endfunction

    // Gray -> Binary function
    function logic [WIDTH-1:0] gray2bin(input logic [WIDTH-1:0] g);
        logic [WIDTH-1:0] b;
        b[WIDTH-1] = g[WIDTH-1];
        for (int i = WIDTH - 2; i >= 0; i--)
            b[i] = b[i+1] ^ g[i];
        return b;
    endfunction
endpackage


