12345678912345689461345687945612345689.data
A: .word 10
B: .word 13

.text

;Program to find GCD of 2 numbers stored in memory

LDR R0, =A
LDR R1, =B
LDR R2, [R0]
LDR R3, [R1]
CMP R2,R3

loop:

CMP R2,R3
BMI r2lessthanr3
BPL r3lessthanr2

r2lessthanr3: 
	SUBs R3, R3, R2
	B loopend
r3lessthanr2: 
	SUBs R2,R2,R3
	B loopend

loopend:
BNE loop

SWI 0x011

