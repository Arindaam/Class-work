
// Write code for modules you need here

module fadd(input wire a, b, cin, output wire sum, cout);

wire w1,w2,w3;
xor3 xo1(a,b,cin,sum);
and2 an1(a,b,w1);
and2 an2(b,cin,w2);
and2 an3(cin,a,w3);
or3 o1(w1,w2,w3,cout);

endmodule

module new_fa(input a, b, x, c,output sum, carry);
wire w;
xor2 my_xor2(b,x,w);
fadd my_fa(a,w,c,sum,carry);
endmodule

module first_pc(input wire clk, reset, load, inc, o, sub, c, output wire carry, out2);

wire out, sum;
or2 o0(inc, o, out);
new_fa n0(out2,out,sub,c,sum,carry);
dfrl d0(clk, reset, load, sum, out2);

endmodule

module other_pc(input wire clk,reset,load, inc, o, sub, c, output wire carry, out2);

wire inc_i, out, sum;
invert i0(inc, inc_i);
and2 m0(inc_i, o, out);
new_fa n0(out2,out,sub,c,sum,carry);
dfrl d0(clk, reset, load, sum, out2);

endmodule



module pc (input wire clk, reset, inc, add, sub, input wire [15:0] offset, output wire [15:0] pc);

// Declare wires here



wire w[15:0];
wire load;
or3 o1(add,sub,inc,load);
first_pc pc0(clk, reset, load,inc,offset[0] ,sub, sub, w[0], pc[0]);
other_pc pc1(clk, reset, load,inc,offset[1] ,sub,w[0], w[1], pc[1]);
other_pc pc2(clk, reset, load,inc,offset[2] ,sub,w[1], w[2], pc[2]);
other_pc pc3(clk, reset, load,inc,offset[3] ,sub,w[2], w[3], pc[3]);
other_pc pc4(clk, reset, load,inc,offset[4] ,sub,w[3], w[4], pc[4]);
other_pc pc5(clk, reset, load,inc,offset[5] ,sub,w[4], w[5], pc[5]);
other_pc pc6(clk, reset, load,inc,offset[6] ,sub,w[5], w[6], pc[6]);
other_pc pc7(clk, reset, load,inc,offset[7] ,sub,w[6], w[7], pc[7]);
other_pc pc8(clk, reset, load,inc,offset[8] ,sub,w[7], w[8], pc[8]);
other_pc pc9(clk, reset, load,inc,offset[9] ,sub,w[8], w[9], pc[9]);
other_pc pc10(clk, reset, load,inc,offset[10] ,sub,w[9], w[10], pc[10]);
other_pc pc11(clk, reset, load,inc,offset[11] ,sub,w[10], w[11], pc[11]);
other_pc pc12(clk, reset, load,inc,offset[12] ,sub,w[11], w[12], pc[12]);
other_pc pc13(clk, reset, load,inc,offset[13] ,sub,w[12], w[13], pc[13]);
other_pc pc14(clk, reset, load,inc,offset[14] ,sub,w[13], w[14], pc[14]);
other_pc pc15(clk, reset, load,inc,offset[15] ,sub,w[14], w[15], pc[15]);



// Instantiate modules here

endmodule
