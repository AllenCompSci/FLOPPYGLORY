//Kris BIckham
//Prob29
//Tuesday
//Period 6
//Mr. Baker

//Libary Section
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
//Const Section
//Varible Section
int Num;
char Ans;
//Protoypes
long factorial (int);
//Main
void main()
{
clrscr ();
cout<<endl;
do
{
cout<<"Enter a number: ";
cin>>Num;
cout<<factorial(Num);
getch ();
cout<<endl;
cout<<"Do you want to run again? ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');
};
long factorial (int Num)
{long Answer;
	if (Num==1||Num==0)
	 Answer=1;
	else
	 Answer=Num*factorial(Num-1);
	return Answer;
};
