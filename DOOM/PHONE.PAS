Program phone;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
a,b,c,yes:string;
total:real;
z,y,w,x,crack,butt,farce:integer;
begin
repeat
clrscr;
total:=0;
crack:=0;

writeln ('Welcome to phone program');
writeln ('What is your name');(*your stupid*)
readln (a);
writeln ('What is your address');(*dummy*)
(*the sacred toad has many warts*)
readln (b);
writeln ('What hour did the call begin');
readln (z);
writeln ('Was it A.M. or P.M.');
readln (c);
if c='P.M.' then
z:=z+12;
writeln ('What minute did it begin');
readln (y);
(*the meaning of life is pepperoni*)
writeln ('What hour did the call end');
readln (w);
writeln ('Was it A.M. or P.M.');
readln (c);
(*german class stinks*)
if c='P.M.' then
w:=w+12;
writeln ('What minute did it end');
readln (x);
w:=w*60+x;
z:=z*60+y;
(*I like the new adventures of Jonny Quest*)
if (z>0) and (z<481) then
begin
if w>z then
begin
if (w>0) and (w<481) then
begin
crack:=w-z;
total:=total+crack*0.18;
end;
if (w>480) and (w<1081) then
begin
crack:=w-z;
total:=total+crack*0.18;
w:=w-480;
crack:=w;
total:=total-crack*0.18+crack*0.25;
end;
if (w>1080) and (w<2401) then
begin
crack:=w-z;
total:=total+crack*0.18-600*0.18+600*0.25;
end;
end;

if z>w then
begin
if (w>0) and (w<481) then
begin
total:=total+1500+64.8;
crack:=z-w;
total:=total+crack*0.18;
end
(*the answer is in your shoes, I don't know why, but it is in your shoes*)
else
if (w>480) and (w<1081) then
begin
crack:=w-z;
w:=w-480;
crack:=crack-w;
total:=total+crack*0.18;
crack:=w;
total:=total+(crack*0.25);
end
else
if (w>1080) and (w<2401) then
begin
crack:=w-z;
w:=w-1080;
crack:=crack-w;
total:=total+crack*0.18;
total:=total+150;
crack:=w;
total:=total+crack*0.18;
end;
end;
(*the mighty beast shall be slain
it's name is Blair*)
if (z>480) and (z<1081) then
begin
if w>z then
begin
if (w>480) and (w<1081) then
begin
crack:=w-z;
total:=total+crack*0.25;
end;
if (w>1080) and (w<2401) then
begin
crack:=w-z;
total:=total+crack*0.25;
w:=w-1080;
crack:=w;
total:=total-crack*0.25+crack*0.18;
end;
end;
if z>w then
begin
if (w>480) and (w<1081) then
begin
total:=total+64.8+86.22;
crack:=z-w;
total:=total+crack*0.25;
end
else
begin
total:=total+64.8;
crack:=z-w;
total:=total+crack*0.18;
end;
end
else
if (w>1080) and (w<2401) then
begin        (*before i studder out*)
crack:=w-z;
w:=w-1080;
crack:=crack-w;
total:=total+crack*0.25;
crack:=w;
total:=total+crack*0.18;
end;
end
else
if (w>480) and (w<1080) then
begin
crack:=w-z;
total:=total+crack*0.25;
end;
(*El Choda, El Choda, uber alles*)
if (z>1080) and (z<2401) then
begin
crack:=0;
if z>w then
begin
if (w>0) and (w<481) then
begin
crack:=z-w;(*twinkie*)
total:=total+1500+86.22;
total:=total+crack*0.18;
end;
end;
if w>z then
crack:=w-z;                                             (*choda was here*)
total:=total+crack*0.18;
end;
end;
clrscr;
writeln ('NAME:',a);
writeln ('ADDRESS:',b);
writeln ('TOTAL:',total:2:2);
writeln ('Do You Wish To Ruin The Program Again?(yes or no)');(*not a typing error*)
readln (yes);
total:=0;

until yes='no'
(*the ultimate answer is 42*)
End. (*main*)

