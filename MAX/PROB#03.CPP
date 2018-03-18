// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>

double a;
double b;
double c;
double d;

void main ()  {
clrscr();


a=35.00;
b=28.50;
c=22.95;
d=12.25;







cout<<setw(20)<<"Before Sale"<<setw(20)<<"After Sale"<<endl<<endl<<endl;


cout<<setw(8)<<"Sweater"<<setw(12)<<"$"<<a<<setw(12)<<"$"<<a*.85<<endl<<endl;
cout<<setw(8)<<"Skirt"<<setw(12)<<"$"<<b<<setw(12)<<"$"<<b*.85<<endl<<endl;
cout<<setw(8)<<"Blouse"<<setw(12)<<"$"<<c<<setw(12)<<"$"<<c*.85<<endl<<endl;
cout<<setw(8)<<"Bracelet"<<setw(12)<<"$"<<d<<setw(12)<<"$"<<d<<endl<<endl<<endl<<endl<<endl;


cout<<"Please press return to continue.";
getch();
};