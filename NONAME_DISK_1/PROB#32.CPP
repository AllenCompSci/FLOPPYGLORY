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

long fact (int, long&);
int Num;
long Ans;
void main()
{
clrscr();

cout<<"Enter a number."<<endl;
cin>>Num;
fact(Num, Ans);
cout<<"The Answer is: "<<Ans;





getch();
};

long fact (int Num, long & Ans)
{
int Fact;
Fact=Num;

if (Num==1)
Ans=Num;


else
		Ans=Fact * fact(Num-1, Ans);

return Ans;

}










