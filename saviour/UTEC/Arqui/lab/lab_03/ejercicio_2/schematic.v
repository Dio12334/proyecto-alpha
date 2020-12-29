module schematic (di, d, load, clk, clrn, q, do);

	input [2:0] d;
	input di, load, clk, clrn;
	output [2:0] q;
	output do;
	wire w1, w2, w3, w4;

	mux2_1 m1(di, d[2], load, w1);
	dff2 dff1(w1, clk, clrn, w2);
	assign q[2] = w2;

	mux2_1 m2(w2, d[1], load, w3);
	dff2 dff2(w3, clk, clrn, w4);
	assign q[1] = w4;

	mux2_1 m3(w4, d[0], load, w5);
	dff2 dff3(w5, clk, clrn, do);
	assign q[0] = do;

	endmodule


