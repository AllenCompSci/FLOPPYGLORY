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
//const
//var
int Tickets;
char Choice;
int A;
int B;
int C;
int K;
apvector<int> N (6);
void main()
{clrscr();
do{cout<<"How many tickets would you like, 5 is max";
		cin>>Tickets;
	 if(Tickets<6)
	 {randomize();
		for(B=0; B<Tickets; B++)
		 {for(A=0; A<6; A++)
			{N[A]=random(44)+1;
			 for(C=0; C==6; C++)
			 {for(K=0; N[0]==N[K]; K++)
				 N[A]=50;
				for(K=0; N[1]==N[K]; K++)
				 N[A]=49;
				for(K=0; N[2]==N[K]; K++)
				 N[A]=48;
				for(K=0; N[3]==N[K]; K++)
				 N[A]=47;
				for(K=0; N[4]==N[K]; K++)
				 N[A]=46;
			 }
			 cout<<N[A]<<",";

			}
			cout<<endl;
		 }
	 }
	 else
		cout<<"Too many tickets asked for, please try again"<<endl;
		cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
