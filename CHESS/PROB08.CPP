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
long Temp = 0;

void main ()
{
	clrscr();
	cout << "What temperature do you like (in Farenheight)?"<<endl;
	cin >> Temp;
	cout << "You should ";
	if (Temp > 85) {
		cout << "go swimming.";
	}
	else {
		if (Temp > 70 && Temp <= 85) {
			cout << "play tennis.";
		}
		else {
			if (Temp > 32 && Temp <= 70) {
				cout << "play golf.";
			}
			else {
				if (Temp > 10 && Temp <= 32) {
					cout << "go skiing.";
				}
				else cout << "play checkers.";
			}
		}
	}
	getch();
}