module ejercicio_2_c(in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8, in_9, in_10, in_11, in_12, in_13, in_14, in_15, in_16, sel_1, sel_2, sel_3, sel_4, out_1);

        input [15:0] in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8, in_9, in_10, in_11, in_12, in_13, in_14, in_15, in_16;
        input sel_1, sel_2, sel_3, sel_4;
        wire [15:0] wi_1, wi_2;

        output [15:0] out_1;

        ejercicio_2_b a1_0(in_1, in_2, in_3, in_4, in_5, in_6, in_7, in_8, sel_1, sel_2, sel_3, wi_1);
        ejercicio_2_b a1_1(in_9, in_10, in_11, in_12, in_13, in_14, in_15, in_16, sel_1, sel_2, sel_3, wi_2);

        ejercicio_1 a2_0(wi_1, wi_2, sel_4, out_1);

endmodule
