module assert_z1_state_110_tb;

reg rst_n, clk, x1;
wire [1:3] y;
wire z1;

initial
$monitor ("x1 = %b, state = %b, z1 = %b", x1, y, z1);

initial
begin
	clk = 1'b0;
	forever
		#10 clk = ~clk;
end

initial 
begin
	#0 rst_n = 1'b0;
		x1 = 1'b0;
	#5 rst_n = 1'b1;

	x1 = 1'b1; @ (posedge clk)
	x1 = 1'b1; @ (posedge clk)
	x1 = 1'b1; @ (posedge clk)
	x1 = 1'b1; @ (posedge clk)
	x1 = 1'b0; @ (posedge clk)

	x1 = 1'b1; @(posedge clk)
	x1 = 1'b0; @(posedge clk)
	x1 = 1'b1; @(posedge clk)

	#10 $stop;
end
assert_z1_state_110 inst1(rst_n, clk, x1, y, z1);


        initial begin
                $dumpfile("assert_z1_state_110.vcd");
                $dumpvars;
        end

endmodule
