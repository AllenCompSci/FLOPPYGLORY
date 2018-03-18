//Jon Adams && Alex Baker
//WHEEL OF FORTUNE
//3rd Period



//Library Section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <fstream.h>
#include <graphics.h>
#include <alloc.h>
#include <dos.h>
#include <ctype.h>

//Constant Section


//Structure Section
struct Player_dat
	{
	apstring Name;
	int Score;
	int Hiscore;
	};

struct Phrase_dat
	{
	apstring Phrase;
	apvector <bool> Phrasebool;
	int Catagory;
	};


//Global Variable Section
int grdriver,grmode,errorcode;
int Player_num;
int Plr;
int Money;
int Catagory;
int Round;
int P_num;
int Phel;
int Q;
int I;
int J;
int C;
apvector <Phrase_dat> Phrase_array (200);
apvector <Player_dat> Players;
apvector <bool> Alphabet (26);
apstring Phrase;
char Let;
bool Letbool;
ifstream in_file;



//Prototype Section
void gr_start (int&,int&,int&);
void alphabetbool (bool&);
void assign_phrase (int&);
void getdata (int&);
void readin ();
void menu (int);
	void getconsonant ();
	void spinwheel (int&);
	void getvowel ();
	void solve ();
void resetvar ();
void introscreen ();
void credits ();
void drawall ();
void lettersbox();
void wheelbox();
void phrasebox ();
void phraseshow ();
void drawwheel ();
void userbox (int);
void readin (apvector<Phrase_dat>&);



//Program Section
void main ()
{
int A,B;

clrscr();
gr_start(grdriver,grmode,errorcode);
cleardevice();
randomize();
readin(Phrase_array);

introscreen();
clrscr();

getdata(Player_num);

for(A=0;A<Player_num;A++)
	{
	Players[A].Score=0;
	Players[A].Hiscore=0;
	}

drawall();


//Rounds start ===============================================================



do{

	assign_phrase(P_num);

	do{

	menu(Plr);

		for(B=0;B<Phrase_array[P_num].Phrase.length();B++)
			{
			if(Phrase_array[P_num].Phrasebool[B]==true)
				{
				Phel++;
				}
			}

		}while(Phel<Phrase_array[P_num].Phrase.length()); //Round ends

	resetvar();

	}while(Round<3);

credits();


getch();
}

//****************************************************************************

//Function Section

void gr_start(int&,int&,int&)
	{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{clrscr();
		cout<<"Error:"<<errorcode<<endl;
		cout<<"Press Return to Continue.";
		getch();
		exit(1);
		}
	};

void getdata (int&)
	{
	int I;
	apstring Trash;
	clrscr();
	cleardevice();
	gotoxy(0,0);

	cout<<"Please enter the number of players (2-4): ";
	do{
		cin>>Player_num;
		}while(Player_num<2||Player_num>4);
	getline(cin,Trash);
	Players.resize(Player_num);
	cout<<endl;
	for(I=0;I<Player_num;I++)
		 {
		 cout<<"Please enter Player "<<I+1<<"'s Name (max characters=10): "<<endl;
		 do{
				getline(cin,Players[I].Name);
			 }while(Players[I].Name.length()>10||Players[I].Name.length()<1);
		 }

	clrscr();

	};

void menu (int Plr)
	{

	int Choice;

	cout<<Players[Plr].Name<<" choose an option:"<<endl;
	cout<<"1) Spin 2) Buy a Vowel 3) Solve the phrase"<<endl;
	do{
		cin>>Choice;
		}while(Choice<1||Choice>3);
	cout<<endl;

	switch(Choice-1)
		{
		case 0: getconsonant();
						break;
		case 1: getvowel();
						break;
		case 2: solve();
						break;

		}
	};

void solve ()
	{
	int A;
	int B;
	int C;

	apstring Sol;

	cout<<"Solve (include commas): ";
	do{
		getline(cin,Sol);
		}while(Sol=="");

	B=0;
	for(A=0;A<Phrase_array[P_num].Phrase.length();A++)
		{
		if(Sol[A]==Phrase_array[P_num].Phrase[A])
			{
			B++;
			}
		}

	if(B==Phrase_array[P_num].Phrase.length())
		{
		for(C=0;C<Phrase_array[P_num].Phrase.length();C++)
			{
			Phrase_array[P_num].Phrasebool=true;
			}
		}

	else
		cout<<"Incorrect.";


	};


void getvowel ()
	{

	int Z;

	cout<<"Vowel: ";

	do{
		do{
			cin>>Let;
			Let=char(toupper(Let));
			}while(Let!='A'||Let!='E'||Let!='I'||Let!='O'||Let!='U');


		alphabetbool(Letbool);

		}while(Letbool == false);

	do{
		if(Phrase_array[P_num].Phrase[Z]==Let)
			{
			Players[Plr].Score+=Money;
			Phrase_array[P_num].Phrasebool[Z]=true;
			}

		Z++;
		}while(Z<Phrase_array[P_num].Phrase.length());

	lettersbox();
	};


