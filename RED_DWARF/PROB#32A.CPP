//Kris BIckham
//Prob32A
//Tuesday
//Period 6
//Mr. Baker
//Libary Section
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
//Const Section
//Varible Section
ofstream Store;
apvector <int> Nums (10);
char Ans;
int I;
//Protoypes

//Main
void main()
{
clrscr ();
Store.open("List.txt");
do
{
cout<<"Enter 10 numbers to save to a file:"<<endl;
for(I=0;I<10;I++)
{cout<<"Word "<<I+1<<": ";
 cin>>Nums[I];
 Store<<Nums[I]<<endl;}

cout<<"Do you want to run again? ";
cin>>Ans;
clrscr ();
}while(Ans=='Y'||Ans=='y');
Store.close ();
};




