//Kris BIckham
//Prob30
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
long fibonacci (int);
//Main
void main()
{clrscr ();
cout<<endl;
do
{
cout<<"Enter a number: ";
cin>>Num;
cout<<fibonacci(Num);
getch ();
cout<<endl;
cout<<"Do you want to run again? ";
cin>>Ans;
clrscr ();
}while(Ans=='Y'||Ans=='y');
};

long fibonacci (int Num)
{long Answer;
if (Num==1||Num==0)
	Answer=Num;
else if (Num==2||Num==3)
	Answer=1;
else
	Answer=fibonacci(Num-1)+fibonacci(Num-2);
return Answer;};




