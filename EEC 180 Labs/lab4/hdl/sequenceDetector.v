module initialState
(
    output reg q1;
    input d1;
    input clk;
);
endmodule

module firstCorrectSeq
(
    output reg q2;
    input clk;
    input a;
    input b;
    input q1;
);

    reg d2;

    always@
    (
        posedge clk
    )
    begin
        q2 <= d2; 
    end

    always@
    (
        a or b or q1 or q2
    )
    begin
        d2 = (a & ~b & q1) | (a & ~b & q2);
    end
endmodule

module firstWaitingPeriod
(
    output reg q3;
    input clk;
    input a;
    input b;
    input q2;
);

    reg d3;

    always@
    (
        posedge clk
    )
    begin
        q3 <= d3;
    end

    always@
    (
        a or b or q2 or q3
    )
    begin
        d3 = (~a & ~b & q2) | (~a & ~b & q3);
    end
endmodule

module secondCorrectSeq
(
    output reg q4;
    input clk;
    input a;
    input b;
    input q3;
);

    reg d4;

    always@
    (
        posedge clk
    )
    begin
        q4 <= d4;
    end

    always@
    (
        a or b or q3 or q4
    )
    begin
        d4 = (~a & b & q3) | (~a & b & q4);
    end
endmodule

module secondWaitingPeriod
(
    output reg q5;
    input clk;
    input a;
    input b;
    input q4;
);

    reg d5;

    always@
    (
        posedge clk
    )
    begin
        q5 <= d5;
    end

    always@
    (
        a or b or q4 or q5 
    )
    begin
        d5 = (~a & ~b & q4) | (~a & ~b & q5);
    end
endmodule

module
(
    output reg q6;
    input clk;
    input a;
    input b;
    input q5;
);

    reg d6;

    always@
    (
        posedge clk
    )
    begin
        q6 <= d6;
    end

    always@
    (
        a or b or q5 or q6
    )
    begin
        d6 = () | ();
    end
endmodule
