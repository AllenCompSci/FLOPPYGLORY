Program charity;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
a,b,d,e,f:longint;
c:real;

begin (*main*)
writeln ('Mrs. Williams penny pinching program.');
a:=1;
b:=1;
repeat
writeln ('Day ',a);
a:=a+1;
writeln (b,' cents');

c:=b/100;
writeln ('or ',c:2:2,' dollars');
b:=b*2;
readln;
clrscr;
until a=21



End. (*main*)

