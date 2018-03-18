Program pop;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
city_files=record
city:string;
people:longint;
state:string[2];
end;
cuty_ray=array [1..100] of city_files;
const
y=3;
var
city_ray:cuty_ray;
a,x:integer;
ans,counter:string;
begin (*main*)
clrscr;
writeln (' Welcome to the city population keeper');
writeln (' I am your helpful servant ''Slave 1''');
for x:= 1 to y do
begin
writeln (' May I get the name of your city please');
repeat
readln (city_ray[x].city);
if city_ray[x].city='' then
writeln ('Don''t mess with me, enter a city')
else a:=1;
until a=1;
writeln (' May I have the population of the city');
repeat
readln (city_ray[x].people);
if city_ray[x].people=0 then
writeln ('either that''s an empty town or you did not input a number')
else a:=2;
until a=2;
writeln (' May I get a an abbreviation for the state');
repeat
readln (city_ray[x].state);
if length(city_ray[x].state)<>2 then
writeln ('I need two letters please')
else a:=3;
until a=3;
end;
writeln ('do you want to look up a population of a city,(yes or no)');
readln (ans);
if ans='yes' then
begin
repeat
writeln ('what city would you like information on');
readln (counter);
for a:= 1 to 100 do
if counter=city_ray[a].city then begin
writeln (city_ray[a].city);
writeln (city_ray[a].people);
writeln (city_ray[a].state);
x:=1;
end;
if x<>1 then writeln ('either you didn''t spell it write or this city is not on file');
writeln ('do you wish to enter another');
readln (ans);
until ans='no';
end;
writeln ('thank you and have a new day');
readln;

End. (*main*)

