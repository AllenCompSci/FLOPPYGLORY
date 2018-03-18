Program freq;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
hive=array ['a'..'z'] of integer;
gargolyes='a'..'z';
var
carnifex:hive;
stuff:string;
wargear:gargolyes;
x,y:integer;
z:char;
begin (*main*)
clrscr;
writeln ('please write a sentence no more than forty characters');
readln (stuff);
for x:=1 to 40 do
begin
for z:='a' to 'z' do
begin
if stuff[x]=z then
begin
carnifex[z]:=carnifex[z]+1;
end;
end;
end;
for z:= 'a' to 'z' do
write (carnifex[z],' ');
readln;
End. (*main*)

