//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<graphics.h>
#include<stdlib.h>
#include<fstream.h>
//struct

//const
//var
apstring Tree, Trash;
long Num, A, B, C;

ifstream in;

int grdriver, grmode, errorcode;
char Choice;
//proto
void gr_start(int&, int&, int&);
void main()
{clrscr();
do{
	 gr_start(grdriver, grmode, errorcode);
	 in.open("a:\\TREES.dat");
	 A=5;
	 B=10;
	 while(!in.eof())
	 {
	 getline(in, Tree);
	 in>>Num;
	 cout<<setw(80)<<Tree<<Num<<endl;
	 A+=27;
	 B+=27;

	 Num/=2;
	 getline(in, Trash);
	 setcolor(1);
	 rectangle(0, A, Num, B);
	 }









	cout<<endl<<endl<<endl<<endl;
	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}

void gr_start(int &grdriver,int &grmode, int &errorcode)
{grdriver=VGA;
 grmode=VGAHI;

 initgraph(&grdriver, &grmode,"C:\\TC\\BGI");
 errorcode=graphresult();

 if(errorcode!=grOk)
	 {clrscr();
		cout<<"Error"<<errorcode<<endl;
		cout<<"Press Return to continue";
		getch();
		exit(1);
	 }

}