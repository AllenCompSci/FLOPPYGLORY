//Kris BIckham
//Prob32B
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
char Ans;
int I;
int B;
apvector <int> Nums (10);
ifstream Load;
//Protoypes
//Main
void main()
{
do
{
B=0;
clrscr ();
Load.open("List.txt");
I=1;
do
{
cout<<"Word "<<I<<" you entered was: ";
 Load>>B;
 cout<<B<<endl;
 I++;
}while(!Load.fail());
cout<<"Do you want to run again? ";
cin>>Ans;
clrscr ();
Load.close();
}while(Ans=='Y'||Ans=='y');
};



