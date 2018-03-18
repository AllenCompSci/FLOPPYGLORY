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
	int X, Y, Color;

//Prototypes
	void gr_start(int&, int&, int&);

void main ()
{
	clrscr();
	randomize();
	gr_start(grdriver, grmod() && Bypass2 == 0;J++)
				if (Puzzle[X + (Xdir * J)][Y + (Ydir * J)] != '±')
					if(Puzzle[X + (Xdir * J)][Y + (Ydir * J)] != Words[I][J])
						Bypass2 = 1;

			if (Bypass2 == 0)
			{
				for(J = 0;J < Words[I].length();J++)
					Puzzle[X + (Xdir * J)][Y + (Ydir * J)] = Words[I][J];
				Bypass = 1;
			}
		} while (Bypass == 0);
	}
}

void fill_cells(int SizeX, int SizeY)
{
// Section 4: Fills all the blanks cells in the matrix.

int I, J, Letter;

	for (I =