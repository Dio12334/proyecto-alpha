`timescale 1ns/1ns
module ejercicio_2_b_tb;
        reg [15:0] in_1, in_2,in_3, in_4, in_5, in_6, in_7, in_8, in_9, in_10, in_11, in_12, in_13, in_14, in_15, in_16;
        reg sel_1, sel_2,sel_3, sel_4;

        wire [15:0] out_1;

	ejercicio_2_c e2_b(in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8, in_9, in_10, in_11, in_12, in_13, in_14, in_15, in_16, sel_1, sel_2, sel_3, sel_4, out_1);
       
        initial begin
                in_1 <= 0;
                in_2 <= 1;
                in_3 <= 2;
                in_4 <= 3;
                in_5 <= 4;
                in_6 <= 5;
                in_7 <= 6;
                in_8 <= 7;
	        in_9 <= 8;
                in_10 <= 9;
                in_11 <= 10;
                in_12 <= 11;
                in_13 <= 12;
                in_14 <= 13;
                in_15 <= 14;
                in_16 <= 15;

                sel_1 = 0;
                sel_2 = 0;
                sel_3 = 0;
		sel_4 = 0;

                $display("time\tsel_1\tsel_2\tsel_3\tsel_4\tout_1"); $monitor("%2d:\t%b\t%b\t%b\t%b\t%b",$time, sel_1, sel_2, sel_3, sel_4, out_1);
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

        always #9 sel_1 = sel_1;
        always #9 sel_2 = sel_2;
        always #9 sel_3 = sel_3;
        always #9 sel_4 = sel_4;

        always #10 sel_1 = sel_1;
        always #10 sel_2 = sel_2;
        always #10 sel_3 = sel_3;
        always #10 sel_4 = sel_4; 

        always #11 sel_1 = sel_1; 
        always #11 sel_2 = sel_2; 
        always #11 sel_3 = sel_3; 
        always #11 sel_4 = sel_4;

        always #12 sel_1 = sel_1;
        always #12 sel_2 = sel_2;
        always #12 sel_3 = sel_3;
        always #12 sel_4 = sel_4;

        always #13 sel_1 = sel_1;
        always #13 sel_2 = sel_2;
        always #13 sel_3 = sel_3;
        always #13 sel_4 = sel_4;

        always #14 sel_1 = sel_1;
        always #14 sel_2 = sel_2;
        always #14 sel_3 = sel_3;
        always #14 sel_4 = sel_4; 

        always #15 sel_1 = sel_1; 
        always #15 sel_2 = sel_2; 
        always #15 sel_3 = sel_3; 
        always #15 sel_4 = sel_4;


        initial begin
                $dumpfile("ejercicio_2_c.vcd");
                $dumpvars;
        end

endmodule

