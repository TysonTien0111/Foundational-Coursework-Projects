module full_adder
(
	input a, b, carry_in,
	output sum, carry_out
);
	
	assign sum = a ^ b ^ carry_in;
	assign carry_out = (a & b) | (a & carry_in) | (b & carry_in);
endmodule

module full_adder_test_bench;
	wire sum, carry_out;
	reg [2:0] test;
	
	full_adder FA (test[2], test[1], test[0], sum, carry_out);
	
	initial begin
		for (test = 0; test < 8; test = test + 1)
		begin
		#10;
			if ({carry_out, sum} != (test[2] + test[1] + test[0]) )
				$display("ERROR: a=%b b=%b carry_in=%b sum=%b cout=%b", test[2], test[1], test[0], sum, carry_out);
			end
		#10 $finish;
		end
endmodule
