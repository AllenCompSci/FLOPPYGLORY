// Sean Murray
// Due Date
// Prob 30
// Mr. Baker - 3rd pd.

// 0 1 1 2 3 5 8 13 21 34 55 89 (you get the idea)

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>

#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

//Constants

//Global Variables
	int Num;

//Prototypes
	long fib (int);
void main ()
{
	clrscr();
	cout << "What number in the sequence do you want: ";
	cin >> Num;
	cout << "Fibonacci #"<<Num<<": "<<fib(Num - 1);
	getch();
}

long fib (int Num)
{
	if (Num < 2)
		return Num;
	else
		return fib(Num - 2) + fib(Num - 1);
}