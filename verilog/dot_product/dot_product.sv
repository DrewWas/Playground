module dot_product (

    // Takes in a vector of 8 0 -> 255 digits and outputs 1 0 -> 2^18 - 1 digits
    input clk,
    input reset,
    input logic [7:0] vector_a [7:0],
    input logic [7:0] vector_b [7:0],
    output logic [18:0] vector_out

);

    logic [15:0] temps [7:0];


    always_comb begin

        if (reset) begin

            for (int i = 0; i < 8; i++) begin
                temps[i] = 16'b0;
            end

        end else begin

            for (int i = 0; i < 8; i++) begin
                temps[i] = vector_a[i] * vector_b[i];
            end
            
        end
    end

    always @(posedge clk) begin
        for (int i = 0; i < 8; i++) begin
            vector_out <= vector_out + temps[i];
        end
    end



endmodule




