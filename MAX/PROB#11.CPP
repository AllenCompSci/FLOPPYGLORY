// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>

double a;
apstring b;


void main ()  {
clrscr();

cout<<"How much do you weigh (in pounds)?"<<endl<<endl<<endl;
cin>>a;

clrscr();
cout<<"Which planet/moon do you want to see your weight in (please type in lower case)?"
<<endl<<endl<<"Moon"<<endl<<"Mercury"<<endl<<"Venus"<<endl<<"Mars"
<<endl<<"Jupiter"<<endl<<"Saturn"<<endl<<"Uranus"<<endl<<"Neptune"
<<endl<<"Pluto"<<endl<<endl;
cin>>b;

clrscr();

		if (b=="moon")
		cout<<a*.16<<" pounds";

		if (b=="mercury")
		cout<<a*.37<<" pounds";

		if (b=="venus")
		cout<<a*.88<<" pounds";

		if (b=="mars")
		cout<<a*.38<<" pounds";

		if (b=="jupiter")
		cout<<a*2.64<<" pounds";

		if (b=="saturn")
		cout<<a*1.15<<" pounds";

		if (b=="uranus")
		cout<<a*1.15<<" pounds";

		if (b=="neptune")
		cout<<a*1.12<<" pounds";

		if (b=="pluto")
		cout<<a*.04<<" pounds";


cout<<endl<<endl<<"Please press return to continue.";
getch();
};