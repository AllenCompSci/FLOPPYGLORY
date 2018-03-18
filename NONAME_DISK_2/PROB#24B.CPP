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
char Choice;
long R;
long W;
long C;
long I;
long X;
long A;
long Y;
long Q;
long B;
long M;
bool Flag;
apstring Trash;
apvector<apstring> Words (20);
apmatrix<apstring> Puzzle (20, 20);
apmatrix<bool> Check (20, 20);
void main()
{clrscr();
do{cout<<"How Many Words Would you like";
	 cin>>M;


	 //for(W=0; W<M; W++)
	 //Words[W]="abcde";

	 cout<<endl<<"How long would you like the X axis to be";
	 cin>>X;
	 cout<<endl<<"How long would you like the Y axis to be";
	 cin>>Y;
	 getline(cin, Trash);
	 for(R=0; R<X; R++)
		 for(C=0; C<Y; C++)
			 {Puzzle[C][R]=char(random(26)+65);
				Check[C][R]=false;
			 }
	 for(R=0; R<X; R++)
		{ for(C=0; C<Y; C++)
			 cout<<Puzzle[C][R]<<" ";
			 cout<<endl;
		}

	for(W=0; W<M; W++)
		{ do{clrscr();
				 cout<<"Please enter "<<M<<" "<<"2-8"<<" letter Words"<<endl;
				 cout<<"Word #"<<W<<" ";
				 getline(cin, Words[W]);
				}while(Words[W].length()>9);
		}
	 clrscr();

	 for(W=0; W<M; W++)

		{switch (random(8))
		 {case 0:do{Flag=false;
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
	 gotoxy(2, 21);
	 cout<<"Would you like to run the Program again";
	 cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
