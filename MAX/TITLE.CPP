//Andrew Closson
//Period 5
//Mr. Baker
//Program:

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apvector.h>
#include <apstring.h>
#include <graphics.h>
#include <stdlib.h>

//CONSTANTS


//PROTOTYPES
void initgraphics();


//VARIABLES
char *fname[] = { "DEFAULT font",
                  "TRIPLEX font",
                  "SMALL font",
									"SANS SERIF font",
                  "GOTHIC font"
								};


int midx = getmaxx() / 2;
int midy = getmaxy() / 2;
int I;


void main()
{


initgraphics();

/*
settextstyle(0, HORIZ_DIR, 4);
outtextxy(4, 4, "This is a test.");

settextstyle(1, HORIZ_DIR, 4);
outtextxy(4, 50, "This is a test.");

settextstyle(2, HORIZ_DIR, 4);
outtextxy(4, 100, "This is a test.");

settextstyle(3, HORIZ_DIR, 4);
outtextxy(4, 150, "This is a test.");

settextstyle(4, HORIZ_DIR, 4);
outtextxy(4, 200, "This is a test.");
*/

 midx = getmaxx() / 2;
 midy = getmaxy() / 2;
I=1;

settextstyle(3, HORIZ_DIR, 1);
setcolor(3);
outtextxy(midx-195, 120, "By: Andrew Closson and Mahmood Subhani");
settextstyle(2, HORIZ_DIR, 4);
setcolor(4);
outtextxy(midx-73, 250, "Please type a number:");
outtextxy(midx-50, 300, "1) Play");
outtextxy(midx-50, 320, "2) Instructions");
outtextxy(midx-50, 340, "3) Quit");
do{
setcolor(I);
settextstyle(4, HORIZ_DIR, 6);
outtextxy(midx-75, 3, "Max's");
outtextxy(midx-85, 50, "Escape");
I++;
}while(!kbhit());

getch();
closegraph();
};


void initgraphics()
{
int grdriver = VGA;
int grmode = VGAHI;
int errorcode;

initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
errorcode = graphresult();

if(errorcode!=grOk)
	{
	clrscr();
	cout << "Error on graphics init" << endl;
	getch();
	exit(1);
	}

}