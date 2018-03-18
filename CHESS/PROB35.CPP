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

//Structures
	struct Cust_Data
	{
		apstring Name;
		apstring Address;
		apstring Phone;
		apstring City_State;
	};
	struct Seat_Vars
	{
		apstring Seats_Bought, Seat_Location, Seat_Type;
		double Seat_Costs;
	};
	struct Customer
	{
		Cust_Data Personal_Data;
		apvector <Seat_Vars> Seat_Data;
	};

//Constants

//Global Variables
	apvector <Customer> Customers(40);

	int MainMenu_Choice, Cust_Num, I, A;
	apstring Trash;

	ofstream Out_File;

//Prototypes
	void save_file();
	void buy_tickets(int &);
	void view_data();

void main ()
{
	for(I = 0;I < 40; I++)
	{
		Customers[I].Seat_Data.resize(30);
	}

	for (I = 0;I < 40;I++)
		for (A = 0;A < 30;A++)
		{
			Customers[I].Seat_Data[A].Seats_Bought = "!";
			Customers[I].Seat_Data[A].Seat_Costs = 0;
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
		Out_File << Customers[I].Personal_Data.Name << endl;
		Out_File << Customers[I].Personal_Data.Address << endl;
		Out_File << Customers[I].Personal_Data.City_State << endl;
		Out_File << Customers[I].Personal_Data.Phone << endl;
		for (A = 0; A < 30; A++)
		{
			Out_File << Customers[I].Seat_Data[A].Seats_Bought << endl;
			Out_File << Customers[I].Seat_Data[A].Seat_Costs << endl;
			Out_File << Customers[I].Seat_Data[A].Seat_Location << endl;
			Out_File << Customers[I].Seat_Data[A].Seat_Type << endl;
		}
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
	getline(cin, Customers[Cust_Num].Personal_Data.Name);
	cout << "Address: ";
	getline(cin, Customers[Cust_Num].Personal_Data.Address);
	cout << "City, State, & Zip: ";
	getline(cin, Customers[Cust_Num].Personal_Data.City_State);
	cout << "Phone Number: ";
	getline(cin, Customers[Cust_Num].Personal_Data.Phone);
	A = 0;

	do
	{
		TotalCost = 0;
		Cost_Seat = 0;
		clrscr();
		cout << "Customer: "<<Customers[Cust_Num].Personal_Data.Name<<endl;
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
						Customers[Cust_Num].Seat_Data[I].Seat_Costs = Cost_Seat;
						getline(cin, Trash);
						D = A;
						for(A = A;A < Num_Seats + D;A++)
						{
							Available = 1;
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
							}
							getline(cin, Seat_Num);
							for (B = 0; B < 40; B++)
								for (C = 0;C < 30;C++)
									if (Customers[B].Seat_Data[C].Seats_Bought == Seat_Num)
										Available = 0;

							if (! Available)
							{
								cout << "Seat already taken." << endl;
								I--;
								A--;
							}
							else
							{
								Customers[Cust_Num].Seat_Data[A].Seats_Bought = Seat_Num;
								Customers[Cust_Num].Seat_Data[A].Seat_Costs = Cost_Seat;
								cout << "Done."<<endl;

								switch(Seat_Loc)
								{
									case 1: Customers[Cust_Num].Seat_Data[A].Seat_Location = "Nosebleed";
										break;
									case 2: Customers[Cust_Num].Seat_Data[A].Seat_Location = "Home Plate";
										break;
									case 3: Customers[Cust_Num].Seat_Data[A].Seat_Location = "Outfield";
										break;
									case 4: Customers[Cust_Num].Seat_Data[A].Seat_Location = "Luxury Box";
								}
								switch(MenuChoice2)
								{
									case 1: Customers[Cust_Num].Seat_Data[A].Seat_Type = "Single Game";
										break;
									case 2: Customers[Cust_Num].Seat_Data[A].Seat_Type = "Month of Games";
										break;
									case 3: Customers[Cust_Num].Seat_Data[A].Seat_Type = "First Half of Season";
										break;
									case 4: Customers[Cust_Num].Seat_Data[A].Seat_Type = "Second Half of Season";
										break;
									case 5: Customers[Cust_Num].Seat_Data[A].Seat_Type = "Full Season";
								}
							}
							I++;
						}
					}
					else
						cout << "You can't buy that many seats!";

					cout << endl << "Press a key to continue.";
					getch();
				}
				break;

			case 2:
				clrscr();
				cout << Customers[Cust_Num].Personal_Data.Name << "'s Purchases:"<<endl;
				for (D = 0;D < 30;D++)
					if (Customers[Cust_Num].Seat_Data[D].Seats_Bought != "!")
					{
						cout << Customers[Cust_Num].Seat_Data[D].Seats_Bought <<"  $";
						cout << Customers[Cust_Num].Seat_Data[D].Seat_Costs << "  " << Customers[Cust_Num].Seat_Data[D].Seat_Location;
						cout << ", " << Customers[Cust_Num].Seat_Data[D].Seat_Type << endl;

						TotalCost += Customers[Cust_Num].Seat_Data[D].Seat_Costs;
					}

				cout << "Total Cost: $" << TotalCost;
				getch();
				break;
		}
	}while(MenuChoice < 3);

	if (MenuChoice == 4)
	{
		Customers[Cust_Num].Personal_Data.Name = "";
		Customers[Cust_Num].Personal_Data.Address = "";
		Customers[Cust_Num].Personal_Data.City_State = "";
		Customers[Cust_Num].Personal_Data.Phone = "";
		for(I = 0;I < 30;I++)
		{
			Customers[Cust_Num].Seat_Data[I].Seats_Bought = "!";
			Customers[Cust_Num].Seat_Data[I].Seat_Costs = 0.0;
			Customers[Cust_Num].Seat_Data[I].Seat_Location = "";
			Customers[Cust_Num].Seat_Data[I].Seat_Type = "";
		}
		Cust_Num --;
	}

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
		if (Customers[I].Personal_Data.Name != "")
			cout << I+1  << ". " << Customers[I].Personal_Data.Name << endl;

	for (I = 20;I < 40;I++)
		if (Customers[I].Personal_Data.Name != "")
			cout << setw (20) << I+1 << ". " << Customers[I].Personal_Data.Name << endl;

	cout << "41. View Total Amounts Sold" << endl;
	cin >> Choice;
	if (Choice == 41)
	{
		clrscr();
		for (I = 0;I < 40;I++)
			for (A = 0;A < 30;A++)
				if (Customers[I].Seat_Data[A].Seats_Bought != "!")
				{
					AmountSold++;
					TotalCost += Customers[I].Seat_Data[A].Seat_Costs;
				}

		cout << "Total Earned: $" << TotalCost << "  ";
		cout << "Total Tickets Sold: " << AmountSold;
	}
	else
	{
		clrscr();
		Choice--;
		cout << "Customer: " << Customers[Choice].Personal_Data.Name;
		cout << setw(12) << "Address: " << Customers[Choice].Personal_Data.Address << endl;
		cout << "City, State, Zip: " << Customers[Choice].Personal_Data.City_State << endl;
		cout << "Phone #: " << Customers[Choice].Personal_Data.Phone << endl;
		for (I = 0; I < 30; I++)
			if (Customers[Choice].Seat_Data[I].Seats_Bought != "!")
			{
				cout << Customers[Choice].Seat_Data[I].Seats_Bought << "  $" << Customers[Choice].Seat_Data[I].Seat_Costs<<"  ";
				cout << Customers[Choice].Seat_Data[I].Seat_Type << ", " << Customers[Choice].Seat_Data[I].Seat_Location;
				cout << endl;
				TotalCost += Customers[Choice].Seat_Data[I].Seat_Costs;
			}
		cout << "Total Cost: $" << TotalCost;
	}
	getch();
}