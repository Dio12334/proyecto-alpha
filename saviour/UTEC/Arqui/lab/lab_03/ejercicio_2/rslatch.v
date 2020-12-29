module rslatch(r, s, q, nq);

	input r, s;
	output q, nq;
	wire wir1, wir2;

	assign q = ~(r | nq);
	assign nq = ~(s | q);

endmodule
