//Kathy Harrod
//6th
//Mr. Baker
//Program: forest program-bar graph
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<iomanip.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<alloc.h>
#include<dos.h>

//Constant
//Variable
int Grdriver;
int Grmode;
int Errorcode;
int I;
int J;
int L;
//Prototype
void function (int&, int&, int&);


void main ()
{
//open file;

//get info

function (Grdriver,Grmode,Errorcode);
cleardevice();

//bar (100,50,150,80);
//setfillstyle (4,5);
//bar (100,90,150,120);
//setfillstyle (3,8);
//bar (100,130,150,160);
//setfillstyle (2,6);
//bar (100,170,150,200);
//setfillstyle (5,7);
//bar (100,210,150,240);
//setfillstyle (6,9);
//bar (100,250,150,280);


	for (I=0;I<10;I++)

 {setcolor(I+1);
	 rectangle (100,50+I*40,150,80+I*40);
	 };


	 for (I=1;I<10;I++)
	{setcolor(I+11);
	 rectangle (200,50+I*40,250,80+I*40);
	}











//close file;

getch();
};

void function (int& Grdriver, int& Grmode, int& Errorcode)
{Grdriver=VGA;
Grmode=VGAHI;
initgraph(&Grdriver, &Grmode,"C:\\TC\\BGI");
Errorcode=graphresult();
if (Errorcode!=grOk)
{clrscr();
cout<<"Error";
getch();
exit(1);
}
};