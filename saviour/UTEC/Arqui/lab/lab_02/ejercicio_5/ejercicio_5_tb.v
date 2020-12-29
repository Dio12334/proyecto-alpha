`timescale 1ns/1ns
module ejercicio_5_tb;
        reg [7:0] in_1;
        reg en;
        wire [2:0] out_1;
	wire g;

       ejercicio_5 e5 (in_1, en, out_1, g);

      initial begin
                in_1 = 0;
                en = 1;

                $display("time\ten\tin_1\tout_1"); $monitor("%2d:\t%b\t%b\t%b\t%b",$time,
en, in_1, out_1, g);
                #257 $finish;
        end

        always #1 in_1 = in_1 +1;
        

        always #257 en = ~en;


        initial begin
                $dumpfile("ejercicio_5.vcd");
                $dumpvars;
        end

endmodule


