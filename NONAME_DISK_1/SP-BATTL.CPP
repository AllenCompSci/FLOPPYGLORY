// Space Battles
// Programmed By: Bryan Baker
// This is a texted based ship to ship combat simulator.

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apstring.h>
#include <string.h>
#include <dos.h>
#include <apvector.h>

int KeyPress();
void Build_Ship();
apstring Name_Ship();
void Menu_Choice();
void Item_Choice();
void Ship_Diagram(int);
void Place_Item(int);
void Init_Items();
int	Build_Number(int,int);

typedef struct Item_Rec
{	apstring	Name;
	double	Size;
	apstring	Power_Info;
	apstring	Item_Notes;
	apstring	Abrev;
};

typedef struct Box
{ apstring 	Item_Name;
	apstring  Abrev;
	bool	Active;
	int	Type;
	double	Power;
	double	Damage;
	double	Points;
};
struct Ship_Rec
{	apstring	Name;
	apstring	Type;
	apvector<Box> Space;
	int	Chassis_Weight;
	int	Max_Power;
	int Sinsors;
	int Size;
	double	Speed_Factor;
	double	Shield_Pts;
	double	Aromor_Pts;
};
int I, X, Y, Key, Point=3, Ship_Type, Choice;
double Boxs;
apvector<Item_Rec> Items;
Ship_Rec 	Ship;

void main ()
{ cout<<setprecision(2)<<setiosflags(ios::showpoint);
 textmode(C4350);
 _setcursortype(_NOCURSOR);
clrscr();
Init_Items();
Build_Ship();
//Menu_Choice();
//Ship_Diagram();
//Item_Choice();
getch();
}

int KeyPress()
{ while(!kbhit());
	return getch();
}

void Build_Ship()
{ clrscr();
	cout<<setw(12)<<"Ship Type"<<setw(15)<<"Ship Space"<<setw(15)<<"Engin Size"
			<<setw(19)<<"Chassis Weight"<<setw(17)<<"Speed Factor"<<endl<<endl;

	cout<<setw(14)<<"Light Attack"<<setw(8)<<"8"<<setw(15)<<"2"<<setw(20)
			<<"800 pts"<<setw(19)<<"0.5 to 1"<<endl;
	cout<<setw(14)<<"Heavy Attack"<<setw(8)<<"12"<<setw(15)<<"4"<<setw(20)
			<<"1200 pts"<<setw(19)<<"1 to 1"<<endl;
	cout<<setw(16)<<"Battle Crusier"<<setw(6)<<"20"<<setw(15)<<"6"<<setw(20)
			<<"2000 pts"<<setw(19)<<"1.5 to 1"<<endl;
	Point=3;
	gotoxy(2,3);
	cout<<"<";
	gotoxy(17,3);
	cout<<">";
	do{ Key=KeyPress();
			switch(Key)
				{ case 72: gotoxy(2,Point);
									 cout<<" ";
									 gotoxy(17,Point);
									 cout<<" ";
									 Point--;
									 if (Point<3)
											Point=5;
									 gotoxy(2,Point);
									 cout<<'<';
									 gotoxy(17,Point);
									 cout<<'>';
									 gotoxy(2,Point);
									 break;  // Go UP

					case 80: gotoxy(2,Point);
									 cout<<" ";
									 gotoxy(17,Point);
									 cout<<" ";
									 Point++;
									 if (Point>5)
											Point=3;
									 gotoxy(2,Point);
									 cout<<'<';
									 gotoxy(17,Point);
									 cout<<'>';
									 gotoxy(2,Point);
									 break;  // Go Down
					//case 77: cout<<"right"<<endl;break;
					//case 75: cout<<"left"<<endl;break;
					case 13: Ship_Type=Point-2;
				}

		}while(Key!=13);

			switch(Ship_Type)
				{	case 1: // Light Attack Ship
									Ship.Name=Name_Ship();
									Ship.Type="Light Attack Ship";
									Ship.Size=8;
									Ship.Space.resize(8);
									for (I=0;I<8;I++)
										Ship.Space[I].Abrev="Open";
									Ship_Diagram(Ship_Type);
									Menu_Choice();
									break;
					case 2: // Heavy Attack Ship
									Ship.Name=Name_Ship();
									Ship.Type="Heavy Attack Ship";
									Ship.Size=12;
									Ship.Space.resize(12);
									for (I=0;I<12;I++)
										Ship.Space[I].Abrev="Open";
									Ship_Diagram(Ship_Type);
									Menu_Choice();
									break;
					case 3:	// Battle Crusier
									Ship.Name=Name_Ship();
									Ship.Type="Battle Crusier";
									Ship.Size=20;
									Ship.Space.resize(20);
									for (I=0;I<20;I++)
										Ship.Space[I].Abrev="Open";
									Ship_Diagram(Ship_Type);
									Menu_Choice();
									break;
				}
}

