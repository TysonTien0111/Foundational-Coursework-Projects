module tb_partI;
    reg[1:0] correct_output;
    reg correct_valid;

    reg [3:0] test_input; 
    wire [2:0] test_output;

    partI UUT(.SW(test_input), .LEDR(test_output));
    
    initial begin
        test_input = 4'b0000;
        correct_output = 2'b00;
        correct_valid = 1'b0;

        repeat(16) begin
            #10
        casez(test_input)
            4'b0000: begin
                if(test_output != {correct_output[1], correct_output[0], correct_valid}) begin
                    $display("ERROR: I3=%b I2=%b I1=%b I0=%b o1=%b o0=%b v=%b", test_input[3], test_input[2], test_input[1],
                            test_input[0], test_output[2], test_output[1], test_output[0]);
                end

                correct_valid = 1'b1;
            end

            4'b0001: begin
                if(test_output != {correct_output[1], correct_output[0], correct_valid}) begin
                    $display("ERROR: I3=%b I2=%b I1=%b I0=%b o1=%b o0=%b v=%b", test_input[3], test_input[2], test_input[1],
                            test_input[0], test_output[2], test_output[1], test_output[0]);
                end

                correct_output = 2'b01;
            end

            4'b001?: begin
                if(test_output != {correct_output[1], correct_output[0], correct_valid}) begin
                    $display("ERROR: I3=%b I2=%b I1=%b I0=%b o1=%b o0=%b v=%b", test_input[3], test_input[2], test_input[1],
                            test_input[0], test_output[2], test_output[1], test_output[0]);
                end

                if(test_input == 4'b0011) begin
                    correct_output = 2'b10;    
                end
            end

            4'b01??: begin
                if(test_output != {correct_output[1], correct_output[0], correct_valid}) begin
                    $display("ERROR: I3=%b I2=%b I1=%b I0=%b o1=%b o0=%b v=%b", test_input[3], test_input[2], test_input[1],
                            test_input[0], test_output[2], test_output[1], test_output[0]);
                end
                
                if(test_input == 4'b0111)
                begin
                    correct_output = 2'b11;
                end
            end

            4'b1???: begin
                if(test_output != {correct_output[1], correct_output[0], correct_valid}) begin
                    $display("ERROR: I3=%b I2=%b I1=%b I0=%b o1=%b o0=%b v=%b", test_input[3], test_input[2], test_input[1],
                            test_input[0], test_output[2], test_output[1], test_output[0]);
                end
            end
        endcase
            test_input = test_input + 4'b0001;
        end
    end
endmodule
