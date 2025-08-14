module pe42
(
    input [3:0] I,
    output o1, o0, v
);

// o1 Logic

    or (o1, I[3], I[2]);

// o0 Logic

    not(g1, I[2]);
    and(g2, I[1], g1);
    or(o0, I[3], g2);

// v Logic
    or(v, I[3], I[2], I[1], I[0]);

endmodule
