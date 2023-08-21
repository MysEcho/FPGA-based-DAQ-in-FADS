`timescale 1ns / 1ps

module Sampler #
( parameter HIGH_THRESHOLD = 100
)
(
    input [9:0]   adc_dat,
    input         clk,
	input         start,
	input [15:0]  nsamples,
	input [8:0]   npeaks,
    output[9:0]   dout,
    output        we,
    output [15:0] cnt,
    output        finished
    );
    reg [9:0] adc_data;
    reg wr_en;
    reg fin;
    reg [15:0]counter =0;
	reg [15:0]samples;
	reg [8:0] peaks=0;
	reg state =0;
    
    assign dout = adc_data;
    assign we   = wr_en;
    assign cnt  = counter;
    assign finished = fin;
    
    always @(posedge clk) 
	begin
		case (state)
		0:
		begin
            samples = 0;
            wr_en   = 0;
            state   = 1;
            fin     = 0;
		end
		1:
		begin
            if (start  == 1 && samples != nsamples && peaks!=npeaks)
                begin
                    if (adc_dat > HIGH_THRESHOLD) 
                        begin
                            adc_data <= adc_dat;
                            wr_en    <= 1;
                            counter   = counter +1;
                            samples   = samples +1;
                        end
                    else    
                        begin
                            wr_en    <= 0;
                        end
                end
            else if(start !=1 || samples==nsamples)
				begin
				    state =0;
					if(peaks == npeaks)
					   begin
					       state=2;
					   end
					else
					   begin
					       peaks =peaks +1;
					   end
					
				end
		end	
		2:
		begin
		      fin   =1; 
		      counter =0;
		      state =0;
		           
		end
	   endcase
	end

endmodule
