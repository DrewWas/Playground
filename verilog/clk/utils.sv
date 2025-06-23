
`timescale 1ns/1ps

package conversionFunctions;

    parameter int WIDTH = 9;

    // Binary -> Gray Function
    function logic [WIDTH:0] bin2gray(input logic [WIDTH:0] b);
        return (b >> 1) ^ b;
    endfunction

    // Gray -> Binary function
    function logic [WIDTH:0] gray2bin(input logic [WIDTH:0] g);
        logic [WIDTH:0] b;
        b[WIDTH] = g[WIDTH];
        for (int i = WIDTH - 1; i >= 0; i--)
            b[i] = b[i+1] ^ g[i];
        return b;
    endfunction
endpackage



