    .text
    .globl main

main:
    # la (it will load the address)
    # lw (it will load the word at that address) 
    la $t0 num1
    li $t1 0
    lw $t2 num2
    print_loop:
        bge $t1 $t2 endloop
        
        li $v0 1
        lw $a0 0($t0)		# $t0 = $t1 $a0 $t3
        syscall
        
        addi $t0 $t0 4
        addi $t1 $t1 1
        j print_loop
    endloop:
        li $v0 10
        syscall

.data
num1: .word 2, 1, 3, 2, 4
num2: .word 5