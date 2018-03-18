Program posneg;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
x:real;
a:string;
begin (*main*)
clrscr;
writeln ('enter a number please');
readln (x);
if x<0 then
a:='-'
else a:='+';
writeln (abs(x):2:10,a);
readln;
End. (*main*)

