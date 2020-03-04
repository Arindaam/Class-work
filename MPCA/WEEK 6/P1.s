.data
    A: .asciz "SDAsjejkjsfd"
    B: .asciz "A"
    C: .asciz "Found"
    D: .asciz "Not Found"
.text
    ldr r0,=A
    ldr r1,=B
    ldrb r3,[r1]
    mov r4,#0
    loop:
        ldrb r2,[r0],#1
        cmp r2,r3
        beq found
        cmp r2,#0
        bne loop
    
    ldr r0,=D
    swi 0x02
    swi 0x011

    found:
        ldr r0,=C
        swi 0x02
        mov r4,#1
        swi 0x011