apstring Name_Ship()
{ apstring Temp;
	do	{
				gotoxy (10,10);
				cout<<"Please enter the Name of your Ship:";
				gotoxy (46,10);
				getline(cin,Temp);
			}	while (Temp =="");
	return Temp;
}

void Menu_Choice()
{ //clrscr();
	Boxs = 0;
do{
	gotoxy(1,1);
	cout<<setw(15)<<"Menu Choice"<<endl<<endl;
	cout<<setw(21)<<"Support Sub-Systems"<<endl;
	cout<<setw(20)<<"Weapon Sub-Systems"<<endl;
	cout<<setw(19)<<"Remove Sub-System"<<endl;
	cout<<setw(17)<<"Mission Control"<<endl;
	gotoxy(2,3);
	cout<<"<";
	gotoxy(22,3);
	cout<<">";
	Point=3;
	X=22;
	Choice=1;
	do{ Key=KeyPress();
			switch(Key)
				{ case 72: gotoxy(2,Point);
									 cout<<" ";
									 gotoxy(X,Point);
									 cout<<" ";
									 Point--;
									 X++;
									 if (Point<3)
											{	Point=6;
												X=19;
											}
									 gotoxy(2,Point);
									 cout<<'<';
									 gotoxy(X,Point);
									 cout<<'>';
									 gotoxy(2,Point);
									 break;  // Go UP

					case 80: gotoxy(2,Point);
									 cout<<" ";
									 gotoxy(X,Point);
									 cout<<" ";
									 Point++;
									 X--;
									 if (Point>6)
											{	Point=3;
												X=22;
											}
									 gotoxy(2,Point);
									 cout<<'<';
									 gotoxy(X,Point);
									 cout<<'>';
									 gotoxy(2,Point);
									 break;  // Go Down
					case 13: Choice=Point-2;
				}
		}	while(Key!=13);
	switch(Choice)
		{	case 1:	Item_Choice();
							Choice=1;
							break;
			case 2: Choice=2;
							break;
			case 3: Choice=3;
							break;
		}

	}	while (Choice!=4);
}


void Item_Choice()
{
	gotoxy(25,1);
	cout<<"Item"<<setw(30)<<"Space Size"<<setw(11)<<"Power";
	for (I=0;I<13;I++)
			{	gotoxy(25,3+I);
				cout<<Items[I].Name<<setw(27-Items[I].Name.length())
						<<"  "<<Items[I].Size<<setw(16-Items[I].Power_Info.length())
						<<" "<<Items[I].Power_Info;
			}

	gotoxy(25,16);
	cout<<"Return to Menu Choice";
	gotoxy(24,3);
	cout<<"<";
	gotoxy(32,3);
	cout<<">";
	gotoxy(25,18);
	cout<<"Items Notes: Storage device: 2 power units copassity.";
	X=24;
	Y=3;
	Choice =1;
	do{ Key=KeyPress();
			switch(Key)
				{ case 72:  gotoxy(24,Y);
										cout<<" ";
										gotoxy(X,Y);
										cout<<" ";
										Y--;
										Choice--;
										if (Y<3) {Y=16;Choice=14;}
										break;// Going Up
					case 80:	gotoxy(24,Y);
										cout<<" ";
										gotoxy(X,Y);
										cout<<" ";
										Y++;
										Choice++;
										if (Y>16) {Y=3;Choice=1;}
										break;// Going Down
				}
			if (Choice<14)
				 {	gotoxy(24,Y);
						cout<<"<"<<Items[Choice-1].Name<<">";
						gotoxy(38,18);
						cout<<setw(44)<<" ";
						gotoxy(38,18);
						cout<<Items[Choice-1].Item_Notes;
						X=25+Items[Choice-1].Name.length();
				 }
			else
				 {  gotoxy(24,Y);
						cout<<"<Return to Menu Choice>";
						gotoxy(38,18);
						cout<<setw(44)<<" ";
						X=46;
				 }

		}while(Key!=13);
		if (Choice<14)
			 {	Place_Item(Choice-1);
					gotoxy(24,Y);
					cout<<" ";
					gotoxy(X,Y);
					cout<<" ";
			 }
		else
			 for (I=1; I <24;I++)
				{ gotoxy(24,I);
					cout<<setw(56)<<" ";
				}
}

