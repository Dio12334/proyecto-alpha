module mips(input  reg        clk, reset,
            output reg [31:0] pc,
            input  reg [31:0] instr,
            output reg        memwrite,
            output reg [31:0] aluout, writedata,
            input  reg [31:0] readdata);

  reg        memtoreg, branch,
               pcsrc, zero,
               alusrc, regdst, regwrite, jump;
  reg [3:0]  alucontrol;

  controller c(instr[31:26], instr[5:0], zero,
               memtoreg, memwrite, pcsrc,
               alusrc, regdst, regwrite, jump,
               alucontrol);
  datapath dp(clk, reset, memtoreg, pcsrc,
              alusrc, regdst, regwrite, jump,
              alucontrol,
              zero, pc, instr,
              aluout, writedata, readdata);
endmodule

module controller(input  reg [5:0] op, funct,
                  input  reg       zero,
                  output reg       memtoreg, memwrite,
                  output reg       pcsrc, alusrc,
                  output reg       regdst, regwrite,
                  output reg       jump,
                  output reg [2:0] alucontrol);

  reg [1:0] aluop;
  reg       branch;

  maindec md(op, memtoreg, memwrite, branch,
             alusrc, regdst, regwrite, jump,
             aluop);
  aludec  ad(funct, aluop, alucontrol);

  assign pcsrc = branch & zero;
endmodule

module maindec(input  reg [5:0] op,
               output reg       memtoreg, memwrite,
               output reg       branch, alusrc,
               output reg       regdst, regwrite,
               output reg       jump,
               output reg [1:0] aluop);

  reg [8:0] controls;

  assign {regwrite, regdst, alusrc,
          branch, memwrite,
          memtoreg, jump, aluop} = controls;

  always_comb
    case(op)
      6'b000000: controls <= 9'b110000010; //Rtype
      6'b100011: controls <= 9'b101001000; //LW
      6'b101011: controls <= 9'b001010000; //SW
      6'b000100: controls <= 9'b000100001; //BEQ
      6'b001000: controls <= 9'b101000000; //ADDI
      6'b000010: controls <= 9'b000000100; //J
      default:   controls <= 9'bxxxxxxxxx; //???
    endcase
endmodule

module aludec(input  reg [5:0] funct,
              input  reg [1:0] aluop,
              output reg [3:0] alucontrol);

  always_comb
    case(aluop)
      2'b00: alucontrol <= 3'b010;  // add
      2'b01: alucontrol <= 3'b110;  // sub
      default: case(funct)          // RTYPE
          6'b100000: alucontrol <= 4'b0000; // ADD
          6'b100010: alucontrol <= 4'b0010; // SUB
          6'b100100: alucontrol <= 4'b0100; // AND
          6'b100101: alucontrol <= 4'b0101; // OR
          6'b101010: alucontrol <= 4'b1010; // SLT
          default:   alucontrol <= 4'bxxxx; // ???
        endcase
    endcase
endmodule

module datapath(input          clk, reset,
                input          memtoreg, pcsrc,
                input  reg        alusrc, regdst,
                input  reg        regwrite, jump,
                input  reg [3:0]  alucontrol,
                output reg        zero,
                output reg [31:0] pc,
                input  reg [31:0] instr,
                output reg [31:0] aluout, writedata,
                input  reg [31:0] readdata);

  reg [4:0]  writereg;
  reg [31:0] pcnext, pcnextbr, pcplus4, pcbranch;
  reg [31:0] signimm, signimmsh;
  reg [31:0] srca, srcb;
  reg [31:0] result;

  // next PC logic
  flopr #(32) pcreg(clk, reset, pcnext, pc);
  adder       pcadd1(pc, 32'b100, pcplus4);
  sl2         immsh(signimm, signimmsh);
  adder       pcadd2(pcplus4, signimmsh, pcbranch);
  mux2 #(32)  pcbrmux(pcplus4, pcbranch, pcsrc,
                      pcnextbr);
  mux2 #(32)  pcmux(pcnextbr, {pcplus4[31:28], 
                    instr[25:0], 2'b00}, 
                    jump, pcnext);

  // register file logic
  regfile     rf(clk, regwrite, instr[25:21],
                 instr[20:16], writereg,
                 result, srca, writedata);
  mux2 #(5)   wrmux(instr[20:16], instr[15:11],
                    regdst, writereg);
  mux2 #(32)  resmux(aluout, readdata,
                     memtoreg, result);
  signext     se(instr[15:0], signimm);

  // ALU logic
  mux2 #(32)  srcbmux(writedata, signimm, alusrc,
                      srcb);
  alu         alu(.a(srca), .b(srcb), .f(alucontrol),
                  .y(aluout), .zero(zero));
endmodule

