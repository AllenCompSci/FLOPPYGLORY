// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

apvector <long> Numbers(30);
apvector <long> Length(30);
int Tickets;
int I,J;
int Exit;

void main ()
{
do{

clrscr();

do{
cout<<"How many tickets do you want? (1-5)"<<endl;
cin>>Tickets;
}
while((Tickets<1)||(Tickets>5));

clrscr();

J=0;
while(J<Tickets)
{

for(I=0;I<6;I++)
{
if(I==0)
{
Numbers[I]=random(50)+1;
}

Numbers[I]=random(50)+1;

}

cout<<"Ticket: ";
for(I=0;I<6;I++)
{
cout<<Numbers[I]<<"  ";
}
cout<<endl;
J=J++;
}

cout<<endl<<endl<<"Do you want to start again? (1=yes, 2=no)";
cin>>Exit;

}while(Exit==1);


};