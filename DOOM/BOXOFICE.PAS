Program boxorifice;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
a,b,c,d,e,f,g,h,i,j,k:integer;
total:real;
z,x,y,w,u,v,q,p:string;
begin (*main*)
repeat
clrscr;
k:=0;
writeln ('Welcome to the London Cricket squad ticket booth');
writeln ('May I have your first and last name governor');
readln (z);
repeat
repeat
writeln ('Which ticket package would you like, my lord');
writeln ('1)single tickets');
writeln ('2)season tickets');
writeln ('3)monthly tickets');
writeln ('4)group specials');
readln (a);
case a of
1:begin
repeat
writeln ('What date would you like your ticket, sir? (month then date in numeric format)');
readln;
writeln ('Where would you like to sit?');
writeln ('1)Lord''s seat (25 pounds per seat)');
writeln ('2)Knight''s seat (15 pounds per seat)');
writeln ('3)Regular seats (10 pounds per seat)');
writeln ('4)Serf''s seats (5 pounds per seat)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you like in this section');
readln (c);
total:=total+c*25;
end;
2:begin
writeln ('And how many tickets would you like in this section');
readln (c);
total:=total+c*15;
end;
3:begin
writeln ('And how many seats would you like in this section');
readln (c);
total:=total+c*10;
end;
4:begin
writeln ('And how many seats would you like in this section');
readln (c);
total:=total+c*5;
end;
else writeln ('NOT A VALID SELECTION YOU TWIT');
end;
writeln ('Would you like to select more singular tickets? (yes or no)');
readln (y);
if y='no' then
k:=1;
until k=1;
end;
2:begin
repeat
writeln ('What date would you like your tickets, my lord?');
readln (b);
writeln ('There are 42 games this season');                         (*choda was here*)
writeln ('Where would you like your seats, sir?');
writeln ('1)Lord''s seat (150 pounds)');
writeln ('2)Knight''s seat (100 pounds)');
writeln ('3)Regular seats (75 pounds)');
writeln ('4)Serf''s seats (50 pounds)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you like in this section?');
readln (c);
total:=total+c*150;
end;
2:begin
writeln ('And how many tickets would you like in this section?');
readln (c);
total:=total+c*100;
end;
3:begin
writeln ('And how many tickets would you like in this section?');
readln (c);
total:=total+c*75;
end;
4:begin
writeln ('And how many tickets would you like in this section?');
readln (c);
total:=total+c*50;
end;
else writeln ('YOU SILLY TWIT, THAT IS AN INVALID ANSWER');
end;
writeln ('Would you like to buy more season tickets?(yes or no)');
readln (y);
if y='no' then k:=1;
until k=1;
end;
3:begin
repeat
writeln ('A monthly special is where you can buy all tickets for that month at a reduced rate');
writeln ('Each month has eleven games');
writeln ('Where would you like your seats');
writeln ('1)Lord''s seats (100 pounds)');
writeln ('2)Knight''s seats (75 pounds)');
writeln ('3)Regular tickets (50 pounds)');
writeln ('4)Serf''s tickets (25 pounds)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you like?');
readln (c);
total:=total+c*100;
end;
2:begin
writeln ('And how many tickets would you like?');
readln (c);
total:=total+c*75;
end;
3:begin
writeln ('And how many tickets would you like?');
readln (c);
total:=total+c*50;
end;
4:begin
writeln ('And how many tickets would you like?');
readln (c);
total:=total+c*25;
end;
else writeln ('INVALID SELECTION YOU BOOB');
end;
writeln ('Would you like to buy more monthly tickets?(yes or no)');
readln (y);
if y='no' then k:=1;
until k=1;
end;
4:begin
repeat
writeln ('Group specials are discounted tickets when anyone buys more than');
writeln ('five tickets!!(this offer not valid with any other offer)');
writeln ('What section would you like your tickets, my lord');
writeln ('1)Lord''s seats (20 pounds per ticket)');
writeln ('2)Knight''s seats (15 pounds per ticket)');
writeln ('3)Regular seats (8 pounds per tickets)');
writeln ('4)Serf''s seats (3 pounds per tickets)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you like');
readln (c);
if c>4 then
total:=total+c*20
else writeln ('INVALID SELECTION. You need five or more tickets');
end;
2:begin
writeln ('And how many tickets would you like');
readln (c);
if c>4 then
total:=total+c*15
else
writeln ('INVALID SELECTION. You need five or more tickets');
end;
3:begin
writeln ('And how many tickets would you like');
readln (c);
if c>4 then
total:=total+c*8
else
writeln ('INVALID SELECTION. You need five or more tickets');
end;
4:begin
writeln ('And how many tickets would you like');
readln (c);
if c>4 then
total:=total+c*3;
if c<5 then writeln ('INVALID SELECTION. You need five or more tickets');
end;
else
writeln ('INVALID SELECTION YOU KNEEBITER');
end;
writeln ('Would you like to order more ticket group rate tickets? (yes or no)');
readln (y);
until y='no';
end;
else writeln ('INVALID SELECTION YOU TWIT');
end;
case a of
1:
begin
writeln ('You have purchased ',c,' tickets for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
2:
begin
writeln ('You have purchased ',c,' season passes for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
3:
begin
writeln ('You have purchased ',c,' monthly specials for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
4:begin
writeln ('You have purchsed ',c,' group specials for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
end;
writeln ('total so far equals:',total:2:2,'�');
writeln ('Do you wish to purchase more tickets?(yes or no)');
readln (y);
if y='yes'then
k:=1;

if y='no' then
k:=0;
until k=0;
writeln ('Do you want to edit your ticket purchases?(yes or no)');
readln (y);
(*removal begins here*)
if y='yes' then
repeat
writeln ('Which ticket package would you like to remove, my lord');
writeln ('1)single tickets');
writeln ('2)season tickets');
writeln ('3)monthly tickets');
writeln ('4)group specials');
readln (a);
case a of
1:begin
repeat
writeln ('What date was your ticket, sir? (month then date in numeric format)');
readln;
writeln ('Where did you like to sit?');
writeln ('1)Lord''s seat (25 pounds per seat)');
writeln ('2)Knight''s seat (15 pounds per seat)');
writeln ('3)Regular seats (10 pounds per seat)');
writeln ('4)Serf''s seats (5 pounds per seat)');
readln (j);
case j of
1:begin
writeln ('And how many seats would you like to remove in this section');
readln (c);
total:=total-c*25;
end;
2:begin
writeln ('And how many seats would you like to remove in this section');
readln (c);
total:=total-c*15;
end;
3:begin
writeln ('And how many seats would you like to remove in this section');
readln (c);
total:=total-c*10;
end;
4:begin
writeln ('And how many seats would you like to remove in this section');
readln (c);
total:=total-c*5;
end;
else writeln ('NOT A VALID SELECTION YOU TWIT');
end;
writeln ('Would you like to edit more singular tickets? (yes or no)');
readln (y);
if y='no' then
k:=1;
until k=1;
end;
2:begin
repeat
writeln ('There are 42 games this season');
writeln ('Where was your seats, my lord?');
writeln ('1)Lord''s seat (150 pounds)');
writeln ('2)Knight''s seat (100 pounds)');
writeln ('3)Regular seats (75 pounds)');
writeln ('4)Serf''s seats (50 pounds)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you like to remove in this section?');
readln (c);
total:=total-c*150;
end;
2:begin
writeln ('And how many tickets would you like to remove in this section?');
readln (c);
total:=total-c*100;
end;
3:begin
writeln ('And how many tickets would you like to remove in this section?');
readln (c);
total:=total-c*75;
end;
4:begin
writeln ('And how many tickets would you like to remove in this section?');
readln (c);
total:=total-c*50;
end;
else writeln ('YOU SILLY TWIT, THAT IS AN INVALID ANSWER');
end;
writeln ('Would you like to edit more season tickets?(yes or no)');
readln (y);
if y='no' then k:=1;
until k=1;
end;
3:begin
repeat
(* you are no longer needed writeln ('A monthly special is where you can buy all tickets for that month at a reduced rate');*)
writeln ('Each month has eleven games');
writeln ('Where was your seats');
writeln ('1)Lord''s seats (100 pounds)');
writeln ('2)Knight''s seats (75 pounds)');
writeln ('3)Regular tickets (50 pounds)');
writeln ('4)Serf''s tickets (25 pounds)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you to remove like?');
readln (c);
total:=total-c*100;
end;
2:begin
writeln ('And how many tickets would you to remove like?');
readln (c);
total:=total-c*75;
end;
3:begin
writeln ('And how many tickets would you to remove like?');
readln (c);
total:=total-c*50;
end;
4:begin
writeln ('And how many tickets would you to remove like?');
readln (c);
total:=total-c*25;
end;
else writeln ('INVALID SELECTION YOU BOOB');
end;
writeln ('Would you like to edit more monthly tickets?(yes or no)');
readln (y);
if y='no' then k:=1;
until k=1;
end;
4:begin
repeat
(* into the void with yee writeln ('Group specials are discounted tickets when anyone buys more than');
writeln ('five tickets!!(this offer not valid with any other offer)');*)
writeln ('What section was your tickets, my lord');
writeln ('1)Lord''s seats (20 pounds per ticket)');
writeln ('2)Knight''s seats (15 pounds per ticket)');
writeln ('3)Regular seats (8 pounds per tickets)');
writeln ('4)Serf''s seats (3 pounds per tickets)');
readln (j);
case j of
1:begin
writeln ('And how many tickets would you like to remove');
readln (c);
if c>4 then
total:=total-c*20
else writeln ('INVALID SELECTION. You need five or more tickets');
end;
2:begin
writeln ('And how many tickets would you like to remove');
readln (c);
if c>4 then
total:=total-c*15
else
writeln ('INVALID SELECTION. You need five or more tickets');
end;
3:begin
writeln ('And how many tickets would you like to remove');
readln (c);
if c>4 then
total:=total-c*8
else
writeln ('INVALID SELECTION. You need five or more tickets');
end;
4:begin
writeln ('And how many tickets would you like to remove');
readln (c);
if c>4 then
total:=total-c*3;
if c<5 then writeln ('INVALID SELECTION. You need five or more tickets');
end;
else
writeln ('INVALID SELECTION YOU KNEEBITER');
end;
writeln ('Would you like to edit more group rate tickets? (yes or no)');
readln (y);
until y='no';
end;
else writeln ('INVALID SELECTION YOU TWIT');
end;
case a of
1:
begin
writeln ('You have removed ',c,' tickets for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
2:
begin
writeln ('You have removed ',c,' seaon passes for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
3:
begin
writeln ('You have removed ',c,' monthly specials for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
4:begin
writeln ('You have removed ',c,' group specials for the');
case j of
1:writeln ('Lord''s section');
2:writeln ('Knight''s section');
3:writeln ('Regular section');
4:writeln ('Serf''s section');
end;
end;
end;
writeln ('total so far equals:',total:2:2,'�');
if total<0 then
begin
writeln ('You screwed up. This entire tranaction has been cancelled');
k:=0;
end
else
begin
writeln ('Do you wish to edit more tickets?(yes or no)');
readln (y);
end;
if y='no' then
k:=0;
until k=0;
writeln ('Are you sure you don''t want buy more tickets?');
readln (y);
if y='yes' then
k:=69;
if y='no' then
k:=0;
until k=0;
if y='no' then
k:=0;
writeln ('Have a super terrific day. Bye-bye');
readln;
until k=0;


End. (*main*)

