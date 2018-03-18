//Chris Chapman
//7th
//prob34
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>

//const.section

//Prototype
void towers (char, char, char, int, int&);

//variable section
int N, Count;
char Answer, Topeg, Frompeg, Auxpeg;

void main ()
{
do{
	clrscr();

	Frompeg='A';
	Topeg='B';
	Auxpeg='C';
	Count=0;

	cout<<"Disks: ";
	cin>>N;

	towers (Frompeg, Topeg, Auxpeg, N, Count);
	cout<<"Total Moves: "<<Count<<endl;
	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

void towers (char Frompeg, char Topeg, char Auxpeg, int N, int& Count)
{

 if (N>1)
		towers (Frompeg, Auxpeg, Topeg, N-1, Count);



	cout<<"Move disk "<<N<<" from peg "<<Frompeg<<" to "<<Topeg<<endl;
	Count++;


 if (N>1)
		towers (Auxpeg, Topeg, Frompeg, N-1, Count);

};