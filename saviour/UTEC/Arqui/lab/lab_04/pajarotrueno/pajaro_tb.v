`timescale 1ns/1ns
module pajaro_tb;
	reg clk, rst, izq, der;
	output wire [2:0] out;
	always #1 clk = ~clk;
	always #1 rst = 0;
	pajaro dodo(clk, rst, izq, der, out);
	initial begin
		clk <= 1;
		rst <= 1;
		izq <= 1;
		der <= 0;
		#3 izq = 1;
		#3 der = 0;
		#5 der = 1;
		#10 izq = 1;
		#4 der = 0;
		#4 izq = 0;
		#1 der = 1;
		#7 $finish;
	end
	initial begin
		$dumpfile("pajaro.vcd");
		$dumpvars;
	end
	endmodule
