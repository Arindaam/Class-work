.data
    A: .word 1,2,3,4,5,6,7,8,9,10
    B: .word 11
    C: .asciz "Found"
    D: .asciz "Not Found"

.text
    ldr r0,=A
    ldr r1,=B
    ldr r2,[r1]
    mov r3,#0           ;Start
    mov r4,#9           ;End
    loop:
        add r5,r3,r4
        mov r5,r5,LSR #1;Mid
        cmp r3,r4
        bgt notfound
        ldr r6,[r0,r5,LSL #2]
        cmp r2,r6
        beq found
        bge greater
        blt less

        greater:
            add r3,r5,#1
            b loop
        
        less:
            sub r4,r5,#1
            b loop

    found:
        ldr r0,=C
        swi 0x02
        swi 0x011

    notfound:
        ldr r0,=D
        swi 0x02
        swi 0x011
