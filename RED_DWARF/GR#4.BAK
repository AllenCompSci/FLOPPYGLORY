//KRIS BICKHAM
//GR#3
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
#include <graphics.h>
#include <dos.h>
#include <alloc.h>
//Struct
//VARIABLES------------
int grdriver;
int grmode;
int errorcode;
unsigned size;
int I;
int direction;
int X;
int Y;
int XPlus;
int YPlus;
int Oldcolor;
//------------
//PROTOTYPES-----------
void gr_start (int&, int&, int&);
void *far*P;
//MAIN

void main ()
{
randomize();
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();
setfillstyle(1,15);
X=1;
Y=1;


XPlus=1;
YPlus=1;
Oldcolor=15;
setcolor(0);
do
	{ if	(X<=10)
		 {XPlus=random(10)+1;
			Oldcolor=random(14)+1;
			};
		if  (Y<=10)
			{YPlus=random(10)+1;
			Oldcolor=random(14)+1;
			};
		if  ((X)>=(getmaxx()-10))
			{XPlus=random(-10);
			Oldcolor=random(14)+1;
			};
		if  ((Y)>=(getmaxy()-10))
			{YPlus=random(-10);
			Oldcolor=random(14)+1;
			};


		setfillstyle(0,0);
		fillellipse(X,Y,X+10,X+10);
		setfillstyle(1,Oldcolor);

		X+=XPlus;
		Y+=YPlus;



		fillellipse(X,Y,10,10);
		delay (5);

}while(kbhit);

getch();
closegraph();
};





void gr_start (int& grdriver, int& grmode, int& errorcode)
{grdriver=VGA;
 grmode=VGAHI;
 initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
 errorcode=graphresult();
 if (errorcode!=grOk)
	{clrscr();
	 cout<<"Error: "<<errorcode;
	 getch();
	 exit(1);
	 };
};


