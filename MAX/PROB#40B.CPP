//Mahmood Subhani
//Period 5
//Mr. Baker
//Program: Planet Info

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apvector.h>
#include <apstring.h>
#include <fstream.h>

//CONSTANTS


//STRUCTURES


//PROTOTYPES



//VARIABLES
apvector <apstring> Solar(9);
apvector <apstring> Words(198);
int I;

apstring Name;
ifstream file;


void main()
{
int Planet;

clrscr();
file.open("A:\\myfile2");

for(I=0;I<198;I++)
{
file>>Words[I];
}






cout<<"Please select a planet."<<endl;

cout<<endl;
cout<<"1) Mercury"<<endl;
cout<<"2) Venus"<<endl;
cout<<"3) Earth"<<endl;
cout<<"4) Mars"<<endl;
cout<<"5) Jupiter"<<endl;
cout<<"6) Saturn"<<endl;
cout<<"7) Uranus"<<endl;
cout<<"8) Neptune"<<endl;
cout<<"9) Pluto"<<endl;
cin>>I;
I--;


switch(I)
{
case 0:I=0;
case 1:I=22;
case 2:I=44;
case 3:I=66;
case 4:I=88;
case 5:I=110;
case 6:I=132;
case 7:I=154;
case 8:I=176;









cout<<Words[I]<<endl<<endl;


cout<<Words[I+1]<<" "<<Words[I+2]<<" "<<Words[I+3]<<" "<<Words[I+4]<<" "<<Words[I+5]<<" "<<Words[I+6]<<endl;
cout<<Words[I+7]<<" "<<Words[I+8]<<" "<<Words[I+9]<<" "<<Words[I+10]<<" "<<Words[I+11]<<endl;
cout<<Words[I+12]<<" "<<Words[I+13]<<" "<<Words[I+14]<<" "<<Words[I+15]<<endl;
cout<<Words[I+16]<<" "<<Words[I+17]<<endl;
cout<<Words[I+18]<<" "<<Words[I+19]<<endl;
cout<<Words[I+20]<<" "<<Words[I+21]<<endl;

}
getch();
};