void getconsonant ()
	{
	int Z;

	spinwheel(Money);

	cout<<"Consonant: ";

	do{

		do{
			cin>>Let;
			Let=char(toupper(Let));
			}while(Let=='A'||Let=='E'||Let=='I'||Let=='O'||Let=='U');

		alphabetbool(Letbool);

		}while(Letbool == false);

	do{
		if(Phrase_array[P_num].Phrase[Z]==Let)
			{
			Players[Plr].Score+=Money;
			Phrase_array[P_num].Phrasebool[Z]=true;
			}

		 Z++;
		}while(Z<Phrase_array[P_num].Phrase.length());

	lettersbox();

	};



void alphabetbool (bool& Letbool)
	{

	if(Alphabet[ int(Let)-65 ] == false )
		{
		Alphabet[ int(Let)-65 ] = true;
		Letbool=true;
		}

	else
		{
		Letbool=false;
		cout<<"Letter already chosen.";
		}

	};

void credits ()
	{
	int down;

	settextstyle(8,0,7);
	outtextxy(20,0,"Wheel of Fortune");
	settextstyle(2,0,2);
	outtextxy(500,80,"(c) Jon Adams and Alex Baker");

	for(down=0;down<10;down++)
		cout<<endl;

	cout<<"Based off the concept of 'ABC's' show 'Wheel Of Fortune' ";
	cout<<endl<<endl<<endl;
	cout<<"Programming"<<endl<<endl<<"Jon Adams"<<endl<<"Alex Baker";
	cout<<endl<<endl;
	cout<<"Graphics"<<endl<<endl<<"Jon Adams";
	cout<<endl<<endl;
	cout<<"Thank You For Playing!";

	};


void resetvar ()
	{
	int A;

	for(A=0;A<Phrase_array[P_num].Phrase.length();A++)
		{
		Phrase_array[P_num].Phrasebool=false;
		}

	Plr++;
	Round++;
	Phel=0;
	for(A=0;A<26;A++)
		{
		Alphabet[A]=false;
		}
	Let=' ';
	Letbool=false;

	};



void introscreen ()
	{
	int down;


	settextstyle(8,0,7);
	outtextxy(20,0,"Wheel of Fortune");
	settextstyle(2,0,2);
	outtextxy(500,80,"copyleft Jon Adams and Alex Baker");

	for(down=0;down<15;down++)
		cout<<endl;

	cout<<"Press Any Key to Continue!";

	do{



		}while(!kbhit());

	};

void drawall ()
	{
	lettersbox ();
	wheelbox ();
	phrasebox ();
	phraseshow ();
	userbox(Player_num);
	drawwheel();
	};


void lettersbox ()
	{
	int A;
	int X;
	int Y;

	X=78;
	Y=0;

	for(A=0;A<26;A++)
		{
		Y++;
		if(A==1||A==2||A==3||A==5||A==6||A==7||A==9||A==10||A==11||A==12||A==13||A==15||A==16||A==17||A==18||A==19||A==21||A==22||A==23||A==25)
			{
			if(Alphabet[A]==false)
				{
				gotoxy(X,Y);
				cout<<char(65+A);
				}
			}
		else
			{
			Y--;
			}
		}
	X++;
	Y=0;
	for(A=0;A<26;A++)
		{
		Y++;
		if(A==0||A==4||A==8||A==14||A==20||A==24)
			{
			if(Alphabet[A]==false)
				{
				gotoxy(X,Y);
				cout<<char(65+A);
				}
			}
		else
			{
			Y--;
			}
		}
	};

void wheelbox ()
	{
	rectangle(436,0,600,204);

	};

void phrasebox ()
	{
	rectangle(0,0,436,204);

	};

void phraseshow ()
	{
	int A;
	int X;
	int Y;
	X=3;
	Y=3;

	for(A=0;A<Phrase_array[P_num].Phrase.length();A++)
		{
		if(A>10&&Phrase_array[P_num].Phrase[A])
			{
			gotoxy(X,Y);
			X++;
			}
		else
			{
			X=3;
			Y++;
			gotoxy(X,Y);
			}
		if(Phrase_array[P_num].Phrasebool[A]==false)
			{
			cout<<Phrase_array[P_num].Phrase[A];
			}
		else
			{
			cout<<" ";
			}

		}

	};

