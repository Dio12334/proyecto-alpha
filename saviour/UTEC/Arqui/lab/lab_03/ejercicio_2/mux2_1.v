module mux2_1(a, b ,s , out);
	input a, b, s;
	output out;

	assign out = s? b:a;

endmodule
