//KRIS BICKHAM
//PROB#20
//DUE DATE
//PERIOD 6
//MR. BAKER
//LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
//VARIABLES
char Ans;
apvector <apstring> Name (20);
apvector <apstring> Other (20);
int I;
int Length;
int K;
//CONSTANTS
//MAIN
void main ()
{
do
{
clrscr ();
for(I=0;I<20;I++)
{Name[I]="";
 Other[I]="";}

Length=1;
cout<<"Enter 20 Names or ZZZ to end:"<<endl;
for(I=0;I<20;I++)
{cout<<I+1<<".) ";
 getline(cin,Name[I]);
 if (Name[I]=="ZZZ")
	 {Name[I]="";
		I=19;}}
Length=1;
K=0;
do
{for (I=0;I<20;I++)
	{if (Name[I].length()==Length)
		{Other[K]=Name[I];

		 K++;}
	}
Length++;
}while(K<20);
clrscr ();

for (I=0;I<20;I++)
 cout<<Other[I]<<endl;



cout<<endl<<"Do you want to run again (Y/N)? "<<endl;
	cin>>Ans;





}while(Ans=='Y'||Ans=='y');
getch ();
}




