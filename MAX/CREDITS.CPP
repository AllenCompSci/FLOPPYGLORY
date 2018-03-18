
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
#include <dos.h>

//CONSTANTS


//PROTOTYPES
void initgraphics();


//VARIABLES
int midx;

void main()
{
initgraphics();
midx = getmaxx() / 2;



settextstyle(3, HORIZ_DIR, 4);
setcolor(5);
outtextxy(midx-60, 150, "Credits");
getch();

setcolor(0);
outtextxy(midx-60, 150, "Credits");


settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-75, 150, "Lead Programmer:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-84, 170, "Andrew Closson");
getch();

settextstyle(3, HORIZ_DIR, 1);
setcolor(0);
outtextxy(midx-75, 150, "Lead Programmer:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-84, 170, "Andrew Closson");



settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-90, 150, "Lead Content Designer:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-86, 170, "Mahmood Subhani");
getch();

settextstyle(3, HORIZ_DIR, 1);
setcolor(0);
outtextxy(midx-90, 150, "Lead Content Designer:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-86, 170, "Mahmood Subhani");



settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-110, 150, "Image Creation Tool Coder:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-84, 170, "Andrew Closson");
getch();

settextstyle(3, HORIZ_DIR, 1);
setcolor(0);
outtextxy(midx-110, 150, "Image Creation Tool Coder:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-84, 170, "Andrew Closson");



settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-67, 150, "Lead Map Artist:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-86, 170, "Mahmood Subhani");
getch();

settextstyle(3, HORIZ_DIR, 1);
setcolor(0);
outtextxy(midx-67, 150, "Lead Map Artist:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-86, 170, "Mahmood Subhani");



settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-72, 150, "Lead Play Tester:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-84, 170, "Andrew Closson");
getch();

settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-72, 150, "Lead Program Tester:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-84, 170, "Andrew Closson");



settextstyle(3, HORIZ_DIR, 1);
setcolor(5);
outtextxy(midx-67, 150, "Lead Map Artist:");
settextstyle(3, HORIZ_DIR, 3);
outtextxy(midx-86, 170, "Mahmood Subhani");
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
