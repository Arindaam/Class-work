.data
    A: .asciz "SDAsjejkjsfd"
    B: .asciz ""

.text
    ldr r1,=A
    ldr r2,=B
    ldr r0,=B
    loop:
        ldrb r3,[r1],#1
        strb r3,[r2],#1
        cmp r3,#0
        bne loop
    
    swi 0x02
