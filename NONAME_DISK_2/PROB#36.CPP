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
//struct
struct info2
{apvector <int> Grade;
 apstring Name;
};
struct info
{apvector <info2> Student;
};
//const
//var
char Choice;
apvector <info> Class (8);
//proto
void Question();
void main()
{clrscr();
do{
	 Question();
	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
void Question()
	 {int A, B, C, D, E, F, H;
		cout<<"How many classes";
		cin>>C;
		for(B=0;B<C;B++)
		{cout<<"How many Students in class "<<B+1;
		 cin>>A;
		 Class[B].Student.resize(A);
		 for(D=0; D<A; D++)
		 {cout<<"Enter name of student "<<D+1<<" in class "<<B+1;
			cin>>Class[B].Student[D].Name;
		 }
		 cout<<"How many grades in class "<<B+1;
		 cin>>E;
		 for(D=0; D<A; D++)
		 Class[B].Student[D].Grade.resize(E);
		 for(D=0; D<A; D++)
		 for(F=0; F<E; F++)
		 {
		 cout<<"Enter Grades for class "<<B+1<<" student "<<D+1;
		 cin>>Class[B].Student[D].Grade[F];
		 }
		}
			do{cout<<"Which Class would you like to see, enter # for class, ( to stop";
				 cin>>C;
				 clrscr();
				 cout<<C<<endl;
				 for(B=0; B<A; B++)
				 {cout<<Class[C].Student[B].Name<<" ";
					for(D=0; D<E; D++)
					 cout<<Class[C].Student[B].Grade[D]<<" ";
					cout<<endl;
				 }
				}while(C!=9);
		}