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
int A;
int B;
bool Flag;
apvector<apstring> Words (20);
apmatrix<apstring> Puzzle (20, 20);
apmatrix<bool> Check (20, 20);
void main()
{clrscr();
do{//for(W=0; W<20; W++)
	 //Words[W]="aaaaw";
	 for(R=0; R<20; R++)
		 for(C=0; C<20; C++)
			 {Puzzle[C][R]=char(random(26)+65);
				Check[C][R]=false;
			 }
	 for(R=0; R<20; R++)
		{ for(C=0; C<20; C++)
			 cout<<Puzzle[C][R]<<" ";
			 cout<<endl;
		}
	for(W=0; W<20; W++)
		{ do{clrscr();
				cout<<"Please enter 20 5 letter Words"<<endl;
				cout<<"Word #"<<W<<" ";
				getline(cin, Words[W]);
				}while(Words[W].length()!=5);
		}
	 clrscr();
	 for(W=0; W<20; W++)
		{switch (random(8))
		 {case 0:do{Flag=false;
								C=random(16);
								R=random(20);
								for(I=0; I<5; I++)
								 if(Check[C+I][R]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C+I][R]=Words[W][I];
								 Check[C+I][R]=true;
								}
			break;
			case 1:do{Flag=false;
								C=random(16)+4;
								R=random(20);
								for(I=0; I<5; I++)
								 if(Check[C-I][R]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C-I][R]=Words[W][I];
								 Check[C-I][R]=true;
								}
			break;
			case 2:do{Flag=false;
								C=random(20);
								R=random(16);
								for(I=0; I<5; I++)
								 if(Check[C][R+I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C][R+I]=Words[W][I];
								 Check[C][R+I]=true;
								}
		 break;
		 case 3:do{Flag=false;
								C=random(20);
								R=random(16)+4;
								for(I=0; I<5; I++)
								 if(Check[C][R-I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C][R-I]=Words[W][I];
								 Check[C][R-I]=true;
								}
		 break;
		 case 4:do{Flag=false;
								C=random(16);
								R=random(16);
								for(I=0; I<5; I++)
								 if(Check[C+I][R+I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C+I][R+I]=Words[W][I];
								 Check[C+I][R+I]=true;
								}
		 break;
		 case 5:do{Flag=false;
								C=random(16)+4;
								R=random(16)+4;
								for(I=0; I<5; I++)
								 if(Check[C-I][R-I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C-I][R-I]=Words[W][I];
								 Check[C-I][R-I]=true;
								}
		 break;
		 case 6:do{Flag=false;
								C=random(16)+4;
								R=random(16);
								for(I=0; I<5; I++)
								 if(Check[C-I][R+I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C-I][R+I]=Words[W][I];
								 Check[C-I][R+I]=true;
								}
		 break;
		 case 7:do{Flag=false;
								C=random(16);
								R=random(16)+4;
								for(I=0; I<5; I++)
								 if(Check[C+I][R-I]==true)
										Flag=true;
							 }while(Flag);
							 for(I=0; I<5; I++)
								{Puzzle[C+I][R-I]=Words[W][I];
								 Check[C+I][R-I]=true;
								}
		 }
		}
	 for(R=0; R<20; R++)
		{for(C=0; C<20; C++)
			cout<<Puzzle[C][R]<<" ";
			 cout<<endl;
		}

		B=1;
		for(I=0; I<20; I++)
				{gotoxy(50, B);
				 cout<<Words[I]<<endl;
				 B++;
				 cout<<endl;
				}
	 cout<<"Would you like to run the Program again";
	 cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
