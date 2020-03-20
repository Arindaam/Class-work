
// Write code for modules you need here

module fadd(input wire a,b,cin,output wire sum,cout);
	wire [2:0]t;
	xor3 xo(a,b,cin,sum);
	and2 a1(a,b,t[0]);
	and2 a2(b,cin,t[1]);
	and2 a3(a,cin,t[2]);
	or3 o1(t[0],t[1],t[2],cout);
	
endmodule

module addsub(input wire mode,cin,i0,i1, output wire sumdiff,cout);
	wire t;
	xor2 xo(mode,i1,t);
	fadd fa(i0,t,cin,sumdiff,cout);
endmodule

module pc_slice0 (input wire clk,reset,offset,inc,sub,load, output wire pc,cout);
	wire t1,t2;
	or2 or0(offset,inc,t1);
	addsub as(sub,sub,pc,t1,t2,cout);
	dfrl df(clk,reset,load,t2,pc);
endmodule

module pc_slice1 (input wire clk,reset,offset,inc,sub,load,cin, output wire pc,cout);
	wire t1,t2;
	and2 and0(offset,!inc,t1);
	addsub as(sub,cin,pc,t1,t2,cout);
	dfrl df(clk,reset,load,t2,pc);
endmodule

module pc (input wire clk, reset, inc, add, sub, input wire [15:0] offset, output wire [15:0] pc);

// Declare wires here
	wire[15:0] cout;
	wire load;
// Instantiate modules here
	or3 o(inc,add,sub,load);
	pc_slice0 s0(clk,reset,offset[0],inc,sub,load,pc[0],cout[0]);
	pc_slice1 s1[14:0](clk,reset,offset[15:1],inc,sub,load,cout[14:0],pc[15:1],cout[15:1]);

endmodule

