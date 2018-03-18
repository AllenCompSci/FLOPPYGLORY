// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>

#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

//Constants

//Global Variables
	apmatrix <apstring> Customers(40, 4);
	apmatrix <apstring> Seats_Bought(40,30);
	apmatrix <apstring> Seat_Location(40, 30);
	apmatrix <apstring> Seat_Type(40, 30);
	apmatrix <double> Seat_Costs(40, 30);

	int MainMenu_Choice, Cust_Num, I, A;
	apstring Trash;

	ofstream Out_File;

//Prototypes
	void save_file();
	void buy_tickets(int &);
	void view_data();

void main ()
{
	for (I = 0;I < 40;I++)
		for (A = 0;A < 30;A++)
		{
			Seats_Bought[I][A] = "!";
			Seat_Costs[I][A] = 0;
		}

	do
	{
		clrscr();
		cout << "Texas Ranger's Purchasing System"<<endl;
		cout << "Make a selection:"<<endl;
		cout << "1. Buy Tickets"<<endl<< "2. View Data"<<endl;
		cout <<"3. Save and Exit"<<endl;
		cin >> MainMenu_Choice;
		switch(MainMenu_Choice)
		{
			case 1:
				buy_tickets(Cust_Num);
				break;
			case 2:
				view_data();
				break;
			case 3:
				save_file();
		}
	} while (MainMenu_Choice < 3);
}

void save_file()
{
	//This function saves all the customer's info
	//Local Vars
		int I, A;

	cout << "Saving, please wait...";
	Out_File.open("stadium.dat");
	for (I = 0;I < 40;I++)
	{
		for (A = 0;A < 4; A++)
			Out_File << Customers[I][A] << endl;
		for (A = 0; A < 30; A++)
			Out_File << Seats_Bought[I][A] << endl;
		for (A = 0; A < 30;A++)
			Out_File << Seat_Costs[I][A] << endl;
		for (A = 0; A < 30;A++)
			Out_File << Seat_Location[I][A] << endl;
		for (A = 0; A < 30;A++)
			Out_File << Seat_Type[I][A] << endl;
	}
}

