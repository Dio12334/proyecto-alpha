`timescale 1ns/1ns
module ejercicio_4_tb;
        reg [2:0] in_1;
        reg en;
        wire [7:0] out_1, out_2;
	
       ejercicio_4 e4 (in_1, en, out_1);
       
      initial begin	
                in_1 = 0;
                en = 1;

                $display("time\ten\tin_1\tout_1"); $monitor("%2d:\t%b\t%b\t%b",$time, 
en, in_1, out_1);
                #9 $finish;
        end

        always #1 in_1 = in_1 +1;
       	always #2 in_1 = in_1; 
        always #3 in_1 = in_1;
        always #4 in_1 = in_1;
        always #5 in_1 = in_1;
        always #6 in_1 = in_1;
        always #7 in_1 = in_1;
 
        always #8 en = ~en;


        initial begin
                $dumpfile("ejercicio_4.vcd");
                $dumpvars;
        end

endmodule

