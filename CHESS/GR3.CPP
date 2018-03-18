// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>

#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

//Structures
	struct Data
	{
		apstring Name;
		char Char_Name[50];
		int Number;
	};

//Constants

//Global Variables
	int grdriver, grmode, errorcode;
	int I, A, Array_Size, Spacing;
	apvector <Data> Trees;

//Prototypes
	void gr_start(int&, int&, int&);
	void convert(apstring, int);
	void get_data(int&);

void main ()
{
	clrscr();
	Array_Size = 0;
	get_data(Array_Size);
	gr_start(grdriver, grmode, errorcode);

	line(50, 25, 50, 231);
	line(50, 231, 640, 231);

	outtextxy(15, 25, "1000");
	outtextxy(25, 75, "750");
	outtextxy(25, 125, "500");
	outtextxy(25, 175, "250");
	outtextxy(40, 225, "0");

	settextstyle(0,1,0);
	Spacing = (640 - 50) / Array_Size;
	for (I = 0; I < Array_Size; I++)
	{
		outtextxy((Spacing * I)+80, 235, Trees[I].Char_Name);
		rectangle((Spacing * I)+65, 231, (Spacing * I) + 90, 231);
	}

	getch();
}

void get_data(int & I)
{
	int A;
	ifstream In_File;
	apstring Trash;

	Trees.resize(1);
	In_File.open("U:\\F123\\Trees.dat");

	for(A = 0; A < 50; A++)
		Trees[0].Char_Name[A] = NULL;
	getline(In_File, Trees[I].Name);
	while(!In_File.eof())
	{
		In_File >> Trees[I].Number;
		getline(In_File, Trash);
		I++;
		Trees.resize(I+1);
		for (A = 0; A < 50; A++)
			Trees[I].Char_Name[A] = NULL;
		getline(In_File, Trees[I].Name);
	}

	for (A = 0; A < I; A++)
		convert(Trees[A].Name, A);
	In_File.close();
};

void convert(apstring Sent_In, int Num)
{
	int I;
	for (I = 0; I < Sent_In.length(); I++)
		Trees[Num].Char_Name[I] = Sent_In[I];
};

void gr_start(int & grdriver, int & grmode, int & errorcode)
{
	grdriver = VGA;
	grmode = VGAHI;
	initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
	errorcode = graphresult();
	if(errorcode != grOk)
	{
		clrscr();
		cout << "Error: " << errorcode;
		getch();
		exit(1);
	}
};