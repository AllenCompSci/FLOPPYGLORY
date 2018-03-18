//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
//const
//var
char Choice;
//proto
void v1();
void v2();
void v3();
void v4();
void v5();
void c1();
void main()
{clrscr();
do{
	v1();
	cout<<endl;
	c1();
	cout<<endl;
	cout<<"Press enter to go to next verse of song";
	getch();
	clrscr();
	v2();
	cout<<endl;
	c1();
	cout<<endl;
	cout<<"Press enter to go to next verse of song";
	getch();
	clrscr();
	v3();
	cout<<endl;
	c1();
	cout<<endl;
	cout<<"Press enter to go to next verse of song";
	getch();
	clrscr();
	v4();
	cout<<endl;
	c1();
	cout<<endl;
	cout<<"Press enter to go to next verse of song";
	getch();
	clrscr();
	v5();
	cout<<endl;
	c1();
	cout<<endl;
	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
void v1()
	 {cout<<"Well,  the south side of Chicago"<<endl;
		cout<<"Is the baddestpart of town"<<endl;
		cout<<"And if you go down there, you better just beware"<<endl;
		cout<<"Of a man named Leroy Brown"<<endl;

	 }//end function
void v2()
	 {cout<<"Now Leroy, more than trouble"<<endl;
		cout<<"You see hin stand about six feet four"<<endl;
		cout<<"All the downtown ladies call him tree top lover"<<endl;
		cout<<"All the men just call him sir"<<endl;

	 }//end function
void v3()
	 {cout<<"And he's bad (bad) bad (bad) Leroy Brown"<<endl;
		cout<<"Baddest man in the whole darn town"<<endl;
		cout<<"Badder than ol' King Kong"<<endl;
		cout<<"Meaner than a junk yard dog"<<endl;

			 }
void v4()
	 {cout<<"Now Leroy, he a gambler"<<endl;
		cout<<"And he likes his fancy close"<<endl;
		cout<<"And he likes to wave his diamond rings"<<endl;
		cout<<"In front of everybody's nose"<<endl;

	 }
void v5()
	 {cout<<"He got a custom Contnental"<<endl;
		cout<<"He got a Eldorado, too"<<endl;
		cout<<"He got a thirty-two gun in his pocket for fun"<<endl;
		cout<<"He got a razor in he's shoe"<<endl;

	 }
void c1()
	 {cout<<"Now, Friday, down in"<<endl;
		cout<<"Leroy, shootin dice"<<endl;
		cout<<"And at the edge of the bar sat a girl named a-Doris"<<endl;
		cout<<"And, ooooh, that girl looked nice"<<endl;

		cout<<"Well, he cast his eyes upon here"<<endl;
		cout<<"And the trouble soon began"<<endl;
		cout<<"Leroy Brown learned a lessin' bout messin"<<endl;
		cout<<"With the wife of a jealous man"<<endl;

		cout<<"Well, the two men took to fightin'"<<endl;
		cout<<"And they fall down on the floor"<<endl;
		cout<<"Leroy looked like a jig-saw puzzle"<<endl;
		cout<<"With a couple fo pieces gon"<<endl;

		cout<<"Yeah, he was badder than ol' King kong"<<endl;
		cout<<"Meaner than a junk yard dog"<<endl;

	 }