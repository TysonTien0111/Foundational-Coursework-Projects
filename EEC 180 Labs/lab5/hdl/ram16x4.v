module ram16x4
(
    input[3:0] addr,
    input[3:0] mdi,
    input mwr,
    input clk,

    output reg[3:0] mdo
);

    (* ramstyle = "M9K", ram_init_file = "ram_init_file.mif" *) reg [3:0] memory [15:0];

    always @ (posedge clk) begin
        if (mwr) memory[addr] <= mdi; //write mem
        mdo <= memory[addr]; // read mem
    end
endmodule