void userbox (int Player_num)
	{

	int A;
	int N;



	if(Player_num==4)
		{
		rectangle(0,300,150,479);
		rectangle(150,300,300,479);
		rectangle(300,300,450,479);
		rectangle(450,300,600,479);

		if(Players[0].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(9-N,20);
		cout<<Players[0].Name;
		gotoxy(8,22);
		cout<<"$"<<Players[0].Score;
		if(Players[1].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(27-N,20);
		cout<<Players[1].Name;
		gotoxy(27,22);
		cout<<"$"<<Players[1].Score;
		if(Players[2].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(45-N,20);
		cout<<Players[2].Name;
		gotoxy(45,22);
		cout<<"$"<<Players[2].Score;
		if(Players[3].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(63-N,20);
		cout<<Players[3].Name;
		gotoxy(63,22);
		cout<<"$"<<Players[3].Score;
		}
	else if(Player_num==3)
		{
		rectangle(0,300,200,479);
		rectangle(200,300,400,479);
		rectangle(400,300,600,479);

		if(Players[0].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(12-N,20);
		cout<<Players[0].Name;
		gotoxy(12,22);
		cout<<"$"<<Players[0].Score;
		if(Players[1].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(37-N,20);
		cout<<Players[1].Name;
		gotoxy(37,22);
		cout<<"$"<<Players[1].Score;
		if(Players[2].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(60-N,20);
		cout<<Players[2].Name;
		gotoxy(60,22);
		cout<<"$"<<Players[2].Score;
		}
	else
		{
		rectangle(0,300,300,479);
		rectangle(300,300,600,479);

		if(Players[0].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(19-N,20);
		cout<<Players[0].Name;
		gotoxy(19,22);
		cout<<"$"<<Players[0].Score;
		if(Players[1].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(54-N,20);
		cout<<Players[1].Name;
		gotoxy(54,22);
		cout<<"$"<<Players[1].Score;
		}

	};


void userinfo (int Player_num)
	{

	int A;
	int N;



	if(Player_num==4)
		{
		if(Players[0].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(9-N,20);
		cout<<Players[0].Name;
		gotoxy(8,22);
		cout<<"$"<<Players[0].Score;
		if(Players[1].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(27-N,20);
		cout<<Players[1].Name;
		gotoxy(27,22);
		cout<<"$"<<Players[1].Score;
		if(Players[2].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(45-N,20);
		cout<<Players[2].Name;
		gotoxy(45,22);
		cout<<"$"<<Players[2].Score;
		if(Players[3].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(63-N,20);
		cout<<Players[3].Name;
		gotoxy(63,22);
		cout<<"$"<<Players[3].Score;
		}
	else if(Player_num==3)
		{
		if(Players[0].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(12-N,20);
		cout<<Players[0].Name;
		gotoxy(12,22);
		cout<<"$"<<Players[0].Score;
		if(Players[1].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(37-N,20);
		cout<<Players[1].Name;
		gotoxy(37,22);
		cout<<"$"<<Players[1].Score;
		if(Players[2].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(60-N,20);
		cout<<Players[2].Name;
		gotoxy(60,22);
		cout<<"$"<<Players[2].Score;
		}
	else
		{
		if(Players[0].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(19-N,20);
		cout<<Players[0].Name;
		gotoxy(19,22);
		cout<<"$"<<Players[0].Score;
		if(Players[1].Name.length()>5)
		N=1;
		else
		N=0;
		gotoxy(54-N,20);
		cout<<Players[1].Name;
		gotoxy(54,22);
		cout<<"$"<<Players[1].Score;
		}

	};


void drawwheel()
	{

	Q=1;
	for(I=0;I<12;I++)
			{
			J=((Q+I)%12)+1;
			setfillstyle(1,J);
			pieslice(508,82,(I*30),(I*30)+30,72);
			}
	};


void spinwheel(int&Money)
{
	Q=1;
	do{
		setcolor(15);
		if(Q>12)
			Q=1;

		for(I=0;I<12;I++)
			{
			J=((Q+I)%12)+1;
			setfillstyle(1,J);
			pieslice(508,82,(I*30),(I*30)+30,72);
			}

		Q++;
		}while(!kbhit());
	Money=C*100;
};



void readin (apvector<Phrase_dat>& Phrase_array)
	{
	apstring Trash;
	int A;
	A=0;

	in_file.open("A:\\WHEEL.DAT");

	do{

		getline(in_file,Phrase_array[A].Phrase);
		in_file>>Phrase_array[A].Catagory;
		getline(in_file,Trash);
		if(!in_file.eof())
		A++;

		}while(!in_file.eof());

	in_file.close();

	};



void assign_phrase (int& P_num)
	{

	int C;


	P_num=random(200);

	for(C=0;C<Phrase_array[P_num].Phrase.length();C++)
		 {
		 if(Phrase_array[P_num].Phrase[C]==' '||Phrase_array[P_num].Phrase[C]==',')
			 {
			 Phrase_array[P_num].Phrasebool[C]=true;
			 }
		 }
	Phrase_array[P_num].Phrasebool.resize(Phrase_array[P_num].Phrase.length());

	};


