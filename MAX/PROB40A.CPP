//Mahmood Subhani
//Period 5
//Mr. Baker
//Program: Planet Info

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apvector.h>
#include <apstring.h>

//CONSTANTS


//STRUCTURES
struct planet
{
apstring Distance;
apstring Period;
apstring Rotation;
apstring Diameter;
apstring Satellites;
apstring Ringnum;
};

//PROTOTYPES
void assignvalues();
int menu();


//VARIABLES
apvector <planet> Solar(9);


void main()
{
int Planet;
clrscr();



assignvalues();

Planet = menu();


cout<<"Distance from sun: " <<Solar[Planet].Distance << endl;
cout<<"Period of revolution: " <<Solar[Planet].Period << endl;
cout<<"Rotation period: " <<Solar[Planet].Rotation << endl;
cout<<"Diameter" <<Solar[Planet].Diameter << endl;
cout<<Solar[Planet].Satellites << endl;
cout<<Solar[Planet].Ringnum << endl;
getch();
};

void assignvalues()
{

//Mercury

Solar[0].Distance   = "57.9 Million Killometers";
Solar[0].Period     = "88 Days";
Solar[0].Rotation   = "59 Days";
Solar[0].Diameter   = "4,880 Kilometers";
Solar[0].Satellites = "0 Satellites";
Solar[0].Ringnum    = "0 Rings";


//Venus

Solar[1].Distance   = "108.2 Million Killometers";
Solar[1].Period     = "224.7 Days";
Solar[1].Rotation   = "243 Days Retrograde";
Solar[1].Diameter   = "12,100 Kilometers";
Solar[1].Satellites = "0 Satellites";
Solar[1].Ringnum    = "0 Rings";


//Earth

Solar[2].Distance   = "149.6 Million Killometers";
Solar[2].Period     = "365.2 Days";
Solar[2].Rotation   = "23 Hrs, 56 Mins, 3 Sec";
Solar[2].Diameter   = "12,756 Kilometers";
Solar[2].Satellites = "1 Satellite";
Solar[2].Ringnum    = "0 Rings";


//Mars

Solar[3].Distance   = "227.9 Million Killometers";
Solar[3].Period     = "687 Days";
Solar[3].Rotation   = "24 Hrs, 37 Mins";
Solar[3].Diameter   = "6,794 Kilometers";
Solar[3].Satellites = "2 Satellites";
Solar[3].Ringnum    = "0 Rings";


//Jupiter

Solar[4].Distance   = "778.3 Million Killometers";
Solar[4].Period     = "11 Yrs, 9 Hrs, 55 Mins, 30 Sec";
Solar[4].Rotation   = "59 Days";
Solar[4].Diameter   = "4,880 Kilometers";
Solar[4].Satellites = "0 Satellites";
Solar[4].Ringnum    = "0 Rings";


//Saturn

Solar[5].Distance   = "1427 Million Killometers";
Solar[5].Period     = "29.46 Yrs";
Solar[5].Rotation   = "10Hrs, 40 Mins, 24 Sec";
Solar[5].Diameter   = "120,660 Kilometers";
Solar[5].Satellites = "18+ Satellites";
Solar[5].Ringnum    = "1,000(?) Rings";


//Uranus

Solar[6].Distance   = "2,870 Million Killometers";
Solar[6].Period     = "84 Yrs";
Solar[6].Rotation   = "16.8 Hrs";
Solar[6].Diameter   = "51,810 Kilometers";
Solar[6].Satellites = "15 Satellites";
Solar[6].Ringnum    = "11 Rings";


//Neptune

Solar[7].Distance   = "4,497 Million Killometers";
Solar[7].Period     = "165 Yrs";
Solar[7].Rotation   = "16Hrs, 11 Mins";
Solar[7].Diameter   = "49,528 Kilometers";
Solar[7].Satellites = "8 Satellites";
Solar[7].Ringnum    = "4 Rings";


//Pluto

Solar[8].Distance   = "5,900 Million Killometers";
Solar[8].Period     = "248 Yrs";
Solar[8].Rotation   = "6 Days, 9Hrs, 18 Mins";
Solar[8].Diameter   = "2,290 Kilometers";
Solar[8].Satellites = "1 Satellites";
Solar[8].Ringnum    = "? Rings";
}


