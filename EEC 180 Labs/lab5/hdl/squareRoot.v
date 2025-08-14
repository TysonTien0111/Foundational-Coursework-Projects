module squareRoot
(
    input clk, rstn, st,
    input [7:0] n, 
    output reg done,
    output reg [3:0] sqrt
);

    reg [7:0] minuendReg;
    reg [4:0] subtrahendReg;
    reg [3:0] sqrtCounterReg;
    reg [2:0] currentState;
    reg [2:0] nextState;
    reg su, load, inc;

    localparam initialState = 3'b001;
    localparam subtractState = 3'b010;
    localparam doneState = 3'b100;

    wire borrow;
    wire [7:0] difference;

    always @(posedge clk or negedge rstn)
    begin
        if (~rstn)
        begin
            currentState <= initialState;
        end else
        begin
            currentState <= nextState;
        end
    end

    always @(*)
    begin
        nextState = currentState;

        done = 1'b0;
        su = 1'b0;
        load = 1'b0;
        inc = 1'b0;

        case (currentState)
            initialState:
            begin
                if (st)
                begin
                    load = 1'b1;
                    nextState = subtractState;
                end
            end

            subtractState:
            begin
                if (~borrow)
                begin
                    su = 1'b1;
                    inc = 1'b1;
                    nextState = subtractState;
                end else
                begin
                    nextState = doneState;
                end
            end

            doneState:
            begin
                if (~st)
                begin
                    nextState = initialState;
                end else
                begin
                    done = 1'b1;
                end
            end

            default:
            begin
                nextState = initialState;
            end
        endcase
    end

    assign difference = minuendReg - subtrahendReg;
    assign borrow = (subtrahendReg > minuendReg);

    always @(*)
    begin
        sqrt = sqrtCounterReg;
    end

    always @(posedge clk or negedge rstn)
    begin
        if (~rstn)
        begin
            minuendReg <= 8'b0000_0000;
            subtrahendReg <= 5'b0_0000;
            sqrtCounterReg <= 4'b0000;
        end else
        begin
            if (load)
            begin
                minuendReg <= n;
                subtrahendReg <= 5'b0_0001;
                sqrtCounterReg <= 4'b0000;
            end else
            begin
                if (su)
                begin
                    minuendReg <= difference;
                end
                
                if (inc)
                begin
                    subtrahendReg <= subtrahendReg + 2'b10;
                    sqrtCounterReg <= sqrtCounterReg + 1'b1;
                end
            end
        end
    end
endmodule
