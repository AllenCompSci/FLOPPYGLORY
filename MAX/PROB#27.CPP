// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

double Num;
int Num2;
apstring company1;
apstring address1;

double cube (double);
int evenodd (int);
apstring header (apstring);
apstring address (apstring);

void main ()  {
clrscr();

cout<<"Please enter in a number to be cubed"<<endl<<endl;
cin>>Num;






cout<<cube(Num);
getch();
clrscr();

cout<<"Please enter in a number to see if it is even or odd"<<endl<<endl;
cin>>Num2;



// cout<<evenodd(Num2);
	if (evenodd(Num2)==1)
cout<<"Odd";
else
cout<<"Even"<<endl<<endl;

getch();
clrscr();

cout<<"Please enter the name of your company."<<endl;
cin>>company1;

cout<<endl<<"Please enter the address of your company.";
cin>>address1;

cout<<header(company1);
cout<<address(address1);





getch();

};

double cube(double Num)
	{

	 return  Num*Num*Num;


	};

int evenodd(int Num2)
	{

	 return	Num2%2;

	};

apstring header(apstring company)
	{
	int length;

	 clrscr();
	 cout<<endl<<endl;

	 length=company.length()/2;

	 if (company.length()%2==1)
	 {
	 length=length+.5;
	 }
	 length=40+length;

	 cout<<setw(length);

	 return  company;
	}

apstring address(apstring address)
	{
	 int length;

	 cout<<endl<<endl;

	 length=address.length()/2;

	 if (address.length()%2==1)
	 {
	 length=length+.5;
	 }
	 length=40+length;

	 cout<<setw(length);

	 return  address;

	}