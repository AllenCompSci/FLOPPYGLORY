//Michael Crookston
//Problem GR#2
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
//Global Variables
int A,B,C,I,X,Y,X2,Y2,Maxx,Maxy,Color,Radius;
//Program
void main ()
{clrscr();
gr_start (A,B,C);
randomize();
do
{switch(random(4))
{case 0 :  Maxx=getmaxx()/2;
					 Maxy=getmaxy()/2;
					 X=random(Maxx)+1;
					 Y=random(Maxy)+1;
					 Color=random(16);
					 Radius=random(Maxy)+1;
					 setcolor(Color);
					 if(Radius<Maxy-Y && 0<X-Radius && 0<Y-Radius && Radius<Maxx-X)
					 circle(X,Y,Radius);
					 break;
case 1 :	 X=random(Maxx)+Maxx+1;
					 Y=random(Maxy)+1;
					 X2=random(Maxx)+Maxx+1;
					 Y2=random(Maxy)+1;
					 Color=random(16);
					 setcolor(Color);
					 rectangle(X,Y,X2,Y2);
					 break;
case 2 :	 X=random(Maxx)+1;
					 Y=random(Maxy)+Maxy+1;
					 X2=random(Maxx)+1;
					 Y2=random(Maxy)+Maxy+1;
					 Color=random(16);
					 setcolor(Color);
					 line(X,Y,X2,Y2);
					 break;
case 3 :	 X=random(Maxx)+Maxx+1;
					 Y=random(Maxy)+Maxy+1;
					 Color=random(16);
					 putpixel(X,Y,Color);
					 break;}
}
while(!kbhit());
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