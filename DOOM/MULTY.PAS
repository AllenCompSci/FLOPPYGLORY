Program multy;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
CHART=array [1..10,1..10] of integer;
var
tyranid:chart;
s,m,x:integer;

begin (*main*)
clrscr;
for s:= 1 to 10 do
for m:= 1 to 10 do
tyranid[s,m]:=s*m;
for s:= 1 to 10 do
for m:= 1 to 10 do
begin
write (tyranid[s,m],'    ');
if m=10 then
writeln;

end;
readln;

End. (*main*)

