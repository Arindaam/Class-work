.text
    MOV R0,#5
    CMP R0,#0
    BMI L2
    BPL L3
    BEQ L1
    L1:
      MOV R1,#1
      SWI 0x011
    L2:
      MOV R1,#3
      SWI 0x011
    L3:
      MOV R1,#2
      SWI 0x011
.end
