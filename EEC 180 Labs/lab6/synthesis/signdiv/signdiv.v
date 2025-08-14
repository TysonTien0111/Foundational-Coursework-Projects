module signdiv
(
    CLK,
    St,
    Dbus,
    Quotient,
    Remainder,
    Rdy,
    rst
);
    output [15:0] Quotient;
    output [15:0] Remainder;
    output reg Rdy;
    input St;
    input [15:0] Dbus;
    input CLK;
    input rst;

    wire [31:0] fullDividendReg;
    wire [3:0] iterationCountWire;
    wire divisionValid;

    reg [31:0] absoluteDividendReg;
    reg [31:0] finalResultReg;
    reg [15:0] lowerDividendReg;
    reg [15:0] upperDividendReg;
    reg [15:0] divisorReg;
    reg [15:0] absoluteDivisorReg;
    reg [8:0] currentState;
    reg [8:0] nextState;
    reg [3:0] iterationCountReg;
    reg shift;
    reg subtract;
    reg loadQuotient;
    reg increment;
    reg loadUpperDividend;
    reg loadLowerDividend;
    reg loadDivisor;
    reg resetCounter;
    reg negateDividend;
    reg negateDivisor;
    reg storeDividendSign;
    reg storeDivisorSign;
    reg quotientBit;
    reg dividendOriginalSign;
    reg divisorOriginalSign;

    assign iterationCountWire = iterationCountReg;
    assign fullDividendReg = {upperDividendReg, lowerDividendReg};
    assign divisionValid = (finalResultReg [31:16] >= absoluteDivisorReg) ? 1'b1 : 1'b0;
    assign Quotient = (Rdy) ? ((dividendOriginalSign ^ divisorOriginalSign) ? (~finalResultReg [15:0] + 1'b1) : (finalResultReg [15:0])) : 16'b0;
    assign Remainder = (Rdy) ? ((dividendOriginalSign) ? (~finalResultReg[31:16] + 1'b1): (finalResultReg [31:16])) : 16'b0;

    localparam idleState = 9'b000000001;
    localparam loadLowerDividendState = 9'b000000010;
    localparam loadUpperDividendState = 9'b000000100;
    localparam loadDivisorState = 9'b000001000;
    localparam preProcessingState = 9'b000010000;
    localparam shiftState = 9'b000100000;
    localparam compareState = 9'b001000000;
    localparam quotientAndSubtractState = 9'b010000000;
    localparam doneState = 9'b100000000;

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            currentState <= idleState;
        end else
        begin
            currentState <= nextState;
        end
    end

    always @(*)
    begin
        nextState = currentState;
        Rdy = 1'b0;
        shift = 1'b0;
        subtract = 1'b0;
        loadQuotient = 1'b0;
        increment = 1'b0;
        loadUpperDividend = 1'b0;
        loadLowerDividend = 1'b0;
        loadDivisor = 1'b0;
        resetCounter = 1'b0;
        negateDividend = 1'b0;
        negateDivisor = 1'b0;
        storeDividendSign = 1'b0;
        storeDivisorSign = 1'b0;
        quotientBit = 1'b0;

        case (currentState)
            idleState:
            begin
                if (St)
                begin
                    nextState = loadLowerDividendState;
                    loadLowerDividend = 1'b1;
                end
            end
            
            loadLowerDividendState:
            begin
                if (St)
                begin
                    nextState = loadUpperDividendState;
                    loadUpperDividend = 1'b1;
                end else
                begin
                    nextState = idleState;
                end
            end

            loadUpperDividendState:
            begin
                if (St)
                begin
                    nextState = loadDivisorState;
                    loadDivisor = 1'b1;
                end else
                begin
                    nextState = idleState;
                end
            end

            loadDivisorState:
            begin
                if (~St)
                begin
                    nextState = preProcessingState;
                end
            end

            preProcessingState:
            begin
                resetCounter = 1'b1;
                storeDividendSign = 1'b1;
                storeDivisorSign = 1'b1;
                negateDivisor = 1'b1;
                negateDividend = 1'b1;
                nextState = shiftState;
            end

            shiftState:
            begin
                shift = 1'b1;
                nextState = compareState;
            end

            compareState:
            begin
                nextState = quotientAndSubtractState;
            end

            quotientAndSubtractState:
            begin
                if (divisionValid)
                begin
                    subtract = 1'b1;
                    quotientBit = 1'b1;
                end else
                begin
                    quotientBit = 1'b0;
                end
                loadQuotient = 1'b1;

                increment = 1'b1;
                if (iterationCountWire == 4'b1111)
                begin
                    nextState = doneState;
                end else
                begin
                    nextState = shiftState;
                end
            end

            doneState:
            begin
                Rdy = 1'b1;
                if (St)
                begin
                    nextState = loadLowerDividendState;
                    loadLowerDividend = 1'b1;
                end 
            end
        default:
        begin
            nextState = idleState;
        end
        endcase
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            lowerDividendReg <= 16'b0;
        end else
        begin
            if (loadLowerDividend)
            begin
                lowerDividendReg <= Dbus;
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            upperDividendReg <= 16'b0;
        end else
        begin
            if (loadUpperDividend)
            begin
                upperDividendReg <= Dbus;
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            divisorReg [15:0] <= 16'b0;
        end else
        begin
            if (loadDivisor)
            begin
                divisorReg [15:0] <= Dbus [15:0];
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            dividendOriginalSign <= 1'b0;
        end else
        begin
            if (storeDividendSign)
            begin
                dividendOriginalSign <= upperDividendReg [15];
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            divisorOriginalSign <= 1'b0;
        end else
        begin
            if (storeDivisorSign)
            begin
                divisorOriginalSign <= divisorReg[15];
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            iterationCountReg <= 4'b0;
        end else if (resetCounter)
        begin
            iterationCountReg <= 4'b0;
        end else if (increment)
        begin
            iterationCountReg <= iterationCountReg + 4'b0001;
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            absoluteDivisorReg <= 16'b0;
        end else
        begin
            if (negateDivisor)
            begin
                if (divisorReg[15] == 1'b1)
                begin
                    absoluteDivisorReg <= ~divisorReg + 1'b1;
                end else
                begin
                    absoluteDivisorReg <= divisorReg;
                end
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            absoluteDividendReg <= 32'b0;
        end else
        begin
            if (negateDividend)
            begin
                if (fullDividendReg [31] == 1'b1)
                begin
                    absoluteDividendReg <= ~(fullDividendReg) + 1'b1;
                end else
                begin
                    absoluteDividendReg <= fullDividendReg;
                end
            end
        end
    end

    always @(posedge CLK or posedge rst)
    begin
        if (rst)
        begin
            finalResultReg <= 32'b0;
        end else
        begin
            if (resetCounter)
            begin
                if (fullDividendReg[31] == 1'b1)
                begin
                    finalResultReg <= ~fullDividendReg + 1'b1;
                end else
                begin
                    finalResultReg <= fullDividendReg;
                end
            end else if (shift)
            begin
                finalResultReg <= finalResultReg << 1;
            end else if (loadQuotient)
            begin
                if (subtract)
                begin
                    finalResultReg <= {(finalResultReg [31:16] - absoluteDivisorReg), finalResultReg [15:1], quotientBit};
                end else
                begin
                    finalResultReg <= {finalResultReg[31:1], quotientBit};
                end
            end
        end
    end
endmodule
