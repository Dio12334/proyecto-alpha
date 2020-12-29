`timescale 1ns/1ns
module snail_tb;
	reg clk, rst, bit;
	output y;

	always #1 clk = ~clk;
	always #1 rst = 0;
	always #7 bit = ~bit;

	snail sna(clk, rst, bit, y);
	initial begin
		rst = 1;
		clk = 1;
		bit = 0;
		bit = 1;
		#2 bit = 0;
		bit = 1;
		#3 bit = 0;
		#7 $finish;
	end

	initial begin
		 $dumpfile("nail.vcd");
		 $dumpvars;
	 end
	 endmodule
