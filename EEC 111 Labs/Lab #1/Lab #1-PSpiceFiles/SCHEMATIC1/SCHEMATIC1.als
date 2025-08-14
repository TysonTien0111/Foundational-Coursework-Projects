.ALIASES
R_R1            R1(1=NVTEST 2=NVD ) CN @LAB #1.SCHEMATIC1(sch_1):INS206@ANALOG.R.Normal(chips)
D_D1            D1(1=NVD 2=0 ) CN @LAB #1.SCHEMATIC1(sch_1):INS231@DIODE.D1N4002.Normal(chips)
V_V1            V1(+=NVTEST -=0 ) CN @LAB #1.SCHEMATIC1(sch_1):INS275@SOURCE.VPULSE.Normal(chips)
_    _(nVD=NVD)
_    _(nVTEST=NVTEST)
.ENDALIASES
