    .text
    .globl main

main:

    li $v0,4
    la $a0,enter
    syscall

    li $v0,5
    syscall

    move $t0,$v0    

    li $v0,4
    la $a0,enter1
    syscall

    li $v0,5
    syscall

    move $t1,$v0

    bgt $t0,$t1,greaterto
    move $t2,$t1

    li $v0,4
    la $a0,result
    syscall

    li $v0, 1
    move $a0,$t2
    syscall

    li $v0,10
    syscall

greaterto:
    move $t2,$t0

    li $v0,4
    la $a0,result
    syscall

    li $v0, 1
    move $a0,$t2
    syscall

    li $v0,10
    syscall    

.data
enter:.asciiz "enter first number: "
enter1: .asciiz "enter second number: "
result: .asciiz "max is : "
