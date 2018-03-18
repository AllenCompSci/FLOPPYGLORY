Program mult2;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
c3po=file of integer;
var
x,y,z:integer;
luke,leia:c3po;
begin (*main*)
clrscr;
assign (luke,'A:luke.dat');
reset(luke);
assign (leia,'A:leia.dat');
reset(leia);
writeln ('Welcome');
while not eof(leia) do
begin
read (luke,x);
read (leia,y);
z:=x*y;
writeln (x,'X',y,'=',z);
readln;
end;
close (luke);
close (leia);
End. (*main*)

