`timescale 1ns/1ns
module schematic_tb;
        reg 	di, load, clk, clrn;
	reg [2:0] d;
        wire 	do;
	wire [2:0] q;

	always #1 clk = ~clk;
        
        always #2 di = ~di;
        always #1 d[0] = ~d[0];
        always #2 d[1] = ~d[1];
        always #4 d[2] = ~d[2];

        schematic schematic_1 (di, d, load, clk, clrn, q, do); 
	//le hubye
	initial begin
        	#29 clrn = ~clrn;
	end
	initial begin
		#16 load = ~load;		   

	end
	//fin le hubye
	
        initial begin
                 
		clk 	= 1;
		load 	= 1;
		clrn 	= 0;
		di 	= 1;
		d	<= 3'b000;
                

                $display("time\tdi\td\tload\tclk\tclrn\tq\tdo"); $monitor("%2d:\t%b\t%b\t%b\t%b\t%b\t%b\t%b",$time, di, d, load, clk, clrn, q, do);
                #30 $finish;
        end

        initial begin
                $dumpfile("schematic.vcd");
                $dumpvars;
        end

        endmodule

