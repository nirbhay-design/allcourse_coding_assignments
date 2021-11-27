    .text
    .globl main

main:
    li $t0,25
    li $t1,10
    add $t2 ,$t0,$t1

    li $v0,4
    la $a0,mystring
    syscall
    
    li $v0,5
    syscall

    b19cse114_q.s
    move $t0 , $v0

    jal myfile

    li $v0,10
    syscall
    

myfile:
    li $t3,100
    addi $t4 , $t3,100

    jr $ra

.data
mystring: .asciiz "Hello Nirbhay sharma\n"
