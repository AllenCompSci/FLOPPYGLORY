Program mach;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
x,y,z:real;
begin (*main*)
clrscr;
writeln ('input the temperature please');
readln (x);
y:=1.1*x;
z:=1055+y;
writeln ('you are moving at ',z:2:2,' miles an hour. Go speed racer');
readln;

End. (*main*)

