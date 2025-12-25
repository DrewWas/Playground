

// TODO: Right now a lot of functionality is downstream of a 3x3 kernel/window
// and not arbitrarily abstracted (i.e. 3 distinct line buffers)
// See if we can generalize 


// ASSUMPTIONS: 
// 2048x2048 images
// each pixel is 8-bit unsigned grayscale 

module main #(
    parameter IMG_W = 2048, 
    parameter IMG_H = 2048,
    parameter BYTE = 8,
    parameter KERNEL_DIM = 3,
    parameter WINDOW_DIM = 3
) (
    input clk,
    input reset,
    input [BYTE - 1:0] input_pixel, //8-bit unsigned grayscale
    input in_valid,
    output logic out_valid,
    output logic [BYTE - 1:0] output_pixel //8-bit unsigned grayscale
);


    // variables
    logic [$clog2(IMG_W) - 1:0] x_pos;
    logic [$clog2(IMG_H) - 1:0] y_pos;

    // line buffers (2D array to streamline reassignment when full)
    logic [BYTE - 1:0] line_buffer [0 : KERNEL_DIM - 1][0 : IMG_W - 1];
    logic [$clog2(KERNEL_DIM) - 1 : 0] top_buf;
    logic [$clog2(KERNEL_DIM) - 1 : 0] mid_buf;
    logic [$clog2(KERNEL_DIM) - 1 : 0] bot_buf;


    // LINE BUFFERS LOGIC 
    always_ff @(posedge clk) begin

        if (reset) begin
            // Initialize/Reset all signals/registers 
            x_pos <= '0;
            y_pos <= '0;
            top_buf <= 'd0;
            mid_buf <= 'd1;
            bot_buf <= 'd2;

            foreach (line_buffer[b, x]) begin
                line_buffer[b][x] <= '0;
            end

        end else if (in_valid) begin
            if (y_pos == 0) begin
                line_buffer[top_buf][x_pos] <= input_pixel;
            end else if (y_pos == 1) begin
                line_buffer[mid_buf][x_pos] <= input_pixel;
            end else if (y_pos == 2) begin
                line_buffer[bot_buf][x_pos] <= input_pixel;
            end else begin
                // Steady State
                line_buffer[bot_buf][x_pos] <= input_pixel;
            end

            if (x_pos == IMG_W - 1) begin
                x_pos <= '0;
                y_pos <= y_pos + 1'd1;
                if (y_pos >= 2) begin
                    top_buf <= mid_buf;
                    mid_buf <= bot_buf;
                    bot_buf <= top_buf; // uses old top_buf value and overwrites
                end else begin
                    x_pos <= x_pos + 1'd1;
                end
            end
            
        end
    end


    //Kernel variables and logic 
    logic [WINDOW_DIM - 1: 0] window [WINDOW_DIM - 1: 0];

    always_comb begin
        window[0] = {line_buffer1[x_pos - 2], line_buffer1[x_pos - 1], line_buffer1[x_pos]};
        window[1] = {line_buffer2[x_pos - 2], line_buffer2[x_pos - 1], line_buffer2[x_pos]};
        window[2] = {line_buffer3[x_pos - 2], line_buffer3[x_pos - 1], line_buffer3[x_pos]};
    end


    // Perform Actual Convolution and assign output
    logic [KERNEL_DIM - 1: 0] GX [KERNEL_DIM - 1: 0];
    logic [KERNEL_DIM - 1: 0] GY [KERNEL_DIM - 1: 0];

    always_ff @(posedge clk) begin
        if (reset) begin
            // INIT KERNEL
            //GX <= {[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]};
            //GY <= {[1, 2, 1], [0, 0, 0], [-1, -2, -1]};
        end else begin
            // Peform Convolution

        end

    end


endmodule 


