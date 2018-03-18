Program cable;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
const
     o='yes';
var
   a,b,c,d,e,f,g:integer;
   l,m,n,p,w,x,y,z:string;
   total:real;

begin (*main*)
clrscr;
writeln ('Welcome to Cable Connection');
writeln ('Please enter your name');
readln (l);
writeln ('Please enter your address');
readln (m);
writeln ('Please enter your phone number');
readln (n);
writeln ('Please type yes or no in lower case');

writeln ('You get Standard service':10,'$7.00':19);
If o='yes' then
     total:=total+7;
writeln ('Do you want Cable service':10,'$4.00':18);
readln (p);
If (o='yes') and (p='yes') then
   total:=total+4;
If (o<>'yes') or (p<>'yes') then
   writeln ('You must have standard and cable to order premium')
   else
       begin
writeln ('Do you want Home Cinema Channel':4,'$2.00':12);
readln (w);
If (((o='yes') and (p='yes')) and (w='yes')) then
   total:=total+2;
writeln ('Do you want Continual Cartoon Channel':2,'$2.00':6);
readln (x);
If (((o='yes') and (p='yes')) and (x='yes')) then
   total:=total+2;
   end;
writeln ('What year is the bill due? (in numerical value, please)');
readln (e);
writeln ('What month is the bill due? (in numerical value, please)');
readln (a);
writeln ('What day is the bill due? (in numerical value)');
readln (b);
writeln ('What year is it today? (in numerical value)');
readln (f);
writeln ('What month is today? (in numerical value)');
readln (c);
writeln ('What day is today? (in numerical value)');
readln (d);
clrscr;
writeln ('NAME:',l);
writeln ('ADDRESS:',m, 'CURRENT DATE:':29,c,'/',d,'/',f);
writeln ('PHONE NUMBER:',n, 'DUE DATE:':20,a,'/',b,'/',e);
writeln ('SERVICES:');
If o='yes' then
   writeln ('Standard services...............$7.00');
If p='yes' then
   writeln ('Basic services..................$4.00');
If w='yes' then
   writeln ('Home Cinema Channel.............$2.00');
If x='yes' then
   writeln ('Continual Cartoon Channel.......$2.00');
writeln ('$',total:2:2);
If (f>e) then
   begin
   writeln ('Your payment was late. That''s a five percent fee.');
   total:=total*1.05;
   writeln ('$',total:2:2);
   end;
If (f=e) and (c>a) then
   begin
   writeln ('Your payment was late. That''s a five percent fee.');
   total:=total*1.05;
   writeln ('$',total:2:2);
   end;
If (((f=e) and (c=a)) and (d>b)) then
   begin
   writeln ('Your payment was late. That''s a five percent fee.');
   total:=total*1.05;
   writeln ('$',total:2:2);
   end;
readln;
End. (*main*)

