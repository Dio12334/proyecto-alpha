module ejercicio_3_a(in_1,sel_1, out_1, out_2);
	input [15:0] in_1; 
	input sel_1;
	output [15:0] out_1, out_2;

	assign out_1 = (in_1 && ~sel_1)?in_1:0;

	assign out_2 = (in_1 && sel_1)? in_1:0;

endmodule



