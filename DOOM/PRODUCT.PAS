Program product;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
TYPE
NUMBERS = array [1..15] of integer;
TOLIET = array [1..15] of integer;
PRODUCT1 = array [1..15] of integer;
var
num:NUMBERS;
tol:TOLIET;
ans:PRODUCT1;
x,y,z:integer;
begin (*main*)
clrscr;
writeln ('The magnifacent multiplying machine');
for x :=1 to 15 do
begin
writeln ('Input a number please');
readln (num[x]);
end;
x:=1;
for x :=1 to 15 do
begin
writeln ('Input another number please');
readln (tol[x]);
end;
x:=1;
clrscr;
for x :=1 to 15 do
begin
ans[x]:=num[x]*tol[x];
writeln (ans[x]);
end;
readln;
End. (*main*)

