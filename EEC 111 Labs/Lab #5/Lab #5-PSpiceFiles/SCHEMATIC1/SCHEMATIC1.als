.ALIASES
M_M1            M1(d=NVDD g=NVIN s=Y0 b=NVDD ) CN @LAB #5.SCHEMATIC1(sch_1):INS21912@CD4007.cd4007_PMOS.Normal(chips)
V_VVDD          VVDD(+=NVDD -=0 ) CN @LAB #5.SCHEMATIC1(sch_1):INS21977@SOURCE.VDC.Normal(chips)
M_M3            M3(d=Y0 g=NVIN s=0 b=0 ) CN @LAB #5.SCHEMATIC1(sch_1):INS22048@CD4007.cd4007_NMOS.Normal(chips)
V_VIN           VIN(+=NVIN -=0 ) CN @LAB #5.SCHEMATIC1(sch_1):INS22181@SOURCE.VDC.Normal(chips)
M_M4            M4(d=0 g=NVIN s=Y0 b=0 ) CN @LAB #5.SCHEMATIC1(sch_1):INS22378@CD4007.cd4007_NMOS.Normal(chips)
_    _(nVDD=NVDD)
_    _(nVIN=NVIN)
_    _(Y0=Y0)
.ENDALIASES
