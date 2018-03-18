//Inforation Section
//Hendrik Schuetz
//Shell
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<alloc.h>
#include<dos.h>
#include<bitmap.h>


//Const Section

//Structure Section

//Prototype Section
void grstart (int&,int&,int&);
void menu (int&);

//Global Variables Section
int grdriver, grmode, errorcode, Choice;
image Start;

void main ()
{
	clrscr();
	grstart (grdriver, grmode, errorcode);
	menu (Choice);
	if (Choice==2)




}

void grstart (int& grdriver, int& grmode, int& errorcode)
	{
		grdriver=VGA;
		grmode=VGAHI;
		initgraph (&grdriver, &grmode, "c:\\TC\\BGI");
		errorcode=graphresult();
		if (errorcode!=grOk)
			{
				clrscr();
				cout<<"Error: "<<errorcode<<endl;
				cout<<"Please press return to continue.";
				getch();
				exit(1);
			}
	};

void menu (int &Choice)
	{
	Start.open("A:\\name.bmp");
	Start.draw (0,0);
	settextstyle (4,0,1);
	outtextxy (300,280,"Pick one of the following:");
	outtextxy (300,330,"(1) New Game");
	outtextxy (300,360,"(2) Read Me");
	outtextxy (300,390,"(3) Exit");
	cin>>Choice;
	getch();
	};
