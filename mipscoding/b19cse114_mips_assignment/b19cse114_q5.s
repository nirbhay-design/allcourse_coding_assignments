    .text
    .globl main

main:
    la $t0, num

    lw $t1,num1
    sw $t1,0($t0)

    lw $t1,num2
    sw $t1,4($t0)

    lw $t1,num3
    sw $t1,8($t0)

    lw $t1,num4
    sw $t1,12($t0)

    lw $t1,num5
    sw $t1,16($t0)

    lw $t1,num6
    sw $t1,20($t0)

    lw $t1,num7
    sw $t1,24($t0)

    lw $t1,num8
    sw $t1,28($t0)

    lw $t1,num9
    sw $t1,32($t0)

    lw $t1,num10
    sw $t1,36($t0)

    li $t1,4 # i
    li $t2,40 # n
    # array initialization complete

    loop1: 
        bge $t1,$t2,exit

        li $t4,0 # j
        li $t3,0
        sub $t3,$t2,$t1 # n-i 
        loop2: 
            bge $t4, $t3,brk

            addi $t5,$t4,4
            lw $t6,num($t4)
            lw $t7,num($t5)

            ble $t6,$t7,continue
            move $t8 , $t6
            sw $t7, num($t4)
            sw $t8 ,num($t5)

            addi $t4,$t4,4
            j loop2

            continue:
                addi $t4,$t4,4
                j loop2

        brk:
            addi $t1,$t1,4
            j loop1


    exit:

        li $v0,4
        la $a0,mytext
        syscall

        li $t1,0
        loop: 
            bge $t1,$t2,mybreak

            lw $t6,num($t1)
            li $v0,1
            move $a0,$t6
            syscall

            li $v0,4
            la $a0,mynewtext
            syscall
            addi $t1,$t1,4
            j loop

        mybreak:    
            li $v0,10
            syscall


    # li $v0,1
    # lw $a0,36($t0)
    # syscall

    li $v0,10
    syscall

.data 
num:.space 40
num1: .word 10
num2: .word 2
num3: .word 5
num4: .word 1
num5: .word 0
num6: .word 14
num7: .word 12
num8: .word 7
num9: .word 8
num10: .word 9
mytext:.asciiz "array after bubble sort: \n"
mynewtext:.asciiz " "

