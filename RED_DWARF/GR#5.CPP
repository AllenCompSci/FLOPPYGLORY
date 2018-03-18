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
//------------
//PROTOTYPES-----------
void gr_start (int&, int&, int&);
void *far*P;
//MAIN

void main ()
{
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();
setcolor(15);

bar(20,20,40,40);
size=imagesize(20,20,40,40);

*P=farmalloc (size);
getimage(20,20,40,40,*P);

for(I=50;I<getmaxx();I++)
 {putimage(I,50,*P,COPY_PUT);
	delay (100);
	putimage(I,50,*P,NOT_PUT);
	};

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


