//Michael Crookston
//Problem #29
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
//Structures
//Constants
//Prototypes
void gr_start (int&,int&,int&);
//Global Variables
//Program
void main ()
{

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