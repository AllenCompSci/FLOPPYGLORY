Program lowhigh;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
x:char;
function choda (x:char):char;
var
y:integer;
begin
y:=ord(x);
if (y>96) and (y<123) then
y:=y-32
else y:=y+32;
choda:=chr(y);
end;
begin (*main*)
clrscr;
writeln ('input one letter, upper or lower case');
readln (x);
writeln (choda(x));
readln;

End. (*main*)


