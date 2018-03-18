//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
//const
//var

char Choice;
int B;
int C;
int D;
int E;
apstring Trash;
apvector<apstring> Name (20);
apstring A;
void main()
{clrscr();
do{
	 cout<<"Type 20 Names or type ZZZ to stop the program";
		 D=0;
		 E=0;
		 for (B=1; B<21; B++)
		 {getline (cin, A);
			 if (A=="ZZZ")
				B=20;
					else
					 {Name.resize(B);
						 Name[D]=A;
							 D++;
							 E++;
					 }
		 }
		 clrscr();
		 for (D=0; D<127; D++)
			{for (B=0; B<E; B++)
			 {if (Name[B].length()==D)
						cout<<Name[B]<<endl;
			 }
			}







	 cout<<"Do you want to run the Program again";
	 cin>>Choice;

	}while (Choice=='Y' || Choice=='y');
}