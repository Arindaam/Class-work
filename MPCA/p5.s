.data
  A: .word 1,2,3,4,5,6
.text
 MOV R1,#6
 LDR R0,=A
 MOV R3,#0
 L1:
  LDR R2,[R0]
  ADD R3,R2,R3
  ADD R0,R0,#4
  SUBs R1,R1,#1
  BNE L1
.end
