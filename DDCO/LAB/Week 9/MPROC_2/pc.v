
// Write code for modules you need here
module fadd(input wire a,b,c, output wire sum,cout);
	
	wire [2:0]t;
	xor3 xorn(a,b,c,sum);
	and2 a1(a,b,t[0]);
	and2 a2(b,c,t[1]);
	and2 a3(a,c,t[2]);
	or3 a123(t[0],t[1],t[2],cout);
	
endmodule

/*module addsub(input wire mode,cin,i0,i1, output wire sumdiff,cout);
	wire t;
	xor2 xo(mode,i1,t);
	fadd scam3(i0,t,cin,sumdiff,cout);
	


endmodule*/

module slice0(input wire clk,reset,offset,inc,sub,load,output wire pc,cout);
	wire t1,t2;
	or2 o1(offset,inc,t1);
	addsub scam(sub,sub,pc,t1,t2,cout);
	dfrl scam2(clk, reset, load, t2, pc);
	
endmodule

module slice1(input wire clk,reset,offset,inc,sub,load,cin,output wire pc,cout);
	wire t1,t2;
	and2 a1(~inc,offset,t1);
	addsub a2(sub,cin,pc,t1,t2,cout);
	dfrl a3(clk,reset,load,t2,pc);
endmodule
	
module pc (input wire clk, reset, inc, add, sub, input wire [15:0] offset, output wire [15:0] pc);

// Declare wires here
	wire [15:0]cout;
	wire load;
// Instantiate modules here
	or3 r(inc,add,sub,load);
	slice0 r1(clk,reset,offset[0],inc,sub,load,pc[0],cout[0]);
	slice1 r2[14:0](clk,reset,offset[15:1],inc,sub,load,cout[14:0],pc[15:1],cout[15:1]);
	

endmodule
