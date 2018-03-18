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
apvector<int> N (21);
apvector<int> Even (10);
apvector<int> Odd (10);
char Choice;
int A;
int B;
int C;
int D;
int Time;
void main()
{clrscr();
do{
	 for(A=0; A<20; A++)
	 N[A]=A+1;



	 C=0;
	 D=0;
	 for(A=0; A<20; A++)
			 {if(N[A]%2==0)
				{Even[C]=N[A];
				 C++;
				}
				else
				{Odd[D]=N[A];
				 D++;
				}
			 }
	 cout<<"Even Numbers";
	 for(C=0; C<10; C++)
		cout<<Even[C]<<endl;
		cout<<"Odd Numbers";
		for(D=0; D<10; D++)
		cout<<Odd[D]<<endl;


	 cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');

}
