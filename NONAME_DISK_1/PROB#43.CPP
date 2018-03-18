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
void line();
void rect();
void cir();
void pix();

void main()
{
 clrscr();
 Graphic_Setup ( Grdriver, Grmode, Errorcode);
;

line();
rect();
cir();
pix();



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

void line()
{

 rectangle(0,75,250,450);





}

void rect ()
{
rectangle(300,150,500,200);



}

void cir ()
{
rectangle(300,150,500,200);



}

void pix ()
{

rectangle(300,150,500,200);




}


