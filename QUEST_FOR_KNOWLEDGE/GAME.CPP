//Michael Crookston
//GAME
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include<stdlib.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
//Structures
struct info
{int GameType;
 int NumPlayers;
 apvector <apstring> PlayerNames;
};
//Constants
//Prototypes
void gr_start (int&,int&,int&);
void convert (char String[],apstring);
int dice ();
int menu ();
void board ();
void clearstring (char String[]);
void convertchar (apstring, char String[]);
void gamepieces (void far *GamePiece[],int);
info datgath (void);
void fadein ();
void loserscreen (apstring);
void winnerscreen (int);
int questionscreen (void);
void addpieces (int,int);
void movepieces (int,int,int Coordinates[4][2],int);
int convert2 (apstring,int);
//Global Variables
char String[50];
int A,B,C,Ans;
apstring Selection,Hello,Trash;
unsigned Size;
void far *GamePiece[4];
info GameInfo;
apmatrix <apstring> Questions (200,6);
int Coordinates[4][2],PlayerTurn,NumSpaces[4];
ifstream In;
//Program

void main ()
{gr_start(A,B,C);
 randomize();
 GameInfo.GameType=menu();
 switch(GameInfo.GameType)
 {case 1:In.open("A:\\Math.txt");
				 break;
	case 2:In.open("A:\\History.txt");
				 break;
	case 3:In.open("A:\\Mixed.txt");
				 break;
	}
 GameInfo=datgath();
 clrscr();
 for(A=0;A<200;A++)
	for(B=0;B<6;B++)
		{getline(In,Questions[A][B]);
		}
 clrscr();
 gr_start(A,B,C);
 board();
 gamepieces(GamePiece,GameInfo.NumPlayers);
 getch();
 getch();
 for(A=0;A<4;A++)
	NumSpaces[A]=0;
 PlayerTurn=-1;
 do
 {if(PlayerTurn==-1)
	 PlayerTurn=0;
	else
	if(GameInfo.NumPlayers==0)
	 PlayerTurn=0;
	else if(GameInfo.NumPlayers==2)
			 {if(PlayerTurn==0)
				 PlayerTurn++;
				else
				 PlayerTurn=0;
			 }
	else if(GameInfo.NumPlayers==3)
			 {switch(PlayerTurn)
				{case 0: PlayerTurn++;
								 break;
				 case 1: PlayerTurn++;
								 break;
				 case 2: PlayerTurn=0;
								 break;
				}
			 }
	else if(GameInfo.NumPlayers==4)
			 {switch(PlayerTurn)
				{case 0: PlayerTurn++;
								 break;
				 case 1: PlayerTurn++;
								 break;
				 case 2: PlayerTurn++;
								 break;
				 case 3: PlayerTurn=0;
				}
			 }
	Ans=questionscreen();
	if(Ans==0)
	{B=dice();
	 board();
	 addpieces(PlayerTurn,GameInfo.NumPlayers);
	 clearstring(String);
	 convert(String,"You have rolled a   ");
	 settextstyle(1,0,2);
	 setcolor(15);
	 switch(B)
	 {case 1: String[19]='1';
						break;
		case 2: String[19]='2';
						break;
		case 3: String[19]='3';
						break;
		case 4: String[19]='4';
						break;
		case 5: String[19]='5';
						break;
		case 6: String[19]='6';
						break;
	 }

	 outtextxy(30,55,String);






	 NumSpaces[PlayerTurn]=NumSpaces[PlayerTurn]+B;
	 movepieces(B,PlayerTurn,Coordinates,GameInfo.NumPlayers);
	}
	else
	 loserscreen(GameInfo.PlayerNames[PlayerTurn]);
 }while(Coordinates[PlayerTurn][0]<560 && Coordinates[PlayerTurn][1]<416);
 winnerscreen(20);
 getch();
 getch();
};

void gr_start (int&grdriver,int&grmode,int&errorcode)
	{grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{clrscr();
		cout<<"Error:"<<errorcode;
		getch();
		exit(1);}
	};
