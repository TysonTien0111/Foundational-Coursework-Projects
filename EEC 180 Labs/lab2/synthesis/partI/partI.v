module partI
(
	input [7:0] a, b,
	input carry_in,
	output [7:0] sum,
	output carry_out,
	output overflow_indicator //Overflow Bit
);

	generic_full_adder eight_bit_full_adder
	(
		.a(a),
		.b(b),
		.carry_in(carry_in),
		.sum(sum),
		.carry_out(carry_out),
        .overflow_indicator(overflow_indicator)
	);
endmodule
