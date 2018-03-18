//Rebecca Russell
//6th
//Mr.Baker
//Program: Towers of Hanoi
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<stdlib.h>
//Constant
//Variable
int Num_disc, Num_disc1;
char From, To, Not;
int N;
//Prototype
void discmove (int, int);
void compmove (int, char, char, char);

void main ()
{clrscr();
cout<<setw(44)<<"Tower of Hanoi"<<endl<<endl;
cout<<"How many discs would you like on your TOWER OF HANOI: "<<endl;
cin>>Num_disc1;
clrscr();


cout<<"The tower will start on peg A and go to peg B."<<endl<<endl;
for(N=0; N<5; N++)
{cout<<setw(5)<<"|"<<setw(5)<<"|"<<setw(5)<<"|"<<endl;
}
cout<<setw(6)<<"---"<<setw(5)<<"---"<<setw(5)<<"---"<<endl;
cout<<setw(5)<<"A"<<setw(5)<<"B"<<setw(5)<<"C"<<endl;

cout<<endl<<"Hit enter to get the next: "<<endl;
compmove (Num_disc1, 'A', 'B', 'C');
cout<<"The End!!!"<<endl;


getch();
};

void discmove (int Num_disc1, char From, char To)
{cout<<"Move disc # "<<Num_disc1<<" from Tower "<<From<<" to tower "<<To<<endl;
};


void compmove (int Num_disc1, char From, char To, char Not)
{if (Num_disc1 > 0)
 {compmove(Num_disc1-1, From, Not, To);
	discmove(Num_disc1, From, To);
	compmove(Num_disc1-1, Not, To, From);
 }
};
