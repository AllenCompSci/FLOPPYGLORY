// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>

double Don;
int Day;
double t;

void main ()
{
clrscr();
cout<<setiosflags(ios::fixed);

Don=0.005;
for(Day=1;Day<21;Day++)
{Don=Don*2;

t=t+Don;
cout<<"Day "<<Day<<"  Donation total: $"<<t<<endl;
}

cout<<endl<<endl<<"Total= $"<<t<<endl;
getch();
};

