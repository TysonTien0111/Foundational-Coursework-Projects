module generic_full_adder
#(parameter K = 8)
(
	input [K - 1:0] a, b,
	input carry_in,
	output [K - 1:0] sum,
	output carry_out,
	output overflow_indicator
);

	wire [K:0] carry_wire;
	assign carry_wire [0] = carry_in;
	
	genvar i;

	generate
		for (i = 0; i < K; i = i + 1)
		begin : generic_full_adder
			full_adder full_adder_i
			(
				.a(a[i]),
				.b(b[i]),
				.carry_in(carry_wire[i]),
				.sum(sum[i]),
				.carry_out(carry_wire[i + 1])
			); 
		end
	endgenerate
	
	assign carry_out = carry_wire[K];
	assign overflow_indicator = carry_out ^ carry_wire[7]; //Overflow Bit
endmodule
