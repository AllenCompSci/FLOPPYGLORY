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
apstring Address;
apstring Phone;
int Package;
int Seats;
int Where;
int Amount;
int Plan;
void main()
{clrscr();
cout<<setw(40)<<"Tickets"<<endl<<"Please Enter Name= ";
cin>>Name;
cout<<"Please Enter Address= ";
cin>>Address;
cout<<"Please Enter Phone Number= ";
cin>>Phone;
cout<<"Please Enter Number Of Seats";
cin>>Seats;
cout<<"Please Choose Tickets"<<endl;

cout<<"Package=";
cin>>Package;
switch (Package)
{
case 1:Plan=1;
break;
case 2:Plan=2;
break;
case 3:Plan=15;
break;
case 4:Plan=30;
break;
case 5:Plan=45;
break;
case 6:Plan=80;
}
cout<<"Choose where the Seats will be"<<endl;
cout<<"1=Home Plate $45 each"<<endl<<"2=Out Field $20 each"<<endl;
cout<<"3=2nd level $25 each"<<endl<<"4=3rd level $10 each"<<endl;
cout<<"Seats=";
cin>>Where;
switch (Where)
{
case 1:Amount=45;
break;
case 2:Amount=20;
break;
case 3:Amount=25;
break;
case 4:Amount=10;
}
clrscr();
cout<<"Ticket Package="<<Package<<" "<<Plan<<"Games"<<endl;
cout<<Seats*Amount*Plan<<"=Total Cost Of Tickets";




getch();
}
