program fil_prog2;
(*program by aaron evans*)
(*date due *)
(*date due *)
(*for Mr. Baker*)
uses
crt;
type
file_rec=record
adress,City,name:string;
end;
name_file=file of file_rec;
var
people:name_file;
y,loop,x:integer;
rfile:file_rec;
awnser:char;
begin(*main*)
clrscr;
assign(people,'a:\people.dat');
reset(people);
y:=filesize(people);
seek(people,y);
WRITELN('                         MAILING LIST');
WRITELN;
WRITELN;
WRITELN;
loop:=0;
repeat
with rfile do
begin
WRITELN('Please enter your name');
readln(name);
WRITELN('Please enter your adress');
readln(adress);
writeln('Please enter your city and state');
readln(city);
write(people,rfile);
end;
writeln('are there any more customers?(y or n)');
readln(awnser);
until (awnser='n') or (awnser='N');
reset(people);
x:=filesize(people);
clrscr;
for loop:=1 to x do
begin
read(people,rfile);
with rfile do
writeln(name,adress:24,city:14);
end;
readln;
close(people);
end.(*main*)
