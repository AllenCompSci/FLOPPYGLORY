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
apvector<int>A(10);
int B;
int C;
int D;
int Id;
char Choice;
void main()
{clrscr();
do{cout<<"Enter Department ID#";
	 cin>>Id;
	 cout<<endl;
	 C=0;
	 for (B=0; B<10; B++)
	 {cout<<"How many students in (Maximum is 40) "<<Id<<"0"<<C;
		cin>>A[B];
		C++;
	 }
	 clrscr();
	 if(A[0]<41 && A[1]<41 && A[2]<41 && A[3]<41 && A[4]<41 &&
	 A[5]<41 && A[6]<41 && A[7]<41 && A[8]<41 && A[9]<41)
	 {
		C=0;
		for(D=0; D<10; D++)
		 {cout<<endl<<Id<<"0"<<C<<"  "<<A[D]<<" ";
			C++;
			for(A[D]; A[D]>0; A[D]--)
			cout<<"*";
		 }
	 }
	 else
		cout<<"Too Many students in a class please run program again"<<endl;
	 cout<<endl<<"Do you want to run the program again y/n";
	 cin>>Choice;
	}while(Choice=='y' || Choice=='Y');
}
