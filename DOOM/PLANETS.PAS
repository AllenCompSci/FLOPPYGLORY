Program planet;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
letters=array[1..9] of string;
number=array[1..9] of string;
var
planets:letters;
size,distance,length,moon:number;
x:integer;
ans:string;
begin (*main*)
clrscr;
planets[1]:='Mercury';
planets[2]:='Venus';
planets[3]:='Earth';
planets[4]:='Mars';
planets[5]:='Jupiter';
planets[6]:='Saturn';
planets[7]:='Uranus';
planets[8]:='Neptune';
planets[9]:='Pluto';
size[1]:='4880';
size[2]:='12100';
size[3]:='12756';
size[4]:='6794';
size[5]:='142800';
size[6]:='120660';
size[7]:='51810';
size[8]:='49528';
size[9]:='2290';
distance[1]:='57.9';
distance[2]:='106.2';
distance[3]:='149.6';
distance[4]:='227.9';
distance[5]:='778.3';
distance[6]:='1427';
distance[7]:='2870';
distance[8]:='4497';
distance[9]:='5900';
length[1]:='88 days';
length[2]:='224.7 days';
length[3]:='365.2 days';
length[4]:='141.71 days';
length[5]:='11.86 yrs';
length[6]:='29.46 yrs';
length[7]:='84 yrs';
length[8]:='165 yrs';
length[9]:='248 yrs';
moon[1]:='0';
moon[2]:='0';
moon[3]:='1';
moon[4]:='2';
moon[5]:='16';
moon[6]:='18';
moon[7]:='15';
moon[8]:='8';
moon[9]:='1';
writeln ('welcome to serach of the planets');
writeln (' I am your helpful servant slave I');
repeat
writeln ('enter a number for the corisponing planet');
writeln ('1)Mercury');
writeln ('2)Venus');
writeln ('3)Earth');
writeln ('4)Mars');
writeln ('5)Jupiter');
writeln ('6)Saturn');
writeln ('7)Uranus');
writeln ('8)Neptune');
writeln ('9)Pluto');
readln (x);
writeln (planets[x]);
writeln ('It''s diameter is ',size[x],' kilometers');
writeln ('It is ',distance[x],' kilometers from the sun');
writeln ('It has a year equal to ',length[x]);
writeln ('It has ',moon[x],' moons');
writeln ('Do you wish to see another planet (yes/no)');
readln (ans);
until ans='no'
End. (*main*)

