module pajaro(clk, rst, izq, der, out);
	input clk, rst, izq, der;
	output[2:0] out;
	reg[2:0] state_1, state_2;

	parameter s0 = 3'b000;
	parameter s1 = 3'b001;
	parameter s2 = 3'b011;
	parameter s3 = 3'b111;
	parameter s4 = 3'b100;
	parameter s5 = 3'b110;

	//aqui basicamente estoy reciclando lo del snail con cambios

	always @(posedge clk, posedge rst)
		if(rst) state_1 = s0;
		else state_1 <= state_2;

	always @(*)
		case(state_1)
			s0: if((izq & der) || ~(izq || der)) state_2 = s0;	
			else if(der) state_2 = s4;	
			else state_2 = s1;
			s1: state_2 = s2;
			s2: state_2 = s3;
			s3: if(~izq & der) state_2 = s4;
				else if(izq & ~der) state_2 = s1;
				else state_2 = s0;
			s4: state_2 = s5;
			s5: state_2 = s3;
		endcase

	assign out = state_1;
endmodule
