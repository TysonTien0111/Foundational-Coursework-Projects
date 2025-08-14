module hex_7seg_decoder(
	bin,
	segs
);


input wire	[3:0] bin;
output wire	[7:0] segs;

wire	[3:0] S;
wire	S0N;
wire	S1N;
wire	S2N;
wire	S3N;
wire	X0;
wire	X1;
wire	X2;
wire	X3;
wire	X4;
wire	X5;
wire	X6;
wire	X7;
wire	SYNTHESIZED_WIRE_0;
wire	SYNTHESIZED_WIRE_1;
wire	SYNTHESIZED_WIRE_2;
wire	SYNTHESIZED_WIRE_3;
wire	SYNTHESIZED_WIRE_4;
wire	SYNTHESIZED_WIRE_5;
wire	SYNTHESIZED_WIRE_6;
wire	SYNTHESIZED_WIRE_7;
wire	SYNTHESIZED_WIRE_8;
wire	SYNTHESIZED_WIRE_9;
wire	SYNTHESIZED_WIRE_10;
wire	SYNTHESIZED_WIRE_11;
wire	SYNTHESIZED_WIRE_12;
wire	SYNTHESIZED_WIRE_13;
wire	SYNTHESIZED_WIRE_14;
wire	SYNTHESIZED_WIRE_15;
wire	SYNTHESIZED_WIRE_16;
wire	SYNTHESIZED_WIRE_17;
wire	SYNTHESIZED_WIRE_18;
wire	SYNTHESIZED_WIRE_19;
wire	SYNTHESIZED_WIRE_20;
wire	SYNTHESIZED_WIRE_21;
wire	SYNTHESIZED_WIRE_22;




assign S0N = ~S[0];
assign S1N = ~S[1];
assign S2N = ~S[2];
assign S3N = ~S[3];

assign	X1 = SYNTHESIZED_WIRE_0 | SYNTHESIZED_WIRE_1 | SYNTHESIZED_WIRE_2 | SYNTHESIZED_WIRE_3;

assign	SYNTHESIZED_WIRE_1 = S3N & S[2] & S[1] & S0N;

assign	SYNTHESIZED_WIRE_2 = S3N & S[2] & S1N & S[0];

assign	X2 = SYNTHESIZED_WIRE_4 | SYNTHESIZED_WIRE_5 | SYNTHESIZED_WIRE_6;

assign	SYNTHESIZED_WIRE_6 = S[3] & S[2] & S[1];

assign	SYNTHESIZED_WIRE_4 = S[3] & S[2] & S0N;

assign	SYNTHESIZED_WIRE_5 = S3N & S2N & S[1] & S0N;

assign	X3 = SYNTHESIZED_WIRE_7 | SYNTHESIZED_WIRE_8 | SYNTHESIZED_WIRE_9;

assign	SYNTHESIZED_WIRE_9 = S[2] & S[1] & S[0];

assign	SYNTHESIZED_WIRE_7 = S3N & S[2] & S1N & S0N;

assign	SYNTHESIZED_WIRE_8 = S3N & S2N & S1N & S[0];

assign	SYNTHESIZED_WIRE_0 = S[3] & S[1] & S[0];

assign	X4 = SYNTHESIZED_WIRE_10 | SYNTHESIZED_WIRE_11 | SYNTHESIZED_WIRE_12;

assign	SYNTHESIZED_WIRE_12 = S3N & S[0];

assign	SYNTHESIZED_WIRE_10 = S2N & S1N & S[0];

assign	SYNTHESIZED_WIRE_11 = S3N & S[2] & S1N;

assign	X5 = SYNTHESIZED_WIRE_13 | SYNTHESIZED_WIRE_14 | SYNTHESIZED_WIRE_15 | SYNTHESIZED_WIRE_16;

assign	SYNTHESIZED_WIRE_13 = S2N & S[1] & S0N;

assign	SYNTHESIZED_WIRE_16 = S[3] & S[2] & S1N;

assign	SYNTHESIZED_WIRE_14 = S3N & S[1] & S[0];

assign	SYNTHESIZED_WIRE_15 = S3N & S2N & S[0];

assign	X6 = SYNTHESIZED_WIRE_17 | SYNTHESIZED_WIRE_18;

assign	SYNTHESIZED_WIRE_3 = S[3] & S[2] & S1N & S0N;

assign	SYNTHESIZED_WIRE_18 = S3N & S2N & S1N;

assign	SYNTHESIZED_WIRE_17 = S3N & S[2] & S[1] & S[0];

assign	SYNTHESIZED_WIRE_19 = S[2] & S1N & S0N;

assign	SYNTHESIZED_WIRE_22 = S[3] & S[2] & S1N;

assign	SYNTHESIZED_WIRE_20 = S[3] & S2N & S[1] & S[0];

assign	SYNTHESIZED_WIRE_21 = S3N & S2N & S1N & S[0];

assign	X0 = SYNTHESIZED_WIRE_19 | SYNTHESIZED_WIRE_20 | SYNTHESIZED_WIRE_21 | SYNTHESIZED_WIRE_22;


assign	segs[7] = X7;
assign	segs[6] = X6;
assign	segs[5] = X5;
assign	segs[4] = X4;
assign	segs[3] = X3;
assign	segs[2] = X2;
assign	segs[1] = X1;
assign	segs[0] = X0;
assign	S = bin;
assign	X7 = 1;

endmodule
