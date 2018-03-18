//Michael Crookston
//Problem GR#5
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
#include<dos.h>
#include<alloc.h>
#include<stdlib.h>
//Structures
//Constants
//Prototypes
void gr_start (int&,int&,int&);
void * far * P;
//Global Variables
unsigned Size;
int A,B,C,I;
//Program
void main ()
{
gr_start(A,B,C);
cleardevice();
setcolor(15);
bar(20,20,40,40);
Size=imagesize(20,20,40,40);
*P=farmalloc(Size);
getimage(20,20,40,40,*P);
for(I=50;I<getmaxx();I++)
	{putimage(I,50,*P,COPY_PUT);
	delay(10);
	putimage(I,50,*P,NOT_PUT);
	}
getch();
closegraph();
};
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
	};