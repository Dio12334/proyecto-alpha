module ejercicio_2_b(in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8, sel_1, sel_2, sel_3, out_1);

	input [15:0] in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8;
	input sel_1, sel_2, sel_3;
	wire [15:0] wi_1, wi_2, wi_3, wi_4, wi_5, wi_6; 

	output [15:0] out_1;

	ejercicio_1 a1_0(in_1, in_2, sel_1, wi_1);
	ejercicio_1 a1_1(in_3, in_4, sel_1, wi_2);
	ejercicio_1 a1_2(in_5, in_6, sel_1, wi_3);
	ejercicio_1 a1_3(in_7, in_8, sel_1, wi_4);

	ejercicio_1 a2_0(wi_1, wi_2, sel_2, wi_5);
        ejercicio_1 a2_1(wi_3, wi_4, sel_2, wi_6);

	ejercicio_1 a3_0(wi_5, wi_6, sel_3, out_1);

endmodule
