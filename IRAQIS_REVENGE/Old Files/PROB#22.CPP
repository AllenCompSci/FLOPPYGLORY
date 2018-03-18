//Inforation Section
//Chris Chapman
//Prob22
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>

//Const Section

//Variables Section
apvector <apstring> Name (20);
apvector <int> Length (20);
int E,H,B;
char Answer;
apstring Trash;

void main ()
{
do{

	do{
		clrscr();
		cout<<"Enter names until you get tired of doing so, and then enter ZZZ."<<endl;
		getline (cin,Name[E]);
		E++;
	}while(Name[E-1]!="ZZZ" && E<20);
	clrscr();

	for (H=0;H<E;H++)
		Length[H]=Name[H].length();
	for (B=1;B<80;B++)
		for (H=0;H<E;H++)
			if (Name[H].length()==B && Name[H]!="ZZZ")
				cout<<Name[H]<<endl;

	cout<<"Run again? (Y/N)";
	cin>>Answer;
}while(Answer=='Y'||Answer=='y');
}