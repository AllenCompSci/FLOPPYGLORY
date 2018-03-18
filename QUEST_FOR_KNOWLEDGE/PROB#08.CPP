//Michael Crookston
//Prob#08
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
int Temperature;
//Program
void main ()
{
clrscr();
cout<<"Please enter the temperature:  ";
cin>>Temperature;
clrscr();
if(Temperature>115)
	cout<<"It's too hot for anything.";
	else if((Temperature<=115)&&(Temperature>85)

			 else if((Temperature>70)&&(Temperature<=85))
			 cout<<"You should play tennis today.";
		 else if((Temperature>32)&&(Temperature<=70))
						cout<<"How about a round of golf?";
					else if((Temperature>10)&&(Temperature<=32))
								 cout<<"Try skiing.";
							 else if(Temperature<=10)
											cout<<"The only good activity is checkers.";
cout<<endl<<endl<<endl<<"Press return to exit the program.";
getch();

}
