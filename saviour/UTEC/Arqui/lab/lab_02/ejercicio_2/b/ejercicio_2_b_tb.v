`timescale 1ns/1ns
module ejercicio_2_b_tb;
        reg [15:0] in_1, in_2,in_3, in_4, in_5, in_6, in_7, in_8;
        reg sel_1, sel_2,sel_3;

        wire [15:0] out_1;

       ejercicio_2_b e2_b(in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8, sel_1, sel_2, sel_3, out_1); 
        initial begin
                in_1 <= 0;
		in_2 <= 1;
		in_3 <= 2;
		in_4 <= 3;
		in_5 <= 4;
		in_6 <= 5;
		in_7 <= 6;
		in_8 <= 7;
		sel_1 = 0;
		sel_2 = 0;
                sel_3 = 0;

                $display("time\tsel_1\tsel_2\tsel_3\tout_1"); $monitor("%2d:\t%b\t%b\t%b\t%b",$time, sel_1, sel_2, sel_3, out_1);
                #8 $finish;
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
                $dumpfile("ejercicio_2_b.vcd");
                $dumpvars;
        end

endmodule

