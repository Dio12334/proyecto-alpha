addi $s2, $s0, 5
addi $s3, $s0, 12
addi $s7, $s3, -9
or $s4, $s7, $s2
and $s5, $s3, $s4
add $s5, $s5, $s4
beq $s5, $s7, here
slt $s4, $s3, $s4
beq $s4, $s0, there
there: slt $s4, $s7, $s2
	add $s7, $s4, $s5
	sub $s7, $s7, $s2
	sw $s7, 68($s3)
	lw $s3, 80($s0)
	j end
end: sw $s7, 84($s0)

here: