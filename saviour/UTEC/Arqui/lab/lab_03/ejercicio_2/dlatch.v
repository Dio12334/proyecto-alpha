module dlatch(clk, d, q, nq);

	input 	clk, d;
	output 	q, nq;
	wire  	r, s;

	assign r = ~d & clk;
	assign s = d & clk;

	rslatch a1(r, s, q, nq);

endmodule
