program GRADEBOOK;
(*El CHoDA 3rd period Mr. Baker's class seniors rule the plains of valhala*)
uses
crt;
type
patriarch=array[1..20] of string[20];
wargear=array[1..20,1..40] of string[20];
killer=array[1..20] of integer;
gargoyles=array[1..40,1..20] of killer;
lictor=array[1..20,1..40] of real;
marines=array[1..20] of integer;
var
hive:patriarch;
genestealers:wargear;
dreadnought:gargoyles;
mode,median,stuff:marines;
savg,cavg,retard:lictor;
a,b,c,m,x,g,h,i,j,s,carnifex,y:integer;
tyranid,azmodi,letter,ans:string;
begin {main}
clrscr;
writeln ('Welcome to CHoDA High School grade book wonder');
writeln ('How many classes do you have? (max of ten)');
readln (g);
for s:=1 to g do
begin
writeln ('Input the class name please ');
readln (tyranid);
hive[s]:=tyranid;
writeln ('How many students are in this class?(40 max)');
readln (h);
for b:=1 to h do
begin
writeln ('Input the students name please');
readln (azmodi);
genestealers[s,b]:=azmodi;
writeln ('How many grades does ',azmodi,' have?(maxium of 20)');
readln (m);
stuff[b]:=m;
for a:=1 to m do
begin
writeln ('What is grade number ',a);
readln (dreadnought[b,a,s]);
end;
for a:=1 to m do
begin
savg[s,b]:=savg[s,b]+dreadnought[b,a,s];
savg[s,b]:=savg[s,b]/m;
end;
end;
for b:= 1 to h do
cavg[s,b]:=savg[s,b]+cavg[s,b];
cavg[s,b]:=cavg[s,b]/g;

writeln ('Do you wish to see the results of your maddness?(type yes or no)');
readln (ans);
if ans='yes' then
begin
for s:=1 to g do
begin
writeln (hive[s]);
writeln ('Class avgerage:',cavg[s,b]:2:2);
writeln ('Class median:',median[s]:2);
writeln ('Class mode:',mode[s]:2);
for b:=1 to h do
begin
writeln (genestealers[s,b]);
if genestealers[s,b]='choda' then
writeln ('This boy is a GOD');
for a:=1 to stuff[b] do
writeln ('Grade ',a,'=',dreadnought[b,a,s]);
if savg[s,b]>96 then letter:='+A';
if (savg[s,b]>93) and (savg[s,b]<97) then letter:='A';
if (savg[s,b]>89) and (savg[s,b]<94) then letter:='-A';
if (savg[s,b]>86) and (savg[s,b]<90) then letter:='+B';
if (savg[s,b]>83) and (savg[s,b]<87) then letter:='B';
if (savg[s,b]>79) and (savg[s,b]<84) then letter:='-B';
if (savg[s,b]>76) and (savg[s,b]<80) then letter:='+C';
if (savg[s,b]>73) and (savg[s,b]<77) then letter:='C';
if (savg[s,b]>69) and (savg[s,b]<74) then letter:='-C';
if (savg[s,b]>66) and (savg[s,b]<70) then letter:='+D';
if (savg[s,b]>63) and (savg[s,b]<67) then letter:='D';
if (savg[s,b]>59) and (savg[s,b]<64) then letter:='D';
if savg[s,b]<60 then letter:='F';
writeln ('student avgerage=',savg[s,b]:2:2);
writeln ('Student''s grade is a ',letter);
if savg[s,b]<60 then writeln ('He failed. This student is a fool!!!')
else writeln ('He passed');
readln;
end;
end;
end;
End.