// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#09 ticket the person the right amount


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>



int x;
apstring y;
apstring z;
int r;


void main ()  {
clrscr();




cout<<"How many credit hours are you taking?"<<endl<<endl<<endl;
cin>>x;

cout<<"Are you a resident of the state?"<<endl<<endl<<endl;
cin>>y;

cout<<"What is your name?"<<endl<<endl<<endl;
cin>>z;

cout<<"What is your social security number?"<<endl<<endl<<endl;
cin>>r;

clrscr();
cout<<"Bill for:           "<<z<<endl<<endl<<endl;
cout<<"Credit hours:"<<setw(8)<<x<<endl<<endl<<endl;
cout<<"Resident:           "<<y<<endl<<endl<<endl;
cout<<"Amount Owed:"<<setw(9);



		 if (y=="yes")
		 if (x>12)
		cout<<"$900"<<endl<<endl<<endl;

		 if (y=="yes")
		 if (x>4)
		cout<<"$"<<x*70<<endl<<endl<<endl;

		 if (y=="yes")
		 if (x>0)
		cout<<"$"<<x*80<<endl<<endl<<endl;

		 if (y=="no")
		 if (x>12)
		cout<<"$1400"<<endl<<endl<<endl;

		 if (y=="no")
		 if (x>4)
		cout<<"$"<<x*110<<endl<<endl<<endl;

		 if (y=="no")
		 if (x>0)
		cout<<"$"<<x*120<<endl<<endl<<endl;






cout<<"Please press return to continue.";
getch();
};