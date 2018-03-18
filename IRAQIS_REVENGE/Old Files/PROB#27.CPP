//Chris Chapman
//7th
//prob23
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>

//const.section

//Prototypes
void verse1 (void);
void verse2 (void);
void verse3 (void);
void verse4 (void);
void verse5 (void);
void verse6 (void);
void chorus (void);

//variable section
int E;
char Answer;
apvector <int> Numbers (15);

void main ()
{
do{
	clrscr();
	//Hello, there. Starving, how about you?
	cout<<setw(37)<<"One- U2"<<endl<<"Press any enter to continue as needed.";
	getch();
	clrscr();
	verse1();
	getch();
	clrscr();
	chorus();
	getch();
	clrscr();
	verse2();
	getch();
	clrscr();
	verse3();
	getch();
	clrscr();
	verse4();
	getch();
	clrscr();
	verse5();
	getch();
	clrscr();
	verse6();
	getch();
	clrscr();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

void verse1 ()
	{
	cout<<"Is it getting better?"<<endl;
	cout<<"Or do you feel the same"<<endl;
	cout<<"Will it make it easier on you now,"<<endl;
	cout<<"That you got somone to blame"<<endl<<"You said...";
	};

void chorus ()
	{
	cout<<"One love"<<endl<<"One life"<<endl;
	cout<<"When its one need,"<<endl<<"In the night"<<endl;
	cout<<"One love"<<endl<<"You get to share it"<<endl;
	cout<<"Leaves you baby,"<<endl<<"If you dont care for it";
	};

void verse2 ()
	{
	cout<<"Did i dissapoint you"<<endl;
	cout<<"Or leave a bad taste in your mouth"<<endl;
	cout<<"You act like you never had love,"<<endl;
	cout<<"And you want me to go without"<<endl<<"Well its...";
	};

void verse3 ()
	{
	cout<<"Too late"<<endl<<"Tonight";
	cout<<"To drag the past out into the light";
	cout<<"Were one, but were not the same"<<endl<<"We get to"<<endl;
	cout<<"Carry eachother"<<endl<<"Carry eachother"<<"One...";
	};

void verse4 ()
	{
	cout<<"Have you come here for forgivness"<<endl;
	cout<<"Have you come to raise the dead"<<endl;
	cout<<"have you come here to play Jesus"<<endl;
	cout<<"To the lepers in your head";
	};

void verse5 ()
	{
	cout<<"Did I ask too much"<<endl<<"More than a lot"<<endl;
	cout<<"You gave me nothing,"<<endl<<"Now its all I got"<<endl;
	cout<<"Were one, but were not the same"<<endl;
	cout<<"Well, we hurt eachother and we do it agian"<<endl;
	cout<<"You said..."<<endl<<"Love is a temple"<<"Love a higher law"<<endl;
	cout<<"Love is a temple"<<"Love a higher law"<<endl;
	cout<<"You ask me to enter,"<<endl<<"But then you make me crawl"<<endl;
	cout<<"And I cant keep holding on"<<endl<<"To what you got,"<<endl;
	cout<<"When all you got is hurt"<<endl;
	};

void verse6 ()
	{
	cout<<"One love"<<endl<<"One blood"<<endl<<"One life"<<endl;
	cout<<"You got to do what you should"<<endl<<"One life,"<<endl;
	cout<<"With eachother"<<endl<<"Sisters"<<endl<<"Brothers..."<<endl;
	};


