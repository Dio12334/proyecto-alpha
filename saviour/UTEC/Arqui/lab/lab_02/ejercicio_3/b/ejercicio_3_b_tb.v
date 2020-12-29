`timescale 1ns/1ns
module ejercicio_3_b_tb;
        reg [15:0] in_1;
        reg sel_1, sel_2, sel_3;

        wire [15:0] out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8;

       ejercicio_3_b e3_a(in_1, sel_1, sel_2, sel_3, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8);
        initial begin
                in_1 <= 1;
                sel_1 = 0;
		sel_2 = 0;
		sel_3 = 0;

                $display("time\tsel_1\tsel_2\tsel_3\tout_1\tout_2\tout_3\tout_4\tout_5\tout_6\tout_7\tout_8"); $monitor("%2d:\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b",$time, sel_1, sel_2, sel_3, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8);
                #7 $finish;
        end

        always #1 sel_1 = sel_1;
        always #1 sel_2 = sel_2;
        always #1 sel_3 = ~sel_3;

        always #2 sel_1 = sel_1;
        always #2 sel_2 = ~sel_2;
        always #2 sel_3 = sel_3;

        always #3 sel_1 = sel_1;
        always #3 sel_2 = sel_2;
        always #3 sel_3 = sel_3;

        always #4 sel_1 = ~sel_1;
        always #4 sel_2 = sel_2;
        always #4 sel_3 = sel_3;

        always #5 sel_1 = sel_1;
        always #5 sel_2 = sel_2;
        always #5 sel_3 = sel_3;

        always #6 sel_1 = sel_1;
        always #6 sel_2 = sel_2;
        always #6 sel_3 = sel_3;

        always #7 sel_1 = sel_1;
        always #7 sel_2 = sel_2;
        always #7 sel_3 = sel_3;


        initial begin
                $dumpfile("ejercicio_3_b.vcd");
                $dumpvars;
        end

endmodule