void buy_tickets(int & Cust_Num)
{
	//Buys tickets...'nuff said.
	//Local Vars
		int I, MenuChoice, MenuChoice2, Num_Seats, Seat_Loc, B, C, Available;
		int Cost_Seat;
		double TotalCost, A, D;
		apstring Seat_Num;
	I = 0;
	getline(cin, Trash);
	clrscr();
	cout << "Name: ";
	getline(cin, Customers[Cust_Num][0]);
	cout << "Address: ";
	getline(cin, Customers[Cust_Num][1]);
	cout << "City, State, & Zip: ";
	getline(cin, Customers[Cust_Num][2]);
	cout << "Phone Number: ";
	getline(cin, Customers[Cust_Num][3]);
	A = 0;

	do
	{
		TotalCost = 0;
		Cost_Seat = 0;
		clrscr();
		cout << "Customer: "<<Customers[Cust_Num][0]<<endl;
		cout << "Make a selection:"<<endl;
		cout << "1. Buy Tickets" << endl << "2. View Tickets Bought" << endl;
		cout << "3. Save & Exit" << endl << "4. Cancel" << endl;
		cin >> MenuChoice;

		switch(MenuChoice)
		{
			case 1:
				clrscr();
				cout << "Make a selection:"<<endl;
				cout << "1. Single Game" << endl << "2. Month of Games" << endl;
				cout << "3. 1st half of Season" << endl << "4. 2nd half of Season";
				cout << endl << "5. Full Season" << endl << "6. Cancel" << endl;
				cin >> MenuChoice2;
				if (MenuChoice2 != 6)
				{
					cout << "How many seats do you want (Limit: " << 30 - A << ")? ";
					cin >> Num_Seats;
					if (Num_Seats <= 30 - A)
					{
						cout << "Where do you want to sit?  Make a selection:"<<endl;
						cout << "1. Nosebleed" << endl << "2. Home plate" << endl;
						cout << "3. Out Field" << endl << "4. Luxury Boxes" << endl;
						cin >> Seat_Loc;
						switch (Seat_Loc)
						{
							case 1: Cost_Seat = 15;
								break;
							case 2: Cost_Seat = 25;
								break;
							case 3: Cost_Seat = 40;
								break;
							case 4: Cost_Seat = 150;
								break;
						}
						switch (MenuChoice2)
						{
							case 2: Cost_Seat *= 2;
								break;
							case 3:
							case 4: Cost_Seat *= 3;
								break;
							case 5: Cost_Seat *= 5;
						}
						Seat_Costs[Cust_Num][I] = Cost_Seat;
						getline(cin, Trash);
						D = A;
						for(A = A;A < Num_Seats + D;A++)
						{
							Available = 0;
							cout << "Select Seat Location."<<endl;
							switch(Seat_Loc)
							{
								case 1: cout << "Rows: A-E, Seats: 1 - 20. (Ex: A 15)"<<endl;
									break;
								case 2: cout << "Rows: F-J, Seats: 1 - 20. (Ex: F 15)"<<endl;
									break;
								case 3: cout << "Rows: K-O, Seats: 1 - 20. (Ex: K 15)"<<endl;
									break;
								case 4: cout << "Rows: P-T, Seats: 1 - 20. (Ex: P 15)"<<endl;
									break;
							}
							getline(cin, Seat_Num);
							for (B = 0; B < 40; B++)
								for (C = 0;C < 30;C++)
									if (Seats_Bought[B][C] == Seat_Num)
										Available = 1;
							if (Available == 1)
							{
								cout << "Seat already taken." << endl;
								I--;
								A--;
							}
							else
							{
								Seats_Bought[Cust_Num][A] = Seat_Num;
								Seat_Costs[Cust_Num][A] = Cost_Seat;
								cout << "Done."<<endl;

								switch(Seat_Loc)
								{
									case 1: Seat_Location[Cust_Num][A] = "Nosebleed";
										break;
									case 2: Seat_Location[Cust_Num][A] = "Home Plate";
										break;
									case 3: Seat_Location[Cust_Num][A] = "Outfield";
										break;
									case 4: Seat_Location[Cust_Num][A] = "Luxury Box";
										break;
								}
								switch(MenuChoice2)
								{
									case 1: Seat_Type[Cust_Num][A] = "Single Game";
										break;
									case 2: Seat_Type[Cust_Num][A] = "Month of Games";
										break;
									case 3: Seat_Type[Cust_Num][A] = "First Half of Season";
										break;
									case 4: Seat_Type[Cust_Num][A] = "Second Half of Season";
										break;
									case 5: Seat_Type[Cust_Num][A] = "Full Season";
										break;
								}
							}
							I++;
						}
					}
					else
					{
						cout << "You can't buy that many seats!";
						getch();
					}
				}
				break;

			case 2:
				clrscr();
				cout << Customers[Cust_Num][0] << "'s Purchases:"<<endl;
				for (D = 0;D < 30;D++)
					if (Seats_Bought[Cust_Num][D] != "!")
					{
						cout << Seats_Bought[Cust_Num][D] <<"  $";
						cout << Seat_Costs[Cust_Num][D] << "  " << Seat_Location[Cust_Num][D];
						cout << ", " << Seat_Type[Cust_Num][D] << endl;

						TotalCost += Seat_Costs[Cust_Num][D];
					}

				cout << "Total Cost: $" << TotalCost;
				getch();
				break;
		}
	}while(MenuChoice < 3);

	switch(MenuChoice)
		case 4:
			for(I = 0;I < 4;I++)
				Customers[Cust_Num][I] = "";

			for(I = 0;I < 30;I++)
			{
				Seats_Bought[Cust_Num][I] = "!";
				Seat_Costs[Cust_Num][I] = 0.0;
				Seat_Location[Cust_Num][I] = "";
				Seat_Type[Cust_Num][I] = "";
			}
			Cust_Num --;

	Cust_Num++;
}

void view_data()
{
	//Local Vars
		double I, Choice, Choice2, A, B, AmountSold, TotalCost;

	clrscr();
	TotalCost = 0;
	AmountSold = 0;

	for (I = 0;I < 30;I++)
		if (Customers[I][0] != "")
			cout << I+1  << ". " << Customers[I][0] << endl;

	for (I = 20;I < 40;I++)
		if (Customers[I][0] != "")
			cout << setw (20) << I+1 << ". " << Customers[I][0] << endl;

	cout << "41. View Total Amounts Sold" << endl;
	cin >> Choice;
	if (Choice == 41)
	{
		clrscr();
		for (I = 0;I < 40;I++)
			for (A = 0;A < 30;A++)
				if (Seats_Bought[I][A] != "!")
				{
					AmountSold++;
					TotalCost += Seat_Costs[I][A];
				}

		cout << "Total Earned: $" << TotalCost << "  ";
		cout << "Total Tickets Sold: " << AmountSold;
	}
	else
	{
		clrscr();
		Choice--;
		cout << "Customer: " << Customers[Choice][0];
		cout << setw(12) << "Address: " << Customers[Choice][1] << endl;
		cout << "City, State, Zip: " << Customers[Choice][2] << endl;
		cout << "Phone #: " << Customers[Choice][3] << endl;
		for (I = 0; I < 30; I++)
			if (Seats_Bought[Choice][I] != "!")
			{
				cout << Seats_Bought[Choice][I] << "  $" << Seat_Costs[Choice][I]<<"  ";
				cout << Seat_Type[Choice][I] << ", " << Seat_Location[Choice][I];
				cout << endl;
				TotalCost += Seat_Costs[Choice][I];
			}
		cout << "Total Cost: $" << TotalCost;
	}
	getch();
}