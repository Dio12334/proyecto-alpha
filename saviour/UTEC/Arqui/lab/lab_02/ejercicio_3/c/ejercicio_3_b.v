module ejercicio_3_b(in_1, sel_1, sel_2, sel_3, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8);
	input [15:0] in_1;
	input sel_1, sel_2, sel_3;
	output [15:0] out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8;
	wire [15:0] wi_1, wi_2, wi_3, wi_4, wi_5, wi_6;

	ejercicio_3_a a1(in_1, sel_3, wi_1, wi_2);

	ejercicio_3_a a2_0(wi_1, sel_2, wi_3, wi_4);
	ejercicio_3_a a2_1(wi_2, sel_2, wi_5, wi_6);

	ejercicio_3_a a3_0(wi_3, sel_1, out_1, out_2);
        ejercicio_3_a a3_1(wi_4, sel_1, out_3, out_4);
        ejercicio_3_a a3_2(wi_5, sel_1, out_5, out_6);
	ejercicio_3_a a3_3(wi_6, sel_1, out_7, out_8);



endmodule
