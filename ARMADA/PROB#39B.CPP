//Rebecca Russell
//6th
//Mr.Baker
//Program:  retrieves 10 numbers from file
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
//Constant
//Structs
//Variable
int I;
ifstream In_file;
apvector <int> Nums (10);
//Prototype
void main ()
{clrscr();
In_file.open("A:\\PROB#39.DAT");
for(I=0; I<10; I++)
{In_file>>Nums[I];
 cout<<Nums[I]<<endl;
}
In_file.close();
getch();
};
