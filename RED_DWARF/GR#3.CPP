//KRIS BICKHAM
//GR#3
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
#include <graphics.h>
//Struct
struct Data
{apstring Name;
 int Num;
};


//VARIABLES------------
int grdriver;
int grmode;
int errorcode;
int X;
int Y;
int A;
apstring Trash;
ifstream In_File;
//Arrays---
char String [50];
apvector <Data> Dat (18);



//------------
//PROTOTYPES-----------
void gr_start (int&, int&, int&);
void convert (char String[], apstring);
//MAIN

void main ()
{
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();

settextstyle(0,1,1);
setbkcolor(4);
setcolor(6);

In_File.open("U:\\F123\\Trees.dat");
A=50;

for(X=0;X<9;X++)
	{ getline (In_File, Dat[X].Name);
		convert (String, Dat[X].Name);
		In_File>>Dat[X].Num;
		getline(In_File, Trash);
		outtextxy (A, 300, String);
		A+=50;
	};

In_File.close();

rectangle(45,10, 620,280);


getch();
};



void gr_start (int& grdriver, int& grmode, int& errorcode)
{grdriver=VGA;
 grmode=VGAHI;
 initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
 errorcode=graphresult();
 if (errorcode!=grOk)
	{clrscr();
	 cout<<"Error: "<<errorcode;
	 getch();
	 exit(1);
	 };
};


void convert (char String [], apstring Sent_In)
{int I;
	for(I=0;I<Sent_In.length();I++)
	 String[I]=Sent_In[I];
};

