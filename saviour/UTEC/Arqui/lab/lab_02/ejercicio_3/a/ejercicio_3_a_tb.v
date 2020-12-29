`timescale 1ns/1ns
module ejercicio_3_a_tb;
        reg [15:0] in_1;
        reg sel_1;

        wire [15:0] out_1, out_2;

       ejercicio_3_a e3_a(in_1, sel_1, out_1, out_2);
        initial begin
                in_1 <= 2;
                sel_1 = 0;

                $display("time\tsel_1\t\tout_1\tout_2"); $monitor("%2d:\t%b\t%b\t%b",$time, sel_1, out_1, out_2);
                #2 $finish;
        end

        always #1 sel_1 = !sel_1;

        initial begin
                $dumpfile("ejercicio_3_a.vcd");
                $dumpvars;
        end

endmodule

