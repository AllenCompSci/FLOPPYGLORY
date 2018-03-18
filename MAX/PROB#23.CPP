// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

int Id, Exit, I;
apvector <long> Students(11);
char A;

void main ()  {
clrscr();
do{


do {
cout<<"What is the department's ID# (0-9)?"<<endl;
cin>>Id;
}
while ((Id>9)||(Id<0));



for(I=0;I<10;I++){
do {
cout<<endl<<"How many people are in class "<<Id<<"0"<<I<<"?"<<endl;
cin>>Students[I];
}
while ((Students[I]<0)||(Students[I]>40));
}

getch();
clrscr();
cout<<"Department: "<<Id<<endl<<endl;

for(I=0;I<10;I++){
cout<<"Class: "<<Id<<"0"<<I<<"   ";
for(A=Students[I];A>0;A--){
cout<<"*";              }
cout<<"  "<<Students[I]<<endl;
}
cout<<"  "<<endl<<endl;

cout<<"Enter 1 to Exit or 2 to continue.";
cin>>Exit;
clrscr();
}
while(Exit==2);

};