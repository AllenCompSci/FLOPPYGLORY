Program horizons;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
store=record
name:string;
dress:string;
city:string;
end;
choda=file of store;
var
hold:choda;
fred:store;
big:string;
x:integer;
begin (*main*)
assign (hold,'a:\hold.dat');
clrscr;
reset (hold);
clrscr;
writeln ('Welcome');
x:=filesize(hold);
seek (hold,x);
repeat
writeln ('Enter in the name');
readln (fred.name);
writeln ('Enter in the address');
readln (fred.dress);
writeln ('Enter in the city, state');
readln (fred.city);
write (hold,fred);
writeln ('Do you have another entry?(y/n)');
readln (big);
until big='n';
reset (hold);
while not eof(hold) do
begin
read (hold,fred);
writeln ('NAME:',fred.name);
writeln ('ADDRESS:',fred.dress);
writeln ('CITY,STATE:',fred.city);
readln;
end;
close (hold);
End. (*main*)
