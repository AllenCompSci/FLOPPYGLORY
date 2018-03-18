// Sean Murray
// Due Date
// Prob 25a
// Mr. Baker - 3rd pd.

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>

#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

//Constants

//Variables
apvector <apstring> Words (20);
char Puzzle [20][20];
int I, J, K, Direction, X, Y, Xdir, Ydir, Letter, Bypass, Bypass2;

void main ()
{
	clrscr();
	randomize();
	for (I = 0;I < 20;I++)
		for (J = 0;J < 20;J++)
			Puzzle[I][J] = '±';

	//Section 1: Gets all 2 to 8 letter words.
	for (I = 0;I < 20;I++)
	{
		cout << "Enter a 2 to 8 letter word (Word #"<<I+1<<"): ";
		do
			cin >> Words[I];
		while (Words[I].length() < 2 || Words[I].length() > 8);
	}

	clrscr();

	//Section 2: Puts the words into a 20 x 20 matrix
	for (I = 0;I < 20;I++)
	{
		do
		{
			Bypass = 0;
			Bypass2 = 0;
			Direction = random(8);
			switch(Direction)
			{
				case 0: //up
					Xdir = 0;
					Ydir = -1;
					X = random(20);
					do
						Y = random(20);
					while (Y < Words[I].length());
					break;

				case 1: //down
					Xdir = 0;
					Ydir = 1;
					X = random(20);
					do
						Y = random(20);
					while (Y > 20 - Words[I].length());
					break;

				case 2: //left
					Xdir = -1;
					Ydir = 0;
					Y = random(20);
					do
						X = random(20);
					while (X < Words[I].length());
					break;

				case 3: //right
					Xdir = 1;
					Ydir = 0;
					Y = random(20);
					do
						X = random(20);
					while (X > 20 - Words[I].length());
					break;

				case 4: //left up
					Xdir = -1;
					Ydir = -1;
					do {
						X = random(20);
						Y = random(20);
					} while (X < Words[I].length() || Y < Words[I].length());
					break;

				case 5: //left down
					Xdir = -1;
					Ydir = 1;
					do {
						X = random(20);
						Y = random(20);
					} while (X < Words[I].length() || Y > 20 - Words[I].length());
					break;

				case 6: //right up
					Xdir = 1;
					Ydir = -1;
					do {
						X = random(20);
						Y = random(20);
					} while (X > 20 - Words[I].length() || Y < Words[I].length());
					break;

				case 7: //right down
					Xdir = 1;
					Ydir = 1;
					do {
						X = random(20);
						Y = random(20);
					} while (X > 20 - Words[I].length() || Y > 20 - Words[I].length());
					break;
			}
			for(J = 0;J < Words[I].length() && Bypass2 == 0;J++)
				if (Puzzle[X + (Xdir * J)][Y + (Ydir * J)] != '±')
					if(Puzzle[X + (Xdir * J)][Y + (Ydir * J)] != Words[I][J])
						Bypass2 = 1;

			if (Bypass2 == 0)
				for(J = 0;J < Words[I].length();J++)
				{
					Puzzle[X + (Xdir * J)][Y + (Ydir * J)] = Words[I][J];
					Bypass = 1;
				}

		} while (Bypass == 0);
	}
	// Section 3: Fills all the blanks cells in the matrix.
	for (I = 0;I < 20;I++)
		for (J = 0;J < 20;J++)
			if (Puzzle[I][J] == '±')
			{
				Letter = random(2);
				if (Letter == 0)
					Puzzle[I][J] = char(random(26) + 65);
				else
					Puzzle[I][J] = char(random(26) + 97);
			}

	// Section 4: Puts it on the screen!
	cout << "Your word search" << endl << endl;
	for (I = 0;I < 20;I++)
	{
		for (J = 0;J < 20;J++)
			cout << Puzzle[I][J] << " ";
		cout << endl;
	}

	gotoxy(60,1);
	cout << "Your words";
	for (I = 0;I < 20;I++)
	{
		gotoxy(60,I + 3);
		cout << Words[I];
	}
	getch();
}
