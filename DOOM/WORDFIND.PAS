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
x,rnd1,rnd2,a,keeper,l:integer;
j:char;
yes,super:string;
procedure fill (var stuff:charecter);
begin
for x:=1 to 20 do
for a:=1 to 20 do
stuff[a,x]:='A';
end;
procedure userstore (var entry:words; var l:integer);
begin
writeln ('Please enter a word 5 characters long');
for x:=1 to 20 do
readln (entry[x]);
end;
procedure store (var entry:words);
begin
entry[1]:='water';
entry[2]:='shine';
entry[3]:='sheep';
entry[4]:='choda';
entry[5]:='texas';
entry[6]:='hound';
entry[7]:='docks';
entry[8]:='shirt';
entry[9]:='class';
entry[10]:='cable';
entry[11]:='glass';
entry[12]:='phone';
entry[13]:='shell';
entry[14]:='fines';
entry[15]:='comma';
entry[16]:='names';
entry[17]:='sport';
entry[18]:='stock';
entry[19]:='hello';
entry[20]:='music';
end;
procedure way1 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if rnd2<16 then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1,rnd2+1]='A' then
if stuff [rnd1,rnd2+2]='A' then
if stuff [rnd1,rnd2+3]='A' then
if stuff [rnd1,rnd2+4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1,rnd2+1]:=entry[x,2];
stuff [rnd1,rnd2+2]:=entry[x,3];
stuff [rnd1,rnd2+3]:=entry[x,4];
stuff [rnd1,rnd2+4]:=entry[x,5];
end;
end;
procedure way2 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if rnd1<16 then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1+1,rnd2]='A' then
if stuff [rnd1+2,rnd2+2]='A' then
if stuff [rnd1+3,rnd2+3]='A' then
if stuff [rnd1+4,rnd2+4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1+1,rnd2]:=entry[x,2];
stuff [rnd1+2,rnd2]:=entry[x,3];
stuff [rnd1+3,rnd2]:=entry[x,4];
stuff [rnd1+4,rnd2]:=entry[x,5];
end;
end;
procedure way3(var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if rnd2>5 then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1,rnd2-1]='A' then
if stuff [rnd1,rnd2-2]='A' then
if stuff [rnd1,rnd2-3]='A' then
if stuff [rnd1,rnd2-4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1,rnd2-1]:=entry[x,2];
stuff [rnd1,rnd2-2]:=entry[x,3];
stuff [rnd1,rnd2-3]:=entry[x,4];
stuff [rnd1,rnd2-4]:=entry[x,5];
end;
end;
Procedure way4 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if rnd1>5 then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1-1,rnd2]='A' then
if stuff [rnd1-2,rnd2]='A' then
if stuff [rnd1-3,rnd2]='A' then
if stuff [rnd1-4,rnd2]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1-1,rnd2]:=entry[x,2];
stuff [rnd1-2,rnd2]:=entry[x,3];
stuff [rnd1-3,rnd2]:=entry[x,4];
stuff [rnd1-4,rnd2]:=entry[x,5];
end;
end;
end;
procedure way5 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if (rnd1<16) and (rnd2<16) then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1+1,rnd2+1]='A' then
if stuff [rnd1+2,rnd2+2]='A' then
if stuff [rnd1+3,rnd2+3]='A' then
if stuff [rnd1+4,rnd2+4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1+1,rnd2+1]:=entry[x,2];
stuff [rnd1+2,rnd2+2]:=entry[x,3];
stuff [rnd1+3,rnd2+3]:=entry[x,4];
stuff [rnd1+4,rnd2+4]:=entry[x,5];
end;
end;
procedure way6 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if (rnd1>5) and (rnd2>5) then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1-1,rnd2-1]='A' then
if stuff [rnd1-2,rnd2-2]='A' then
if stuff [rnd1-3,rnd2-3]='A' then
if stuff [rnd1-4,rnd2-4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1-1,rnd2-1]:=entry[x,2];
stuff [rnd1-2,rnd2-2]:=entry[x,3];
stuff [rnd1-3,rnd2-3]:=entry[x,4];
stuff [rnd1-4,rnd2-4]:=entry[x,5];
end;
end;
procedure way7 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if (rnd1>5) and (rnd2<16) then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1-1,rnd2+1]='A' then
if stuff [rnd1-2,rnd2+2]='A' then
if stuff [rnd1-3,rnd2+3]='A' then
if stuff [rnd1-4,rnd2+4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1-1,rnd2+1]:=entry[x,2];
stuff [rnd1-2,rnd2+2]:=entry[x,3];
stuff [rnd1-3,rnd2+3]:=entry[x,4];
stuff [rnd1-4,rnd2+4]:=entry[x,5];
end;
end;
procedure way8 (var stuff:charecter; var keeper:integer;rnd1,rnd2:integer;entry:words);
begin
rnd1:=random(20)+1;
rnd2:=random(20)+1;
if (rnd1<16) and (rnd2>5) then
if stuff [rnd1,rnd2] ='A' then
if stuff [rnd1+1,rnd2-1]='A' then
if stuff [rnd1+2,rnd2-2]='A' then
if stuff [rnd1+3,rnd2-3]='A' then
if stuff [rnd1+4,rnd2-4]='A' then
begin
keeper:=0;
stuff [rnd1,rnd2]:=entry[x,1];
stuff [rnd1+1,rnd2-1]:=entry[x,2];
stuff [rnd1+2,rnd2-2]:=entry[x,3];
stuff [rnd1+3,rnd2-3]:=entry[x,4];
stuff [rnd1+4,rnd2-4]:=entry[x,5];
end;
end;
begin (*main*)
clrscr;
randomize;
fill (stuff);
writeln ('do you want to enter your own words?');
readln (super);
if super='yes' then
userstore(entry,l)
else
store (entry);
for x:= 1 to 20 do
repeat
keeper:=5;
a:=random(8)+1;
case a of
1:way1 (stuff,keeper,rnd1,rnd2,entry);
2:way2 (stuff,keeper,rnd1,rnd2,entry);
3:way3 (stuff,keeper,rnd1,rnd2,entry);
4:way4 (stuff,keeper,rnd1,rnd2,entry);
5:way5 (stuff,keeper,rnd1,rnd2,entry);
6:way6 (stuff,keeper,rnd1,rnd2,entry);
7:way7 (stuff,keeper,rnd1,rnd2,entry);
8:way8 (stuff,keeper,rnd1,rnd2,entry);
end;
until keeper=0;
for a:=1 to 20 do
for x:=1 to 20 do
if stuff [a,x]='A' then
begin
rnd1:=random(26)+97;
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

