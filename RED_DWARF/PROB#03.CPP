//KRIS BICKHAM
//PROB#03
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
double Sweater;
double Skirt;
double Blouse;
double Bracelet;
double Total;
//CONSTANTS------------
//MAIN
void main ()
{
Sweater=35.00;
Skirt=28.50;
Blouse=22.95;
Bracelet=12.25;
Total=Sweater+Skirt+Blouse+Bracelet;
clrscr();
cout<<setprecision(2);
cout<<setiosflags(ios::showpoint);
cout<<setw(10)<<"Sweater";
cout<<setw(10)<<"Skirt";
cout<<setw(10)<<"Blouse";
cout<<setw(10)<<"Bracelet"<<endl;
cout<<setw(10)<<Sweater;
cout<<setw(10)<<Skirt;
cout<<setw(10)<<Blouse;
cout<<setw(10)<<Bracelet<<endl;
getch();
cout<<setw(10)<<"Total="<<Total;
getch();
clrscr();
cout<<"Press return to see what they would be on sale"<<endl;
getch();
cout<<"It's 15% Off"<<endl;
cout<<setw(10)<<"Sweater";
cout<<setw(10)<<"Skirt";
cout<<setw(10)<<"Blouse";
cout<<setw(10)<<"Bracelet"<<endl;
Sweater=Sweater-(Sweater*.15);
Skirt=Skirt-(Skirt*.15);
Blouse=Blouse-(Blouse*.15);
cout<<setw(10)<<Sweater;
cout<<setw(10)<<Skirt;
cout<<setw(10)<<Blouse;
cout<<setw(10)<<Bracelet<<endl;
getch();
cout<<setw(10)<<Total<<endl;
getch();

}

