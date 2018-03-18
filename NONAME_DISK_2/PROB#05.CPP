//Jeremy Higgins
//Setember, 6 2001
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
int Pound;
int Ounce;
int Weight;
void main()
{clrscr();
cout<<"Enter the pounds, then enter the ounces,up to 10lbs enter after each";
cout<<endl;
cout<<"Pound:";
cin>>Pound;
cout<<endl;
cout<<"Ounce:";
cin>>Ounce;
clrscr();
Weight=Pound*16+Ounce;
cout<<setprecision(2);
cout<<setiosflags(ios::showpoint);
cout<<Weight<<"  Ounces"<<endl;
cout<<setw(24)<<"Total"<<setw(25)<<"Price Per Ounce"<<endl;
cout<<"In City:"<<setw(12)<<"$"<<Weight*.15;
cout<<setw(18)<<".15 cents"<<endl;
cout<<"In State:"<<setw(11)<<"$"<<Weight*.35;
cout<<setw(18)<<".35 cents"<<endl;
cout<<"East Coast:"<<setw(9)<<"$"<<Weight*.55;
cout<<setw(18)<<".55 cents"<<endl;
cout<<"Mid West:"<<setw(11)<<"$"<<Weight*.42;
cout<<setw(18)<<".42 cents"<<endl;
cout<<"South:"<<setw(14)<<"$"<<Weight*.38;
cout<<setw(18)<<".38 cents"<<endl;
cout<<"West Coast:"<<setw(9)<<"$"<<Weight*.615;
cout<<setw(19)<<".615 cents"<<endl;
cout<<"Overseas:"<<setw(11)<<"$"<<Weight*1.07;
cout<<setw(18)<<"107 cents"<<endl;
getch();
}
