// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#02 user defined variables shown on screen


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>


int A;
int B;
int C;
int D;


void main ()  {
clrscr();


cout<<"A=";
cin>>A;
cout<<"B=";
cin>>B;
cout<<"C=";
cin>>C;
cout<<"D=";
cin>>D;

clrscr();


cout<<setw(10)<<"First"<<setw(10)<<"Second"<<setw(10)<<"Third"<<setw(10)<<"Fourth"<<endl;
cout<<setw(10)<<A<<setw(10)<<B<<setw(10)<<C<<setw(10)<<D<<endl<<endl<<endl;

cout<<"Please press return to continue.";
getch();
};