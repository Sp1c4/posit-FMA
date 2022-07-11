module SignextSigned8x8(input wire[35:0]  gen,
                      input wire[3:0]   sign,
                      output wire[11:0] pp00,pp03,
                      output wire[12:0] pp01,pp02);

    wire[3:0] e,ne;

    assign e  = ~{gen[35],gen[26],gen[17],gen[8]};
    assign ne = ~e;

    assign pp00 = {e[0],ne[0],ne[0],gen[8:0]};
    assign pp01 = {1'b1,e[1],gen[17:9],1'b0,sign[0]};
    assign pp02 = {1'b1,e[2],gen[26:18],1'b0,sign[1]};
    assign pp03 = {e[3],gen[35:27],1'b0,sign[2]};

endmodule