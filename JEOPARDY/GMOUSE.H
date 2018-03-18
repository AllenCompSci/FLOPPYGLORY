 // GMOUSE.C
 // Glen H. Barratt's Mouse Utilities
 //
 // (c) Glen H. Barratt Productions. 1998.
 // ghbarratt@hotmail.com

//Edited by William Schleede (SizeMouseX()&SizeMouseY()&DefMouse()) 4/22/2005

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

 //SizeMouseX(unsigned const int)
 //Sets horizontal mouse boundaries to 0 through Size-1
 int SizeMouseX(unsigned const int Size){
  union REGS inregs,outregs;
  inregs.x.ax=0x07;
  inregs.x.cx=0x00;
  inregs.x.dx=(Size-1);
  int86(0x33,&inregs,&outregs);
  return(outregs.x.ax);
 }

 //SizeMouseY(unsigned const int)
 //Sets vertical mouse boundaries to 0 through Size-1
 int SizeMouseY(unsigned const int Size){
  union REGS inregs,outregs;
  inregs.x.ax=0x08;
  inregs.x.cx=0x00;
  inregs.x.dx=(Size-1);
  int86(0x33,&inregs,&outregs);
  return(outregs.x.ax);
 }

 //DefMouse()
 //Returns mouse boundaries to normal
 void DefMouse()
 {
  union REGS inregs,outregs;
  inregs.x.ax=0x07;
  inregs.x.cx=0x00;
  inregs.x.dx=0x027F;
  int86(0x33,&inregs,&outregs);

  inregs.x.ax=0x08;
  inregs.x.cx=0x00;
  inregs.x.dx=0x01DF;
  int86(0x33,&inregs,&outregs);
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
