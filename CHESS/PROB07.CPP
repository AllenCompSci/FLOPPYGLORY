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
int Age = 0;

void main ()
{
	clrscr();
	cout << "Welcome to the Theater!"<<endl;
	cout << "Your age:";
	cin >> Age;
	if (Age <= 12) {
		cout << "It'll cost you $4.00 to see a movie!";
	}
	else {
		cout << "So you're "<<Age<<" huh?  That'll be $6.50!";
	}

	getch();
}