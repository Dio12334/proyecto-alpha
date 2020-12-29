module tff(prn, t, clk, clrn, q, nq);

        input   prn, t, clk, clrn;
        output  q, nq;
        wire    w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16;

        //Master JK Latch
		
	or a1(w1, ~nq, ~t);
	or a2(w2, clk, ~clrn);
	or a3(w3, w1, w2);

	//w3

	or a4(w4, ~q, ~t);
        or a5(w5, clk, ~prn);
        or a6(w6, w4, w5);

	//w6

        or a7(w7, ~w3, ~prn);
        or a8(w8, w7, ~w10);

	//w3->w8
	
        or a9(w9, ~clrn, ~w6);
        or a10(w10, w9, ~w8);

	//w6->w10


	//Slave D Latch

        or a11(w11, ~w8, ~clrn);
        or a12(w12, w11, ~clk);


	//w8->w12

	or a13(w13, ~w10, ~prn);
        or a14(w14, w13, ~clk);

	//w10->w14

        //Output
	
	or a15(w15, ~w12, ~prn);
        or a16(q, w15, ~nq);

        or a17(w16, ~w14, ~clrn);
        or a18(nq, w16, ~q);



endmodule

