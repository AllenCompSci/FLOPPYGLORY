// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
//constants



//structure
struct Date_rec
{
int Day;
int Month;
int Year;
};

struct Everything_rec
{
apstring Name;
int Points;
Date_rec Date;
};




//variables
int I;
int High;
int Save;
int J;
int Loop;

//prototypes

apvector <Everything_rec> Everything(10);
void findhigh ();

void main ()  {
clrscr();
for(I=0;I<10;I++)
{
cout<<"Enter Name:  ";
cin>>Everything[I].Name;

cout<<"Enter Points:  ";
cin>>Everything[I].Points;

cout<<"Enter Year:  ";
cin>>Everything[I].Date.Year;

cout<<"Enter Month:  ";
cin>>Everything[I].Date.Month;

cout<<"Enter Day:  ";
cin>>Everything[I].Date.Day;
cout<<endl;
};
clrscr();


cout<<"Acending order:"<<endl;
for(Loop=0;Loop<10;Loop++)
{
 findhigh();
 cout<<endl;
 }







};





void findhigh()
{

I=0;
int Hold;
int High;

High=0;
Hold=0;
do{

if(Everything[I].Points > High)
{
High = Everything[I].Points;
Hold = I;
}

I++;

}while(I<10);



cout<< Everything[Hold].Name<<endl;
cout<< Everything[Hold].Date.Month<<"/"<<Everything[Hold].Date.Day<<"/"<<Everything[Hold].Date.Year<<endl;
cout<< Everything[Hold].Points<<endl;
getch();
Everything[Hold].Points=0;


};








