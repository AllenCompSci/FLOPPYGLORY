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
int Speed;
int Limit;
int Zone;
int Total;
void main()
{clrscr();
cout<<"Enter Ticket Info"<<endl;
cout<<"Speed=";
cin>>Speed;
cout<<"Limit=";
cin>>Limit;
cout<<"Enter 1=yes/3=no"<<endl;
cout<<"School Zone=";
cin>>Zone;
cout<<"Total over limit="<<Speed-Limit<<endl;
Total=Speed-Limit;
if (Total>=30 && Zone<2)
	cout<<Total*6+130;
		else if (Total>=30 && Zone>2)
		cout<<Total*3+130;
		 else if (Zone<2 && Total<30)
		 cout<<Total*6+30;
			else
			cout<<Total*3+30;
cout<<endl<<"Press Return to continue";
getch();
}
