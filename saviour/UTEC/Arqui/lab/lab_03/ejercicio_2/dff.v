module dff(d, clk, clrn, q);

	input d, clk, clrn;
	output q;
	wire nq , qw, qw2, nq2;

	dlatch a1(~clk, d, qw, nq);

	dlatch a2(clk, qw, qw2, nq2);

	assign q = qw2 & ~clrn;

	endmodule

	