void convert (char String[],apstring Sent_In)
	{int I;
	for(I=0;I<Sent_In.length();I++)
		String[I]=Sent_In[I];
	};
int dice ()
	{int I, Answer;
	Answer=random(6)+1;
	return Answer;};
int menu ()
	{int I;
	convert(String,"Quest for Knowledge");
	settextstyle(4,0,7);
	outtextxy(30,1,String);
	clearstring(String);
	convert(String,"1. Math");
	settextstyle(4,0,3);
	outtextxy(100,150,String);
	clearstring(String);
	convert(String,"2. History");
	outtextxy(100,200,String);
	clearstring(String);
	convert(String,"3. Mixed");
	outtextxy(100,250,String);
	clearstring(String);
	convert(String,"Selection:  ");
	outtextxy(100,400,String);
	clearstring(String);
	do
	{cin>>I;
	}while(I<1||I>3);
	//if(I==5);
	 //exit(1);
	cleardevice();
	return I;};
void board ()
	{int X,I;
	cleardevice();
	setfillstyle(1,WHITE);
	bar(1,1,50,50);
	X=52;
	for(I=0;I<11;I++)
		{setfillstyle(1,WHITE);
		bar(X,1,X+50,50);
		X+=52;}
	bar(X-51,52,X-1,102);
	X=1;
	for(I=0;I<12;I++)
		{bar(X,104,X+50,154);
		X+=52;}
	bar(1,156,51,206);
	X=1;
	for(I=0;I<12;I++)
		{bar(X,208,X+50,258);
		X+=52;}
	bar(X-51,260,X-1,310);
	X=1;
	for(I=0;I<12;I++)
		{bar(X,312,X+50,362);
		X+=52;}
	bar(1,364,51,414);
	X=1;
	for(I=0;I<12;I++)
		{if(I==11)
			setfillstyle(1,WHITE);
		bar(X,416,X+50,466);
		X+=52;}}
void convertchar (apstring Sent_In,char String[])
	{int I;
	 for(I=0;String[I]>0;I++)
			 Sent_In[I]=String[I];};
void clearstring (char String[])
	{int I;
	 for(I=0;I<50;I++)
			 String[I]=0;};
void gamepieces (void far *GamePiece[], int Pieces)
{char String[50];
 settextstyle(0,0,1);
 //Piece 1
 setfillstyle(1,1);
 fillellipse(14,14,9,9);
 Coordinates[0][0]=4;
 Coordinates[0][1]=5;
 clearstring(String);
 convert(String,"1");
 outtextxy(12,11,String);
 clearstring(String);
 Size=imagesize(4,5,23,23);
 GamePiece[0]=farmalloc(Size);
 getimage(4,5,23,23,GamePiece[0]);
 if(Pieces>1)
 {//Piece 2
	setfillstyle(1,2);
	fillellipse(38,14,9,9);
	Coordinates[1][0]=28;
	Coordinates[1][1]=5;
	convert(String,"2");
	outtextxy(36,11,String);
	clearstring(String);
	Size=imagesize(28,5,47,23);
	GamePiece[1]=farmalloc(Size);
	getimage(28,5,47,23,GamePiece[1]);
	if(Pieces>2)
	{//Piece 3
	 setfillstyle(1,3);
	 fillellipse(14,38,9,9);
	 Coordinates[2][0]=4;
	 Coordinates[2][1]=29;
	 convert(String,"3");
	 outtextxy(12,35,String);
	 clearstring(String);
	 Size=imagesize(4,29,23,47);
	 GamePiece[2]=farmalloc(Size);
	 getimage(4,29,23,47,GamePiece[2]);
	 if(Pieces>3)
	 {//Piece 4
		setfillstyle(1,5);
		fillellipse(38,38,9,9);
		Coordinates[3][0]=28;
		Coordinates[3][1]=28;
		convert(String,"4");
		outtextxy(35,35,String);
		clearstring(String);
		Size=imagesize(28,28,47,47);
		GamePiece[3]=farmalloc(Size);
		getimage(28,28,47,47,GamePiece[3]);}}}};
