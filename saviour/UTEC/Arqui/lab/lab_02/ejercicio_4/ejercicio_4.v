module ejercicio_4 (in_1, en, out_1);
	input [2:0] in_1;
	input en;
	output [7:0] out_1;

	assign out_1[0] = in_1 == 0? en : 0;
	assign out_1[1] = in_1 == 1? en : 0;
	assign out_1[2] = in_1 == 2? en : 0;
        assign out_1[3] = in_1 == 3? en : 0;
        assign out_1[4] = in_1 == 4? en : 0;
        assign out_1[5] = in_1 == 5? en : 0;
        assign out_1[6] = in_1 == 6? en : 0;
        assign out_1[7] = in_1 == 7? en : 0;
endmodule
