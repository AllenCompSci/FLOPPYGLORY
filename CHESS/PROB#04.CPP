		cout<<"How big is the table (2-20 by 2-20)"<<endl<<"X: ";
		cin >> SizeX;
		cout << "Y: ";
		cin >> SizeY;
	} while (SizeX < 2 || SizeX > 20 || SizeY < 2 || SizeY > 20);
}


void get_words(int SizeX, int SizeY)
{
//Gets all words and makes sure they aren't too long, etc.

int I, MaxLength;

	if(SizeX < 13 || SizeY < 13)
		if (SizeY < 6 || SizeX < 6)
			MaxLength = 2;
		else
			MaxLength = 5;
	else
		MaxLength = 8;

//This loop will make sure there aren't too many words for the puzzle// Sean Murray
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

void main ()
{
clrscr();
cout << setprecision(2);
cout << setiosflags(ios::showpoint);
cout <<"Sally wants..."<<endl<<endl;
cout <<"Sweater:    $35.00"<<endl;
cout <<"Skirt:      $28.50"<<endl;
cout <<"Blouse:     $22.95"<<endl;
cout <<"Bracelet:   $12.25"<<endl<<endl;
cout <<"Total: $"<<35 + 28.5 + 22.95 + 12.25;
getch();
cout <<endl<<"Whoops...there's a sale today!";
getch();
clrscr();
cout <<"Sally still wants..."<<endl<<endl;
cout <<"Sweater:    $"<<35 * 0.85<<endl;
cout <<"Skirt:      $"<<28.5 * 0.85<<endl;
cout <<"Blouse:     $"<<22.95 * 0.85<<endl;
cout <<"Bracelet:   $12.25"<<endl<<endl;
cout <<"Total: $"