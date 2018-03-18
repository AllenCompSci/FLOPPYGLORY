Program fines;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
   a,b,c,d,e,f:integer;
   m,n:string;
   z,y,x,w,s,l,o:real;
begin (*main*)
clrscr;
writeln ('School Libary Program');
writeln ('Paperbacks are 15 cents a day fine');
writeln ('Other general books are 20 cents a day fine');
writeln ('Magazines are 25 cents a day fine');
writeln ('Reference books are 50 cents a day fine');
m:='yes';
while m='yes' do
begin
n:='yes';
while n='yes' do
begin
writeln ('Do you have any:');
writeln ('1)Paperbacks');
writeln ('2)Other general books');
writeln ('3)Magazines');
writeln ('4)Reference books');
readln (f);
case f of
1:begin
writeln ('How many paperbacks do you have late?');
readln (a);
b:=0;
while a<>b do
begin
b:=b+1;
writeln ('How many days has paperback number ', b,' been late');
readln (c);
z:=c*0.15;
y:=y+z;
end;
end;
2:begin
writeln ('How many general books do you have late?');
readln (a);
b:=0;
while a<>b do
begin
b:=b+1;
writeln ('How many days has general book number ', b,' been late');
readln (c);
z:=c*0.2;
w:=w+z;
end;
end;
3:begin
writeln ('How many magazines do you have late?');
readln (a);
b:=0;
while a<>b do
begin
b:=b+1;
writeln ('How many days has magazine number ', b,' been late');
readln (c);
z:=c*0.25;
s:=s+z;
end;
end;
4:begin
writeln ('How many reference books do you have late?');
readln (a);
b:=0;
while a<>b do
begin
b:=b+1;
writeln ('How many days has reference book number ', b,' been late');
readln (z);
z:=c*0.50;
l:=l+z;
end;
end;
end;
writeln ('Do you have any other books late? (type yes or no)');
readln (n);
end;
o:=l+s+y+w;
writeln ('Your total fine equals ',o:2:2);
o:=0;
writeln ('Would you like to run the program again? (type yes or no)');
readln (m);
end;

end. (*main*)

