//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
void main()
{clrscr();
cout<<setprecision(2);
cout<<setiosflags(ios::showpoint);
cout<<"Cost"<<endl;
cout<<"sweater:    $35.00"<<endl;
cout<<"skirt:      $28.50"<<endl;
cout<<"blouse:     $22.95"<<endl;
cout<<"bracelet:   $12.25"<<endl;
cout<<"total=      $"<<35+28.50+22.95+12.25;
cout<<endl<<endl;
cout<<"Sale Price"<<endl;
cout<<"sweater:    $"<<35-(35*.15)<<endl;
cout<<"skirt:      $"<<28.50-(28.50*.15)<<endl;
cout<<"blouse:     $"<<22.95-(22.95*.15)<<endl;
cout<<"bracelet:   $12.25"<<endl;
cout<<"total=      $"<<98.70- ((35+28.50+22.95)*.15);
getch();
}
