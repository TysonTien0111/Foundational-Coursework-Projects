module multiplier_4x4
(
    input [3:0] a, b,
    output [7:0] p
);

wire g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15, g16; // And Gates
wire sum_full_adder_2, sum_full_adder_3, sum_full_adder_4, sum_full_adder_6, sum_full_adder_7, sum_full_adder_8; // Full Adders
wire carry_out_1, carry_out_2, carry_out_3, carry_out_4, carry_out_5, carry_out_6, carry_out_7, carry_out_8, carry_out_9, carry_out_10, carry_out_11; // Carry Outs

// First Level -- And Gates

    and(p[0], a[0], b[0]);
    and(g2, a[1], b[0]);
    and(g3, a[2], b[0]);
    and(g4, a[3], b[0]);

// Second Level -- And Gates

    and(g5, a[0], b[1]);
    and(g6, a[1], b[1]);
    and(g7, a[2], b[1]);
    and(g8, a[3], b[1]);

// Third Level -- Full Adders

    full_adder(g2, g5, 0, p[1], carry_out_1);
    full_adder(g3, g6, carry_out_1, sum_full_adder_2, carry_out_2);
    full_adder(g4, g7, carry_out_2, sum_full_adder_3, carry_out_3);
    full_adder(0, g8, carry_out_3, sum_full_adder_4, carry_out_4);

// Fourth Level -- And Gates

    and(g9, a[0], b[2]);
    and(g10, a[1], b[2]);
    and(g11, a[2], b[2]);
    and(g12, a[3], b[2]);

// Fifth Level -- Full Adders
    
    full_adder(sum_full_adder_2, g9, 0, p[2], carry_out_5);
    full_adder(sum_full_adder_3, g10, carry_out_5, sum_full_adder_6, carry_out_6);
    full_adder(sum_full_adder_4, g11, carry_out_6, sum_full_adder_7, carry_out_7);
    full_adder(carry_out_4, g12, carry_out_7, sum_full_adder_8, carry_out_8);

// Sixth Level -- And Gates
    
    and(g13, a[0], b[3]);
    and(g14, a[1], b[3]);
    and(g15, a[2], b[3]);
    and(g16, a[3], b[3]);

// Seventh Level -- Full Adders

    full_adder(sum_full_adder_6, g13, 0, p[3], carry_out_9);
    full_adder(sum_full_adder_7, g14, carry_out_9, p[4], carry_out_10);
    full_adder(sum_full_adder_8, g15, carry_out_10, p[5], carry_out_11);
    full_adder(carry_out_8, g16, carry_out_11, p[6], p[7]);
	 
endmodule
