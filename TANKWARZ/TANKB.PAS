program tanka;
{Andrew Short
Computer Science p.3
Mr. Baker}
  {$G+}
(*http://www.cs.odu.edu/~ruett_j/starawars2/starwars.html*)
(*www.cms.uncwil,edu/~rodrigu/starwars/starwars.html*)
uses dos,crt,graph;
const
z=7;
a=35;
bgc=0;
dma    = 4096;

type
  rcd=record (*Record for keeping track of player statistics*)
      nam:string[25];    (*Player name*)
      x,y,hits_left,wins,bulx,buly:integer;  (*Hits left till death, Rounds won*)
      dir,firedir:char;
      hit,fired:boolean;
      pic:pointer;
   end;
  id_t   = Array[1..4] of Char;
      riff_t = Record
                R_Ident : id_t;
                length  : Longint;
                C_Ident : id_t;
                S_Ident : id_t;
                s_length: Longint;
                Format  ,
                Modus   : Word;
                freq    ,
                byte_p_s: LongInt;
                byte_sam,
                bit_sam : Word;
                D_Ident : id_t;
                d_length: LongInt;
              End;
      blaster_T = Record
                    port : Word;
                    dmac ,
                    hdmac,
                    irq  : Byte;
                  End;
      buffer_T = Array[1..dma] of Byte;

var
GrDriver,grmode,grerror,i,j,h1c,h2c:integer;
p,pd,pr,pl,pb:pointer;
size :word;
c:char;
son:boolean;
as,hy:rcd;   (*Player 1 (Andrew) record, Player 2 (Hyrum) record*)
instruct:text; (*instruction variable*)
id:riff_T;
fn:string;
wav:File;
sbb:Word;
Ende,nocando:Boolean;
blaster:Blaster_T;
alt_irq:Pointer;
dma_buf_1,dma_buf_2,zwi:^Buffer_T;
Channel:Byte;

Const RIFF : id_t = ('R','I','F','F');
      WAVE : id_t = ('W','A','V','E');
      FMT_ : id_t = ('f','m','t',' ');
      DATA : id_t = ('d','a','t','a');

      DMA_Dat : Array [0..7,1..6] of Byte=
                  (($A,$C,$B,$0,$87,$1),
                   ($A,$C,$B,$2,$83,$3),
                   ($A,$C,$B,$4,$81,$5),
                   ($A,$C,$B,$6,$82,$7),
                   ($D4,$D8,$D6,$C0,$8F,$C2),
                   ($D4,$D8,$D6,$C4,$8B,$C6),
                   ($D4,$D8,$D6,$C8,$89,$CA),
                   ($D4,$D8,$D6,$CC,$8A,$CE));
(*
son: sound toggle
GrDriver,grmode,grerror: graphics
i,j: loop variables
p,pd,pr,pl,as.pic,hy.pic:tank picture locations
size: size of pictures
c: readkey variable
as.bulx,hy.bulx,as.buly,hy.buly: give location of bullets
as.firedir,hy.firedir: direction bullet is heading
instruct: instruction file
  *)
Procedure Blaster_Command(c :Byte); Assembler;
Asm
    Mov dx,Word Ptr sbb
    Add dx,$c
 @t:In al,dx
    And al,128
    Jnz @t
    Mov al,c
    Out dx,al
End;

Procedure Init_SB(base : Word; var nocando:boolean);
Var w,w2:Word;
Begin
  sbb:=base;
  Port[base+6]:=1; Delay(4); Port[base+6]:=0; w:=0; w2:=0;
  Repeat
    Repeat Inc(w); Until ((Port[base+$e] and 128)=128) or (w>29);
    Inc(w2);
  Until (Port[base+$a]=$AA) or (W2>30);
  If w2>30 then
    Begin
      (*WriteLn('Failed to ReSet Blaster');*)
      nocando:=true;
    End;
  if not (nocando=true) then
  Blaster_Command($d1);
End;

Procedure Set_Stereo; Assembler;
Asm
  Mov dx,Word Ptr sbb
  Add dx,$4
  Mov al,$e
  Out dx,al
  Inc dx
  In al,dx
  And al,253
  Or al,2
  Out dx,al
End;

Procedure Clear_Stereo; Assembler;
Asm
  Mov dx,Word Ptr sbb
  Add dx,$4
  Mov al,$e
  Out dx,al
  Inc dx
  In al,dx
  And al,253
  Out dx,al
End;

Function No_Wave(Var id:riff_T):Boolean;
Begin
  With id do
    No_Wave:=(R_Ident<>RIFF) or
             (C_Ident<>WAVE) or
             (S_Ident<>FMT_) or
             (D_Ident<>DATA);
End;

Procedure Init(bob:string; var nocando:boolean);
Var b : Byte;
Begin
  (*WriteLn;
  WriteLn('ABo WAV-Player (16bit Test)      (p) 27.11.94 ABo');*)
  Blaster.Port:=0;
  Blaster.dmac:=0;
  Blaster.hdmac:=0;
  Blaster.irq:=0;
  fn:=GetEnv('BLASTER');
  If fn='' then
    Begin
      (*WriteLn('BLASTER must be set...');*)
      nocando:=true;
    End;
  b:=1;
  Repeat
    Case fn[b] of
      'A' : Repeat
              Inc(b);
              Blaster.Port:=Blaster.Port*16+Ord(fn[b])-48;
            Until Fn[b+1]=' ';
      'D' : Begin
              Blaster.DMAc:=Ord(fn[b+1])-48;
              Inc(b,2);
            End;
      'I' : Repeat
              Inc(b);
              Blaster.IRQ:=Blaster.IRQ*16+Ord(fn[b])-48;
            Until Fn[b+1]=' ';
      'H' : Begin
              Blaster.hDMAc:=Ord(fn[b+1])-48;
              Inc(b,2);
            End;
        End;
    Inc(b);
  Until b>Length(fn);
  With Blaster do
    (*WriteLn('Blaster : P',Port,'  I',irq,'  D',dmac,'  H',hdmac);*)
  Init_SB(Blaster.Port,nocando);
  If ParamCount>0 then
    fn:=ParamStr(1)
  Else
    Begin
       fn:=bob(*'c:\gdapps\clpmedia\sounds\applause.wav'*);
    End;
  Assign(wav,fN);
  {$I-} ReSet(wav,1); {$I+}
  If IOResult<>0 then
    Begin
      (*WriteLn('File "',fn,'" not found!');*)
      nocando:=true;
    End;
  if nocando<>true then BlockRead(wav,id,Sizeof(id));
  If no_Wave(id) then
    Begin
      (*writeLn('"',fn,'" seems to be no WAVE-File...');*)
      nocando:=true;
    End;
  (*Write('Wave    : ',id.bit_sam,'bit ');*)
  If id.Modus=2 then
    Begin
      Set_Stereo;
      (*Write('stereo ');*)
    End
  Else
    Begin
      Clear_Stereo;
      (*Write('mono    ');*)
    End;
  If (id.bit_sam>8) and (Blaster.hdmac>3) then
    Channel:=Blaster.hdmac
  Else Channel:=Blaster.dmac;
  (*WriteLn(id.freq,' Hz  ',id.byte_p_s,' Bytes/Sec');
  WriteLn('Length  : ',id.d_length,' Bytes    ',id.d_length div id.byte_p_s, ' Sec');
  WriteLn('Playing : ',fn);*)
End;

{$F+}
Procedure Stelle_DMA(Freq: Word;Var size : Word);
Var PageNr,PageAdress,DMALength: Word;
Begin
  Inline($FA);
  Asm
    Mov ax,Word Ptr DMA_Buf_1[2]
    Shr ax,12
    Mov Word Ptr PageNr,ax
    Mov ax,Word Ptr DMA_Buf_1[2]
    Shl ax,4
    Mov Word Ptr PageAdress,ax
    Mov ax,Word Ptr DMA_Buf_1
    Add Word Ptr PageAdress,ax
    Adc Word Ptr PageNr,0
  End;
  DMALength:=Size;
  Freq:=256-Trunc(1000000/Freq);
  If Channel>3 then
    Begin
      DMALength:=DMALength div 2;
      PageAdress:=PageAdress div 2;
      If Odd(PageNr) then
        Begin
          Dec(PageNr);
          PageAdress:=PageAdress+$8000
        End;
    End;
  If id.Modus=2 then
    Begin
      If id.bit_sam=16
        then Blaster_Command($A4)
        Else Blaster_Command($A8);
    End
  Else
    If id.bit_sam=16
      then Blaster_Command($A4);

  Dec(DMALength);

  Port[DMA_dat[Channel,1]]:=$4 or (Channel and $3);
  Port[DMA_dat[Channel,2]]:=$0;
  Port[DMA_dat[Channel,3]]:=$49;
  Port[DMA_dat[Channel,4]]:=lo(PageAdress);
  Port[DMA_dat[Channel,4]]:=hi(PageAdress);
  Port[DMA_dat[Channel,5]]:=lo(PageNr);
  Port[DMA_dat[Channel,6]]:=lo(DMALength);
  Port[DMA_dat[Channel,6]]:=hi(DMALength);
  Port[DMA_dat[Channel,1]]:=(Channel and $3);

  Blaster_Command($40);
  Blaster_Command(Lo(Freq));
  Blaster_Command($48);
  Blaster_Command(lo(DMALength));
  Blaster_Command(hi(DMALength));
  Blaster_Command($91);
  Inline($FB);
End;

Procedure Ausgabe_IRQ; Interrupt;
Var test : Byte;
Begin
  Inline($FA);
  Port[$20]:=$20;
  test:=Port[sbb+$e];
  Ende:=True;
  Inline($fB);
End;
{$F-}

Procedure Play;
Var  p,s,s2 : Word;
    w      : LongInt;
Begin
  GetMem(zwi,16);
  GetMem(dma_buf_1,dma);
  p:=16;
  While (Seg(dma_buf_1^[1]) mod 4096)>(4096-(dma*2 div 16)) do
    Begin
      FreeMem(dma_buf_1,dma);
      FreeMem(zwi,p);
      p:=p+16;
      If p>65525 then halt(111);
      GetMem(zwi,p);
      GetMem(dma_buf_1,dma);
    End;
  GetMem(dma_buf_2,dma);
  FreeMem(zwi,p);
  port[$21]:=Port[$21] and (255 xor (1 shl Blaster.IRQ));
  GetIntVec(Blaster.IRQ+8,Alt_irq);
  SetIntVec(Blaster.IRQ+8,@Ausgabe_IRQ);
  w:=id.freq*id.modus;
  BlockRead(wav,dma_buf_1^[1],dma,s);
  Repeat
    Ende:=False;
    Stelle_DMA(w,s);
    BlockRead(wav,dma_buf_2^[1],dma,s2);
    Repeat Until Ende;
    s:=s2;
    zwi:=dma_buf_1;
    dma_buf_1:=dma_buf_2;
    dma_buf_2:=zwi;
  Until EoF(wav) or Keypressed;
  While KeyPressed do w:=Ord(ReadKey);
  If EoF(wav) then
    Begin
      Ende:=False;
      Stelle_DMA(w,s);
      Repeat Until Ende;
    End;
  SetintVec(Blaster.IRQ+8,Alt_IRQ);
  FreeMem(dma_buf_1,dma);
  FreeMem(dma_buf_2,dma);
  Port[$21]:=Port[$21] or (1 shl Blaster.IRQ);
  Blaster_Command($d3);
  close(wav);
End;

procedure intgraph (var Grdriver,grmode,grerror:integer);
begin               (*initialize graphics*)
GrDriver:= Detect;
InitGraph (GrDriver, Grmode,'');
GrError:=GraphResult;
If GrError<> GrOk
Then Writeln ('Graphics error: ', GraphErrorMsg (GrError));
end;

function bpf:integer;
begin
bpf:=getmaxy-60;     (*defines end of playing field and begining of status bar*)
end;

function checkpixel (x,y:integer):boolean;
 (*determine if tanks new location is empty *)
begin
if (getpixel(x,y)=bgc)and (getpixel(x+50,y)=bgc)and (getpixel(x,y+50)=bgc)and (getpixel(x+50,y+50)=bgc)
and (getpixel(x+25,y)=bgc)and (getpixel(x,y+25)=bgc)and (getpixel(x+25,y+50)=bgc)and (getpixel(x+50,y+25)=bgc)
then checkpixel:=true
else checkpixel:=false;
end;

procedure tankplace (var x,y:integer);
begin           (*chooses empty location to randomly place tanks*)
repeat
x:=random(getmaxx-100)+50;
y:=random(bpf-100)+50;
until checkpixel (x,y);


end;

procedure draw_house (x,y:integer);
var i:integer;
begin
setfillstyle (solidfill,brown);
bar (x+0,y+0,x+60,y+36);
setcolor (lightgray);
for i:= 0 to 4 do
rectangle (x+i,y+i,x+60-i,y+36-i);
(*line (0,0,60,36);
line (0,36,60,0); *)
outtextxy (X+10,y+14,'HOUSE');
end;

procedure draw_tree(x,y:integer);
begin
   setfillstyle(solidfill,2);
   bar(x,y,x+36,y+42);
   setfillstyle(solidfill,10);
   setcolor(2);
   fillellipse(x+18,y+21,18,21);
   outtextxy(x+4,y+19,'Tree');
end;

procedure draw_rock(x,y,dir:integer);
begin
   setfillstyle(solidfill,7);
   setcolor(7);
   fillellipse(x+23,y+24,23,24);
   if dir=1 then fillellipse(x,y+24,18,12);
   if dir=2 then fillellipse(x+23,y,12,18);
   if dir=3 then fillellipse(x+46,y+24,18,12);
   if dir=4 then fillellipse(x+23,y+48,12,18);
   setcolor(8);
   outtextxy(x+9,y+19,'Rock');
end;

procedure draw_field;
var
   i,j,x,y,dir:integer;
   bx,by:integer;

begin

bx:=getmaxx;
by:=bpf;
setcolor (2);
for i := 0 to z  do
rectangle (0+i,0+i,bx-i,by-i);

   j:=random(2)+4;
   for i:=1 to j do begin
      x:=random(getmaxx-82)+18;
      y:=random(bpf-84)+18;
      dir:=random(4)+1;
      case dir of
         1:begin
if(getpixel(x-18,y)=0)and(getpixel(x-18,y+48)=0)and(getpixel(x+46,y)=0)and(getpixel(x+46,y+48)=0) then begin
               setfillstyle(solidfill,2);
               bar(x-18,y,x+46,y+48);
            end;
         end;
         2: begin
if(getpixel(x,y-18)=0)and(getpixel(x,y+48)=0)and(getpixel(x+46,y-18)=0)and(getpixel(x+46,y+48)=0) then begin
               setfillstyle(solidfill,2);
               bar(x,y-18,x+46,y+48);
            end;
         end;
         3: begin
if(getpixel(x,y)=0)and(getpixel(x,y+48)=0)and(getpixel(x+64,y)=0)and(getpixel(x+64,y+48)=0) then begin
               setfillstyle(solidfill,2);
               bar(x,y,x+66,y+48);
            end;
         end;
         4: begin
if(getpixel(x,y)=0)and(getpixel(x,y+66)=0)and(getpixel(x+46,y)=0)and(getpixel(x+46,y+66)=0) then begin
               setfillstyle(solidfill,2);
               bar(x,y,x+46,y+66);
            end;
         end;
      end;
      draw_rock(x,y,dir);
   end;
   j:=random(2)+4;
   for i:=1 to j do begin
      x:=random(getmaxx-36);
      y:=random(bpf-42);
if (getpixel(x,y)=0) and (getpixel(x,y+42)=0) and (getpixel(x+36,y)=0) and (getpixel(x+36,y+42)=0) then draw_tree(x,y);
   end;


j:=random (3);
for i:= 1 to j do
begin
x:=random(getmaxx-36);
      y:=random(bpf-42);
if (getpixel(x,y)=0)and (getpixel(x+60,y)=0) and (getpixel(x,y+36)=0) and (getpixel(x+60,y+36)=0) then draw_house (x,y);
end;

end;

procedure myinit (var as,hy:rcd);
begin                    (*initialize variables*)
hy.hits_left:=5;       (*reset hits to *)
as.hits_left:=5;
setbkcolor (green);
draw_field;        (*draw playing field*)
tankplace (as.x,as.y);   (*randomly place tanks on field*)
putimage (as.x,as.y,p^,notput);
tankplace (hy.x,hy.y);
putimage (hy.x,hy.y,p^,normalput);
hy.pic:=p;            (**)       (*initialize direction of tanks*)
as.pic:=p;                (**)
as.dir:='U';              (**)
hy.dir:='U';          (**)
hy.wins:=0;  (*reset win counters*)
as.wins:=0;

end;

function str1(inpute:integer):string;    (*Function to convet integers to strings*)
var
   fun:string;  (*Converted String*)
begin
   str(inpute,fun);
   str1:=fun;
end;



procedure show_score(var as,hy:rcd; pl,pr:pointer;var c:char; son:boolean);
(*Procedure to draw status bar at bottom*)
var
h,i,j,k,l,m,xi,yi:integer;

begin
   if as.hits_left=0 then begin    (*Checks to see if Andrew is dead, and takes action accordingly*)
      {following code sets up status bar}
      setfillstyle(solidfill,0);
   setcolor(9);
   if (as.nam='INVISIBLE') and (hy.nam='BULLETS') then
   begin
   outtextxy(30,425,'Andrew Short');
   outtextxy(350,425,'Hyrum Wright');
   end else
   begin
   outtextxy(30,425,as.nam);
   outtextxy(350,425,hy.nam);
   end;
   setcolor(5);
   outtextxy(350,445,concat('Rounds Taken:  ',str1(hy.wins)));
   outtextxy(30,445,concat('Rounds Taken:  ',str1(as.wins)));
   setcolor (15);
   outtextxy (5,getmaxy-10,'Press ''ESC'' to quit to menu');
   setcolor(6);
   line(0,getmaxy-60,getmaxx,getmaxy-60);
   line(getmaxx div 2,getmaxy-60,getmaxx div 2, getmaxy);
   setfillstyle(solidfill,15);
   bar(200,440,300,460);
   bar(520,440,620,460);
   setfillstyle(solidfill,4);
   bar(521,441,519+hy.hits_left*20,459);
   bar(201,441,199+as.hits_left*20,459);
   setfillstyle(solidfill,15);
      bar(200,440,300,460);

      {following code draws explosions}
      putimage (as.x,as.y,as.pic^,andput);
      l:=as.x+25; {l,m are xy coordanants for center of explosion}
      m:=as.y+25;
      j:=20;        {j is radius}
      repeat
      for i:=1 to 100 do begin
      repeat
      k:=random (2)+1;
      case k of
      1:xi:=l-random (j);     {random chooses placement of pixel in circle}
      2:xi:=l+random (j);
      end;
      k:=random (2)+1;
      case k of
      1:yi:=m-random (j);
      2:yi:=m+random (j);
      end;
      until sqr((xi-l))+sqr((yi-m))<=sqr(j);
      k:=random (5)+1;               {random chooses color of pixel}
      case k of
      1,3,4,5:putpixel(xi,yi,red);
      2:putpixel(xi,yi,yellow);
      end;

      end;
      delay (100);

      j:=j+3;
      until j>=100;

      setfillstyle (solidfill,green);
      bar (200,200,570,210);
         if (as.nam='INVISIBLE') and (hy.nam='BULLETS') then
   begin
         outtextxy(200,200,concat('Hyrum Wright',' has taken this Round!'));
   end else
   begin
         outtextxy(200,200,concat(hy.nam,' has taken this Round!'));
   end;

       inc(hy.wins);
      as.hits_left:=5;
      hy.hits_left:=5;

      k:=random (7)+1;                     {random chooses end sound}
      case k of
      1:Init('applause.wav',nocando);
      2:Init('master.wav',nocando);
      3:Init('all2easy.wav',nocando);
      4:Init('dontmake.wav',nocando);
      5:Init('impresiv.wav',nocando);
      6:Init('piece.wav',nocando);
      7:Init('sorry.wav',nocando);

      end;

      if (nocando<>true) and (son=true) then Play;
      cleardevice;
      c:=#255;

      draw_field;
      tankplace (as.x,as.y);
      putimage (as.x,as.y,p^,notput);
      tankplace (hy.x,hy.y);
      putimage (hy.x,hy.y,p^,normalput);
      hy.pic:=p;
      as.pic:=p;
      as.dir:='U';
      hy.dir:='U';

   end;
   if hy.hits_left=0 then begin   (*Checks to see if Hyrum is dead, and takes action accordingly*)
         setfillstyle(solidfill,0);
   setcolor(9);
   if (as.nam='INVISIBLE') and (hy.nam='BULLETS') then
   begin
   outtextxy(30,425,'Andrew Short');
   outtextxy(350,425,'Hyrum Wright');
   end else
   begin
   outtextxy(30,425,as.nam);
   outtextxy(350,425,hy.nam);
   end;
   setcolor(5);
   outtextxy(350,445,concat('Rounds Taken:  ',str1(hy.wins)));
   outtextxy(30,445,concat('Rounds Taken:  ',str1(as.wins)));
   setcolor (15);
   outtextxy (5,getmaxy-10,'Press ''ESC'' to quit to menu');
   setcolor(6);
   line(0,getmaxy-60,getmaxx,getmaxy-60);
   line(getmaxx div 2,getmaxy-60,getmaxx div 2, getmaxy);
   setfillstyle(solidfill,15);
   bar(200,440,300,460);
   bar(520,440,620,460);
   setfillstyle(solidfill,4);
   bar(521,441,519+hy.hits_left*20,459);
   bar(201,441,199+as.hits_left*20,459);
      setfillstyle (solidfill,15);
      bar (520,440,620,460);



      putimage (hy.x,hy.y,hy.pic^,xorput);
      l:=hy.x+25;
      m:=hy.y+25;
      j:=20;
      repeat
      for i:=1 to 100 do begin
      repeat
      k:=random (2)+1;
      case k of
      1:xi:=l-random (j);
      2:xi:=l+random (j);
      end;
      k:=random (2)+1;
      case k of
      1:yi:=m-random (j);
      2:yi:=m+random (j);
      end;
      until sqr((xi-l))+sqr((yi-m))<=sqr(j);
      k:=random (5)+1;
      case k of
      1,3,4,5:putpixel(xi,yi,red);
      2:putpixel(xi,yi,yellow);
      end;

      end;
      delay (100);

      j:=j+3;
      until j>=100;

      setfillstyle (solidfill,green);
      bar (200,200,570,210);
      if (as.nam='INVISIBLE') and (hy.nam='BULLETS') then
   begin
         outtextxy(200,200,concat('Andrew Short',' has taken this Round!'));
   end else
   begin
         outtextxy(200,200,concat(as.nam,' has taken this Round!'));
   end;


      inc(as.wins);
      as.hits_left:=5;
      hy.hits_left:=5;

      k:=random (7)+1;
      case k of
      1:Init('applause.wav',nocando);
      2:Init('master.wav',nocando);
      3:Init('all2easy.wav',nocando);
      4:Init('dontmake.wav',nocando);
      5:Init('impresiv.wav',nocando);
      6:Init('piece.wav',nocando);
      7:Init('sorry.wav',nocando);

      end;

      if (nocando <> true) and (son=true) then Play;
      cleardevice;
      c:=#255;
      draw_field;
      tankplace (as.x,as.y);
      putimage (as.x,as.y,p^,notput);
      tankplace (hy.x,hy.y);
      putimage (hy.x,hy.y,p^,normalput);
      hy.pic:=p;
      as.pic:=p;
      as.dir:='U';
      hy.dir:='U';

   end;
   (*Draws status bar at bottom of screen*)
   setfillstyle(solidfill,0);
   setcolor(9);
   if (as.nam='INVISIBLE') and (hy.nam='BULLETS') then
   begin
   outtextxy(30,425,'Andrew Short');
   outtextxy(350,425,'Hyrum Wright');
   end else
   begin
   outtextxy(30,425,as.nam);
   outtextxy(350,425,hy.nam);
   end;
   setcolor(5);
   outtextxy(350,445,concat('Rounds Taken:  ',str1(hy.wins)));
   outtextxy(30,445,concat('Rounds Taken:  ',str1(as.wins)));
   setcolor (15);
   outtextxy (5,getmaxy-10,'Press ''ESC'' to quit to menu');
   setcolor(6);
   line(0,getmaxy-60,getmaxx,getmaxy-60);
   line(getmaxx div 2,getmaxy-60,getmaxx div 2, getmaxy);
   setfillstyle(solidfill,15);
   bar(200,440,300,460);
   bar(520,440,620,460);
   setfillstyle(solidfill,4);
   bar(521,441,519+hy.hits_left*20,459);
   bar(201,441,199+as.hits_left*20,459);


end;

procedure tank_hit(var perhit:rcd); (*Deducts from hits_left if the tank is hit*)
begin
   with perhit do begin
      dec(hits_left);
   end;
end;


procedure tankdraw (i:integer;var p,pd,pr,pl,pb:pointer;var size:word; var as,hy:rcd);
begin                  (*draw pictures *)
setfillstyle (solidfill,4);  {draw tank facing up }
bar (0,0,50,50);
for i:= 0 to 16 do begin
if odd (i) then setfillstyle (solidfill,4) else setfillstyle (solidfill,lightcyan);
if i=16 then bar(43,i*3,50,(i*3)+2)else bar (43,i*3,50,(i*3)+3);
if i=16 then bar(0,i*3,7,(i*3)+2)else bar (0,i*3,7,(i*3)+3);
end;
setfillstyle (solidfill,lightcyan);
bar (13,23,37,41);
bar (23,5,27,21);  (*barrel*)
line (7,0,7,50);
line (43,0,43,50);
size:=imagesize (0,0,50,50);  {put picture in mem}
getmem (p,size);
getimage (0,0,50,50,p^);
putimage (0,0,p^,xorput);
(******************************************************************)
(*down*)
setfillstyle (solidfill,4);
bar (0,0,50,50);
for i:= 0 to 16 do begin
if odd (i) then setfillstyle (solidfill,4) else setfillstyle (solidfill,lightcyan);
if i=16 then bar(43,i*3,50,(i*3)+2)else bar (43,i*3,50,(i*3)+3);
if i=16 then bar(0,i*3,7,(i*3)+2)else bar (0,i*3,7,(i*3)+3);
end;
setfillstyle (solidfill,lightcyan);
bar (13,9,37,27);
bar (23,44,27,29);  (*barrel*)
line (7,0,7,50);
line (43,0,43,50);
size:=imagesize (0,0,50,50);
getmem (pd,size);
getimage (0,0,50,50,pd^);
putimage (0,0,p^,xorput);

(******************************************************************)
(*left*)
setfillstyle (solidfill,4);
bar (0,0,50,50);
for i:= 0 to 16 do begin
if odd (i) then setfillstyle (solidfill,4) else setfillstyle (solidfill,lightcyan);
if i=16 then bar(i*3,43,(i*3)+2,50)else bar (i*3,43,(i*3)+3,50);
if i=16 then bar(i*3,0,(i*3)+2,7)else bar (i*3,0,(i*3)+3,7);
end;
setfillstyle (solidfill,lightcyan);
bar (23,13,41,37);
bar (5,23,21,27);  (*barrel*)
line (0,7,50,7);
line (0,43,50,43);
size:=imagesize (0,0,50,50);
getmem (pl,size);
getimage (0,0,50,50,pl^);
putimage (0,0,pl^,xorput);
(******************************************************************)
(*right*)
setfillstyle (solidfill,4);
bar (0,0,50,50);
for i:= 0 to 16 do begin
if odd (i) then setfillstyle (solidfill,4) else setfillstyle (solidfill,lightcyan);
if i=16 then bar(i*3,43,(i*3)+2,50)else bar (i*3,43,(i*3)+3,50);
if i=16 then bar(i*3,0,(i*3)+2,7)else bar (i*3,0,(i*3)+3,7);
end;
setfillstyle (solidfill,lightcyan);
bar (9,13,27,37);
bar (44,23,29,27);  (*barrel*)
line (0,7,50,7);
line (0,43,50,43);
size:=imagesize (0,0,50,50);
getmem (pr,size);
getimage (0,0,50,50,pr^);
putimage (0,0,pr^,xorput);
(******************************************************************)
(*bullet *)
if (as.nam='INVISIBLE') and (hy.nam='BULLETS') then
setfillstyle (solidfill,0) else setfillstyle (solidfill,15);
bar (0,0,3,3);
size:=imagesize (0,0,3,3);
getmem (pb,size);
getimage (0,0,3,3,pb^);
putimage (0,0,pb^,xorput);
(******************************************************************)
end;

function checkpix (x,y:integer):boolean;
 (*determine if bullet can go forward *)
begin
if (getpixel(x,y)=bgc)and (getpixel(x+3,y)=bgc)and (getpixel(x,y+3)=bgc)and (getpixel(x+3,y+3)=bgc)
then checkpix:=true
else checkpix:=false;
end;

function hittank (x,y:integer):boolean;
 (*determine if tank candrive forward *)
begin
if (getpixel(x,y)=11) or (getpixel(x+3,y)=11)or (getpixel(x,y+3)=11)or (getpixel(x+3,y+3)=11)or (getpixel(x,y)=4)
or (getpixel(x+3,y)=4)or (getpixel(x,y+3)=4)or (getpixel(x+3,y+3)=4)
then hittank:=true
else hittank:=false;
end;

procedure fire(var hy,as:rcd);
begin
if hy.fired then       {checks to see if player 2 has fired}
case hy.firedir of

'U':begin
putimage (hy.bulx,hy.buly,pb^,xorput);  {take bullet off screen}
if checkpix(hy.bulx,hy.buly-a) then begin     {see if new location for bullet is empty}
putimage (hy.bulx,hy.buly-a,pb^,normalput); {put image}
hy.buly:=hy.buly-a;                         {change location of bullet}
delay (150);
if hy.buly<=0 then hy.fired:=false;            {if bullet goes of screen delete it}
end else if hittank(hy.bulx,hy.buly-a) then begin {check to see if bullet hit tank}
as.hit:=true;
hy.fired:=false;
end else hy.fired:=false;
end;

'D':begin
putimage (hy.bulx,hy.buly,pb^,xorput);
if checkpix(hy.bulx,hy.buly+a) and not (hy.buly+a>=bpf) then begin
putimage (hy.bulx,hy.buly+a,pb^,normalput);
hy.buly:=hy.buly+a;
delay (150);

end else if hittank(hy.bulx,hy.buly+a) and not (hy.buly+a>=bpf) then begin
as.hit:=true;
hy.fired:=false;
end else hy.fired:=false;
end;

'L':begin
putimage (hy.bulx,hy.buly,pb^,xorput);
if checkpix(hy.bulx-a,hy.buly) then begin
putimage (hy.bulx-a,hy.buly,pb^,normalput);
hy.bulx:=hy.bulx-a;
delay (150);
if hy.bulx<=0 then hy.fired:=false;
end else if hittank(hy.bulx-a,hy.buly) then begin
as.hit:=true;
hy.fired:=false;
end else hy.fired:=false;
end;
'R':begin
putimage (hy.bulx,hy.buly,pb^,xorput);
if checkpix(hy.bulx+a,hy.buly) then begin
putimage (hy.bulx+a,hy.buly,pb^,normalput);
hy.bulx:=hy.bulx+a;
delay (150);
if hy.bulx>=getmaxx then hy.fired:=false;
end else if hittank(hy.bulx+a,hy.buly) then begin
as.hit:=true;
hy.fired:=false;
end else hy.fired:=false;
end;
end;

if as.fired then
case as.firedir of
'U':begin
putimage (as.bulx,as.buly,pb^,xorput);
if checkpix(as.bulx,as.buly-a) then begin
putimage (as.bulx,as.buly-a,pb^,normalput);
as.buly:=as.buly-a;
delay (150);
if as.buly<=0 then as.fired:=false;
end else if hittank(as.bulx,as.buly-a) then begin
hy.hit:=true;
as.fired:=false;
end else as.fired:=false;
end;
'D':begin
putimage (as.bulx,as.buly,pb^,xorput);
if checkpix(as.bulx,as.buly+a) and not (as.buly+a>=bpf) then begin
putimage (as.bulx,as.buly+a,pb^,normalput);
as.buly:=as.buly+a;
delay (150);

end else if hittank(as.bulx,as.buly+a) and not (as.buly+a>=bpf)  then begin
hy.hit:=true;
as.fired:=false;
end else as.fired:=false;
end;
'L':begin
putimage (as.bulx,as.buly,pb^,xorput);
if checkpix(as.bulx-a,as.buly) then begin
putimage (as.bulx-a,as.buly,pb^,normalput);
as.bulx:=as.bulx-a;
delay (150);
if as.bulx<=0 then as.fired:=false;
end else if hittank(as.bulx-a,as.buly) then begin
hy.hit:=true;
as.fired:=false;
end else as.fired:=false;
end;
'R':begin
putimage (as.bulx,as.buly,pb^,xorput);
if checkpix(as.bulx+a,as.buly) then begin
putimage (as.bulx+a,as.buly,pb^,normalput);
as.bulx:=as.bulx+a;
delay (150);
if as.bulx>=getmaxx then as.fired:=false;
end else if hittank(as.bulx+a,as.buly) then begin
hy.hit:=true;
as.fired:=false;
end else as.fired:=false;
end;
end;
end;

procedure tankmove (var c:char;var p,pd,pl,pr:pointer;var son:boolean; var hy,as:rcd);
begin                   (*read keyboard imputs *)
c:=readkey;
(*
setcolor (15);
outtext (c);*)

(*if son and (c<>'R') and (c<>'C') and (c<>'O') and (c<>#27) then sound (70) else nosound;*)
case upcase(c) of
(*'C':begin
restorecrtmode;
writeln (h1c,'  ',h2c);
halt;
end;*)
'R',#9:if not hy.fired then begin
hy.fired:=true;             {fire bullet}
hy.firedir:=hy.dir;
(*
init('blaster.wav',nocando);
if (nocando <> true) and (son=true) then Play;
  *)
case hy.dir of                         {check to see which direction bullet was fired}
'U':begin
putimage (hy.x+23,hy.y-4,pb^,normalput); {put bullet}
hy.bulx:=hy.x+23;                        {sets x and y of bullet}
hy.buly:=hy.y-4;
end;
'D':begin
putimage (hy.x+23,hy.y+51,pb^,normalput);
hy.bulx:=hy.x+23;
hy.buly:=hy.y+51;
end;
'L':begin
putimage (hy.x-4,hy.y+23,pb^,normalput);
hy.bulx:=hy.x-4;
hy.buly:=hy.y+23;
end;
'R':begin
putimage (hy.x+51,hy.y+23,pb^,normalput);
hy.bulx:=hy.x+51;
hy.buly:=hy.y+23;
end;
end;
end;
'O',#47:if not as.fired then begin
as.fired:=true;
as.firedir:=as.dir;
(*
Init('blaster.wav',nocando);
if (nocando <> true) and (son=true) then Play;
  *)
case as.dir of
'U':begin
putimage (as.x+23,as.y-4,pb^,normalput);
as.bulx:=as.x+23;
as.buly:=as.y-4;
end;
'D':begin
putimage (as.x+23,as.y+51,pb^,normalput);
as.bulx:=as.x+23;
as.buly:=as.y+51;
end;
'L':begin
putimage (as.x-4,as.y+23,pb^,normalput);
as.bulx:=as.x-4;
as.buly:=as.y+23;
end;
'R':begin
putimage (as.x+51,as.y+23,pb^,normalput);
as.bulx:=as.x+51;
as.buly:=as.y+23;
end;
end;
end;
(********************************tank movement keys************************)
'D':begin putimage (hy.x,hy.y,hy.pic^,andput);      {takes off tank}
hy.dir:='D';                                        {changes tank direction}
if checkpixel (hy.x,hy.y+z) then begin              {sees if tank can be put}
putimage (hy.x,hy.y+z,pd^,notput);                  {puts tank}
hy.pic:=pd;                                         {changes which picture is being used}
hy.y:=hy.y+z;                                       {changes tank location}
end else putimage (hy.x,hy.y,pd^,notput);           {puts tank if can't move}
end;
'E':begin putimage (hy.x,hy.y,hy.pic^,andput);
hy.dir:='U';
if checkpixel (hy.x,hy.y-z) then begin
putimage (hy.x,hy.y-z,p^,notput);
hy.pic:=p;
hy.y:=hy.y-z;
end else putimage (hy.x,hy.y,p^,notput);
end;
'F':begin putimage (hy.x,hy.y,hy.pic^,andput);
hy.dir:='R';
if checkpixel (hy.x+z,hy.y) then begin
putimage (hy.x+z,hy.y,pr^,notput);
hy.pic:=pr;
hy.x:=hy.x+z;
end else putimage (hy.x,hy.y,pr^,notput);
end;
'S':begin putimage (hy.x,hy.y,hy.pic^,andput);
hy.dir:='L';
if checkpixel (hy.x-z,hy.y) then begin
putimage (hy.x-z,hy.y,pl^,notput);
hy.pic:=pl;
hy.x:=hy.x-z;
end else putimage (hy.x,hy.y,pl^,notput);
end;
'K':begin  putimage (as.x,as.y,as.pic^,xorput);
as.dir:='D';
if checkpixel (as.x,as.y+z) then begin
putimage (as.x,as.y+z,pd^,normalput);
as.pic:=pd;
as.y:=as.y+z;
end else putimage (as.x,as.y,pd^,normalput);
end;
'I':begin  putimage (as.x,as.y,as.pic^,xorput);
as.dir:='U';
if checkpixel (as.x,as.y-z) then begin
putimage (as.x,as.y-z,p^,normalput);
as.pic:=p;
as.y:=as.y-z;
end else putimage (as.x,as.y,p^,normalput);
end;
'L':begin  putimage (as.x,as.y,as.pic^,xorput);
as.dir:='R';
if checkpixel (as.x+z,as.y) then begin
putimage (as.x+z,as.y,pr^,normalput);
as.pic:=pr;
as.x:=as.x+z;
end else putimage (as.x,as.y,pr^,normalput);
end;
'J':begin  putimage (as.x,as.y,as.pic^,xorput);
as.dir:='L';
if checkpixel (as.x-z,as.y) then begin
putimage (as.x-z,as.y,pl^,normalput);
as.pic:=pl;
as.x:=as.x-z;
end else putimage (as.x,as.y,pl^,normalput);
end;
end;
end;

Procedure instructions(var instruct: text);
Var
   c: longint;
   let: string;
   put: integer;
Begin                                   {are asked for}
      Init('stayhelp.wav',nocando);
      if (nocando<>true) and (son=true) then Play;

   Reset(instruct);                 {reset instruction file}
   ClrScr;
   c:=0;
   Repeat                            {read instructions to screen one line at a time}
    inc(c);
    Readln(instruct,let);
     If c=24 then begin
      gotoxy(25,24);
      Write('Press any key to continue'); {keep words on screen until you are done with them}
      readkey;
      ClrScr;
      c:=0;
     end;
    Write(let);
    Writeln;
   Until eof(instruct);
   gotoxy(25,24);
   Write('Press any key to continue');
   readkey;
   Init('helpyou.wav',nocando);
      if (nocando<>true) and (son=true) then Play;

   clrscr;

end;

procedure closepics (var p,pd,pr,pl,pb:pointer; size:word);
begin
size:=imagesize (0,0,50,50);   {free memory that was used by pictures}
freemem (p,size);
freemem (pd,size);
freemem (pl,size);
freemem (pr,size);
size:=imagesize (0,0,3,3);
freemem (pb,size);
end;

procedure intro (Grdriver,grmode,grerror:integer; p,pd,pr,pl,pb:pointer; size:word);
var                            {introduction}
xi,yi,i,j,k,l,m:integer;
begin
intgraph (Grdriver,grmode,grerror);
tankdraw (i,p,pd,pr,pl,pb,size,as,hy);

for j:= 0 to (((getmaxx div 2)-45)div 5) do begin    {drives tank across screen}
if keypressed then j:= (((getmaxx div 2)-45)div 5);

i:=j*5;
putimage (i,170,pr^,normalput);
putimage (getmaxx-i-50,170,pl^,notput);
delay (50);
putimage (i,170,pr^,xorput);
putimage (getmaxx-i-50,170,pl^,andput);
settextstyle (1,horizdir,5);
Outtextxy ((getmaxx div 2)-100,170,'TankWarz');
end;
cleardevice;
settextstyle (1,horizdir,5);                       {changes font}
Outtextxy ((getmaxx div 2)-100,170,'TankWarz');
settextstyle (2,horizdir,7);
Outtextxy ((getmaxx div 2)-71,(getmaxy-140),'Developed by');
Outtextxy ((getmaxx div 2)-121,(getmaxy-120),'Wright Short Programs');

l:=getmaxx div 2;
m:=190;

j:=20;                     {explosion (see show_score)}
repeat
for i:=1 to 70 do begin
repeat
k:=random (2)+1;
case k of
1:xi:=l-random (j);
2:xi:=l+random (j);
end;
k:=random (2)+1;
case k of
1:yi:=m-random (j);
2:yi:=m+random (j);
end;
until sqr((xi-l))+sqr((yi-m))<=sqr(j);
k:=random (5)+1;
case k of
1,3,4,5:putpixel(xi,yi,red);
2:putpixel(xi,yi,yellow);
end;

end;
delay (75);

j:=j+3;
until keypressed;

c:=readkey;
closepics (p,pd,pr,pl,pb,size);
closegraph;
end;

(*************************************************************************)
begin (*main*)
assign (instruct,'readme.dat');
reset (instruct);
clrscr;
intro (Grdriver,grmode,grerror, p,pd,pr,pl,pb,size); {run intro}
clrscr;
gotoxy(30,7);
write ('What is Player 1''s name?  ');
readln(as.nam);
gotoxy(30,8);
write ('What is Player 2''s name?  ');
readln(hy.nam);
clrscr;
randomize;                 {draw menu}
gotoxy (30,7);
writeln ('P: Play');
gotoxy (30,8);
writeln ('I: Instructions');
gotoxy (30,9);
writeln ('S: Sound is');
gotoxy (30,10);
writeln ('Q: Quit to DOS');
if son then begin
gotoxy (42,9);
write ('ON        ');
end else
begin
gotoxy (42,9);
write ('OFF');
end;


c:=readkey;

while upcase (c) <> 'Q' do begin
case upcase (c) of
'S':if son= true then son:=false else son:=true;
'I':instructions(instruct);   {run instructions}
'P':
begin

intgraph (Grdriver,grmode,grerror);
tankdraw (i,p,pd,pr,pl,pb,size,as,hy);
myinit (as,hy);
i:=1;
show_score(as,hy,pl,pr,c,son);
while not (upcase(c)=#27)  do
begin
nosound;
if keypressed then tankmove (c,p,pd,pl,pr,son,as,hy);
if as.fired or hy.fired then fire(as,hy);
if as.hit then begin
tank_hit (as);
as.hit:=false;
show_score(as,hy,pl,pr,c,son);
end;
if hy.hit then begin
tank_hit (hy);
hy.hit:=false;
show_score(as,hy,pl,pr,c,son);
end;
end; (*end while loop*)
closepics (p,pd,pr,pl,pb,size);
closegraph;
end;
end; (*case*)
gotoxy (30,7);
writeln ('P: Play');
gotoxy (30,8);
writeln ('I: Instructions');
gotoxy (30,9);
writeln ('S: Sound is');
gotoxy (30,10);
writeln ('Q: Quit to DOS');
if son then begin
gotoxy (42,9);
write ('ON ');
end else
begin
gotoxy (42,9);
write ('OFF');
end;

c:=readkey;
end;

close (instruct);
clrscr;
end.