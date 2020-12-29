module jkff(prn, j, k, clk, clrn, q, nq);

	input 	prn, j, k, clk, clrn;
	output 	q, nq;
	wire 	w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16;

	//Master JK Latch
	
	assign w1 = ~(nq & j & ~clk & clrn);
        assign w2 = ~(q & k & ~clk & prn);

        assign w3 = ~(w1 & prn & w4);
        assign w4 = ~(w2 & clrn & w3);

	//Slave D Latch
	
	assign w5 = ~(w3 & clrn & clk);
	assign w6 = ~(w4 & clk & prn);

	//Output
	
	assign q = ~(w5 & prn & nq);
	assign nq = ~(w6 & clrn & q);

endmodule
