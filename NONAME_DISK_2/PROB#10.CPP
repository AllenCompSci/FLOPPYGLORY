//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
apstring Name;
int Number;
int Hours;
int Res;
void main()
{clrscr();
cout<<"Students Name=";
cin>>Name;
cout<<"Social Security Number=";
cin>>Number;
cout<<"Credit Hours=";
cin>>Hours;
cout<<"Residency Status 1 for y/3 for n"<<endl;
cin>>Res;
clrscr();
cout<<"Bill for:"<<Name<<endl;
cout<<"Credit Hours:"<<Hours<<endl;
cout<<"Resident:"<<Res<<endl;
cout<<"Amount Owed:";
if (Res<2 && Hours<=4)
	cout<<Hours*80;
	 else if (Res<2 && Hours<=12)
	 cout<<Hours*70;
		 else if (Hours>12 && Res<2)
		 cout<<"900";
			else if (Hours<=4 && Res>2)
			cout<<Hours*120;
				else if (Res>2 && Hours<=12)
				cout<<Hours*110;
					else
					cout<<"1400";
cout<<"Press Enter to continue";
getch();
}
