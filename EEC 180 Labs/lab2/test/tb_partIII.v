module tb_partIII;
    parameter K = 8;

	integer test_a, test_b;
	reg test_carry_in;
	wire [K - 1:0] test_sum;
	wire test_carry_out;
    wire test_overflow;
	
	partIII #(.K(K)) UUT
	(
		.a(test_a),
		.b(test_b),
		.carry_in(test_carry_in),
		.sum(test_sum),
		.carry_out(test_carry_out),
        .overflow_indicator(test_overflow)
	);
	
   initial begin
		test_carry_in = 0;
	
		for (test_a = 0; test_a < 2 ** K; test_a = test_a + 1)
		begin
			for (test_b = 0; test_b < 2 ** K; test_b = test_b + 1)
			begin
			#10
				if ({test_carry_out, test_sum} != (test_a + test_b + test_carry_in))
					$display("ERROR: a=%b b=%b carry_in=%b sum=%b carry_out=%b", test_a, test_b, test_carry_in, test_sum, test_carry_out);
			end
		end
		#10 $finish;
	end
endmodule
