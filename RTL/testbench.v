`timescale 1ns / 1ps
module testbench();
reg [1:0] in_pre,out_pre;
reg [31:0] A,B,C,D;
wire[31:0] out;
wire soe;
reg clk=0;
reg start=0;

top top(clk,start,A,B,C,D,in_pre,out_pre,out,soe);
initial begin
    A = 32'b10001000;
    B = 32'b10001100;
    C = 32'b01100000;
    D = 32'b01000000;
	in_pre = 2'b00;
    out_pre = 2'b00;
    start=1;
    #20
    start=0;

end

always #10 clk <= ~clk;
endmodule