Program stars;
(*El CHoDA
Baker 6th, *)
uses
    crt;
const
a='*';
var
x,y:integer;


begin (*main*)
clrscr;
x:=0;
y:=1;
while x<7 do
begin
gotoxy (5,y);
writeln (a);
y:=y+1;
x:=x+1;
end;
x:=0;
y:=2;
while x<5 do
begin
gotoxy (4,y);
writeln (a);
y:=y+1;
x:=x+1;
end;
x:=0;
y:=2;
while x<5 do
begin
gotoxy (6,y);
writeln (a);
y:=y+1;
x:=x+1;
end;
x:=0;
y:=3;
while x<3 do
begin
gotoxy (3,y);
writeln (a);
y:=y+1;
x:=x+1;
end;
x:=0;
y:=3;
while x<3 do
begin
gotoxy (7,y);
writeln (a);
y:=y+1;
x:=x+1;
end;
x:=0;
y:=4;
while x<1 do
begin
gotoxy (2,y);
writeln (a);
y:=y+1;
x:=x+1;
end;
x:=0;
y:=4;
while x<1 do
begin
gotoxy (8,y);
writeln (a);
y:=y+1;
x:=x+1;
end;



readln;
End. (*main*)

