// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#20 cout 5 numbers into a 1d array


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

apvector <int> Numbers (5);
int Redo;
int I;


void main ()  {
clrscr();

do{

for(I=0;I<5;I++){
cout<<"Please enter a number."<<endl<<endl;
cin>>Numbers[I];
}
cout<<" "<<endl<<endl;


cout<<endl<<endl;
for(I=0;I<5;I++)
{
cout<<Numbers[I];
 }
cout<<" "<<endl<<endl;
for(I=4;I>=0;I--)
{
cout<<Numbers[I];
}




cout<<endl<<endl<<"Would you like to enter 5 more numbers? (1 for yes 2 for no)"<<endl<<endl;
cin>>Redo;




}
while(Redo==1);

};