//KRIS BICKHAM
//PROB16
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
int Select;
int Late;
double Total;
int Again;
int Null;

//CONSTANTS------------
//MAIN
void main ()
{
Total=0.00;
cout<<setprecision(2)<<Total;
cout<<setiosflags(ios::showpoint);
clrscr();
cout<<setw(55)<<"[Ms. Kings Library Fine Calculator]"<<endl;
cout<<endl;
for (Again=1;Again==1;Null++)
 {cout<<"How many days has your book been late?"<<endl;
	cin>>Late;
	cout<<endl;
	cout<<"What type of book is it?"<<endl;
	cout<<"1) Paperback"<<endl;
	cout<<"2) Magazine"<<endl;
	cout<<"3) Reference"<<endl;
	cout<<"4) Other/General"<<endl;
	cin>>Select;
	cout<<endl;
				switch (Select)
	{case 1 : Total+=(.20*Late);
						break;
	 case 2 : Total+=(.35*Late);
						break;
	 case 3 : Total+=(.75*Late);
						break;
	 case 4 : Total+=(.50*Late);
						break;
	 default : break;
	}
	Late=0;
	Select=0;
	cout<<endl;
	cout<<"Enter another,"<<endl;
	cout<<"Your current total is $"<<Total;
	cout<<"(1 for Yes, 2 for No) :"<<endl;
	cin>>Again;
	clrscr();
	}
cout<<endl;
cout<<"Your final total is $"<<Total;
getch ();
}

