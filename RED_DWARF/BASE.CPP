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
//------------
//PROTOTYPES-----------
void gr_start (int&, int&, int&);

//MAIN

void main ()
{
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();


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
