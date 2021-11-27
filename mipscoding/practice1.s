    .text
    .globl main

main:
    la $t3 num1
    li $v0 4
    la $a0 promptt
    syscall


    li $v0 5
    syscall

    add $t0 $zero $v0
    sw $t0 0($t3)

    li $v0 5
    syscall

    add $t0 $zero $v0
    sw $t0 4($t3)

    li $v0 5
    syscall

    add $t0 $zero $v0
    sw $t0 8($t3)

    li $v0 5
    syscall

    add $t0 $zero $v0
    sw $t0 12($t3)

    add $t2 $zero $zero
    addi $t4 $zero 4
    print_arr:
        bge $t2 $t4 exit
        lw $t6 ($t3)

        li $v0 1
        move $a0 $t6
        syscall

        addi $t2 $t2 1
        addi $t3 $t3 4    
        j print_arr
    exit:
        li $v0 10
        syscall
    # add $t2 $zero $zero
    # addi $t4 $zero 16
    # print_arr:
    #     bge $t2 $t4 exit
    #     lw $t6 num1($t2)

    #     li $v0 1
    #     move $a0 $t6
    #     syscall

    #     addi $t2 $t2 4    
    #     j print_arr
    # exit:
    #     li $v0 10
    #     syscall

.data
num1: .space 16
num2: .word 4
promptt: .asciiz "enter the 5 numbers: "
