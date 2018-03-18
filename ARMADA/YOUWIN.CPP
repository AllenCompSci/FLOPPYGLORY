//Rebecca Russell
//6th
//Mr. Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
//Constant

//Structures
struct track
{
int X;
int Y;
bool Ships;
};

//Variable
int Ycoor, Xcoor, D, AI, X2, Y2, I, Letnum, UI, UI2, Xcoor2;
int Grdriver, Grmode, Errorcode;
bool Redo;
ifstream In;
track User [10][10];
track Computer [10][10];
apvector <int> Compships(5);
apvector <apstring> Nameships(5);
//Prototypes
void grsetup (int&, int&, int&);
//void hit();
//void miss();
//void title_screen();
//void sink();
//void setup();
void screen();
void usersetup ();
void win();
void loose();
void main ()
{clrscr();
 grsetup(Grdriver, Grmode, Errorcode);
 win();
getch();
};

void grsetup (int& Grdriver, int& Grmode, int& Errorcode)
{Grdriver=VGA;
 Grmode=VGAHI;
 initgraph(&Grdriver, &Grmode, "C:\\TC\\BGI");
 Errorcode=graphresult();
 if(Errorcode!=grOk)
	{clrscr();
	 cout<<"Error";
	 getch();
	 exit(1);
	}
};

void win ()
{setbkcolor(9);
 setcolor(1);
 //Y
 line(10,180,40,180);
 line(70,180,100,180);
 line(10,180,40,240);
 line(40,180,55,210);
 line(55,210,70,180);
 line(70,240, 100,180);
 line(40,240,40,300);
 line(70,240,70,300);
 line(40,300,70,300);
 //O
 line(120,180,210,180);
 line(210,180,210,300);
 line(210,300,120,300);
 line(120,300,120,180);
 line(150,210,180,210);
 line(180,210,180,270);
 line(180,270,150,270);
 line(150,270,150,210);
 //U
 line(240,180,270,180);
 line(270,180,270,270);
 line(270,270,300,270);
 line(300,270,300,180);
 line(300,180,330,180);
 line(330,180,330,300);
 line(330,300,240,300);
 line(240,300,240,180);
 //W
 line(336,180,360,280);
 line(360,280,380,280);
 line(380,280,400,240);
 line(400,240,420,280);
 line(420,280,440,280);
 line(440,280,464,180);
 line(464,180,444,180);
 line(444,180,428,252);
 line(428,252,408,220);
 line(408,220,392,220);
 line(392,220,372,252);
 line(372,252,356,180);
 line(356,180,336,180);
 //I
 line(472,180,472,280);
 line(472,280,492,280);
 line(492,280,492,180);
 line(492,180,472,180);
 //N
 line(500,180,500,280);
 line(500,280,520,280);
 line(520,280,520,228);
 line(444,180,428,252);
 line(428,252,408,220);
 line(408,220,392,220);
 line(392,220,372,252);
 line(372,252,356,180);
 line(356,180,336,180);

};

