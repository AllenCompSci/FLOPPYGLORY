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
long Disk, A, B, C;
//proto
void towers(long, long, long, long);
void main()
{clrscr();
do{cout<<"How many disks are there";
	 cin>>Disk;
	 A=1;
	 B=2;
	 C=3;

	 towers(Disk, A, B, C);







	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
void towers(long Disk, long A, long B, long C)
	 {if(Disk==1)
		 cout<<"Move disk "<<Disk<<" from Peg "<<A<<" to "<<C<<endl;



			else
			 {
				towers(Disk-1, A, B, C);
				cout<<"Move disk "<<Disk<<" from Peg "<<A<<" to "<<B<<endl;
				//towers(Disk-1, C, A, B);
				towers(Disk-1, B, A, C);
				//cout<<"Move disk "<<Disk<<" from Peg "<<A<<" to "<<B<<endl;

			 }

	 }