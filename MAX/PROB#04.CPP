// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#04 Calories expended


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>

double a;
double b;
double c;

void main ()  {
clrscr();


a=2.3;
b=15.0;
c=1.7;







cout<<setw(20)<<"15 Minutes"<<setw(20)<<"30 Minutes"<<setw(20)<<"60 Minutes"<<endl<<endl<<endl;


cout<<setw(8)<<"Sleeping"<<setw(12)<<a*15<<setw(20)<<a*30<<setw(20)<<a*60<<endl<<endl;
cout<<setw(8)<<"Jogging"<<setw(12)<<b*15<<setw(20)<<b*30<<setw(20)<<b*60<<endl<<endl;
cout<<setw(8)<<"Sitting"<<setw(12)<<c*15<<setw(20)<<c*30<<setw(20)<<c*60<<endl<<endl;



cout<<"Please press return to continue.";
getch();
};