void Ship_Diagram(int Type)
{ bool Flag;
	int T;
	clrscr(); //Note - Might need to take this out. or more it to first call.
	gotoxy(2,8);
	cout<<Ship.Type<<endl<<setw((Ship.Name.length())+1)<<Ship.Name;

	switch(Type)
	{	case 1:
						gotoxy(4,11);
						cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)
								<<char(203)<<char(205)<<char(205)<<char(205)<<char(205)
								<<char(187)<<endl;
						for (I=1;I<4;I++)
								{
									cout<<"   "<<char(186)<<"    "<<char(186)<<"    "
											<<char(186)<<endl;
									cout<<"   "<<char(204)<<char(205)<<char(205)<<char(205)
											<<char(205)<<char(206)<<char(205)<<char(205)<<char(205)
											<<char(205)<<char(185)<<endl;
								}
						cout<<"   "<<char(186)<<"    "<<char(186)<<"    "<<char(186)<<endl;
						cout<<"   "<<char(200)<<char(205)<<char(205)<<char(205)
								<<char(205)<<char(202)<<char(205)<<char(205)<<char(205)
								<<char(205)<<char(188)<<endl;
						Flag = true;
						break;
		case 2:
						gotoxy(4,11);
						cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)
								<<char(203)<<char(205)<<char(205)<<char(205)<<char(205)
								<<char(187)<<endl;
						for (I=1;I<6;I++)
								{
									cout<<"   "<<char(186)<<"    "<<char(186)<<"    "
											<<char(186)<<endl;
									cout<<"   "<<char(204)<<char(205)<<char(205)<<char(205)
											<<char(205)<<char(206)<<char(205)<<char(205)<<char(205)
											<<char(205)<<char(185)<<endl;
								}
						cout<<"   "<<char(186)<<"    "<<char(186)<<"    "<<char(186)<<endl;
						cout<<"   "<<char(200)<<char(205)<<char(205)<<char(205)
								<<char(205)<<char(202)<<char(205)<<char(205)<<char(205)
								<<char(205)<<char(188)<<endl;
						Flag=true;
						break;
		case 3:
		case 4:
						gotoxy(7,10);
						cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)
								<<char(203)<<char(203)<<char(205)<<char(205)<<char(205)
								<<char(205)<<char(187)<<endl;
						gotoxy(7,11);
						cout<<char(186)<<"    "<<char(186)<<char(186)<<"    "
								<<char(186)<<endl;
						gotoxy(4,12);
						cout<<char(201)<<char(205)<<char(205)<<char(202)<<char(205)
								<<char(203)<<char(203)<<char(205)<<char(202)<<char(202)
								<<char(205)<<char(203)<<char(203)<<char(205)<<char(202)
								<<char(205)<<char(205)<<char(187)<<endl;
						for (I=1;I<6;I++)
						{
							cout<<"   "<<char(186)<<"    "<<char(186)<<char(186)
									<<"    "<<char(186)<<char(186)<<"    "<<char(186)<<endl;
							cout<<"   "<<char(204)<<char(205)<<char(205)<<char(205)
									<<char(205)<<char(206)<<char(206)<<char(205)<<char(205)
									<<char(205)<<char(205)<<char(206)<<char(206)<<char(205)
									<<char(205)<<char(205)<<char(205)<<char(185)<<endl;
						}
						cout<<"   "<<char(186)<<"    "<<char(186)<<char(186)
								<<"    "<<char(186)<<char(186)<<"    "<<char(186)<<endl;
						cout<<"   "<<char(200)<<char(205)<<char(205)<<char(205)
								<<char(205)<<char(202)<<char(202)<<char(205)<<char(205)
								<<char(205)<<char(205)<<char(202)<<char(202)<<char(205)
								<<char(205)<<char(205)<<char(205)<<char(188)<<endl;

						Flag=false;
						break;

	}
	if (Flag)
		for (I=1;I<Ship.Size;I+=2)
				{
					if (I<10)
						gotoxy(3,11+I);
					else
						gotoxy(2,11+I);
					cout<<I;
					gotoxy(5,11+I);
					cout<<Ship.Space[I-1].Abrev;
					gotoxy(15,11+I);
					cout<<I+1;
					gotoxy(10,11+I);
					cout<<Ship.Space[I].Abrev;
				}
	else
		{ T=13;
			gotoxy(6,11);
			cout<<"1";
			gotoxy(8,11);
			cout<<Ship.Space[0].Abrev;
			gotoxy(19,11);
			cout<<"2";
			gotoxy(14,11);
			cout<<Ship.Space[1].Abrev;
			for (I=3;I<Ship.Size;I+=3)
					{
						if (I<10)
							gotoxy(3,T);
						else
							gotoxy(2,T);
						cout<<I;
						gotoxy(5,T);
						cout<<Ship.Space[I-1].Abrev;
						gotoxy(11,T);
						cout<<Ship.Space[I].Abrev;
						gotoxy(22,T);
						cout<<I+2;
						gotoxy(17,T);
						cout<<Ship.Space[I+1].Abrev;
						T+=2;
					}
		}

}
/***************************************************************************
 ***** 	Function Name: Place_Items																		 *****
 *****	Description: This function will place items into a ships space *****
 *****	and .																													 *****
 ***************************************************************************/

