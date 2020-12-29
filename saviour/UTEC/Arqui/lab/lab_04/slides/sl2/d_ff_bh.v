module d_ff_bh (rst_n, clk, d, q);

	input rst_n, clk, d;
	output q;

	wire rst_n, clk, d;
	reg q;

	always @ (rst_n or posedge clk)
	begin
		if (rst_n == 0)
			q <= 1'b0;
		else q <= d;
	end
endmodule