void fadein (void)
{long A;
 int X,Y;
 A=0;
 do
 {X=random(640)+1;
	Y=random(480)+1;
	if(A%2==1)
	{putpixel(X,Y,15);
	 putpixel(X+1,Y+1,15);
	 putpixel(X-1,Y-1,15);
	}
	else
	{putpixel(X,Y,15);
	 putpixel(X+1,Y-1,15);
	 putpixel(X-1,Y+1,15);
	}
	A++;
 }while(!kbhit());
 setfillstyle(1,15);
 bar(0,0,640,480);
};
void winnerscreen(int K)
	{int I,X,Y,J,L,Color;
	L=0;
	do
	{X=random(getmaxx())+1;
	Y=random(getmaxy())+1;
	Color=WHITE;
	for(I=1;I<100;I++)
		{for(J=0;J<50;J++)
			{putpixel(X+random(3*I),Y+random(3*I),Color);
			putpixel(X-random(3*I),Y-random(3*I),Color);
			putpixel(X-random(3*I),Y+random(3*I),Color);
			putpixel(X+random(3*I),Y-random(3*I),Color);}
		 cleardevice();}
	L++;}
	while(L<K);
	setcolor(YELLOW);
	settextstyle(7,0,7);
	convert(String,"Congratulations!!!!");
	outtextxy(3,1,String);
	clearstring(String);
	settextstyle(7,0,6);
	convert(String,"You WON!!!!");
	outtextxy(150,100,String);};
info datgath ()
{info Data;
 int I;
 apstring Trash;
 cleardevice();
 setcolor(0);
 floodfill(10,10,0);
 closegraph();
 do{
 clrscr();
 cout<<"How many players are playing Quest for Knowledge today? <=4"<<endl;
 cin>>Data.NumPlayers;
 }while(Data.NumPlayers>4||Data.NumPlayers<1);
 Data.PlayerNames.resize(Data.NumPlayers);

 for(I=0;I<Data.NumPlayers;I++)
 {cout<<"What is the name of player "<<I+1<<"?  (First Name only please)  ";
	getline(cin,Trash);
	cin>>Data.PlayerNames[I];
 }

return Data;
};

void loserscreen (apstring Name)
{char String[50];
 setfillstyle(1,3);
 bar(0,0,640,480);
 setcolor(7);
 setfillstyle(1,7);
 setlinestyle(0,0,3);
 line(340,330,360,400);
 line(300,330,280,400);
 setcolor(8);
 setfillstyle(1,8);
 fillellipse(320,310,50,75);
 setfillstyle(1,7);
 bar(300,330,305,400);
 bar(340,330,335,400);
 setcolor(7);
 setfillstyle(1,7);
 rectangle(285,160,355,280);
 floodfill(300,200,7);
 setcolor(1);
 setfillstyle(1,1);
 fillellipse(300,200,5,5);
 fillellipse(340,200,5,5);
 setcolor(8);
 setfillstyle(1,8);
 fillellipse(320,240,4,4);
 arc(320,260,180,360,12);
 line(295,155,260,170);
 line(260,170,245,155);
 line(245,155,295,155);
 floodfill(286,160,8);
 setcolor(8);
 setfillstyle(1,8);
 line(345,155,360,200);
 line(360,200,385,175);
 line(385,175,345,155);
 floodfill(350,160,8);
 settextstyle(3,0,4);
 clearstring(String);
 convert(String,"The Dog Says...");
 outtextxy(200,50,String);
 getch();
 setfillstyle(1,7);
 delay(750);
 bar(305,260,332,275);
 arc(320,260,200,340,12);
 delay(750);
 bar(305,260,332,275);
 arc(320,260,220,320,12);
 delay(750);
 bar(305,260,332,275);
 arc(320,260,240,300,12);
 delay(750);
 bar(305,260,332,275);
 arc(320,260,260,280,12);
 clearstring(String);
 convert(String,Name);
 outtextxy(275,400,String);
 convert(String,"is a loser!");
 outtextxy(250,425,String);
 getch();};

