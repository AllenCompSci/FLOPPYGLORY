Program bowling;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
a1=array [1..5] of real;
a2=array [1..5] of string;
var
choda:a1;
carnifex:a2;
score,x,y,z:integer;
begin (*main*)
clrscr;
for x:=1 to 5 do
begin
writeln ('input bowler number ',x,' name');
readln (carnifex[x]);
score:=0;
for y:=1 to 5 do
begin
writeln ('enter score number ',y);
readln (z);
score:=score+z;
end;
choda[x]:=score/5;
end;
for x:=1 to 5 do
begin
writeln (carnifex[x]);
writeln (choda[x]:2:2);
readln;
end;



End. (*main*)

