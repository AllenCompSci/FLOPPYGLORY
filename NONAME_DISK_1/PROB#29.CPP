//Jeff Stein
//6th Period
//Mr. Baker
//Program:
#include <iostream.h>
#include <conio.h>
#include <apstring.h>
#include <iomanip.h>
#include <apvector.h>
#include <apmatrix.h>
#include <stdlib.h>

void swap_wrong (int, int);
void swap_right (int &, int &);
int I, X, Num, Numb;

void main()
{
clrscr();


cout<<"Please enter 2 numbers."<<endl;
cin>> I;
cin>> X;

cout<<I<<" "<<X<<"   Normal swap"<<endl;
swap_wrong(I, X);
cout<<I<<" "<<X<<"   Wrong Swap"<<endl;
cout<<I<<" "<<X<<"   Numbers again"<<endl;
swap_right (I, X);
cout<<I<<" "<<X<<"   Swap Right"<<endl;
getch();
};

	void swap_wrong (int I, int X)
{

				Numb=X;
				Num=I;
				X=Num;
				I=Numb;
}
	void swap_right (int & I, int & X)
{

				Numb=I;
				Num=X;
				X=Numb;
				I=Num;
}












