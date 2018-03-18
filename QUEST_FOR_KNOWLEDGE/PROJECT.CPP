//Michael Crookston
//Shell
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
int dice ();
//Global Variables
//Program
void main ()
{clrscr();
randomize();
while(!=kbhit())
cout<<dice();
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
int dice ()
	{int I, Answer;
	Answer=0;
	for(I=0;I<2;I++)
		Answer+=random(6)+1;
	return Answer;};