void SetXLimits(int MinX,int MaxX)
{
	union REGS inregs,outregs;
	inregs.x.cx=MinX;
	inregs.x.dx=MaxX;
	inregs.x.ax=0x07;
	int86(0x33,&inregs,&outregs);
}