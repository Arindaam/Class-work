.text
   
   MOV R0,#9
   MOV R1,#1
   
   L1:
     MUL R1,R0,R1
     SUBs R0,R0,#1
     BNE L1
.end
