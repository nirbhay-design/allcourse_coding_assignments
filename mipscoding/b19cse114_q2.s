    .text
    .globl main

main:
    lw $t0,num1
    lw $t1,num2

    jal product

    li $v0,10
    syscall    
product: 
    li $t2,0
    move $t3,$t1
    li $t4,1
    loop: 
        ble $t3,$zero,brk
        add $t2,$t2,$t0
        sub $t3,$t3,$t4
        j loop
    brk:
        jr $ra

.data
num1: .word 200
num2: .word 10