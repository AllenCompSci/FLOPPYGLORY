// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
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
	int X, Y, X2, Y2, Size, Color, Radius, DrawNum, Object, I;

//Prototypes
	void gr_start(int&, int&, int&);

void main ()
{
	clrscr();
	randomize();
	gr_start(grdriver, grmode, errorcode);

	while(!kbhit())
	{
		Object = random(4);
		DrawNum = random(50)+1;
		switch(Object)
		{
			case 0:
				for (I = 0; I < DrawNum;I++)
				{
					X = random(319);
					Y = random(239);
					Color = random(16);
					setcolor(Color);
					do
						Radius = random(150);
					while(X - Radius < 0 || X + Radius > 318 || Y - Radius < 0 || Y + Radius > 238);
					circle(X, Y, Radius);
				}

			case 1:
				for(I = 0; I < DrawNum;I++)
				{
					X = random(319) + 321;
					X2 = random(319) + 321;
					Y = random(239);
					Y2 = random(239);
					Color = random(16);
					setcolor(Color);
					rectangle(X, Y, X2, Y2);
				}

			case 2:
				for(I = 0; I < DrawNum;I++)
				{
					X = random(319);
					Y = random(239) + 241;
					X2 = random(319);
					Y2 = random(239) +241;
					Color = random(16);
					setcolor(Color);
					line(X, Y, X2, Y2);
				}

			case 3:
				for(I = 0; I < DrawNum;I++)
				{
					X = random(319) + 321;
					Y = random(239) + 241;
					Color = random(16);
					putpixel(X, Y, Color);
				}
		}
	}

	getch();
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