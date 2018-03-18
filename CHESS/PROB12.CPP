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
int AddNum = 0;
apstring Add = "";

int CurMonth = 0;
int CurDay = 0;
int CurYear = 0;
int DueMonth = 0;
int DueDay = 0;
int DueYear = 0;

char Cable = ' ';
char Cinema = ' ';
char Cartoon = ' ';

double Total = 0.0;
void main ()
{
	clrscr();
	cout << setprecision(2);
	cout << setiosflags(ios::showpoint);
	cout << "Stan's TV Corp."<<endl;
	cout << "Your last name: ";
	cin >> Name;
	cout << "Your Address Number: ";
	cin >> AddNum;
	cout << "Your street name: ";
	cin >> Add;
	cout << "The current month (##): ";
	cin >> CurMonth;
	cout << "The current day(##): ";
	cin >> CurDay;
	cout << "The current year(####): ";
	cin >> CurYear;
	cout << "The month due(##): ";
	cin >> DueMonth;
	cout << "The day due(##): ";
	cin >> DueDay;
	cout << "The year due(####): ";
	cin >> DueYear;
	clrscr;
	cout << "Do you use our cable service (y/n)?";
	cin >> Cable;
	cout << "Do you use our cinema service (y/n)?";
	cin >> Cinema;
	cout << "Do you use our cartoon channel (y/n)?";
	cin >> Cartoon;
	clrscr();

	cout << "Name: "<<Name<<setw(12)<<"Address: "<<AddNum<<" "<<Add<<endl;
	cout << "Current Date: "<<CurMonth<<"-"<<CurDay<<"-"<<CurYear;
	cout << setw(15)<<"Due Date: "<<DueMonth<<"-"<<DueDay<<"-"<<DueYear;
	cout <<endl<<endl;
	cout <<"Services:"<<endl;
	cout <<setw(12)<<"Standard: "<<setw(10)<<"$7.00"<<endl;
	Total = 7.00;
	if (Cable == 'y' || Cable == 'Y') {
		Total += 4.00;
		cout <<setw(12)<<"Cable: "<<setw(10)<<"$4.00"<<endl;
	}
	if (Cinema == 'y' || Cinema == 'Y') {
		Total += 2.00;
		cout <<setw(12)<<"Cinema: "<<setw(10)<<"$2.00"<<endl;
	}
	if (Cartoon == 'y' || Cartoon == 'Y') {
		Total += 2.00;
		cout <<setw(12)<<"Cartoon: "<<setw(10)<<"$2.00"<<endl;
	}

	cout <<endl<<endl;
	if (CurYear > DueYear) {
		Total =Total + Total * 0.05;
		cout << "Past due amount: ";
		cout <<setw(10)<<"$"<<Total;
	}
	else if (CurYear == DueYear && CurMonth > DueMonth) {
			Total =Total + Total * 0.05;
			cout << "Past due amount: ";
			cout <<setw(10)<<"$"<<Total;
		}
		else if (CurYear == DueYear && CurMonth == DueMonth && CurDay > DueDay) {
				Total =Total + Total * 0.05;
				cout << "Past due amount: ";
				cout <<setw(10)<<"$"<<Total;
		}
		else {
			cout << "Total amount: "<<setw(10)<<"$"<<Total;
		}
	getch();
}