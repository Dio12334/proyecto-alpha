module tff(prn, t, clk, clrn, q, nq);

	input prn, t, clk, clrn;
	output q ,nq;
	wire w1, w2, w3, w4, w5, w6;

	//Tlatch master

        assign w1 = ~(t & ~clk & nq & clrn);
        assign w2 = ~(t & prn & ~clk & q);

	assign w3 = ~(w1 & prn & w4);
	assign w4 = ~(w3 & w2 & clrn);

	//Dlatch slave
	
	assign w5 = ~(w3 & clrn & clk);
	assign w6 = ~(w4 & prn & clk);

	//output
	assign q = ~(w5 & prn & nq);
	assign nq = ~(w6 & clrn & q);

endmodule
