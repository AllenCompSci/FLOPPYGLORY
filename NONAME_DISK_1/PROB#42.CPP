//Jeff Stein
//6th Period
//Mr. Baker
//Program:
#include <iostream.h>
#include <conio.h>
#include <apstring.h>
#include <iomanip.h>
#include <apvector.h>
#include <apmatrix.h>
#include <stdlib.h>
#include <graphics.h>
int Grdriver, Grmode, Errorcode;
void Graphic_Setup (int &, int &, int &);

void main()
{
 clrscr();
 Graphic_Setup ( Grdriver, Grmode, Errorcode);
 setbkcolor(BLACK);
 setcolor(2);
 rectangle(0,75,250,450);
 rectangle(300,150,500,200);
 rectangle(420,266,550,300);
 line(200,100,200,300);
 arc(100,300,180,0,100);









getch();
};


void Graphic_Setup (int & Grdriver,int & Grmode,int & Errorcode)
	{
		Grdriver = VGA;
		Grmode = VGAHI;
		initgraph(&Grdriver, &Grmode, "C:\\TC\\BGI");
		Errorcode = graphresult();

		if (Errorcode !=grOk)
			{
				clrscr();
				cout<<"Graphic Error"<<endl;
				getch();
				exit(1);
			}
	}



