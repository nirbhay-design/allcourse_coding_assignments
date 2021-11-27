    .text
    .globl main


main:

    li $v0,4
    la $a0,promptt
    syscall
    
    li $v0,5
    syscall
    
    add $t1,$zero,$v0

    li $v0,4
    la $a0,prompt
    syscall

    li $v0,8
    la $a0,mystr
    li $a1,100
    syscall

    #li $v0,4
    #la $a0,promptt
    #syscall
    li $t0,0
    addi $t5,$t1,-1
    li $t7,0
    loop:
    	bge $t0,$t1,exit
    	lb $t2,mystr($t0)
    	addi $t3,$t2,-48
    	li $t4,9
    	bgt $t3,$t4,outzero
    	blt $t3,$zero,outzero
    	
    	li $t6,1
    	move $t8,$t5
    	innerloop:
    	    ble $t8,$zero,exitinner
    	    addi $t9,$zero,10
    	    mul $t6,$t6,$t9
    	    addi $t8,$t8,-1
    	    j innerloop
    	
    	exitinner:
    	    addi $t5,$t5,-1
    	    mul $t3,$t3,$t6
    	    add $t7,$t3,$t7
    	    addi $t0,$t0,1
    	    j loop
    	
    	
    outzero:
    	move $t7,$zero
    	 
    	li $v0,1
    	move $a0,$t7
    	syscall
    	
    	li $v0,10
    	syscall
    	
    	   	   	
    exit:
        li $v0,1
    	move $a0,$t7
    	syscall
    	
    	li $v0,10
    	syscall
    		

    #li $v0,11
    #lb $a0,mystr($t0)
    #syscall

    li $v0,10
    syscall

.data
myzero:.byte '0'
mystr:.space 8
prompt:.asciiz "enter the string: "
promptt:.asciiz "enter length of string: "