void Place_Item(int Item_Type)
{ int S_N;
	if (Boxs>= Ship.Size)
		{	gotoxy(25,20);
			cout<<"The "<<Ship.Name<<" has no more open storage boxs.";
			gotoxy(25,21);
			cout<<"You must either remove an item to make space or";
			gotoxy(25,22);
			cout<<"go on to Mission Control. Press a key to continue.";
			Key=KeyPress();
		}
	else
		{ do{	gotoxy(25,20);
					cout<<"The "<<Ship.Name<<" has ";
					if(Ship.Size-Boxs>1)
						cout<<Ship.Size-Boxs<<" storage boxs left.";
					else
						cout<<Ship.Size-Boxs<<" storage box left.";
					gotoxy(25,21);
					cout<<"Please enter the storage box number that a";
					gotoxy(25,22);
					cout<<Items[Item_Type].Name<<" is to be placed into.";
					gotoxy(48+Items[Item_Type].Name.length(),22);
					cout<<setw(80-(48+Items[Item_Type].Name.length()))<<" ";
					//gotoxy(48+Items[Item_Type].Name.length(),22);
					S_N=Build_Number(48+Items[Item_Type].Name.length(),22);
					//cin>>S_N;
				}	while ((S_N <1) || (S_N>Ship.Size));
			if (Ship.Space[S_N-1].Abrev=="Open")
				{	Boxs++;
					Ship.Space[S_N-1].Item_Name=Items[Item_Type].Name;
					Ship.Space[S_N-1].Abrev=Items[Item_Type].Abrev;
				}
			else { 	gotoxy(25,24);
							cout<<"That Box is full. Please press return to continue.";
							Key=KeyPress();
					 }
			Ship_Diagram((Ship.Size/4)-1);
		}

	for (I=20;I<24;I++)
		{	gotoxy(25,I);
			cout<<setw(55)<<" ";
		}

}
/***************************************************************************
 ***** 	Function Name: Init_Items																			 *****
 *****	Description: This function initializes the Items array to it's *****
 *****	starting values.																							 *****
 ***************************************************************************/

