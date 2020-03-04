.data
    A: .asciz "SDAsjejkjsfd"

.text
    mov r1,#-1
    ldr r0,=A
    ldr r3,=A
    loop:
        ldrb R2,[R3],#1
        add r1,r1,#1
        cmp r2,#0
        bne loop
    
    swi 0x02
    swi 0x011
