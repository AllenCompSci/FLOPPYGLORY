// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<fstream.h>
//constants



//structure



//variables
int I;
double Numbers;

ofstream file;

//prototypes




void main ()  {

clrscr();

file.open("A:\\myfile");

for(I=0;I<10;I++)
{
cout<<"Type in a number.  ";
cin>>Numbers;


file<<Numbers<<endl;
}


getch();

};
