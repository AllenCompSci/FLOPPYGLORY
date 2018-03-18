Program pi;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
x:real;
z:longint;
begin (*main*)
clrscr;
for z:=1 to 20000 do
x:=x+(1/sqr(z));
x:=x*6;
x:=sqrt(x);
write (x);
readln;
End. (*main*)

