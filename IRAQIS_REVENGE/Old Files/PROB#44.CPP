//Chris Chapman
//7th
//prob#44
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
#include<dos.h>
#include<alloc.h>

//const.section

//struct section

//Prototype
void grstart (int&, int&, int&);

//global variable section
int E,K;
char Answer;
unsigned Size;
void far *P, *Q;
int grdriver, grmode, errorcode;

void main ()
{
do{
	 grstart (grdriver, grmode, errorcode);
	 setcolor (15);
	 bar(0, 0, 20, 20);
	 Size=imagesize(0,0,20,20);
	 P=farmalloc(Size);
	 getimage(0,0,20,20,P);
	 cleardevice();
	 for(E=0;E<getmaxx()-20;E++);
		{putimage(E,40,P,COPY_PUT);
		delay(15);
		putimage(E,40,P,NOT_PUT);
		}

	}while(!kbhit);
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