// Sean Murray
// Due Date
// Prob 24
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
	apvector <int> Numbers (6);
	int I, J, K, TempNum, Tickets;

void main ()
{
	randomize();
	clrscr();
	cout << "How many tickets do you want (1-5)?";
	cin >> Tickets;
	clrscr();
	cout << "Your Numbers"<<endl;
	for(K = 0;K < Tickets;K
	for (I = 0;I < (SizeX + SizeY) / 2;I++)
	{
		cout << "Enter a 2 to "<<MaxLength<<" letter word (Word #"<<I+1<<"): ";
		do
			cin >> Words[I];
		while (Words[I].length() < 2 || Words[I].length() > MaxLength);
	}
}


void place_words(int SizeX, int SizeY)
{
//Puts the words into a matrix

int Bypass, Bypass2, Direction, X, Y, Xdir, Ydir, I, J;