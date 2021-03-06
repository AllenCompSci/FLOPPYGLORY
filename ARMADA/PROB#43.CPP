//Rebecca Russell
//6th
//Mr.Baker
//Program:divide screen into 4's and put pixels, lines, rectangles, and
//circles in each.
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
int Grdriver, Grmode, Errorcode, Pix1, Pix2, C, L, L1, L2, L3,Cx,Cy,R,T,B;
//Prototype
void grsetup (int&, int&, int&);
void pixel ();
void line ();
void rec ();
void circle ();
void main ()
{clrscr();
 grsetup(Grdriver, Grmode, Errorcode);
 setcolor(15);
 setbkcolor(0);
 line(320, 0, 320, 479);
 line(0, 240, 639, 240);
 randomize();
do
{pixel();
 line ();
 circle ();
 rec ();
}
while(!kbhit());
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

void circle ()
{do
{Cx=random(getmaxx()/2);
 Cy=random(getmaxy()/2);
 R=random(getmaxy()/4);
}
while ((Cx+R>=(getmaxx()/2)-1||Cy+R>=(getmaxy()/2)) || (Cx-R<=0 || Cy-R<=0));
C=random(16);
setcolor(C);
circle(Cx,Cy,R);
}


void rec ()
{L=random((getmaxx()/2)+2)+((getmaxx()/2)+2);
 T=random((getmaxy()/2)-2)+2;
 R=random((getmaxx()/2)+2)+((getmaxx()/2)+2);
 B=random((getmaxy()/2)-2)+2;
 C=random(16);
 setcolor(C);
 rectangle(L,T,R,B);
}

void pixel ()
{Pix1=random(319)+1;
 Pix2=random(238)+241;
 C=random(16);
 putpixel(Pix1, Pix2, C);
};

void line ()
{L=random(318)+321;
 L1=random(238)+241;
 L2=random(318)+321;
 L3=random(238)+241;
 C=random(16);
 setcolor(C);
 line(L, L1, L2, L3);
}
