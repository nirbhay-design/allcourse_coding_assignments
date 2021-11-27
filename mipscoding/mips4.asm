.data
	
	msg : .asciiz "Impelementing the basic if-else\n"
	msg1: .asciiz "greater is "
	msg2 : .asciiz "lesser is "

.text

	main:
		li $v0,4
		la $a0,msg
		syscall
		
		addi $t0,$zero,15
		addi $t1,$zero,10
		
		bgt $t0 ,$t1 , greater
		
		
		li $v0,10
		syscall
		
		greater:
			li $v0,4
			la $a0,msg1
			syscall
			
			li $v0,1
			move $a0,$t0
			syscall
			
			jr $ra
			
		