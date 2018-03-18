//Chris Chapman
//7th
//prob#40
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>

//const.section

//struct section

//Prototype
void grstart (int&, int&, int&);

//global variable section
int E,K;
char Answer;
int grdriver, grmode, errorcode;

void main ()
{
do{
	 grstart (grdriver, grmode, errorcode);
	 setcolor(14);
	 rectangle(100, 100, 200, 200);
		setfillstyle (1,14);
		floodfill(150, 150, 14);
		setcolor(0);
		arc(150, 150, 45, 315, 30);
		setcolor(9);
	 rectangle(400, 100, 500, 200);
		setfillstyle(1, 9);
		floodfill(450, 150, 9);
		setcolor(0);
			moveto(430, 120);
			lineto(430, 180);
			moveto(430, 120);
			lineto(470, 180);
			lineto(470, 120);
			setcolor(4);
	 rectangle(250, 300, 350, 400); //Hendrik is stupid.
		setfillstyle(1, 4);
		floodfill(300, 350, 4);
			moveto(280, 220);
			setcolor(0);
			lineto(300, 220);
		getch();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

void grstart (int& grdriver, int& grmode, int& errorcode)
	{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph (&grdriver, &grmode, "c:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{
		clrscr();
		cout<<"Error: "<<errorcode<<endl<<"Please resolve."<<endl;
		cout<<"Press enter to continue"<<endl;
		getch();
		exit(1);
		}
	};