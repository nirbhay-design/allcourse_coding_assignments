    .text
    .globl main

main:
    la $t0 num2

    lw $t2 ($t0) 
    
    li $v0 1
    move $a0 $t2 
    syscall
    lw $t1 num2

    li $v0 10
    syscall
.data
num1: .space 16
num2: .word 4
promptt: .asciiz "enter the 5 numbers: "