int questionscreen ()
{int A,B,C,D,E,Ans;
 char String[76],I;

 fadein();
 getch();

 randomize();
 do
 {A=random(200);
 }while(Questions[A][5]=="1");
 settextstyle(6,0,1);
 setcolor(0);
 clearstring(String);
 convert(String,Questions[A][0]);
 outtextxy(20,10,String);
 do
 {B=random(4)+1;
	C=random(4)+1;
	D=random(4)+1;
	E=random(4)+1;
 }while(B+C+D+E!=10 || B*C*D*E!=24);
 clearstring(String);
 convert(String,"a.)");
 outtextxy(40,40,String);
 clearstring(String);
 convert(String,"b.)");
 outtextxy(40,80,String);
 clearstring(String);
 convert(String,"c.)");
 outtextxy(40,120,String);
 clearstring(String);
 convert(String,"d.)");
 outtextxy(40,160,String);
 clearstring(String);
 convert(String,Questions[A][B]);
 outtextxy(60,40,String);
 clearstring(String);
 convert(String,Questions[A][C]);
 outtextxy(60,80,String);
 clearstring(String);
 convert(String,Questions[A][D]);
 outtextxy(60,120,String);
 clearstring(String);
 convert(String,Questions[A][E]);
 outtextxy(60,160,String);
 cin>>I;
 switch(I)
 { case 'a':
	 case 'A': if(B==1)
							Ans=0;
						 break;
	 case 'b':
	 case 'B': if(C==1)
							Ans=0;
						 break;
	 case 'c':
	 case 'C': if(D==1)
							Ans=0;
						 break;
	 case 'd':
	 case 'D': if(E==1)
							Ans=0;
						 break;
 }
 clrscr();
 return Ans;

};
void movepieces (int Dice,int Player,int Coordinates[4][2],int NumPlayers)
	{int I,X,Y;
	X=Coordinates[Player][0];
	Y=Coordinates[Player][1];
	for(I=0;I<Dice;I++)
		{cleardevice();
		board();
		addpieces(Player,NumPlayers);
		if(X<52)
			{if((Y>104 && Y<208)||(Y>312 && Y<416))
				Y+=52;
			else
				{if(Y<52||(Y>208 && Y<260)||(Y>416 && Y<468))
					X+=52;}}
		else
			if(X>52 && X<560)
				{if(Y<52||(Y>208 && Y<260)||(Y>416 && Y<468))
					X+=52;
				else
					{if((Y>104 && Y<156)||(Y>312 && Y<364))
						X-=52;}}
			else
				{if(Y<104)
						Y+=52;
					else
						if(Y>208 && Y<312)
							Y+=52;
						else
							X-=52;}
		putimage(X,Y,GamePiece[Player],COPY_PUT);
		getch();
		if(X>600 && Y>416)
			{winnerscreen(50);}}
	Coordinates[Player][0]=X;
	Coordinates[Player][1]=Y;}
void addpieces (int Player, int Number)
	{if(Player!=0)
		putimage(Coordinates[0][0],Coordinates[0][1],GamePiece[0],COPY_PUT);
	if(Player!=1 && Number>1)
		putimage(Coordinates[1][0],Coordinates[1][1],GamePiece[1],COPY_PUT);
	if(Player!=2 && Number>2)
		putimage(Coordinates[2][0],Coordinates[2][1],GamePiece[2],COPY_PUT);
	if(Player!=3 && Number>3)
		putimage(Coordinates[3][0],Coordinates[3][1],GamePiece[3],COPY_PUT);};

int convert2 (apstring Sent_In, int Element)
	{return Sent_In[Element];
	};
