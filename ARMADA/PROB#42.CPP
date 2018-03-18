//Rebecca Russell
//6th
//Mr.Baker
//Program: 3 rectangles and initials to screen
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
//Constant
//Structs
//Variable
int Grdriver, Grmode, Errorcode, I;
//Prototype
void grsetup (int&, int&, int&);
void initials();
void main ()
{clrscr();
 grsetup(Grdriver, Grmode, Errorcode);
 setcolor(9);
 setbkcolor(1);
 rectangle(500,450,600,400);

 line(1, 0, 80, 0);
 moveto(80,0);
 lineto(80,20);
 lineto(1,20);
 lineto(1,0);

 for(I=100; I<400; I++)
 {putpixel(100, I, 4);
	putpixel(500, I, 4);
 }
 for(I=100; I<500; I++)
 {putpixel(I, 100, 2);
	putpixel(I, 400, 2);
 }
 initials();
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

void initials()
{setcolor(5);
 line(125, 125, 125, 300);
 arc(125, 160, 270, 450, 35);
 line(125, 195, 160, 300);

 line(170, 300, 185, 125);
 line(185, 125, 200, 300);
 line(200, 300, 215, 125);
 line(215, 125, 230, 300);

 line(240, 125, 240, 300);
 arc(240, 160, 270, 450, 35);
 line(240, 195, 275, 300);

}


