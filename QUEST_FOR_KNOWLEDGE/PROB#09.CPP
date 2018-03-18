//Michael Crookston
//Prob#09
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
//Variables
int Speed;
int Limit;
int ExtraSpeed;
double Price;
char Zone;
//Program
void main ()
{
clrscr();
cout<<setprecision(2)<<setiosflags(ios::showpoint);
cout<<"Actual speed:  ";
cin>>Speed;
cout<<endl;
cout<<"Posted legal speed limit:  ";
cin>>Limit;
cout<<endl;
cout<<"Was car in school zone (Y/N):  ";
cin>>Zone;
clrscr();
ExtraSpeed=Speed-Limit;
cout<<"The ticket will cost:  $";
if((Zone=='Y')||(Zone=='y'))
	if(ExtraSpeed<=30)
		{Price=(ExtraSpeed*6.00)+30.00;
		cout<<Price<<".";}
	else
		{Price=(ExtraSpeed*6.00)+130.00;
		cout<<Price<<".";}
else if(ExtraSpeed<=30)
			 {Price=(ExtraSpeed*3.00)+30.00;
			 cout<<Price<<".";}
		 else
			 {Price=(ExtraSpeed*3.00)+130.00;
			 cout<<Price<<".";}
cout<<endl<<endl<<"Press enter to leave the program.";
getch();


}
