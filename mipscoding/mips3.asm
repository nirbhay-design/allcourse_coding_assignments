.data

	word : .asciiz "enter first number: "
	word1: .asciiz "enter second number: "
	word2 : .asciiz "the product is : "

.text
	li $v0 ,4
	la $a0 , word
	syscall
	
	li $v0,5
	syscall
	
	move $a1, $v0
	#move $v0 , $zero
	
	li $v0 ,4
	la $a0 , word1
	syscall
	
	li $v0,5
	syscall
	
	move $a2, $v0
	
	jal product
	
	li $v0,4
	la $a0,word2
	syscall
	
	li $v0,1
	move $a0 , $t0
	syscall
	
	li $v0,10
	syscall
	product:
		mul $t0,$a1,$a2
		jr $ra 
		