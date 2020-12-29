`timescale 1ns/1ns
module tff_tb;
        reg prn, t, clk, clrn;

        wire q, nq;

        tff tf1 (prn, t, clk, clrn, q, nq);
        initial begin
        	prn = 0;
                t = 1;
		clk = 1;
		clrn = 1;

                $display("time\tprn\tt\tclk\tclrn\tq\tnq"); $monitor("%2d:\t%b\t%b\t%b\t%b\t%b\t%b",$time, prn, t, clk, clrn, q, nq);
                #23 $finish;
        end

        always #1 clk = !clk;

        initial begin
                $dumpfile("tff.vcd");
                $dumpvars;
        end

        endmodule

