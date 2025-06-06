module dot_product (

    // Takes in a vector of 8 0 -> 255 digits and outputs 1 0 -> 2^18 - 1 digits
    input logic clk,
    input logic reset,
    input logic [7:0] vector_a [7:0],
    input logic [7:0] vector_b [7:0],
    output logic [18:0] vector_out

);

    logic [15:0] temp [7:0];
    logic [18:0] sum;


    // Combinationally multiply all matching indices and store in a temp register
    always_comb begin
        for (int i = 0; i < 8; i++) begin
            temp[i] = vector_a[i] * vector_b[i];
        end
    end


    always @(posedge clk) begin
        // Reset sum to 0 if reset
        if (reset) begin
            sum <= 19'd0;
        end
        // Otherwise accumulate the temp regs
        // Figure out how to do this more efficiently
        else begin
            sum <= {3'b000, temp[0]} +
                   {3'b000, temp[1]} +
                   {3'b000, temp[2]} +
                   {3'b000, temp[3]} +
                   {3'b000, temp[4]} +
                   {3'b000, temp[5]} +
                   {3'b000, temp[6]} +
                   {3'b000, temp[7]};
        end

        vector_out <= sum;
    end


endmodule




