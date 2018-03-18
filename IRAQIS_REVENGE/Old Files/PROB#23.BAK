//Inforation Section
//Chris Chapman
//Prob23
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apmatrix.h>

//Const Section

//Variables Section
char Answer;
int Dep, C, E, L, Smallest, Temp, Class_num;
apvector <int> Class (10);
void main ()

{
do{
	clrscr();
	cout<<"Please enter your Department number! (0-9)"<<endl;
	cin>>Dep;
	cout<<"Please enter the number of students in each room!";
	cout<<" (cannot be greater than 40!)"<<endl;
	for (C=0;C<=9;C++)
			{
			cout<<"Class "<<Dep<<'0'<<C<<": ";
			switch (C)
			{
			case 0 : do{
							 (cin, Class[0]);
							 if (Class[0]<40)
							 cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[0]>40);
							 break;
			case 1 : do{
							 (cin,Class[1]);
							 if (Class[1]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[1]<40);
							 break;
			case 2 : do{
							 (cin,Class[2]);
							 if (Class[2]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[2]>40);
							 break;
			case 3 : do{
							 (cin,Class[3]);
							 if (Class[3]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[3]<40);
							 break;
			case 4 : do{
							 (cin,Class[4]);
							 if (Class[4]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[4]>40);
							 break;
			case 5 : do{
							 (cin,Class[5]);
							 if (Class[5]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[5]<40);
							 break;
			case 6 : do{
							 (cin,Class[6]);
							 if (Class[6]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[6]>40);
							 break;
			case 7 : do{
							 (cin,Class[7]);
							 if (Class[7]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[7]<40);
							 break;
			case 8 : do{
							 (cin,Class[8]);
							 if (Class[8]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[8]>40);
							 break;
			case 9 : do{
							 (cin,Class[9]);
							 if (Class[9]>40);
									cout<<"Class "<<Dep<<'0'<<C<<": ";
							 }while (Class[9]<40);
			}
			}

	C=0;
	E=0;
	for (C=0;C<Class_num;C++)
				{Smallest=Class[C];
					for(E=C=1;E<Class_num;E++)
						if (Class[E]<Smallest)
						{
						Temp=Class[C];
						Class[C]=Class[E];
						Class[E]=Temp;
						}
						}
			gotoxy (1,C+1);
			cout<<Dep<<'0'<<C;
			switch (C)
			case 0: cout<<Dep<<'0';
							for(L=Class[1];L<Class[1];L++)
							cout<<'*';
							break;
	getch();
	cout<<endl<<"Run again? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}