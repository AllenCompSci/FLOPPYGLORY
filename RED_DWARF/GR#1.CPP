//KRIS BICKHAM
//GR#1
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
//VARIABLES------------
int grdriver;
int grmode;
int errorcode;
int X;
int Y;
//CONSTANTS------------
//PROTOTYPES-----------
void gr_start (int&, int&, int&);
//MAIN

void main ()
{
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();

setcolor(4);
setlinestyle(1,8,3);

//rect 4
rectangle(20,20, 620,200);
//rect 2
setcolor(3);
setlinestyle(2,7,2);
line(20,210, 620,210); //top
line(20,210, 20,390);       //left vert
line(620,210, 620, 390);               //right vert
line(20,390, 620,390);      //bottom
//rect 3
for(X=20;X<621;X++)
 {putpixel(X,410,2);
	putpixel(X,460,2);
	};
for(Y=410;Y<461;Y++)
 {putpixel(20,Y,2);
	putpixel(620,Y,2);
	};
//end rect
setlinestyle(2,2,3);
setcolor(3);
//K
line(30,30, 30,200);
 arc(30,30,  270,0, 85);
 arc(30,200, 0 ,90, 85);
//J
line(205,30, 205,200);
 arc(205,115, 180,270, 85);
//B
line(220,30, 220,200);
 arc(220,65, 270,90, 35);
 arc(220,150, 270,90, 50);

getch();
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

