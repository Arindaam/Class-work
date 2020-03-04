.data
    A: .byte 2
    B: .asciz "even"
    C: .asciz "odd"

.text
    ldr r1,=A
    ldr r2,[r1]
    mov r3,#0
    loop:
        ands r4,r2,#1
        addne r3,r3,#1
        movs r2,r2,LSR #1
        bne loop
        beq done
    
    done:
        ands r3,r3,#1
        bne even
        beq odd

    even:
        ldr r0,=B
        swi 0x02
        swi 0x011

    odd:
        ldr r0,=C
        swi 0x02
        swi 0x011
