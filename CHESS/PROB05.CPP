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
double Pkg = 0.0;
apstring Inpt = "";

void main ()
{
clrscr();

cout <<setprecision(2);
cout <<setiosflags(ios::showpoint);
cout <<"Would you like to use pounds (y/n)?";
cin >> Inpt; //Gets users input
	if (Inpt == "y" | Inpt == "Y") { //Checks users input for yes/no

		do {
			cout << "How much does this package weigh in lbs. (max. 10 lbs.)?"<<endl;
			cin >> Pkg;
		} while (Pkg > 10); //Will not continue until Pkg is less than 10
		Pkg = Pkg * 16;

	}
	else {
		do {
			cout << "About How much does this package weigh in ounces (max 160 oz.)?"<<endl;
			cin >> Pkg;
		} while (Pkg > 10 * 16); //Will not continue until Pkg is less than 160
	}

clrscr();

cout <<"Weight of Package: "<<Pkg<<" oz. ("<<Pkg / 16<<" lbs.)"<<endl;
cout << "Cost to send (In dollars) to location:"<<endl;
cout <<setw(8)<<"In City"<<setw(10)<<"In State"<<setw(12)<<"East Coast";
cout <<setw(10)<<"Mid West"<<setw(7)<<"South"<<setw(12)<<"West Coast";
cout <<setw(10)<<"Overseas"<<endl;

cout <<setw(8)<<Pkg * 0.15<<setw(10)<<Pkg * 0.35<<setw(12)<<Pkg * 0.55;
cout <<setw(10)<<Pkg * 0.42<<setw(7)<<Pkg * 0.38<<setw(12)<<Pkg * 0.615;
cout <<setw(10)<<Pkg * 1.07<<endl;
getch();
}