// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Enter names until ZZZ

#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>




apstring Name;
apvector <apstring> Names (20);
apvector <int> Length (20);
int I;
int J;
int K;
int L;
void main()
{
clrscr();




I=0;

do {
cin>>Names[I];
if (Names[I]!="ZZZ"){
Length[I]=Names[I].length();
I++;}}
while((Names[I]!="ZZZ")&&(I<20));


J=I;
cout<<"Press a key to see the names"<<endl;
getch();
clrscr();


for(K=0; K<=255; K++)
{

for(L=0; L<=J; L++){
if ((K==Length[L])&&(Names[L]!="ZZZ"))
{
cout<<Names[L]<<endl<<endl;

}}}




getch();

};


