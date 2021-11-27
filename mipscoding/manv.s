    .data
numChars: .word	20
input:	  .space 20
prompt:   .asciiz "Please enter an integer : "  
inputs:   .asciiz "Enter length of input string : "
    .text
main:
	la $a0, inputs
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	add $t2, $zero, $v0

	la $a0, prompt
	li $v0, 4
	syscall
	la $a0, input
	la $a1, numChars
	lw $a1, 0($a1)
	li $v0, 8
	syscall

	add $t0, $zero, $a0
	add $t1, $zero, $zero
	add $t5, $zero, $a0

For1:
	beq $t2, $t1, temp
	add $t3, $zero, $t1
	add $t3, $t3, $t0 
	lb $a0, 0($t3)
	addi $a2, $a0, -48
	add $t4, $zero, $zero 
	bgt $t4, $a2, exit1
	addi $t4, $zero, 9
	bgt $a2, $t4, exit1
	addi $t1, $t1, 1
	bgt $t2, $t1, For1

temp:
	add $t0, $zero, $t5
	add $t1, $zero, $zero

For:
	beq $t2, $t1, exit2
	add $t3, $zero, $t1
	add $t3, $t3, $t0 
	lb $a0, 0($t3)
	addi $a2, $a0, -48
	add $a0, $zero, $a2
	li $v0, 1
	syscall
	addi $t1, $t1, 1
	bgt $t2, $t1, For

exit2:
	li $v0, 10
	syscall

exit1:
	add $a0, $zero, $zero
	li $v0, 1
	syscall
	li $v0, 10
	syscall