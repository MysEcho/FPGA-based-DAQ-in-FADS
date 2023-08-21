`timescale 1ns / 1ps

module Sampler #
( parameter HIGH_THRESHOLD = 100
)
(
    input [9:0] adc_dat,
    input clk,
    output [9:0] dout,
    output we,
    output [15:0] cnt
    );
    reg [9:0] adc_data;
    reg wr_en;
    reg [15:0]counter =0;
    
    assign dout = adc_data;
    assign we   = wr_en;
    assign cnt  = counter;
    
    always @(posedge clk) begin
        if (adc_dat > HIGH_THRESHOLD) 
            begin
                adc_data <= adc_dat;
                wr_en    <= 1;
                counter   = counter +1;
            end
        else    
            begin
                wr_en    <= 0;
            end
    end

endmodule
