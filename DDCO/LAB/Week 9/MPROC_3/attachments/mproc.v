module nor5 (input wire [0:4] i, output wire o);
  wire t;
  or3 or3_0 (i[0], i[1], i[2], t);
  nor3 nor3_0 (t, i[3], i[4], o);
endmodule

module ir (input wire clk, reset, load, input wire [15:0] din, output wire [15:0] dout);
  dfrl dfrl_0 (clk, reset, load, din['h0], dout['h0]);
  dfrl dfrl_1 (clk, reset, load, din['h1], dout['h1]);
  dfrl dfrl_2 (clk, reset, load, din['h2], dout['h2]);
  dfrl dfrl_3 (clk, reset, load, din['h3], dout['h3]);
  dfrl dfrl_4 (clk, reset, load, din['h4], dout['h4]);
  dfrl dfrl_5 (clk, reset, load, din['h5], dout['h5]);
  dfrl dfrl_6 (clk, reset, load, din['h6], dout['h6]);
  dfrl dfrl_7 (clk, reset, load, din['h7], dout['h7]);
  dfrl dfrl_8 (clk, reset, load, din['h8], dout['h8]);
  dfrl dfrl_9 (clk, reset, load, din['h9], dout['h9]);
  dfrl dfrl_a (clk, reset, load, din['ha], dout['ha]);
  dfrl dfrl_b (clk, reset, load, din['hb], dout['hb]);
  dfrl dfrl_c (clk, reset, load, din['hc], dout['hc]);
  dfrl dfrl_d (clk, reset, load, din['hd], dout['hd]);
  dfrl dfrl_e (clk, reset, load, din['he], dout['he]);
  dfrl dfrl_f (clk, reset, load, din['hf], dout['hf]);
endmodule

module control_logic (input wire clk, reset, input wire [15:0] cur_ins, output wire [2:0] rd_addr_a, rd_addr_b, wr_addr,
  output wire [1:0] op, output wire sel, jump, pc_inc, load_ir, wr_reg);

// Copy your assignment 3 logic here and modify.
	wire or_term_1, or_term_2, alu_ins, s, w, u, ld_ins;
	wire ld_ins_, fo, eo, ef, wr_reg1, wr_reg2, el, lo, fi;
	wire dfrl_out, dfsl_out;

	//5 input NOR gate
	or3 control_or1(cur_ins[11], cur_ins[12], cur_ins[13], or_term_1);
	or3 control_or2(cur_ins[14], cur_ins[15], or_term_1, or_term_2);
	invert not_gate(or_term_2, alu_ins);
	
	//Defining left side inputs in diagram
	invert not_1(cur_ins[14], s);
	and2 and_1(cur_ins[15], s, ld_ins);
	invert not_2(cur_ins[10], w);
	invert not_3(ld_ins, ld_ins_);	
	invert not_4(cur_ins[15], u);

	//First dfrl and AND gates until wr_reg1
	dfrl dfrl_1(clk, reset, 1'b1, fo, eo);
	and2 and_2(ld_ins_, eo, ef);
	and2 and_3(ef, alu_ins, wr_reg1);
	and3 and_4(cur_ins[14], u, ef, jump);
	and2 and_5(ld_ins, eo, el);

	//Second dfrl and sel, wr_reg2, wr_reg and ef
	and2 and_6(ld_ins, el, wr_reg2);
	or2 or_1(wr_reg1, wr_reg2, wr_reg);
	nand2 nand_1(el, ld_ins, sel);
	dfrl dfrl_2(clk, reset, 1'b1, el, lo);
	or2 or_2(ef, lo, fi);

	// dfsl and pc_inc
	dfsl dfsl_1(clk, reset, 1'b1, fi, fo);
	assign load_ir = fo;
	or2 or_3(el, fo, pc_inc);

	//Assigning write addresses for a and b
	assign rd_addr_a = {cur_ins[2], cur_ins[1], cur_ins[0]};
	assign rd_addr_b = {cur_ins[5], cur_ins[4], cur_ins[3]};
	assign wr_addr = {cur_ins[8], cur_ins[7], cur_ins[6]};
	assign op = {cur_ins[10], cur_ins[9]};

endmodule

module mproc (input wire clk, reset, input wire [15:0] d_in, output wire [6:0] addr, output wire [15:0] d_out);
  wire pc_inc, cout, cout_, sub, sel, sel_addr; wire [2:0] rd_addr_a, rd_addr_b, wr_addr; wire [1:0] op; wire [8:0] _addr;
  wire [15:0] cur_ins, d_out_a, d_out_b;

  and2 and2_0 (jump, cout, sub);
  pc pc_0 (clk, reset, pc_inc, 1'b0, sub, {8'b0, cur_ins[7:0]}, {_addr, addr});
  ir ir_0 (clk, reset, load_ir, d_in, cur_ins);
  control_logic control_logic_0 (clk, reset, cur_ins, rd_addr_a, rd_addr_b, wr_addr, op, sel, jump, pc_inc, load_ir, wr_reg);
  reg_alu reg_alu_0 (clk, reset, sel, wr_reg, op, rd_addr_a, rd_addr_b, wr_addr, d_in, d_out_a, d_out_b, cout);
  assign d_out = d_out_a;
endmodule
