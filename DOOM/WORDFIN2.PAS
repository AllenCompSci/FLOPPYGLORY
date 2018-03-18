Program wordfind;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
    charecter=array[1..20,1..20] of char;
    words=array[1..20] of string[5];
var
entry:words;
stuff:charecter;
s,m,x,i,rnd1,rnd2,a,keeper:integer;
j:char;
p:boolean;
yes:string;
procedure fill (var stuff:charecter);
begin
for x:=1 to 20 do
for a:=1 to 20 do
stuff[a,x]:='A';
end;
procedure store (var entry:words; x:integer);
begin
writeln ('enter in a word no longer than 9 charecters');
writeln;
for x:=1 to 20 do
begin
writeln ('word ',x);
readln (entry[x]);
end;
end;
procedure way1 (var stuff:charecter; var x,keeper:integer;p:boolean; rnd1,rnd2,s,m:integer;entry:words);
begin
p:=false;
s:=length(entry[x]);
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if rnd2<20-s then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
begin
if stuff [rnd1,rnd2+m]<>'A' then
p:=true;
end;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1,rnd2+m]:=entry[x,m+1];
end;
end;
procedure way2 (var stuff:charecter; var x,keeper:integer;p:boolean;rnd1,rnd2,s,m:integer;entry:words);
begin
p:=false;
s:=length(entry[x]);
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if rnd1<(20-s) then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
begin
if stuff [rnd1+m,rnd2]<>'A' then
p:=true;
end;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1+m,rnd2]:=entry[x,1+m];
end;
end;
procedure way3(var stuff:charecter; var x,keeper:integer;p:boolean;s,m,rnd1,rnd2:integer;entry:words);
begin
p:=false;
s:=length(entry[x]);
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if rnd2>s then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
begin
if stuff [rnd1,rnd2-m]<>'A' then
p:=true;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:= 1 to s do
stuff [rnd1,rnd2-s]:=entry[x,s+1];
end;
end;
end;
Procedure way4 (var stuff:charecter; var x,keeper:integer;p:boolean;s,m,rnd1,rnd2:integer;entry:words);
begin
p:=false;
s:=length(entry[x]);
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if rnd1>s then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
begin
if stuff [rnd1-m,rnd2]<>'A' then
p:=true;
end;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1-s,rnd2]:=entry[x,s+1];
end;
end;
procedure way5 (var stuff:charecter; var x,keeper:integer;p:boolean;s,m,rnd1,rnd2:integer;entry:words);
begin
p:=false;
s:=length(entry[x]);
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if (rnd1<20-s) and (rnd2<20-s) then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
if stuff [rnd1+m,rnd2+m]<>'A' then
p:=true;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1+s,rnd2+s]:=entry[x,s+1];
end;
end;
procedure way6 (var stuff:charecter; var x,keeper:integer;p:boolean;s,m,rnd1,rnd2:integer;entry:words);
begin
p:=false;
rnd1:=random(20)+1;
rnd2:=random(20)+1;
s:=length(entry[x]);
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if (rnd1>s) and (rnd2>s) then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
begin
if stuff [rnd1-m,rnd2-m]<>'A' then
p:=true;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1-m,rnd2-m]:=entry[x,m+1];
end;
end;
end;
procedure way7 (var stuff:charecter; var x,keeper:integer;p:boolean;s,m,rnd1,rnd2:integer;entry:words);
begin
p:=false;
rnd1:=random(20)+1;
rnd2:=random(20)+1;
s:=length(entry[x]);
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if (rnd1>s) and (rnd2<20-s) then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
if stuff [rnd1-m,rnd2+m]='A' then
p:=true;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1-m,rnd2+m]:=entry[x,m+1];
end;
end;
procedure way8 (var stuff:charecter; var x,keeper:integer;p:boolean;s,m,rnd1,rnd2:integer;entry:words);
begin
p:=false;
rnd1:=random(20)+1;
rnd2:=random(20)+1;
s:=length(entry[x]);
if stuff [rnd1,rnd2]<>'A' then
p:=true;
if (rnd1<20-s) and (rnd2>s) then
if stuff [rnd1,rnd2] ='A' then
for m:=1 to s do
if stuff [rnd1+m,rnd2-m]<>'A' then
p:=true;
if p=false then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
for m:=1 to s do
stuff [rnd1+m,rnd2-m]:=entry[x,m+1];
end;
end;
begin (*main*)
clrscr;
randomize;
fill (stuff);
store (entry,x);
for x:= 1 to 20 do
repeat
keeper:=5;
a:=random(8)+1;
case a of
1:way1 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
2:way2 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
3:way3 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
4:way4 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
5:way5 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
6:way6 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
7:way7 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
8:way8 (stuff,x,keeper,p,rnd1,rnd2,s,m,entry);
end;
until keeper=0;
for a:=1 to 20 do
for x:=1 to 20 do
if stuff [a,x]='A' then
begin
rnd1:=random(26)+65;
j:=chr(rnd1);
stuff[a,x]:=j;
end;
for a:=1 to 20 do
begin
writeln;
for x:=1 to 20 do
write (stuff[a,x]:2);
end;
readln;

End. (*main*)

