module assert_z1_state_110 (rst_n, clk, x1, y, z1);
	input rst_n, clk, x1;
	output [1:3] y;
	output z1;

	wire net1, net3, net4, net6;

	and inst1(net1, x1, y[2], y[3]);

	d_ff_bh inst2(rst_n, clk, net1, y[1]);

	and inst3(net3, x1, ~y[3]);
	or inst4(net4, y[3], net3);

	d_ff_bh inst5(rst_n, clk, net4, y[2]);

	and inst6(net6, ~y[2], ~y[3]);

	d_ff_bh inst7(rst_n, clk, net6, y[3]);

	and inst8(z1, y[1], y[2], ~y[3]);

	endmodule
