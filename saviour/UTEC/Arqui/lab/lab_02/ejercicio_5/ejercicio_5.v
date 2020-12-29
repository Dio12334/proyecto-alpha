module ejercicio_5(in_1, en, out_1, g);
	input wire[7:0] in_1;
	input en;
	output reg[2:0] out_1;
	output g;

	always @*
	begin
		if(!en)
			out_1 = 8'o0;
		else 
			casex(in_1)
		
	        		8'b00000001 : out_1 = 8'o0;
                		8'b0000001x : out_1 = 8'o1;
                		8'b000001xx : out_1 = 8'o2;
                		8'b00001xxx : out_1 = 8'o3;
                		8'b0001xxxx : out_1 = 8'o4;
                		8'b001xxxxx : out_1 = 8'o5;
                		8'b01xxxxxx : out_1 = 8'o6;
                		8'b1xxxxxxx : out_1 = 8'o7;

				default: begin
					out_1 = 8'o0;
				end
			endcase
	end
	assign g = (en && in_1)? 1:0;

endmodule
