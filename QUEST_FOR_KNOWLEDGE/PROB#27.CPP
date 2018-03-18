//Michael Crookston
//Program Name
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
//Prototype
void verse (int);
void chorus ();
//Variables
char Again;
int I;
//Program
void main ()
{do
{clrscr();
cout<<"The Ants Go Marching";
getch();
clrscr();
for(I=0;I<10;I++)
	{clrscr();
	cout<<"Verse #"<<I+1<<endl<<endl;
	verse(I);
	cout<<endl;
	if(I<9)
		chorus();
	getch();}
clrscr();
cout<<"Do you want to do it again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
void verse (int X)
{//Local Variables
apstring Number;
apstring Stops;
switch(X)
{case 0 : Number="one";
					Stops="suck his thumb";
					break;
case 1 : Number="two";
				 Stops="tie his shoe";
				 break;
case 2 : Number="three";
				 Stops="ride a bee";
				 break;
case 3 : Number="four";
				 Stops="ask for more";
				 break;
case 4 : Number="five";
				 Stops="jump and dive";
				 break;
case 5 : Number="six";
				 Stops="pick up sticks";
				 break;
case 6 : Number="seven";
				 Stops="write with a pen";
				 break;
case 7 : Number="eight";
				 Stops="rollerskate";
				 break;
case 8 : Number="nine";
				 Stops="drink and dine";
				 break;
case 9 : Number="ten";
				 Stops="shout THE END!!";
				 break;}
cout<<"The ants go marching "<<Number<<" by "<<Number<<endl;
cout<<"Hurrah!  Hurrah!"<<endl;
cout<<"The ants go marching "<<Number<<" by "<<Number<<endl;
cout<<"Hurrah!  Hurrah!"<<endl;
cout<<"The ants go marching "<<Number<<" by "<<Number<<";"<<endl;
cout<<"The little one stops to "<<Stops<<endl;}
void chorus()
{cout<<"And they all go marching"<<endl<<"down"<<endl;
cout<<"into the ground"<<endl<<"to get out"<<endl<<"of the rain."<<endl;
cout<<"Boom, boom, boom!";}