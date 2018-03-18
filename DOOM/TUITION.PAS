Program tuition;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
   a,b,c,d,e,f:string;
   w,x,y,z,s,m:integer;

begin (*main*)
clrscr;
writeln ('Bursar''s Office at CHoDA State University');
writeln ('Please type student name');
readln (a);
writeln ('Are you a resident or not? (please enter y or n)');
readln (b);
writeln ('Please type number of credit hours');
readln (w);
If b='y' then
   begin
   If (w>0) and (w<5) then
   x:=80*w
   else if (w>4) and (w<13) then
   x:=70*w
   else if (w>12) then
   x:=900
   end
   else
   begin
   If (w>0) and (w<5) then
   x:=120*w
   else if (w>4) and (w<13) then
   x:=110*w
   else if (w>12) then
   x:=1400
   end;
if b='y' then
   b:='YES'
   else b:='NO';
clrscr;
writeln ('State University Tuition Bill');
writeln ('Bill for:',a);
writeln ('Credit hours:',w);
writeln ('Resident:',b);
writeln ('Amount owned:','$',x,'.00');
writeln ('Have a nice day!!!!!');
readln;



End. (*main*)

