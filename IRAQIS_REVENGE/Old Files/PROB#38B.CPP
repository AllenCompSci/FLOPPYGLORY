//Chris Chapman
//7th
//prob#38b
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<fstream.h>

//const.section

//struct section

//Prototype

//global variable section
int E,K;
char Answer;
ifstream in_file;

void main ()
{
do{
	//almost lunch time :D
	clrscr();
	in_file.open("a:\\Prob#38.dat");
	in_file>>E;
	for(K=E;K<10;K++)
	{
		cout<<K<<endl;
		in_file>>E;
	}
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
