//Rebecca Russell
//6th
//Mr.Baker
//Program: moving square
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
//Constant
//Structs
//Variable
int Grdriver, Grmode, Errorcode, X;
unsigned Size;
//Prototype
void grsetup (int&, int&, int&);
void *far *P;
void main ()
{clrscr();
 grsetup(Grdriver, Grmode, Errorcode);
 cleardevice ();
 setcolor(15);
 bar(5,1, 25, 21);
 Size=imagesize(5,1,25,21);
 *P=farmalloc(Size);
 getimage(5,1,25,21,*P);
 for(X=5; X<640; X++)
 {putimage(X,25,*P, COPY_PUT);
	delay(10);
	putimage(X,25,*P,NOT_PUT);
 }
getch();
};

void grsetup (int& Grdriver, int& Grmode, int& Errorcode)
{Grdriver=VGA;
 Grmode=VGAHI;
 initgraph(&Grdriver, &Grmode, "C:\\TC\\BGI");
 Errorcode=graphresult();
 if(Errorcode!=grOk)
	{clrscr();
	 cout<<"Error";
	 getch();
	 exit(1);
	}
};
