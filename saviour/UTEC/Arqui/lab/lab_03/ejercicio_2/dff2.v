module dff2(d, clk, clrn, q);

        input d, clk, clrn;
        output q;
        wire r, s, nq, qw, r2, s2, nq2, qu;
	

	// master dlatch
	assign r = (~d & ~clk);
        assign s = d & ~clk;

	assign qw = ~(r | nq);
	assign nq = ~(s | qw);


	// slave dlatch
        assign r2 = (~qw & clk);
        assign s2 = qw & clk;

        assign qu = ~(r2 | nq2);
        assign nq2 = ~(s2 | qu);

	assign q = qu & ~clrn;

        endmodule


