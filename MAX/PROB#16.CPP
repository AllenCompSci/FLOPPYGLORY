
// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>

double A;
int book;
double C;


void main()
{
clrscr();
cout<<setiosflags(ios::showpoint);
cout<<setprecision(2);

do
	{

cout<<"What type of book is due?"<<endl<<endl;
cout<<"1: Paperbacks"<<endl;
cout<<"2: Magazines"<<endl;
cout<<"3: Reference"<<endl;
cout<<"4: Other"<<endl;
cout<<"5: To see your total          "<<endl;
cout<<"6: exit"<<endl<<endl;

cin>>book;
cout<<endl;
if(book!=6){



switch(book)
{
case 1:cout<<"For how may days was it late?"<<endl<<endl;
			 cin>>C;cout<<"late fee for that book: $"<<0.2*C<<endl;
			 A=A+(0.2*C);break;

case 2:cout<<"For how may days was it late?"<<endl<<endl;
			 cin>>C;cout<<"late fee: $"<<0.35*C<<endl;
			 A=A+(0.35*C);break;

case 3:cout<<"For how may days was it late?"<<endl<<endl;
			 cin>>C;cout<<"late fee: $"<<0.75*C<<endl;
			 A=A+(0.75*C);break;

case 4:cout<<"For how may days was it late?"<<endl<<endl;
			 cin>>C;cout<<"late fee: $"<<0.5*C<<endl;
			 A=A+(0.5*C);break;
case 5:cout<<"the total is: $"<<A<<endl<<endl;


cout<<endl;
	};
	};

	}while(book!=6);





};