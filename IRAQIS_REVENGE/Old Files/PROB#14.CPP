//Chris Chapman
//shell
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const.section

//variable section
char Answer;
apstring Name;

void main ()
{
clrscr();

do{
	do{
	cout<<"Enter a name, or type ZZZ to leave"<<endl;
	getline (cin, Name);
		}while (Name!="ZZZ");
	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
