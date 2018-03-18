// Mahmood Subhani
// Period 6
// Mr. Baker
// star on the screen using while statement


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>


apstring a;
int c;

void main ()
{
a="*";
c=3;
clrscr();

while(c<4) {
cout<<setw(7)<<a<<endl
<<setw(5)<<a<<setw(2)<<a<<setw(2)<<a<<endl
<<setw(3)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<endl
<<setw(1)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<endl;
cout<<setw(3)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<setw(2)<<a<<endl
<<setw(5)<<a<<setw(2)<<a<<setw(2)<<a<<endl
<<setw(7)<<a<<endl;


break; }

cout<<"Please press return to continue.";
getch();
};