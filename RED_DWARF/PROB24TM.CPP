//KRIS BICKHAM
//PROB#24
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apmatrix.h>
#include <stdlib.h>
//VARIABLES------------
int I;
int Z;
int X;
int Tickets;
int Number;
int T;
int N;
int Numbers [5][6];
apvector <int> Tn (7);
char Ans;
//CONSTANTS------------
//MAIN
void main ()
{
randomize();
do
{
clrscr ();
cout<<"How many tickets would you like (1-5)? ";
cin>>Tickets;
for(I=1;I<=Tickets;I++)       //number of tickets
 {for(N=0;N<6;N++)            //each tickets
	 {Numbers[I-1][N]=random(50)+1;	 //each of the 6 numbers
		Tn[N]=Numbers[I-1][N];
		if (N>0)
		 for(X=0;X<N;X++)
			if(Tn[X]==Numbers[I-1][N])
			 do
			 {
				Numbers[I-1][N]=random(50)+1;
				}while(Tn[X]==Numbers[I-1][N]);}}

for(I=1;I<=Tickets;I++)
{for(N=0;N<6;N++)
	 cout<<Numbers[I-1][N]<<" ";
 cout<<endl;}

cout<<"Do you want to run again? (Y/N): ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');


}

