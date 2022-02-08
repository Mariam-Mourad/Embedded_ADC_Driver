# define SetBit(Reg, Bit_Number)   (Reg|=(1<<Bit_Number))   
# define ClrBit(Reg, Bit_Number)   (Reg&=~(1<<Bit_Number))
# define TogBit(Reg,Bit_Number)    (Reg^=(1<<Bit_Number))
# define GetBit(Reg,Bit_Number)     ((Reg>>Bit_Number)&0x01)
/*tary2a tanya
((1<<Bit_Number)&Reg)>>Bit_Number
tary2a talta
not c standard
!(!((1<<Bit_Number)&Reg))


*/
