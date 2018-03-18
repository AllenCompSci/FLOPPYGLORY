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
apstring Name = "";
apstring SS = "";
int Hours = 0;
char Res = ' ';
double Total = 0.00;

void main ()
{
	clrscr();
	cout <<setiosflags(ios::showpoint);
	cout <<setprecision(2);
	cout << "Busar's Office at State University"<<endl;
	cout << "Your last name: ";
	cin >> Name;
	cout << "Your Social Security Number: ";
	cin >> SS;
	cout << "Credit Hours: ";
	cin >> Hours;
	cout << "Are you a resident of this state(y/n)?";
	cin >> Res;
	cout << "Thank you.  Press any key to continue.";
	getch();
	clrscr();
	if(Hours <= 4) {
		if (Res == 'y' | Res == 'Y') Total = 80.00 * Hours;
		else Total = 120.00 * Hours;
	}
	if(Hours > 4 & Hours <= 12) {
		if (Res == 'y' | Res == 'Y') Total = 70.00 * Hours;
		else Total = 110.00 * Hours;
	}
	else {
		if (Res == 'y' | Res == 'Y') Total = 900.00;
		else Total = 1400.00;
	}
	cout << "Name: "<<Name<<setw(10)<<"SS #: "<<SS<<endl;
	cout << "Credit Hours: "<<Hours<<endl;
	cout << "Resident: "<<Res<<endl;
	cout << "Amount Owed: $"<<Total<<endl;
	getch();
}