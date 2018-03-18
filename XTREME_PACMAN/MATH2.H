// Program: Number Converter for APStrings
// By: Bryan J. Baker


#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apstring.h>
#include <bool.h>
#include <math.h>

// Function Section

apstring itos(int); 	// Converts ints to apstrings
apstring ltos (long); // Converts longs to apstrings


apstring itos (int Val)
{ apstring Answer, Ans;
	int Base, Pos, I;

	Ans = "     ";
	Answer="";
	Pos = 4;
	Base = 10;

	if (Val<0)
	{
		Val=abs(Val);
		Answer+='-';
	}
	
	if (Val==0)
		Answer="0";

	while(Val>0)
	{
		Ans[Pos]=char((Val%Base)+48);
		Val-=(Val%Base);
		Val/=Base;
		Pos--;
	}

	for(I=0;I<=4;I++)
	 if(Ans[I]!=' ')
		Answer+=Ans[I];

	return Answer;
};

apstring ltos (long Val)
{ apstring Answer, Ans;
	long Base, Pos, I;

	Ans = "            ";
	Answer="";
	Pos = 11;
	Base = 10;

	if (Val<0)
	{
		Val=labs(Val);
		Answer+='-';
	}
	if (Val==0)
		Answer="0";
	while(Val>0)
	{
		Ans[Pos]=char((Val%Base)+48);
		Val-=(Val%Base);
		Val/=Base;
		Pos--;
	}

	for(I=0;I<=11;I++)
	 if(Ans[I]!=' ')
		Answer+=Ans[I];

	return Answer;
};