`timescale 1ns/1ns
module ejercicio_3_c_tb;
        reg [15:0] in_1;
        reg sel_1, sel_2,sel_3, sel_4;

        wire [15:0] out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8, out_9, out_10, out_11, out_12, out_13, out_14, out_15, out_16;

	ejercicio_3_c e3_b(in_1, sel_1, sel_2, sel_3, sel_4, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8, out_9, out_10, out_11, out_12, out_13, out_14, out_15, out_16);
       
        initial begin
                in_1 <= 1;

                sel_1 = 0;
                sel_2 = 0;
                sel_3 = 0;
		sel_4 = 0;

                $display("time\tsel_1\tsel_2\tsel_3\tsel_4\tout_1\tout_2\tout_3\tout_4\tout_5\tout_6\tout_7\tout_8\tout_9\tout_10\tout_11\tout_12\tout_13\tout_14\tout_15\tout_16"); $monitor("%2d:\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b\t%b",$time, sel_1, sel_2, sel_3,sel_4, out_1, out_2, out_3, out_4, out_5, out_6, out_7, out_8, out_9, out_10, out_11, out_12, out_13, out_14, out_15, out_16);
                #15 $finish;
        end

                      always #1 sel_1 = sel_1;
        always #1 sel_2 = sel_2;
        always #1 sel_3 = sel_3;
        always #1 sel_4 = ~sel_4;

        always #2 sel_1 = sel_1;
        always #2 sel_2 = sel_2;
        always #2 sel_3 = ~sel_3;
        always #2 sel_4 = sel_4;

        always #3 sel_1 = sel_1;
        always #3 sel_2 = sel_2;
        always #3 sel_3 = sel_3;
        always #3 sel_4 = sel_4;

        always #4 sel_1 = sel_1;
        always #4 sel_2 = ~sel_2;
        always #4 sel_3 = sel_3;
        always #4 sel_4 = sel_4;

        always #5 sel_1 = sel_1;
        always #5 sel_2 = sel_2;
        always #5 sel_3 = sel_3;
        always #5 sel_4 = sel_4;

        always #6 sel_1 = sel_1;
        always #6 sel_2 = sel_2;
        always #6 sel_3 = sel_3;
        always #6 sel_4 = sel_4;

        always #7 sel_1 = sel_1;
        always #7 sel_2 = sel_2;
        always #7 sel_3 = sel_3;
        always #7 sel_4 = sel_4;

        always #8 sel_1 = ~sel_1;
        always #8 sel_2 = sel_2;
        always #8 sel_3 = sel_3;
        always #8 sel_4 = sel_4;


        initial begin
                $dumpfile("ejercicio_3_c.vcd");
                $dumpvars;
        end

endmodule

