// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#21 divide numbers into even and odd


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>


apvector <long> Numbers (20);
apvector <long> Even (20);
apvector <long> Odd (20);
int Number;
int I;
int J;


void main ()  {
clrscr();

I=0;
for(Number=1;Number<21;Number++)


{
Numbers[I]=Number;
I=I++;
}






J=0;


for(I=0;I<20;I++)
{
if (Numbers[I]%2!=0)
{

Odd[J]=Numbers[I];
J=J++;
}
}

J=0;

for(I=0;I<20;I++)
{
if (Numbers[I]%2==0)
{

Even[J]=Numbers[I];
J=J++;
}
}

cout<<"Even"<<endl<<endl;

for(I=0;I<10;I++)
{
cout<<Even[I]<<endl;
}

getch();

cout<<endl<<endl<<"Odd"<<endl<<endl;

for(I=0;I<10;I++)
{
cout<<Odd[I]<<endl;
}





getch();

};