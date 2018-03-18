Program olympic;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
a,b:string;
z,y,w,v,x,s,m,high,low,total,choda:real;
begin (*main*)
clrscr;
repeat
writeln ('What is the diver''s last name');
readln (a);
writeln ('Please enter the first score');
readln (z);
writeln ('Please enter the second score');
readln (y);
writeln ('Please enter the third score');
readln (x);
writeln ('Please enter the fourth score');
readln (w);
writeln ('Please enter the fifth score');
readln (v);
writeln ('Please enter the sixth score');
readln (s);
writeln ('Please enter the seventh score');
readln (m);
(*now the fun begins*)
high:=0;
low:=0;
if z>y then
high:=z
else
high:=y;
if x>high then
high:=x;
if w>high then
high:=w;
if v>high then
high:=v;
if s>high then
high:=s;
if m>high then
high:=m;
if z<y then
low:=z
else
low:=y;
if x<low then
low:=x;
if w<low then
low:=w;
if v<low then
low:=v;
if s<low then
low:=s;
if m<low then
low:=m;

total:=z+y+x+w+v+s+m;
total:=total-low;
total:=total-high;
choda:=total/5;
clrscr;
writeln ('THE HIGH SCORE IS:',high:2:1);
writeln ('THE LOW SCORE IS:',low:2:1);
writeln ('THE DIVER''S NAME IS:',a);
writeln ('THE DIVER''S TOTAL IS:',total:2:1);
writeln ('THE DIVER''S AVERAGE IS:',choda:2:1);
writeln ('Do you want to run the program agian?(yes or no)');
readln (b);
clrscr;
until b='no'
end.