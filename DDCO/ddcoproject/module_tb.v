module tb;

    // Inputs
    reg [15:0] i;

    // Outputs
    wire [4:0] o;

    initial begin $dumpfile("output.vcd"); $dumpvars(0,tb); end

    // Instantiate the Unit Under Test (UUT)
    count_ones uut (
        .i(i), 
        .o(o)
    );

    initial begin
        i = 16'hFFFF;   #100;
        i = 16'hF56F;   #100;
        i = 16'h3FFF;   #100;
        i = 16'h0001;   #100;
        i = 16'hF10F;   #100;
        i = 16'h7822;   #100;
        i = 16'h7ABC;   #100;   
    end
      
endmodule
