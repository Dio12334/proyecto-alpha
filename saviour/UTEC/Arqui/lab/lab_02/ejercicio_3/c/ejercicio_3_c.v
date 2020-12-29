module ejercicio_3_c(in_1, sel_1, sel_2, sel_3, sel_4, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8, out_9, out_10, out_11, out_12, out_13, out_14, out_15, out_16);
	input [15:0] in_1;
	input sel_1, sel_2, sel_3, sel_4;
	output [15:0] out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8, out_9, out_10, out_11, out_12, out_13, out_14, out_15, out_16;
	wire [15:0] wi_1, wi_2;

	ejercicio_3_a a1(in_1, sel_4, wi_1, wi_2);

	ejercicio_3_b a2_0(wi_1, sel_1, sel_2, sel_3, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8);
	ejercicio_3_b a2_1(wi_2, sel_1, sel_2, sel_3, out_9, out_10, out_11, out_12, out_13, out_14, out_15, out_16);



endmodule
