//Mike Crookston
//GR#4
//Period 6
//Mr.Baker
//Libraries
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <alloc.h>
//Structures
//Constants
//Global Variables
int grdriver,grmode,errorcode,AddI,AddJ,I,J,Color;
//Prototypes
void gr_start(int &, int &, int &);
//Functions
void main ()
	{gr_start(grdriver,grmode,errorcode);
	 randomize();
	 I=0;
	 J=0;
	 AddI=0;
	 AddJ=0;
	 while(!kbhit())
		 {if (I-AddI-9<=1)
				{AddI=random(5)+1;
				 Color=random(14)+1;
				}
			if (J-AddJ-9<=1)
				{AddJ=random(5)+1;
				 Color=random(14)+1;
				}
			if (I+9+AddI>=getmaxx())
				{AddI=random(5)-5;
				 Color=random(14)+1;
				}
			if (J+9+AddJ>=getmaxy())
				{AddJ=random(5)-5;
				 Color=random(14)+1;
				}
			I+=AddI;
			J+=AddJ;
			setfillstyle(1,Color);
			fillellipse(I,J,9,9);
			delay(10);
			setfillstyle(1,0);
			bar(I-10,J-10,I+10,J+10);
		 }
	 closegraph();
	}
void gr_start (int & grdriver, int & grmode, int & errorcode)
	{grdriver=VGA;
	 grmode=VGAHI;
	 initgraph(& grdriver, & grmode,"C:\\TC\\BGI");
	 errorcode=graphresult();
	 if (errorcode!=grOk)
		 {clrscr();
			cout << "Error:" << endl << errorcode;
			getch();
			exit(1);
		 }
	}




















