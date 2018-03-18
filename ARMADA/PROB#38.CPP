//Rebecca Russell
//6th
//Mr.Baker
//Program: takes in class info
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
//Constant

//Structs

struct Studentinfo
{apvector <int> Students;
 apvector <apstring> Names;
 apvector <int> Grades;
 apvector <int> Indgrade;
};

//Variable
int G, G1, Number, I, I2, I3, I4, Gresize, Resize;
apstring Trash;
apvector <Studentinfo> Classnum;
apvector <int> Snum;

//Prototype
void question ();
void main ()
{clrscr();
question ();

 for(I4=0; I4<I; I4++)
 {for(I3=0; I3<I2; I3++)
	{cout<<Classnum[I4].Names[I3]<<endl;}
 }
getch();
};

void question ()
{do
 {cout<<"How many classes would you like to set up?"<<endl;
	cin>>I;
	Classnum.resize (I);
	clrscr();
 }
 while((I>8)||(I<1));

 for(I2=0; I2<I; I2++)
 {do
	{cout<<"How many Students are in class "<<I2+1<<" (Max. 25)?"<<endl;
	 cin>>Resize;
	 Classnum[I2].Students.resize(Resize);
	 Classnum[I2].Names.resize(Resize);
	 clrscr();
	}
	while((Resize>25)||(Resize<1));
 }

 for(G=0; G<I; G++)
 {cout<<"How many grades does class "<<G+1<<" have: "<<endl;
	cin>>Gresize;
	Classnum[G].Grades.resize(Gresize);
	Classnum[G].Indgrade.resize(Gresize);
	clrscr();
 }

 getline(cin, Trash);
 for(I4=0; I4<I; I4++)
 {for(I3=0; I3<Resize; I3++)
	{cout<<"What is the name of Student "<<I3+1<<" in class "<<I4+1<<": "<<endl;
	 getline(cin, Classnum[I4].Names[I3]);
	 clrscr();
 }}

 for(I2=0; I2<I; I2++)
 {for(I3=0; I3<Resize; I3++)
 {for(G1=0; G1<Gresize; G1++)
 {cout<<"What is the "<<I3+1<<" grade of class "<<I2+1<<" for student ";
	cout<<Classnum[I2].Names[I3]<<"?"<<endl;
	cin>>Classnum[I2].Indgrade[G1];
//	for(G1=0; G1<Gresize; G1++)
	cout<<"What is the "<<I3+2<<" grade of class "<<I2+1<<" for student ";
	cout<<Classnum[I2].Names[I3]<<"?"<<endl;
	cin>>Classnum[I2].Indgrade[G1+1];
 }}}
 }

