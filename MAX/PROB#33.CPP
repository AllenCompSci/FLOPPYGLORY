// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

long fibonacci(int, int, int);
int N;
int Num1;
int Num2;
int Exit;

long Fibonacci;

void main ()  {

do{

clrscr();

cout<<"Type in a number to get the next fibonacci number for it"<<endl<<endl;
cin>>N;

Num1=1;
Num2=1;


cout<<endl<<endl<<fibonacci(N, Num1, Num2);


getch();

cout<<endl<<endl<<"Are you done? (1=no 2=yes)"<<endl<<endl;
cin>>Exit;
}
while(Exit==1);

};


long fibonacci(int N, int Num1, int Num2)
{




if(N>2)
 {

 Fibonacci=Num1+Num2;

 Num1=Num2;
 Num2=Fibonacci;
 Fibonacci=fibonacci(N-1, Num1, Num2);
 }

 else if((N==2)||(N==1))
 Fibonacci=1;
 else if(N==0)
 Fibonacci=0;

 return Fibonacci;




 }
