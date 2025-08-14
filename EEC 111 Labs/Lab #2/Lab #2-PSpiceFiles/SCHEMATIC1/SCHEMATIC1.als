.ALIASES
V_VS            VS(+=NVIN -=0 ) CN @LAB #2.SCHEMATIC1(sch_1):INS3003@SOURCE.VSIN.Normal(chips)
R_R1            R1(1=NVIN 2=NVOUT ) CN @LAB #2.SCHEMATIC1(sch_1):INS3049@ANALOG.R.Normal(chips)
D_D1            D1(1=NVOUT 2=N03171 ) CN @LAB #2.SCHEMATIC1(sch_1):INS3081@DIODE.D1N4002.Normal(chips)
V_V1            V1(+=N03171 -=0 ) CN @LAB #2.SCHEMATIC1(sch_1):INS3113@SOURCE.VDC.Normal(chips)
V_V2            V2(+=0 -=N03175 ) CN @LAB #2.SCHEMATIC1(sch_1):INS3129@SOURCE.VDC.Normal(chips)
D_D2            D2(1=N03175 2=NVOUT ) CN @LAB #2.SCHEMATIC1(sch_1):INS3155@DIODE.D1N4002.Normal(chips)
_    _(nVIN=NVIN)
_    _(nVOUT=NVOUT)
.ENDALIASES
