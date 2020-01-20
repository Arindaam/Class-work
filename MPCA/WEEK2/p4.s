.data
        A: .WORD 45,25,54,96
        B: .WORD 0,0,0,0
.text
        LDR R0,=A
        LDR R1,=B
        MOV R2,#4
        L1:
          LDR R3,[R0]
          ADD R0,R0,#4
          STR R3,[R1]
          ADD R1,R1,#4
          SUBs R2,R2,#1
     Cancel
© 2020 GitHub, Inc.      BNE L1
        
.end
