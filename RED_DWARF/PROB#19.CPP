//KRIS BICKHAM
//PROGRAM NAME
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
apvector <int> Nums (5);
int Run;
//CONSTANTS
//MAIN
void main()
{
Run=0;
clrscr ();
do
 {cout<<" Enter 5 numbers (whole numbers between)";
cout<<endl;
 do
	{cout<<"Enter Number "<<Run+1<<":";
	 cin>>Nums[Run];
	 Run++;
	}while(Run<=4);
cout<<endl;
Run=0;
 do
	{cout<<"Entered Number "<<Run+1<<":";
	 cout<<Nums[Run];
	 cout<<endl;
	 Run++;
	}while(Run<=4);
Run=0;
cout<<endl;
 do
	{cout<<"Entered Number "<<5-Run<<":";
	 cout<<Nums[4-Run];
	 cout<<endl;
	 Run++;
	}while(Run<=4);
cout<<endl;
cout<<"Do you want to run again (Y/N)? ";
cin>>Ans;
}while(Ans=='y'||Ans=='Y');
getch();
}


