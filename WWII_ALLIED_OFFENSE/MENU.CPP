//Justin Bradley
//Prob#43
//1st
//Library Section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bitmap.h"
#include "gmouse.h"
//Structure Section


//Constant Section


//Global Variable Section
int grdrive, grmode, errorcode;
char Yn;
int I, J, K;
int Case;
bool Button;


//Prototype Section <DT>_<Name>(<DT>,<DT>);
void gr_start(int&, int&, int&);

void main()
{
randomize();

gr_start(grdrive, grmode, errorcode);

SetMouse();
ShowMouse();
setcolor(2);

outtextxy(225,60,"CLICK on your option.");
outtextxy(300,120,"PLAY");
outtextxy(265,216,"INSTRUCTIONS");
outtextxy(300,312,"EXIT");
delay(3000);

do{
	delay(20);
	cleardevice();
	setcolor(random(14)+1);

	if(GetMouseX()>=213&&GetMouseX()<=427&&GetMouseY()>=96&&GetMouseY()<=191)
		{
			for(I=0; I<40; I++)
			{
			line(213,96,427,96);
			line(427,96,427,191);
			line(427,191,213,191);
			line(213,191,213,96);
			outtextxy(300,120,"PLAY");
			outtextxy(250,230,"WWII:");
			}
			if(GetMouseButton()==true)
				Case=1;
		}
	else if(GetMouseX()>=213&&GetMouseX()<=427&&GetMouseY()>=192&&GetMouseY()<=287)
		{
		for(I=0; I<40; I++);
			{
			line(213,192,427,192);
			line(427,192,427,287);
			line(427,287,213,287);
			line(213,287,213,192);
			outtextxy(275,216,"INSTRUCTIONS");
			}

		if(GetMouseButton()==true)
			Case=2;

		}
			else if(GetMouseX()>=213&&GetMouseX()<=427&&GetMouseY()>=288&&GetMouseY()<=384)
				{
				for(I=0; I<40; I++);
					{
					line(213,288,427,288);
					line(427,288,427,384);
					line(427,384,213,384);
					line(213,384,213,288);
					outtextxy(300,312,"EXIT");
					}

				if(GetMouseButton()==true)
					Case=3;

				}
}while(GetMouseButton()==false);  //MOUSE HIT


switch(Case)
	{
	case 1:cout<<"Time to play your game";
				 break;
	case 2:cout<<"Instructions:"<<endl;
				 cout<<"1.Use the mouse to move the cursor"<<endl;
				 cout<<"2.Click the left mouse button to fire "<<endl;
				 cout<<"3.Shoot and kill the enemy"<<endl;
				 break;
	case 3:cout<<"Thank you for playing";
				 break;
	}
cout<<endl<<"Please hit enter to quit."<<endl;

getch();

}//End
/***************************************************************************/

void gr_start(int& grdriver, int& grmode, int& errorcode)
{
grdriver=VGA;
grmode=VGAHI;
initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
	{
	clrscr();
	cout<<"Errorcode # "<<errorcode<<endl;
	getch();
	exit(1);
	}
};

