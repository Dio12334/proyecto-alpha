`timescale 1ns/1ns
module ejercicio_1_tb;
        reg [15:0] in_1, in_2;
        reg sel_3;
        wire [15:0] out_1;
        ejercicio_1 e1 (in_1, in_2, sel_3, out_1);
        initial begin
                in_1 <= 0;
                in_2 <= 1;
                sel_3 = 0;

                $display("time\ts\tin_2\tin_1\tout_1"); $monitor("%2d:\t%b\t%b\t%b\t%b",$time,sel_3,in_2,in_1,out_1);
                #2 $finish;
        end
        always #1 sel_3 = !sel_3;

        initial begin
                $dumpfile("ejercicio_1.vcd");
                $dumpvars;
        end

endmodule
