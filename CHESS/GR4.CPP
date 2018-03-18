// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
#include <dos.h>
#include <alloc.h>
#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>

#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

//Structures

//Constants

//Global Variables
	int grdriver, grmode, errorcode;
	int Direction, X, Y, X_Add, Y_Add, Style, Color, Color2;

//Prototypes
	void gr_start(int&, int&, int&);

void main ()
{
	clrscr();
	randomize();
	gr_start(grdriver, grmode, errorcode);
	X = 300;
	Y = 200;
	do
	{
		X_Add = random(5) - 2;
		Y_Add = random(5) - 2;
	} while (X_Add == 0 || Y_Add == 0);

	while(!kbhit())
	{
		setcolor(0);
		setfillstyle(Style, 0);

		fillellipse(X, Y, 20, 20);

		Style = random(9);
		Color = random(16);
		Color2 = random(16);
		X += X_Add;
		Y += Y_Add;
		setcolor(Color);
		setfillstyle(Style, Color2);

		fillellipse(X, Y, 20, 20);

		if (X < 21 || Y < 21 || X > 619 || Y > 459)
		{
			if (X < 21)
			{
				X_Add = random(4) + 1;
				Y_Add = random(5) - 2;
			}
			if(Y < 21)
			{
				Y_Add = random(4) + 1;
				X_Add = random(7) - 2;
			}

			if (X > 619)
			{
				X_Add = random(5) - 6;
				Y_Add = random(5) - 2;
			}

			if (Y > 459)
			{
				Y_Add = random(5) - 6;
				X_Add = random(5) - 2;
			}
		}
		delay(5);
	}
}

void gr_start(int & grdriver, int & grmode, int & errorcode)
{
	grdriver = VGA;
	grmode = VGAHI;
	initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		clrscr();
		cout << "Error: " << errorcode;
		getch();
		exit(1);
	}
};