void Init_Items()
{ Items.resize(13);
	Items[0].Name="Battery";
	Items[0].Size=1.0;
	Items[0].Power_Info="+2 units";
	Items[0].Item_Notes="Storage device: 2 power units copassity.";
	Items[0].Abrev="B";

	Items[1].Name="Heavy Battery";
	Items[1].Size=2;
	Items[1].Power_Info="+5 units";
	Items[1].Item_Notes="Storage device: 5 power units copassity.";
	Items[1].Abrev="HB";

	Items[2].Name="Shield Box";
	Items[2].Size=1;
	Items[2].Power_Info="-2 units";
	Items[2].Item_Notes="Box which when powered +1000 chassis pts.";
	Items[2].Abrev="SB";

	Items[3].Name="Heavy Shield Box";
	Items[3].Size=2;
	Items[3].Power_Info="-3 units";
	Items[3].Item_Notes="Box which when powered +2500 chassis pts.";
	Items[3].Abrev="HSB";

	Items[4].Name="Armor";
	Items[4].Size=1;
	Items[4].Power_Info="0 units";
	Items[4].Item_Notes="Box which +500 chassis pts.";
	Items[4].Abrev="A";

	Items[5].Name="Heavy Armor";
	Items[5].Size=2;
	Items[5].Power_Info="0 units";
	Items[5].Item_Notes="Box which +1250 chassis pts.";
	Items[5].Abrev="HA";

	Items[6].Name="Regular Sensor Package";
	Items[6].Size=1;
	Items[6].Power_Info="-1 unit ";
	Items[6].Item_Notes="When powered allows ship to ship tracking.";
	Items[6].Abrev="RSP";

	Items[7].Name="Advanced Sensor Package";
	Items[7].Size=1;
	Items[7].Power_Info="-2 units";
	Items[7].Item_Notes="Upgrade: allows +50% to tracking.";
	Items[7].Abrev="ASP";

	Items[8].Name="Repair Module";
	Items[8].Size=1;
	Items[8].Power_Info="-1 unit ";
	Items[8].Item_Notes="Repairs 1 Ship's box or 100 pts of Armor.";
	Items[8].Abrev="RM";

	Items[9].Name="Nano Repair Module";
	Items[9].Size=0.5;
	Items[9].Power_Info="-3 units";
	Items[9].Item_Notes="Repairs 2 Ship's boxs or 300 pts of Armor.";
	Items[9].Abrev="NRM";

	Items[10].Name="Engine Box";
	Items[10].Size=1;
	Items[10].Power_Info="+5 units";
	Items[10].Item_Notes="Generates 5 power points a turn.";
	Items[10].Abrev="EB";

	Items[11].Name="Heavy Engine Box";
	Items[11].Size=1.5;
	Items[11].Power_Info="+8 units";
	Items[11].Item_Notes="Generates 8 power points a turn.";
	Items[11].Abrev="HEB";

	Items[12].Name="Extra Heavy Engine Box";
	Items[12].Size=3;
	Items[12].Power_Info="+20 units";
	Items[12].Item_Notes="Generates 20 power points a turn.";
	Items[12].Abrev="EHEB";

}

int Build_Number(int X1, int Y1)
{	int Value;
	do {
			//gotoxy(48+Items[Item_Type].Name.length(),22);
			gotoxy(X1,Y1);
			cout<<setw(10)<<" ";
			gotoxy(X1,Y1);
			while(!kbhit);
			Key=getche();
		 } while ((Key <48) || (Key>57));
//	 cout <<"Out One"<<endl;
	 Value=Key-48;
	 if (Value ==1)
			{	do {  gotoxy(X1+1,Y1);
						cout<<setw(10)<<" ";
						gotoxy(X1+1,Y1);
						while(!kbhit);
						Key=getche();
					 } while (((Key <48) || (Key>57))&&(Key!=13));
//				cout<<"Out Two"<<endl;
				switch(Key)
				{	case 13:	break;
					case 48:	Value=10;
										break;
					default:	Value=10+(Key-48);
				}
			}
	 else if (Value ==2)
					 {  do {    gotoxy(X1+1,Y1);
									cout<<setw(10)<<" ";
									gotoxy(X1+1,Y1);
									while(!kbhit);
									Key=getche();
								 } while ((Key!=48)&&(Key!=13));
//							cout<<"Out Three"<<endl;
							switch(Key)
							{	case 13:	break;
								case 48:	Value=20;
							}
					 }
	return Value;
}