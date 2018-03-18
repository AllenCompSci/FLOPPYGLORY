//Chris Chapman
//7th
//prob#38a
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
ofstream out_file;

void main ()
{
do{
	clrscr();
	out_file.open("a:\\Prob#38.dat");
	cout<<"Enter ten numbers."<<endl;
	for(E=0;E<10;E++)
	cin>>E;
	for(K=E;K<10;K++)
	{
		out_file<<K<<" ";
		cin>>E;
	}
	out_file.close();

	cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
