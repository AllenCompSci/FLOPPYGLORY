//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
//const
//var
long R, X, C, Y, M, W;
char Choice;
bool Flag;
apvector<apstring> Words (20);
apmatrix<apstring> Puzzle (20, 20);
apmatrix<bool> Check (20, 20);
//proto
void size(long&, long&);
void question(long, long);
void part1(long, long, long&, long&);
void switchcase(long, long&);
void switch0(long, long, long, long&, long&, bool);
void part2(long, long, long&, long&);
void main()
{clrscr();
do{cout<<char(5);

size(X, Y);
	 question(W, M);
	 part1(R, C, X, Y);
	 clrscr();
	 switchcase(W, M);
	 part2(W,M, X,Y);














		cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
void size (long &X, long &Y)
	 {do{clrscr();
			 cout<<"How wide would you like the puzzle 2-20";
			 cin>>X;
			}while(X<2 || X>20);
		do{clrscr();
			 cout<<"How long would you like the puzzle 2-20";
			 cin>>Y;
			}while(Y<2 || Y>20);
	 }
void question (long W, long M)//, apvector<apstring> &Words)
	 {cout<<"How many words would you like";
		cin>>M;
		for(W=0; W<M; W++)
		{do{clrscr();
				cout<<"Please enter "<<M<<" "<<"2-8"<<" letter Words"<<endl;
				cout<<"Word #"<<W<<" ";
				getline(cin, Words[W]);
			 }while(Words[W].length()>9);
		}
		clrscr();
	 }
void part1(long R, long C, long &X, long &Y)
	 {for(R=0; R<X; R++)
		 for(C=0; C<Y;C++)
			 {Puzzle[C][R]=char(random(26)+65);
				Check[C][R]=false;
			 }
		for(R=0; R<X; R++)
		 {for(C=0; C<Y;C++)
			 cout<<Puzzle[C][R]<<" ";
				cout<<endl;
		 }
	 }
void switchcase(long W, long &M)//, apvector<apstring> &Words)
	{long A;
	 long Q;
	 long I;
	 long B;



 for(W=0; W<M; W++)
		{switch (random(1))
		 {case 0:switch0(W, R, C, X, Y, Flag);
			break;
			case 1:do{Flag=false;
								Q=Words[W].length();
								A=Y-Q;
								C=random(A)+Q;
								R=random(X);
								for(I=0; I<Q; I++)
								 if(Check[C-I][R]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C-I][R]=Words[W][I];
								 Check[C-I][R]=true;
								}
			break;
			case 2:do{Flag=false;
								Q=Words[W].length();
								A=Y-Q;
								C=random(Y);
								R=random(A);
								for(I=0; I<Q; I++)
								 if(Check[C][R+I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C][R+I]=Words[W][I];
								 Check[C][R+I]=true;
								}
		 break;
		 case 3:do{Flag=false;
							 Q=Words[W].length();
							 A=Y-Q;
								C=random(Y);
								R=random(A)+Q;
								for(I=0; I<Q; I++)
								 if(Check[C][R-I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C][R-I]=Words[W][I];
								 Check[C][R-I]=true;
								}
		 break;
		 case 4:do{Flag=false;
								Q=Words[W].length();
								A=Y-Q;
								C=random(A);
								R=random(A);
								for(I=0; I<Q; I++)
								 if(Check[C+I][R+I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C+I][R+I]=Words[W][I];
								 Check[C+I][R+I]=true;
								}
		 break;
		 case 5:do{Flag=false;
								Q=Words[W].length();
								A=Y-Q;
								C=random(A)+Q;
								R=random(A)+Q;
								for(I=0; I<Q; I++)
								 if(Check[C-I][R-I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C-I][R-I]=Words[W][I];
								 Check[C-I][R-I]=true;
								}
		 break;
		 case 6:do{Flag=false;
								Q=Words[W].length();
								A=Y-Q;
								C=random(A)+Q;
								R=random(A);
								for(I=0; I<Q; I++)
								 if(Check[C-I][R+I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C-I][R+I]=Words[W][I];
								 Check[C-I][R+I]=true;
								}
		 break;
		 case 7:do{Flag=false;
								Q=Words[W].length();
								A=Y-Q;
								C=random(A);
								R=random(A)+Q;
								for(I=0; I<Q; I++)
								 if(Check[C+I][R-I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<Q; I++)
								{Puzzle[C+I][R-I]=Words[W][I];
								 Check[C+I][R-I]=true;
								}
		 }
		}





	 }
void switch0(long W,long R, long C, long&X, long&Y, bool Flag)
	 {long A;
		long Q;
		long I;

		do{Flag=false;
			 Q=Words[W].length();
			 A=Y-Q;
			 C=random(A);
			 R=random(X);
			 for(I=0; I<Q; I++)
				if(Check[C+I][R]==true)
					 Flag=true;
			}while(Flag);
			for(I=0; I<Q; I++)
			 {Puzzle[C+I][R]=Words[W][I];
				Check[C+I][R]=true;
			 }



	 }
void part2 (long R, long C, long&X, long &Y)
	{long B;
	 long I;
	 for(R=0; R<X; R++)
		{for(C=0; C<Y; C++)
			cout<<Puzzle[C][R]<<" ";
			 cout<<endl;

		}

		B=1;
		for(I=0; I<M; I++)
				{gotoxy(50, B);
				 cout<<Words[I]<<endl;
				 B++;
				 cout<<endl;
				}
	}