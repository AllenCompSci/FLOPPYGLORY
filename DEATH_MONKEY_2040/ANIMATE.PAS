program animate;
(*program by Jim Gifford*)
(*date due *)
(*for Mr. Baker*)
uses
graph,crt;
var size1,size2:word;
p,o,i,n:pointer;
y:integer;
GRDRIVER,GRMODE,GRERROR,LOOP,num:INTEGER;
PROCEDURE GDRIVE(VAR GRDRIVER,GRMODE,GRERROR:INTEGER);
BEGIN
GRDRIVER:=DETECT;
INITGRAPH(GRDRIVER,GRMODE,'C:\TP\BGI\');
GRERROR:=GRAPHRESULT;
IF GRERROR<>GROK THEN
WRITELN('GRAPHICS ERROR:',GRAPHERRORMSG(GRERROR));
END;
begin    {main}
GDRIVE(grdriver,grmode,grerror);
setcolor(9);
delay(500);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
size2:=imagesize(270,330,330,450);
getmem(i,size2);
getimage(270,330,330,450,i^);
setcolor(black);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
getmem(n,size2);
getimage(270,330,330,450,n^);
putimage(270,330,i^,normalput);
setcolor(green);
rectangle(0,451,getmaxx,getmaxy);
setfillstyle(1,green);
floodfill(10,460,green);
setcolor(yellow);
arc(100,350,0,180,21);
arc(100,350,0,180,22);
line(79,350,79,400);
line(121,350,121,400);
setcolor(white);
circle(100,350,20);
line(100,370,100,425);
line(70,390,130,390);
line(100,425,80,450);
line(100,425,120,450);
size1:=imagesize(70,325,130,450);
getmem(p,size1);
getimage(70,325,130,450,p^);
setcolor(black);
arc(100,350,0,180,21);
arc(100,350,0,180,22);
line(79,350,79,400);
line(121,350,121,400);
circle(100,350,20);
line(100,370,100,425);
line(70,390,130,390);
line(100,425,80,450);
line(100,425,120,450);
getmem(o,size2);
getimage(70,325,130,450,o^);
{putimage(70,325,p^,normalput);}
for y:=1 to 150 do
begin
putimage(60+y,325,p^,normalput);
putimage(480-y,325,p^,normalput);
delay(1);
putimage(60+y,325,o^,normalput);
putimage(480-y,325,o^,normalput);
end;
putimage(60+y,325,p^,normalput);
putimage(480-y,325,p^,normalput);
setcolor(white);
circle(295,342,1);
circle(305,342,1);
for y:=1 to 90 do
begin
arc(300,350,270-y,270+y,10);
delay(10);
end;
readln;
closegraph;
end. (*main*)