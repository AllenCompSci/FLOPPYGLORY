Program copy;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
choda,doug:text;
x:integer;
a,b:string;
begin (*main*)
clrscr;
assign (choda,'a:/fred.dat');
assign (doug,'a:/doug.dat');
rewrite (doug);
reset (choda);
x:=0;

repeat
x:=x+1;
readln (choda,a);
writeln (doug,a);
writeln (doug,b);
until x=8;
reset (doug);
x:=0;
repeat
x:=x+1;
readln (doug,a);
writeln (a)
until x=16;
readln;
close (doug);

close (choda);
End. (*main*)

