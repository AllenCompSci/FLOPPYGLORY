 // GMOUSE.C
 // Glen H. Barratt's Mouse Utilities
 //
 // (c) Glen H. Barratt Productions. 1998.
 // ghbarratt@hotmail.com

 /*
	 Started: 10/14/1998
	 Finished: N/A
 */

 // INCLUDES //

 #include <dos.h>
 #include <bios.h>
 #include <stdio.h>
 #include <math.h>
 #include <conio.h>

 // FUNCTIONS //

 int SetMouse(){
  union REGS inregs,outregs;
  inregs.x.ax=0x00;
  int86(0x33,&inregs,&outregs);
  return(outregs.x.ax);
 }

 int ShowMouse(){
  union REGS inregs,outregs;
  inregs.x.ax=0x01;
  int86(0x33,&inregs,&outregs);
  return(1);
 }

 int HideMouse(){
  union REGS inregs,outregs;
  inregs.x.ax=0x02;
  int86(0x33,&inregs,&outregs);
  return(1);
 }

 int GetMouseX(){
  int x;
  union REGS inregs,outregs;
  inregs.x.ax=0x03;
  int86(0x33,&inregs,&outregs);
  x=outregs.x.cx;
  return(x);
 }

 int GetMouseY(){
  int y;
  union REGS inregs,outregs;
  inregs.x.ax=0x03;
  int86(0x33,&inregs,&outregs);
  y=outregs.x.dx;
  return(y);
 }

 int GetMouseButton(){
  int b;
  union REGS inregs,outregs;
  inregs.x.ax=0x03;
  int86(0x33,&inregs,&outregs);
  b=outregs.x.bx;
  return(b);
 }

 int SetMouseSensitivity(int *x,int *y,int *buttons){
  union REGS inregs,outregs;
  inregs.x.bx=*x;
  inregs.x.cx=*y;
  inregs.x.dx=*buttons;
  inregs.x.ax=0x1A;
  int86(0x33,&inregs,&outregs);
  return 1;
 }

 void SetXLimits(int MinX, int MaxX)
 {
	union REGS inregs,outregs;
	inregs.x.cx=MinX;
	inregs.x.dx=MaxX;
	inregs.x.ax=0x07;
	int86(0x33,&inregs,&outregs);
 }

 void SetYLimits(int MinY, int MaxY)
	{
	union REGS inregs,outregs;
	inregs.x.cx=MinY;
	inregs.x.dx=MaxY;
	inregs.x.ax=0x08;
	int86(0x33,&inregs,&outregs);
 }