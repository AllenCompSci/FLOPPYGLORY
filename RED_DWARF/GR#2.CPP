//KRIS BICKHAM
//GR#2
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
int T;
int Radius;
//CONSTANTS------------
//PROTOTYPES-----------
void gr_start (int&, int&, int&);
int key_press();
void makecircle ();
void makesquare ();
void makeline ();
void makepixel ();
//MAIN
void main ()
{
randomize();
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();
setcolor(random(15));

do
{
makecircle();
makesquare();
makeline();
makepixel();
}while(!kbhit());

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

int key_press()
{ while(!kbhit());
	return getch();
};


void makecircle ()
{
setcolor(random(15));
int Radius;
Radius=random(119);
circle(random(319-(Radius*2))+Radius,random(239-(Radius*2))+Radius ,Radius);
};

void makesquare ()
{
setcolor(random(15));
rectangle(random(319)+319,random(239),random(319)+319,random(239));
};

void makeline ()
{
setcolor(random(15));
line(random(319),random(239)+239,random(319),random(239)+239);
};

void makepixel ()
{
setcolor(random(15));
putpixel(random(319)+319,random(239)+239,random(15));
};






