//Chris Chapman
//Prob#31
//7th Period
//Mr. Baker

//Library Section
#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>

//Constant Section

//Prototype Section
void get_stuff (int&,int&);
void get_more_stuff (apvector<apstring>&,long&);
void hiding (int,int,int,int,int,int,apvector<apstring>,apvector<apstring>&,apvector<apstring>&,apmatrix<bool>);
void puzzled (int,int,int,int,apvector<apstring>&,int,int,apvector<apstring>&);

//Global Variable Section
char Answer;
int X,Y,I,A,B;
long N,V;
apvector<apstring> Words (20);
apvector <apstring> Wordbank (20);
apvector <apstring> Puzzle (20);
apmatrix <bool> Check (20,20);

void main ()
{
do{
randomize();
clrscr();

get_stuff(A,B);

if (A>B)
	V=A;
	else
		V=B;

for (X=0;X<A;X++)
	for (Y=0;Y<B;Y++)
		{
		Puzzle[X]=Puzzle[X]+char(random(26)+65);
		Check[X][Y]=false;
		}

N=0;

get_more_stuff (Words, N);

clrscr();
if (Words[N-1]=="0")
	N-=1;


hiding (X,Y,I,A,B,N,Words,Wordbank,Puzzle,Check);

puzzled (X,A,Y,B,Puzzle,I,N,Wordbank);

gotoxy (1,A+2);
cout<<"Run again? (Y/N)"<<endl;
cin>>Answer;
}while (Answer=='Y'||Answer=='y');
}


void get_stuff (int& A, int& B)
	{
		cout<<"Please enter the vertical size of your puzzle (2-20)!"<<endl;
		cin>>A;
		cout<<"Please enter the horizontal size of your puzzle (2-20)!"<<endl;
		cin>>B;
	};

void get_more_stuff (apvector<apstring>& Words, long& N)
	{
		cout<<"Please enter up to 20 words! (up to 8 charcters!) don't exceed the limits!!!"<<endl;
		cout<<"If you don't have more words type 0!"<<endl;
		do{
			do{
				cout<<"Word "<<N+1<<": ";
				cin>>Words[N];
			}while (Words[N].length()>V);
			N++;
		}while (Words[N-1]!="0"&&N<20);
	};

void hiding (int X,int Y,int I,int A,int B,int N,apvector<apstring> Words,apvector<apstring>& Wordbank,apvector<apstring>& Puzzle,apmatrix<bool> Check)
	{
		//Local Variable Section
		int W,L,LC,S,LC1;
		bool Flag;


		for (W=0;W<N;)
			{
				L=Words[W].length();
				if (L>B)
					S=random(2);
				else if (L>A)
					S=random(2)+2;
						 else
							 S=random(8);

				switch (S)
					{
						case 0: LC=0;
										do{
											X=random(A-(L-1));
											Y=random(B);
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X+I][Y])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X+I][Y]=Words[W][I];
													Check[X+I][Y]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 4: LC=0;
										do{
											X=random(A-(L-1));
											Y=random(B-(L-1));
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X+I][Y+I])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X+I][Y+I]=Words[W][I];
													Check[X+I][Y+I]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 2: LC=0;
										do{
											X=random(A);
											Y=random(B-(L-1));
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X][Y+I])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X][Y+I]=Words[W][I];
													Check[X][Y+I]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 5: LC=0;
										do{
											X=random(A-L)+L-1;
											Y=random(B-(L-1));
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X-I][Y+I])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X-I][Y+I]=Words[W][I];
													Check[X-I][Y+I]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 1: LC=0;
										do{
											X=random(A-L)+L-1;
											Y=random(B);
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X-I][Y])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X-I][Y]=Words[W][I];
													Check[X-I][Y]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 6: LC=0;
										do{
											X=random(A-L)+L-1;
											Y=random(B-L)+L-1;
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X-I][Y-I])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X-I][Y-I]=Words[W][I];
													Check[X-I][Y-I]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 3: LC=0;
										do{
											X=random(A);
											Y=random(B-L)+L-1;
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X][Y-I])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X][Y-I]=Words[W][I];
													Check[X][Y-I]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

						case 7: LC=0;
										do{
											X=random(A-(L-1));
											Y=random(B-L)+L-1;
											Flag=false;
											for (I=0;I<L;I++)
												if (Check[X+I][Y-I])
													Flag=true;
											LC++;
											}while (Flag&&LC<A*B);
										if (LC<A*B)
											for (I=0;I<L;I++)
												{
													Puzzle[X+I][Y-I]=Words[W][I];
													Check[X+I][Y-I]=true;
													Wordbank[W]=Words[W];
												}
										else
											LC1++;
										break;

					}

				if (Flag==false||LC1==100)
					{
							W++;
							LC1=0;
					}
			}

	};

void puzzled (int X,int A,int Y,int B,apvector<apstring>& Puzzle,int I,int N,apvector<apstring>&Wordbank)
	{
		for (X=0;X<A;X++)
			{
				for (Y=0;Y<B;Y++)
					cout<<Puzzle[X][Y]<<' ';
				cout<<endl;
			}

		for (I=0;I<N;I++)
			{
				gotoxy(2*B+5,I+1);
				cout<<Wordbank[I];
			}

		cout<<endl<<endl;

		for (X=0;X<A;X++)
			{
				Puzzle[X]="";
				Wordbank[X]="";
			}
	};



