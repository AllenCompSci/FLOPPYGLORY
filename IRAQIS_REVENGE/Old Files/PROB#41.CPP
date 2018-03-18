//Chris Chapman
//7th
//prob#41
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
	 grstart (grdriver, grmode, errorcode);
		do{


		setcolor(random (16));
		circle(random (290),random (100),random (120));
		setcolor(random(16));
		moveto(random(640), random(480));
			}while(!kbhit());
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
		cout<<"Error: "<<errorcode<<endl<<"Please resolve immediately."<<endl;
		cout<<"Press enter to continue"<<endl;
		getch();
		exit(1);
		}
	};