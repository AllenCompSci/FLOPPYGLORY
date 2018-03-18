//Michael Crookston
//Problem GR#1
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
//Structures
//Constants
//Prototypes
void gr_start (int&,int&,int&);
void pixelpixel (int,int,int,int,int);
//Global Variables
int A,B,C;
//Program
void main ()
{
clrscr();
gr_start(A,B,C);
settextstyle(4,1,5);
cout<<"Press a key to see rectangles.";
getch();
cleardevice();
rectangle(25,25,400,400);
moveto(10,1);
lineto(20,1);
lineto(20,10);
lineto(10,10);
lineto(10,1);
pixelpixel(460,460,639,479,6);
//Initials
setcolor(3);
moveto(30,370);
lineto(30,30);
lineto(50,170);
lineto(70,30);
lineto(70,370);
moveto(90,370);
lineto(110,30);
lineto(130,370);
moveto(100,170);
lineto(120,170);
moveto(150,30);
arc(170,60,0,180,30);
moveto(140,60);
lineto(140,340);
arc(170,340,180,0,30);
getch();
}
void gr_start (int&grdriver,int&grmode,int&errorcode)
	{grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{clrscr();
		cout<<"Error:"<<errorcode;
		getch();
		exit(1);}
	}
void pixelpixel(int Left, int Top, int Right, int Bottom, int Color)
	{int I;
	for(I=Left;I<Right;I++)
		{putpixel(I,Top,Color);
		putpixel(I,Bottom,Color);}
	for(I=Top;I<Bottom;I++)
		{putpixel(Right,I,Color);
		putpixel(Left,I,Color);}}