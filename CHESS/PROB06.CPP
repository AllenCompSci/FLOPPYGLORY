// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
//Constants

//Variables
long Num = 0;

void main ()
{
	clrscr();
	cout << "Enter an integer: ";
	cin >> Num;
	cout <<endl;
	if (Num % 2 == 1) {
		cout << "I don't think so.";
	}
	else {
		cout << "Your number is "<<Num<<".";
	}

getch();
}