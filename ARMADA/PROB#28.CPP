//Rebecca Russell
//6th
//Mr.Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
//Constant
//Variable
//Prototype
void chorus ();
void verse1 ();
void verse2 ();
void bridge1 ();
void bridge2 ();
void main ()
{clrscr();
cout<<"The Best Thing"<<endl<<"By: Savage Garden"<<endl<<endl;
chorus ();
verse1 ();
getch();

chorus ();
getch();

verse2 ();
getch();

chorus ();
getch();

bridge1 ();
getch();

chorus ();
bridge2 ();
getch();
};
void chorus ()
{cout<<"Never want to fly"<<endl<<"Never want to leave"<<endl<<
"Never want to say what you mean to me"<<endl<<"Never want to run"<<endl<<
"Frightened to believe"<<endl<<"Youre the best thing about me"<<endl<<endl;
}

void verse1 ()
{cout<<"Sometimes i feel like this is only chemistry"<<endl<<
"Stuck in a maze searching for a way to"<<endl<<
"Shut down run around feel the ground beneath me"<<endl<<
"Youre so close where do you end where do I begin?"<<endl<<
"Always pushing and pulling"<<endl<<
"Sometimes sanity takes vacation time on me"<<endl<<
"Im in a daze stumbling bewildered"<<endl<<
"North of gravity head up in the stratosphere"<<endl<<
"You and I roller coaster riding love"<<endl<<
"Youre the center of adrenaline"<<endl<<
"And Im beginning to understand"<<endl<<endl;
}

void verse2 ()
{cout<<"Walk on broken glass make my way through fire"<<endl<<
"These are the things i would do for love"<<endl<<
"Farewell peace of mind kiss goodbye to reason"<<endl<<
"Up is down the impossible occurs each day"<<endl<<
"This intoxication thrills me"<<endl<<
"I only pray it doesnt kill me"<<endl<<endl;
}

void bridge1 ()
{cout<<"Youre the center of adrenaline"<<endl<<
"And Im beginning to understand"<<endl<<
"You could be the best thing about me"<<endl<<endl;
}

void bridge2 ()
{cout<<"You could be the best thing about me"<<endl<<
"What if youre the best thing about me?"<<endl<<endl;
}