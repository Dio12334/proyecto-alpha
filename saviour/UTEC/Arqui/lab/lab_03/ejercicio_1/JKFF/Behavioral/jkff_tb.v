`timescale 1ns/1ns
module jkff_tb;
        reg prn, j, k, clk, clrn;

        wire q, nq;

        jkff jkff_1 (prn, j, k, clk, clrn, q, nq); 

        initial begin
                prn = 0;
                j = 0;
		k = 0;
                clk = 1;
                clrn = 1;

                $display("time\tprn\tj\tk\tclk\tclrn\tq\tnq"); $monitor("%2d:\t%b\t%b\t%b\t%b\t%b\t%b\t%b",$time, prn, j, k, clk, clrn, q, nq);
                #23 $finish;
        end

	initial begin
        #3 j = 1;
        #5 j = 0;
        #7 j = 1;
        #15 j = 0;
        end

	initial begin
	#1 k = 1;
        #3 k = 0;
        #7 k = 1;
        #15 k = 0;	
	end

        always #1 clk = !clk;
	always #3 prn = !prn;
        initial begin
                $dumpfile("jkff.vcd");
                $dumpvars;
        end

        endmodule

