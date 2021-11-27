.data
	word1 : .asciiz "hello \n this is me \n"
	word2 : .word 10

.text
	main :
		jal displaymsg
		

	# tell the system that program is done;	
	li $v0,10
	syscall
	
	displaymsg:
		li $v0,4
		la $a0,word1
		syscall
		
		jr $ra
	