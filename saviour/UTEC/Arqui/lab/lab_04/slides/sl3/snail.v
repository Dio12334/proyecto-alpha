module snail(clk, rst, bit, y);
	input clk, rst, bit;
	output y;

	reg[3:0] state_1, state_2;

	parameter s0 = 4'b0000;
	parameter s1 = 4'b0001;
	parameter s2 = 4'b0010;
	parameter s3 = 4'b0100;
	parameter s4 = 4'b1000;

	always @ (posedge clk, posedge rst)
		if(rst) state_1 = s0;
		else state_1 <= state_2;

	always @(*)
	case(state_1)
		s0: if(bit)state_2 = s1;
			else state_2 = s0;

		s1: if(bit)state_2 = s2;
                        else state_2 = s0;

		s2: if(bit)state_2 = s3;
                        else state_2 = s2;

		s3: if(bit)state_2 = s4;
                        else state_2 = s0;

		s4: if(bit)state_2 = s2;
                        else state_2 = s0;
	endcase
assign y = (state_1 == s4);
endmodule
