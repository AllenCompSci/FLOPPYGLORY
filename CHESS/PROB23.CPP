// Sean Murray
// Due Date
// Prob 23
// Mr. Baker - 3rd pd.

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <stdlib.h>

//Constants

//Variables
	apvector <int> Numbers (15);
	char choice;
	int I;

void main ()
{
	clrscr();
	randomize();
	do
	{
		clrscr();
		cout << "Your Numbers:";
		for (I = 0;I < 15;I++)
		{
			Numbers [I] = random(6) + 1;
			cout << setw(3) << Numbers[I];
		}
		cout << endl << "Get more numbers (y/n)?";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}