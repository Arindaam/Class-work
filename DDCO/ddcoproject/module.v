module add1(input wire i1,i2,cin, output wire [1:0]o);
    assign o[0] = i1^i2^cin;
    assign o[1] = ((i1 ^ i2) & cin) | (i1 & i2);
endmodule

module add2(input wire [1:0]i1,i2, input wire cin, output wire [2:0]o);
    wire [1:0]t1,t2;
    add1 f1(i1[0],i2[0],cin,t1);
    add1 f2(i1[1],i2[1],t1[1],t2);
    assign o[2:1] = t2;
    assign o[0] = t1[0];
endmodule

module add3(input wire [2:0]i1,i2, output wire [3:0]o);
    wire [2:0]t1;
    wire [1:0]t2;
    add2 f21(i1[1:0],i2[1:0],1'b0,t1);
    add1 f22(i1[2],i2[2],t1[2],t2);
    assign o[3:2] = t2;
    assign o[1:0] = t1;
endmodule

module add4(input wire [3:0]i1, input wire [1:0]i2, output wire[4:0]o);
    wire [2:0]t1,t2;
    add2 f31(i1[1:0],i2,1'b0,t1);
    add2 f32(i1[3:2],{1'b0,1'b0},t1[2],t2);
    assign o[4:2] = t2;
    assign o[1:0] = t1[1:0];
endmodule

module count_ones(input [15:0]i,output wire [4:0]o);

    //Level 1
    wire [1:0] s1,s2,s3,s4,s5;
    add1 a1(i[0],i[1],i[2],s1);
    add1 a2(i[3],i[4],i[5],s2);
    add1 a3(i[6],i[7],i[8],s3);
    add1 a4(i[9],i[10],i[11],s4);
    add1 a5(i[12],i[13],i[14],s5);

    //Level 2
    wire [2:0] s6,s7;
    add2 a6(s1,s2,1'b0,s6);
    add2 a7(s3,s4,i[15],s7);

    //Level 3
    wire [3:0] s8;
    add3 a8(s6,s7,s8);
    add4 a9(s8,s5,o);
endmodule