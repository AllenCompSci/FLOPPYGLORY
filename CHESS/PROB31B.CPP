// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>

#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

//Constants

//Global Variables
	int I, Integer;
	ifstream in_file;

//Prototypes

void main ()
{
	clrscr();
	randomize();
	cout << "Reading from file01.fil"<<endl;
	in_file.open("file01.fil");

	for (I = 0;I < 10;I++)
	{
		in_file >> Integer;
		cout << Integer << endl;
	}

	in_file.close();
	cout <<"done.";
	getch();
}