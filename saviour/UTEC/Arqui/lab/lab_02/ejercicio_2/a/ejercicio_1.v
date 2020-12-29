module ejercicio_1(in_1, in_2, sel_3, out_1);
	input [15:0] in_1;
	input [15:0] in_2;
	input	     sel_3;

	output [15:0] out_1;

	assign out_1 = sel_3 ? in_2: in_1;

endmodule
