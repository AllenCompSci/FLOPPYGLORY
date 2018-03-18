
Program video;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
movies=array [1..6] of string [50];
stupid=record
vid:movies;
vid_id:movies;
vid_time:movies;
vid_rfees:movies;
lfees:integer;
cards:integer;
other:string;
end;
data=record
name:string[30];
phone:string[8];
address:string;
id:integer;
more:stupid;
end;
kreep=record
mov_name:string[50];
mov_id:string[50];
end;
gear=array[1..20] of data;
checkin=array [1..20] of kreep;
checkout=array [1..20] of kreep;
var
members:gear;
inbox:checkin;
outbox:checkout;
a,b,c,choda,m,error_postion,s,toilet,x,y,z,num,id,keep,h:integer;
stuff:string;


begin (*main*)
repeat
clrscr;
writeln ('Welcome to CHODA''s monster video');
writeln ('What would you like to do today');
writeln ('1)Look at membership');
writeln ('2)Videos that are checked out');
writeln ('3)Videos that have been turned in today');
writeln ('4)Fee totals');
writeln ('5)Print reciept');
writeln ('6)Edit customer membership. (you rent videos here)');
writeln ('7)Quit');
readln (num);
case num of
1:begin
writeln ('Press 1 to enter the customer''s name or 2 to enter thier id number');
readln (z);
if z=1 then begin
writeln ('Enter the customer''s full name and capitalize the entire thing');
readln (stuff);
for z:=1 to 20 do
if stuff=members[z].name then y:=z;
if y<>0 then begin
writeln (members[y].name);
writeln (members[y].phone);
writeln (members[y].address);
writeln (members[y].id);
for z:=1 to 6 do
begin
if members[y].more.vid[z]<>''then begin
write (members[y].more.vid[z],'   ');
write (members[y].more.vid_id[z],'    ');
write (members[y].more.vid_time[z],'    ');
writeln (members[y].more.vid_rfees[z]);
end;
writeln (members[y].more.lfees);
writeln (members[y].more.cards);
writeln (members[y].more.other);
readln;
end;
end;
end
else
begin
writeln ('Enter in the customers id number');
readln (id);
for z:=1 to 20 do
if members[z].id=id then y:=z;
if y<>0 then begin
writeln (members[y].name);
writeln (members[y].phone);
writeln (members[y].address);
writeln (members[y].id);
for z:=1 to 6 do
begin
if members[y].more.vid[z]<>''then begin
write (members[y].more.vid[z],'   ');
write (members[y].more.vid_id[z],'    ');
write (members[y].more.vid_time[z],'    ');
writeln (members[y].more.vid_rfees[z]);
end;
writeln (members[y].more.lfees);
writeln (members[y].more.cards);
writeln (members[y].more.other);
readln;
end;
end;
end;
end;
2:begin
x:=1;
while length(outbox[x].mov_name)<>0 do
begin
writeln ('Movie ',x,':',outbox[x].mov_name);
writeln ('ID number:',outbox[x].mov_id);
inc(x);
readln;
end;
end;
3:begin
x:=1;
while length(inbox[x].mov_name)<>0 do
begin
writeln ('Movie ',x,':',inbox[x].mov_name);
writeln ('ID number:',inbox[x].mov_id);
inc (x);
readln;
end;
end;
4:begin
for x:=1 to 20 do
z:=z+(members[x].more.lfees);
for x:=1 to 20 do
for y:=1 to 6 do
begin
val (members[x].more.vid_rfees[y],m,error_postion);
z:=z+m;
end;
writeln ('Fees collected today:',z);
readln;
end;
5:begin
writeln ('Press 1 to enter the customer''s name or 2 to enter thier id number');
readln (z);
if z=1 then begin
writeln ('Enter the customer''s full name and capitalize the entire thing');
readln (stuff);
for z:=1 to 20 do
if stuff=members[z].name then y:=z;
if y<>0 then begin
writeln (members[y].name);
writeln (members[y].phone);
writeln (members[y].address);
writeln (members[y].id);
for z:=1 to 6 do
begin
if members[y].more.vid[z]<>''then begin
write (members[y].more.vid[z],'   ');
write (members[y].more.vid_id[z],'    ');
write (members[y].more.vid_time[z],'    ');
writeln (members[y].more.vid_rfees[z]);
readln;
end;
end;
end;
end
else
begin
writeln ('Enter in the customers id number');
readln (id);
for z:=1 to 20 do
if members[z].id=id then y:=z;
if y<>0 then begin
writeln (members[y].name);
writeln (members[y].phone);
writeln (members[y].address);
writeln (members[y].id);
for z:=1 to 6 do
begin
if members[y].more.vid[z]<>''then begin
write (members[y].more.vid[z],'   ');
write (members[y].more.vid_id[z],'    ');
write (members[y].more.vid_time[z],'    ');
writeln (members[y].more.vid_rfees[z]);
readln;
end;
end;
end;
end;
end;
6:begin
writeln ('Press 1 to enter in the customer''s name or 2 to enter in the id code or 3 to create a brand new one');
readln (s);
if s=1 then begin
writeln ('Enter the customer''s full name and capitalize the entire thing');
readln (stuff);
for z:=1 to 20 do
if stuff=members[z].name then y:=z;
if y<>0 then begin
keep:=y;
writeln (members[y].name);
writeln (members[y].phone);
writeln (members[y].address);
writeln (members[y].id);
for z:=1 to 6 do
begin
if members[y].more.vid[z]<>''then begin
write (members[y].more.vid[z],'   ');
write (members[y].more.vid_id[z],'    ');
write (members[y].more.vid_time[z],'    ');
writeln (members[y].more.vid_rfees[z]);
end;
writeln (members[y].more.lfees);
writeln (members[y].more.cards);
writeln (members[y].more.other);
readln;
end;
end;
end;
if s=2 then begin
writeln ('Enter in the customers id number');
readln (id);
for z:=1 to 20 do
if members[z].id=id then y:=z;
if y<>0 then begin
keep:=y;
writeln (members[y].name);
writeln (members[y].phone);
writeln (members[y].address);
writeln (members[y].id);
for z:=1 to 6 do
begin
if members[y].more.vid[z]<>''then begin
write (members[y].more.vid[z],'   ');
write (members[y].more.vid_id[z],'    ');
write (members[y].more.vid_time[z],'    ');
writeln (members[y].more.vid_rfees[z]);
end;
writeln (members[y].more.lfees);
writeln (members[y].more.cards);
writeln (members[y].more.other);
readln;
end;
end;
writeln ('If you wish to edit the membership, press 1, otherwise press 2');
readln (toilet);
if toilet=1 then begin
writeln ('Edit in the new name');
readln (members[keep].name);
writeln ('Edit in the new phone number');
readln (members[keep].phone);
writeln ('Edit in the new address');
readln (members[keep].address);
writeln ('Edit in the new id number');
readln (members[keep].id);
writeln ('Edit in the number of cards they own');
readln (members[keep].more.cards);
writeln ('Edit in any miscellaneous information');
readln (members[keep].more.other);
end
else
begin
for y:= 1 to 20 do
if length (members[y].name)=0 then
y:=keep;
if length(members[20].name)<>0 then
writeln ('There is no room for any new memberships, buy more memory')
else
begin
writeln ('Edit in the new name');
readln (members[keep].name);
writeln ('Edit in the new phone number');
readln (members[keep].phone);
writeln ('Edit in the new address');
readln (members[keep].address);
writeln ('Edit in the new id number');
readln (members[keep].id);
writeln ('Edit in the number of cards they own');
readln (members[keep].more.cards);
writeln ('Edit in any miscellaneous information');
readln (members[keep].more.other);
end;
end;
end
else
begin

writeln ('Enter in the number of titles that you wish to rent');
readln (h);
for a:=1 to h do
begin
writeln ('Enter in the movie name');
readln (members[keep].more.vid[a]);
for b:=1 to 200 do
if outbox[b].mov_name='' then c:=b;
outbox[c].mov_name:=members[keep].more.vid[a];
writeln ('Enter in the movie id');
readln (members[keep].more.vid_id[a]);
outbox[b].mov_id:=members[keep].more.vid_id[a];
writeln ('Enter in the video rental fee');
readln (members[keep].more.vid_rfees[a]);
writeln ('Enter in the video due date');
readln (members[keep].more.vid_time[a]);
end;
end;
end;
7:choda:=573;
end;
until choda=573;
End. (*main*)

