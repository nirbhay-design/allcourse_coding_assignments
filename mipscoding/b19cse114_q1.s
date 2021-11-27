    .text
    .globl main

main:
    
    # if-else
    # program:
    #     a = 3
    #     b = 4
    #     if (a > b) {
    #         c = a + b;
    #     } else {
    #         c = b - a;
    #     }

    li $t0,3
    li $t1,4

    bgt $t0,$t1,mysum
    sub $t2,$t1,$t0

    li $v0,10
    syscall

mysum:
    add $t2,$t1,$t0

    li $v0,10
    syscall