//Toni Whipple
//Prob#3
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>

//const.section
const double Dis=.85;

//variable section

void main()

{
clrscr();
cout<<setiosflags(ios::showpoint);
cout<<setprecision(2);


cout<<setw(25)<<"Regular_Price";
cout<<setw(10);
cout<<setw(20);
cout<<"Discount_Price"<<endl;
cout<<"Sweater";
cout<<setw(15);
cout<<"$35.00";
cout<<setw(10);
cout<<"$";
cout<<35.00*Dis<<endl;
cout<<"Skirt";
cout<<setw(17);
cout<<"$28.50";
cout<<setw(10);
cout<<"$";
cout<<28.50*Dis<<endl;
cout<<"Blouse";
cout<<setw(16);
cout<<"$22.95";
cout<<setw(10);
cout<<"$";
cout<<22.95*Dis<<endl;
cout<<"Bracelet";
cout<<setw(14);
cout<<"$12.25";
cout<<setw(10);
cout<<"$";
cout<<"12.25"<<endl;
cout<<setw(10);
cout<<"Total       ";
cout<<setw(5);
cout<<"$";
cout<<35+28.50+22.95+12.25;
cout<<setw(10);
cout<<"$";
cout<<29.75+24.22+19.54+12.25;
getch();
		 }
