//Michael Crookston
//PROB#13
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
int Star;
char Again;
//Program
void main ()
{
Again='Y';
do
{clrscr();
 Star=0;
	while(Star<7)
	{switch(Star)
	 {case 0:  cout<<"      *"<<endl;
						 break;
		case 1:  cout<<"    * * *"<<endl;
						 break;
		case 2:  cout<<"  * * * * *"<<endl;
						 break;
		case 3:  cout<<"* * * * * * *"<<endl;
						 break;
		case 4:  cout<<"  * * * * *"<<endl;
						 break;
		case 5:  cout<<"    * * *"<<endl;
						 break;
		case 6:  cout<<"      *"<<endl<<endl;
						 break;
	 }
	 Star++;}
 cout<<"Do you want to play again (Y/N)?  ";
 cin>>Again;}
while (Again=='Y' || Again=='y');

}
