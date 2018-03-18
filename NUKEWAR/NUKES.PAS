{$G+}
program NukeWar;
(*Rick Barnes and Tim Kun*)
uses
    Graph,Crt;

const
Count1:Array[1..17] of PointType = ((x:260;y:210),(x:265;y:180),(x:270;y:220),
(*country at bottom left*)(x:275;y:220),(x:300;y:250),(x:295;y:298),
                          (x:290;y:280),
                          (x:260;y:285),
                          (x:230;y:245),(x:225;y:237),(x:220;y:230),(x:210;y:250),(x:210;y:235),
                          (x:230;y:220),(x:245;y:215),(x:253;y:212),(x:260;y:210));
Count2:Array[1..15] of PointType = ((x:400;y:50),(x:410;y:45),(x:420;y:70),
(*Country at top right*)  (x:415;y:72),(x:410;y:80),(x:390;y:100),(x:380;y:150),
                          (x:375;y:90),(x:350;y:75),(x:300;y:70),(x:350;y:25),(x:375;y:20),
                          (x:390;y:70),(x:410;y:27),(x:400;y:50));
Count3:array[1..7] of pointtype = ((x:180;y:180),(x:183;y:183),(x:188;y:190),
                   (x:190;y:180),(x:187;y:175),(x:175;y:175),(x:180;y:180));
count4:array[1..5]of pointtype=((x:300;y:160),(x:290;y:170),(x:330;y:155),
                     (x:345;y:160),(x:370;y:160));
(*Stuff for the title screen:*)
Const Npoly:Array[1..11] of PointType = ((X:50;Y:50),(X:80;Y:50),
                           (X:150;Y:150),(X:150;Y:50),(X:180;Y:50),
                           (X:180;Y:180),(X:150;Y:180),(X:80;Y:80),
                           (X:80;Y:180),(X:50;Y:180),(X:50;Y:50));
Const Upoly:Array[1..9] of PointType =((X:200;Y:130),(X:220;Y:130),
                           (X:220;Y:160),(X:240;Y:160),(X:240;Y:130),
                           (X:260;Y:130),(X:260;Y:180),(X:200;Y:180),
                           (X:200;Y:130));
Const Kpoly:Array[1..12] of Pointtype = ((X:280;Y:130),(X:300;Y:130),
                            (X:300;Y:150),(X:320;Y:125),(X:320;Y:150),
                            (X:310;Y:160),(X:320;Y:180),(X:310;Y:180),
                            (X:300;Y:160),
                            (X:300;Y:180),(X:280;Y:180),(X:280;Y:130));
Const Epoly:Array[1..13] of Pointtype = ((X:340;Y:130),(X:370;Y:130),
                            (X:370;Y:140),(X:355;Y:140),(X:355;Y:150),
                            (X:370;Y:150),(X:370;Y:160),(X:355;Y:160),
                            (X:355;Y:170),(X:370;Y:170),(X:370;Y:180),
                            (X:340;Y:180),(X:340;Y:130));
Const Wpoly:array[1..15] of pointtype = ((X:390;Y:50),(X:410;Y:50),(X:410;Y:160),
                            (X:430;Y:140),(X:460;Y:140),(x:480;y:160),(x:480;y:50),
                            (x:500;y:50),(x:500;y:180),(x:480;y:180),(x:460;y:160),
                            (x:430;y:160),(x:410;y:180),(x:390;y:180),(x:390;y:50));
Const Apoly:array[1..8] of pointtype = ((x:520;y:180),(x:540;y:130),(x:560;y:130),
                           (x:580;y:180),(x:560;y:180),(x:550;y:160),(x:540;y:180),
                           (x:520;y:180));
Const ADpoly:array[1..5] of pointtype =((x:545;y:140),(x:555;y:140),(x:555;y:150),
                            (x:545;y:150),(x:545;y:140));
Const Rpoly:array[1..10] of pointtype =((x:600;y:130),(x:630;y:130),
                            (x:630;y:160),(x:620;y:160),(x:630;y:180),
                            (x:620;y:180),
                            (x:610;y:170),(x:610;y:180),(x:600;y:180),(x:600;y:130));
Const RDpoly:array[1..5] of pointtype =((x:610;y:140),(x:620;y:140),
                            (x:620;y:150),(x:610;y:150),(x:610;y:140));

Const Nula1:array[1..5] of pointtype =((x:115;y:235),(x:116;y:235),
                          (x:117;y:238),(x:114;y:238),(x:115;y:235));
Const Nula2:array[1..5] of pointtype =((x:515;y:235),(x:516;y:235),
                          (x:517;y:238),(x:514;y:238),(x:515;y:235));

Const  palette : array [1..768] of byte = (

    0,    0,    0,    0,    0,    24,    0,    0,    24,    0,    0,    28,
    0,    0,   32,    0,    0,    32,    0,    0,    36,    0,    0,    40,
    8,    0,   40,   16,    0,    36,   24,    0,    36,   32,    0,    32,
   40,    0,   28,   48,    0,    28,   56,    0,    24,   64,    0,    20,
   72,    0,   20,   80,    0,    16,   88,    0,    16,   96,    0,    12,
  104,    0,    8,  112,    0,     8,  120,    0,     4,  128,    0,     0,
  128,    0,    0,  132,    0,     0,  136,    0,     0,  140,    0,     0,
  144,    0,    0,  144,    0,     0,  148,    0,     0,  152,    0,     0,
  156,    0,    0,  160,    0,     0,  160,    0,     0,  164,    0,     0,
  168,    0,    0,  172,    0,     0,  176,    0,     0,  180,    0,     0,
  184,    4,    0,  188,    4,     0,  192,    8,     0,  196,    8,     0,
  200,   12,    0,  204,   12,     0,  208,   16,     0,  212,   16,     0,
  216,   20,    0,  220,   20,     0,  224,   24,     0,  228,   24,     0,
  232,   28,    0,  236,   28,     0,  240,   32,     0,  244,   32,     0,
  252,   36,    0,  252,   36,     0,  252,   40,     0,  252,   40,     0,
  252,   44,    0,  252,   44,     0,  252,   48,     0,  252,   48,     0,
  252,   52,    0,  252,   52,     0,  252,   56,     0,  252,   56,     0,
  252,   60,    0,  252,   60,     0,  252,   64,     0,  252,   64,     0,
  252,   68,    0,  252,   68,     0,  252,   72,     0,  252,   72,     0,
  252,   76,    0,  252,   76,     0,  252,   80,     0,  252,   80,     0,
  252,   84,    0,  252,   84,     0,  252,   88,     0,  252,   88,     0,
  252,   92,    0,  252,   96,     0,  252,   96,     0,  252,  100,     0,
  252,  100,    0,  252,  104,     0,  252,  104,     0,  252,  108,     0,
  252,  108,    0,  252,  112,     0,  252,  112,     0,  252,  116,     0,
  252,  116,    0,  252,  120,     0,  252,  120,     0,  252,  124,     0,
  252,  124,    0,  252,  128,     0,  252,  128,     0,  252,  132,     0,
  252,  132,    0,  252,  136,     0,  252,  136,     0,  252,  140,     0,
  252,  140,    0,  252,  144,     0,  252,  144,     0,  252,  148,     0,
  252,  152,    0,  252,  152,     0,  252,  156,     0,  252,  156,     0,
  252,  160,    0,  252,  160,     0,  252,  164,     0,  252,  164,     0,
  252,  168,    0,  252,  168,     0,  252,  172,     0,  252,  172,     0,
  252,  176,    0,  252,  176,     0,  252,  180,     0,  252,  180,     0,
  252,  184,    0,  252,  184,     0,  252,  188,     0,  252,  188,     0,
  252,  192,    0,  252,  192,     0,  252,  196,     0,  252,  196,     0,
  252,  200,    0,  252,  200,     0,  252,  204,     0,  252,  208,     0,
  252,  208,    0,  252,  208,     0,  252,  208,     0,  252,  208,     0,
  252,  212,    0,  252,  212,     0,  252,  212,     0,  252,  212,     0,
  252,  216,    0,  252,  216,     0,  252,  216,     0,  252,  216,     0,
  252,  216,    0,  252,  220,     0,  252,  220,     0,  252,  220,     0,
  252,  220,    0,  252,  224,     0,  252,  224,     0,  252,  224,     0,
  252,  224,    0,  252,  228,     0,  252,  228,     0,  252,  228,     0,
  252,  228,    0,  252,  228,     0,  252,  232,     0,  252,  232,     0,
  252,  232,    0,  252,  232,     0,  252,  236,     0,  252,  236,     0,
  252,  236,    0,  252,  236,     0,  252,  240,     0,  252,  240,     0,
  252,  244,    0,  252,  244,     0,  252,  244,     0,  252,  248,     0,
  252,  248,    0,  252,  248,     0,  252,  248,     0,  252,  252,     0,
  252,  252,    4,  252,  252,     8,  252,  252,    12,  252,  252,    16,
  252,  252,   20,  252,  252,    24,  252,  252,    28,  252,  252,    32,
  252,  252,   36,  252,  252,    40,  252,  252,    40,  252,  252,    44,
  252,  252,   48,  252,  252,    52,  252,  252,    56,  252,  252,    60,
  252,  252,   64,  252,  252,    68,  252,  252,    72,  252,  252,    76,
  252,  252,   80,  252,  252,    84,  252,  252,    84,  252,  252,    88,
  252,  252,   92,  252,  252,    96,  252,  252,   100,  252,  252,   104,
  252,  252,  108,  252,  252,   112,  252,  252,   116,  252,  252,   120,
  252,  252,  124,  252,  252,   124,  252,  252,   128,  252,  252,   132,
  252,  252,  136,  252,  252,   140,  252,  252,   144,  252,  252,   148,
  252,  252,  152,  252,  252,   156,  252,  252,   160,  252,  252,   164,
  252,  252,  168,  252,  252,   168,  252,  252,   172,  252,  252,   176,
  252,  252,  180,  252,  252,   184,  252,  252,   188,  252,  252,   192,
  252,  252,  196,  252,  252,   200,  252,  252,   204,  252,  252,   208,
  252,  252,  208,  252,  252,   212,  252,  252,   216,  252,  252,   220,
  252,  252,  224,  252,  252,   228,  252,  252,   232,  252,  252,   236,
  252,  252,  240,  252,  252,   244,  252,  252,   248,  252,  252,   252,
  252,  252,  240,  252,  252,   244,  252,  252,   248,  252,  252,   252);

   radius    = 1.9;
   frequency = 2;
   angleinc  = 3 * pi / frequency;
var
    count       : word;
   delta       : integer;
   path        : array[0..199] of word;
   buffer      : array[0..102,0..159] of integer;

   GrDriver : integer;  {  Stuff for the  }
   GrMode : integer;    {    Graphics      }
   GrError : integer;   {   Initialization }
   Position : integer;  {                  }
   X,S,D, Y, T : integer; (*Variables for loops*)
   sounds : char;

   Pop1,pop2,overpop:Longint; (*Population variables*)
   pop1str,pop2str:string;
   Att1,Att2,def1,def2,ans:char; (*Attack/Defense choices*)
   Nuke1, Nuke2:integer;
   Nuke1str,Nuke2str:string;
   Ship1str,Ship2str:string;
   Ship1,Ship2:integer;

   Size : word;   (*  For    *)
   P : pointer;   (*Animation*)

   Rad : word;    (*Circle Radius*)
   Number : integer;  (*Another multiple-use variable*)
   Name1, Name2, Country1, Country2 : string;  (*Player & Country names*)
   Winner, Loser : string;
   Bakers, Rule : string;
 procedure buildpath;
   var
      count     : byte;
      currangle : real;
   begin
      currangle := pi;
      for count := 0 to 199 do
         begin
            path[count] := 320 + round(radius*sin(currangle));

            { the sin path _must_ lie on an even number }
            { otherwise the picture will be garbage     }

            if path[count] mod 2 <> 0 then
               if path[count] > 320 then
                  dec(path[count])            { round down }
               else
                  inc(path[count]);           { round up   }

            { the path is rounded to the closest even number to 320 }

            currangle := currangle + angleinc;
         end;
   end;
(***************************************************************************)

   procedure Flames;
    begin
     asm
     mov   ax,13h              { ; AX := 13h                            }
     int   10h                 { ; Set Mode 13h (320x200x256)           }

     xor   ax,ax               { ; AX := 0                              }
     mov   cx,768              { ; CX := # of palette entries           }
     mov   dx,03C8h            { ; DX := VGA Port                       }
     mov   si,offset palette   { ; SI := palette[0]                     }

     out   dx,al               { ; send zero to index port              }
     inc   dx                  { ; inc to write port                    }

   @l1:

     mov   bl,[si]             { ; set palette entry                    }
     shr   bl,2
                     { ; divide by 4                          }
     mov   [si],bl             { ; save entry                           }
     outsb                     { ; and write to port                    }
     dec   cx                  { ; CX := CX - 1                         }
     jnz   @l1                 { ; if not done then loop                }

     mov   ax,seg buffer       { ; AX := segment of buffer              }
     mov   es,ax               { ; ES := AX                             }
     mov   di,offset buffer    { ; DI := buffer[0]                      }
     mov   cx,8109             { ; CX := sizeof(buffer) div 2           }
     xor   ax,ax               { ; AX := 0                              }
     rep   stosw               { ; clear every element in buffer to zero}
  end;

  repeat

     asm
        mov   bx,1             { ; BX := 1                              }
        mov   si,offset path   { ; SI := path[0]                        }

        mov   cx,16160         { ; CX := # of elements to change        }
        mov   di,offset buffer { ; DI := buffer[0]                      }
        add   di,320           { ; DI := buffer[320] (0,1)              }

     @l2:

        mov   ax,ds:[di-2]     { ; AX := buffer[DI-2]    (x-1,y)        }
        add   ax,ds:[di]       { ; AX += buffer[DI]      (x  ,y)        }
        add   ax,ds:[di+2]     { ; AX += buffer[DI+2]    (x+1,y)        }
        add   ax,ds:[di+320]   { ; AX += buffer[DI+320]  (x,y+1)        }
        shr   ax,2             { ; AX := AX div 4 (calc average)        }

        jz    @l3              { ; if AX = 0 then skip next line        }
        dec   ax               { ; else AX--                            }

     @l3:

        push  di               { ; save DI                              }
        sub   di,ds:[si]       { ; DI := (x + or - sin,y-1)             }
        mov   word ptr ds:[di],ax { store AX somewhere one line up      }
        pop   di               { ; restore DI                           }

        inc   di               { ; DI++                                 }
        inc   di               { ; DI++ (move to next word)             }

        inc   bx               { ; BX++                                 }
        cmp   bx,320           { ; if bx <> 320                         }
        jle   @l4              { ; then jump to @l4                     }
        mov   bx,1             { ; else BX := 1 (we're on a new line)   }
        inc   si               { ; point SI to next element in path     }
        inc   si               { ;                                      }

     @l4:
        dec   cx               { ; CX--                                 }
        jnz   @l2              { ; if CX <> 0 then loop                 }
     end;

     for count := 0 to 159 do {set new bottom line}
        begin
           if random < 0.4 then
              delta := random(2)*255;
           buffer[101,count] := delta;
           buffer[102,count] := delta;
        end;

     asm
        mov   si,offset buffer { ; SI := buffer[0]                      }
        mov   ax,0A000h        { ; AX := 0A000h (vga segment)           }
        mov   es,ax            { ; ES := AX                             }
        xor   di,di            { ; DI := 0                              }
        mov   dx,100           { ; DX := 100 (# of rows div 2)          }

     @l5:
        mov   bx,2             { ; BX := 2                              }

     @l6:
        mov   cx,160           { ; CX := 160 (# of cols div 2)          }

     @l7:
        mov   al,ds:[si]       { ; AL := buffer[si]                     }
        mov   ah,al            { ; AH := AL (replicate byte)            }
        mov   es:[di],ax       { ; store two bytes into video memory    }
        inc   di               { ; move to next word in VRAM            }
        inc   di               { ;                                      }
        inc   si               { ; move to next word in buffer          }
        inc   si               { ;                                      }
        dec   cx               { ; CX--                                 }
        jnz   @l7              { ; repeat until done with column        }

        sub   si,320           { ; go back to start of line in buffer   }
        dec   bx               { ; BX--                                 }
        jnz   @l6              { ; repeat until two columns filled      }

        add   si,320           { ; restore position in buffer           }
        dec   dx               { ; DX--                                 }
        jnz   @l5              { ; repeat until 100 rows filled         }
     end;

  until keypressed;

  asm
     mov   ax,03h              { ; AX := 3h                             }
     int   10h                 { ; restore text mode                    }
  end;

end;
(***************************************************************************)

Procedure Title;
          Begin
          GrDriver := Detect;
InitGraph (GrDriver, GrMode, 'c:\tp\bgi');
GrError := GraphResult;
if GrError <> GrOk
   then writeln ('Graphics Error: ', GraphErrorMsg (GrError))
   else begin
          Cleardevice;
          Setcolor(Cyan);
          Drawpoly(11,Npoly);
          Drawpoly(9,Upoly);
          Drawpoly(12,Kpoly);
          Drawpoly(13,Epoly);
          Drawpoly(15,Wpoly);
          Drawpoly(8,Apoly);
          Drawpoly(5,ADpoly);
          Drawpoly(10,Rpoly);
          Drawpoly(5,RDpoly);
          readln;
          end;

          End;
(***************************************************************************)
Procedure Missile;
          Begin;
          cleardevice;
GrDriver := Detect;
InitGraph (GrDriver, GrMode, 'c:\tp\bgi');
GrError := GraphResult;
if GrError <> GrOk
   then writeln ('Graphics Error: ', GraphErrorMsg (GrError))
   else begin
      setcolor(lightgray);
      line(400,5,450,5);
      line(400,5,400,75);
      line(400,75,450,75);
      line(450,75,450,5);
      setcolor(lightblue);
      line(400,25,375,25);
      line(375,25,400,50);
      line(450,25,475,25);
      line(475,25,450,50);
      line(425,25,410,25);
      line(410,25,425,50);
      line(425,50,425,25);
      setcolor(red);
      line(400,75,425,100);
      line(450,75,425,100);
   end;
   {delay(500);}
   Size := Imagesize(370,0,475,105);
   Getmem (P,Size);
   GetImage(370,0,475,105,P^);
   PutImage(370,0,P^,XorPut);
   PutImage(370,25,P^,XorPut);
   PutImage(370,25,P^,XorPut);
   PutImage(370,75,P^,XorPut);
   sound(5000);
   delay(50);
   nosound;
   PutImage(370,75,P^,XorPut);
   PutImage(370,125,P^,XorPut);
   sound(4500);
   delay(50);
   nosound;
   PutImage(370,125,P^,XorPut);
   PutImage(370,175,P^,XorPut);
   sound(4000);
   delay(50);
   nosound;
   PutImage(370,175,P^,XorPut);
   PutImage(370,225,P^,XorPut);
   sound(3500);
   delay(50);
   nosound;
   PutImage(370,225,P^,XorPut);
   PutImage(370,275,P^,XorPut);
   sound(3000);
   delay(50);
   nosound;
   PutImage(370,275,P^,XorPut);
   PutImage(370,325,P^,XorPut);
   sound(2500);
   delay(50);
   nosound;
   PutImage(370,325,P^,XorPut);
   PutImage(370,375,P^,XorPut);
   sound(2000);
   delay(50);
   nosound;
   PutImage(370,375,P^,XorPut);
   PutImage(370,425,P^,XorPut);
   sound(1500);
   delay(50);
   nosound;
   PutImage(370,425,P^,XorPut);
   PutImage(370,475,P^,XorPut);
   sound(500);
   delay(50);
   nosound;
   sound(100);
   delay(200);

   sound(50);
   delay(100);
   nosound;
   sound(75);
   delay(100);
   nosound;
   sound(50);
   delay(500);
   nosound;
   sound(100);
   delay(100);
   nosound;
    sound(25);
   delay(100);
   nosound;
    sound(60);
   delay(100);
   nosound;
   end;
(***************************************************************************)
procedure credits;
begin
cleardevice;
                ClearDevice;
        SetTextStyle (TRIPLEXfont,HORIZdir,5);
        outtextXY (20,100,'Written By:');
        outtextXY (300,150,'Rick Barnes');
        outtextXY (300,200,'Tom Kun');
        readln;
        end;
(***************************************************************************)
procedure Names;
begin
RestoreCRTMode;
writeln ('Player 1, Enter Your Name.');
write ('>'); readln (Name1);
writeln (Name1,', Enter Your Country.');
write ('>'); readln (Country1);
writeln ('Player 2, Enter Your Name.');
write ('>'); readln (Name2);
writeln (Name2,', Enter Your Country.');
write ('>'); readln (Country2);
writeln;
writeln ('Do you want sound (Y/N)?');
write ('>');readln(sounds);
writeln ('Activate your CAPS LOCK and NUM LOCK now.');
readln;
SetGraphMode (GrMode);
ClearDevice;
end;
(***************************************************************************)
procedure blackout;
begin
setcolor (black);
OUttextxy(25,310,'Enter your attack choice.');
          outtextxy(25,320,'(Q).....Use Propaganda');
          Outtextxy(25,330,'(A).....Build Nuke');
          outtextxy(25,340,'(Z).....Build Fleet');
          outtextxy(25,350,'(W).....Launch Nuke');
          outtextxy(25,360,'(S).....Launch Coastal Strike');
          OUttextxy(400,310,'Enter your attack choice.');
          outtextxy(400,320,'(9).....Use Propaganda');
          Outtextxy(400,330,'(6).....Build Nuke');
          outtextxy(400,340,'(3).....Build Fleet');
          outtextxy(400,350,'(8).....Launch Nuke');
          outtextxy(400,360,'(5).....Launch Coastal Strike');
          setcolor (white)
end;
(***************************************************************************)
procedure black_the_Def_choice;
begin
setcolor (black);
OUttextxy(25,310,'Enter your defend choice.');
          outtextxy(25,320,'(Q).....Brainwash Citizens');
          outtextxy(25,330,'(A).....Launch SDI Defense');
          outtextxy(25,340,'(Z).....Lay Mines');
          OUttextxy(400,310,'Enter your defend choice.');
          outtextxy(400,320,'(9).....Brainwash Citizens');
          Outtextxy(400,330,'(6).....Launch SDI Defense');
          outtextxy(400,340,'(3).....Lay Mines');
          {overpop:=0;}
setcolor (white);
end;
(***************************************************************************)
Procedure Propaganda1;
          begin
          setcolor(lightgray);
          Line(100,240,105,215);
          Line(105,215,110,215);
          Line(110,215,115,240);
          Line(100,240,112,225);
          Line(115,240,103,225);
          Line(101,238,114,238);
          Line(103,225,111,217);
          Line(112,225,104,217);
          Line(103,225,112,225);

          Line(107,215,107,212);
          Line(108,215,108,212);
          Setfillstyle(SOLIDFILL,RED);

          Fillellipse(107,210,2,2);

          Line(111,210,113,210);
          Line(103,210,101,210);
          Line(107,206,107,204);

          Size:=Imagesize(100,216,110,216);
          getmem(P,Size);
          Getimage(100,199,120,215,P^);
          Putimage(100,200,P^,Xorput);
          if sounds = 'Y' then begin
          sound(500);
          delay(300);
          nosound;end else delay(300);
          Putimage(100,200,P^,Xorput);
          delay(300);
          Putimage(100,200,P^,Xorput);
          if sounds = 'Y' then begin
          sound(500);
          delay(300);
          nosound;end else delay(300);
          Putimage(100,200,p^,xorput);
          delay(300);
          Putimage(100,200,P^,Xorput);
          if sounds = 'Y' then begin
          sound(500);
          delay(300);
          nosound;end else delay(300);
          Putimage(100,200,p^,xorput);
          delay(300);
          Putimage(100,200,P^,Xorput);
          Putimage(100,200,P^,Xorput);
          delay(300);
          if sounds = 'Y' then Nosound;

          SETCOLOR(WHITE);
          end;
(***************************************************************************)
Procedure Propaganda2;
          Begin
           setcolor(lightgray);
          Line(500,240,505,215);
          Line(505,215,510,215);
          Line(510,215,515,240);
          Line(500,240,512,225);
          Line(515,240,503,225);
          Line(501,238,514,238);
          Line(503,225,511,217);
          Line(512,225,504,217);
          Line(503,225,512,225);

          Line(507,215,507,212);
          Line(508,215,508,212);
          Setfillstyle(SOLIDFILL,RED);

          Fillellipse(507,210,2,2);

          Line(511,210,513,210);
          Line(503,210,501,210);
          Line(507,206,507,204);

          Size:=Imagesize(500,216,510,216);
          getmem(P,Size);
          Getimage(500,199,520,215,P^);
          Putimage(500,200,P^,Xorput);
          if sounds = 'Y' then begin
          sound(500);
          delay(300);
          nosound;end else delay(300);
          Putimage(500,200,P^,Xorput);
          delay(300);
          Putimage(500,200,P^,Xorput);
          if sounds = 'Y' then begin
          sound(500);
          delay(300);
          nosound;end else delay(300);
          Putimage(500,200,p^,xorput);
          delay(300);
          Putimage(500,200,P^,Xorput);
          if sounds = 'Y' then begin
          sound(500);
          delay(300);
          nosound;end else delay(300);
          Putimage(500,200,p^,xorput);
          delay(300);
          Putimage(500,200,P^,Xorput);
          Putimage(500,200,P^,Xorput);
          delay(300);
          if sounds = 'Y' then Nosound;

          SETCOLOR(WHITE);
          end;
(***************************************************************************)
Procedure Explode1;
begin
X := 10;
repeat
setcolor (black);
SetFillStyle (SolidFill,yellow);
FillEllipse (25,215,X,X);
delay (50);
SetFillStyle (SolidFill,red);
FillEllipse (25,215,X+5,X+5);
delay (50);
X := X+5;
until X = 50;
SetFillStyle (SolidFill,black);
FillEllipse (25,215,X+5,X+5);
SetColor (White);
end;
Procedure Explode11;
begin
X := 10;
repeat
setcolor (black);
SetFillStyle (SolidFill,yellow);
FillEllipse (85,215,X,X);
delay (50);
SetFillStyle (SolidFill,red);
FillEllipse (85,215,X+5,X+5);
delay (50);
X := X+5;
until X = 50;
SetFillStyle (SolidFill,black);
FillEllipse (85,215,X+5,X+5);
SetColor (White);
end;
(***************************************************************************)
Procedure Explode2;
begin
X := 10;
repeat
setcolor (black);
SetFillStyle (SolidFill,yellow);
FillEllipse (540,215,X,X);
delay (50);
SetFillStyle (SolidFill,red);
FillEllipse (540,215,X+5,X+5);
delay (50);
X := X+5;
until X = 50;
SetFillStyle (SolidFill,black);
FillEllipse (540,215,X+5,X+5);
SetColor (White);
end;
(***************************************************************************)
Procedure Buildnuke1;
          Begin
          setcolor(lightred);
          Line(100,240,100,200);
          Line(100,200,110,200);
          Line(110,200,110,240);
          Line(110,240,100,240);
          Line(100,240,110,230);
          Line(110,230,100,220);
          Line(100,220,110,210);{BUILD NUKE TOWER}
          Line(110,210,100,200);
          Line(110,200,100,210);
          Line(100,210,110,220);
          Line(110,220,100,230);
          Line(100,230,110,240);

          Setcolor(lightcyan);
          Line(110,203,113,203);
          Line(110,204,113,204);
          Line(110,217,113,217);
          Line(110,218,113,218);{BUILD CONNECTORS}

          Setcolor(Lightgray);
          setfillstyle(solidfill,lightgray);{BUILD NUKE MUFFLER}
          fillpoly(5,nula1);

          Setcolor(white);
          Line(113,200,118,200);
          Line(118,200,118,235); {BODY TUBE}
          Line(118,235,113,235);
          Line(113,235,113,200);

          setcolor(lightblue);
          Line(119,226,121,235);
          Line(121,235,119,235); {FIN}
          Line(119,235,119,226);

          Line(112,226,112,235);
          Line(112,235,110,235); {FIN}
          Line(110,235,112,226);

          Line(115,226,116,235);
          Line(116,235,115,235); {FIN}
          Line(115,235,115,226);

          Setcolor(red);
          Line(113,199,115,190);
          Line(115,190,116,190); {WARHEAD}
          Line(116,190,118,199);

          IF SOUNDS = 'Y' THEN BEGIN
          Sound(200);{1}
          delay(500);
          nosound;
          delay(100);
          sound(200);{2}
          delay(500);
          nosound;
          delay(100);
          sound(200);{3}
          delay(500);
          nosound;
          delay(80);
          sound(170);{4}
          delay(325);
          nosound;
          delay(50);
          sound(255);{5}
          delay(170);
          nosound;
          delay(100);
          sound(200);{6}
          delay(500);
          nosound;
          delay(100);
          sound(170);{7}
          delay(300);
          nosound;
          delay(70);
          sound(255);{8}
          delay(200);
          nosound;
          delay(70);
          sound(200);{9}
          delay(1000);
          nosound;
          END ELSE DELAY (1000);

          end;
(***************************************************************************)
Procedure Buildnuke2;
          Begin
          setcolor(lightred);
          Line(500,240,500,200);
          Line(500,200,510,200);
          Line(510,200,510,240);
          Line(510,240,500,240);
          Line(500,240,510,230);
          Line(510,230,500,220);
          Line(500,220,510,210);{BUILD NUKE TOWER}
          Line(510,210,500,200);
          Line(510,200,500,210);
          Line(500,210,510,220);
          Line(510,220,500,230);
          Line(500,230,510,240);

          Setcolor(lightcyan);
          Line(510,203,513,203);
          Line(510,204,513,204);
          Line(510,217,513,217);
          Line(510,218,513,218);{BUILD CONNECTORS}

          Setcolor(Lightgray);
          setfillstyle(solidfill,lightgray);{BUILD NUKE MUFFLER}
          fillpoly(5,nula2);

          Setcolor(white);
          Line(513,200,518,200);
          Line(518,200,518,235); {BODY TUBE}
          Line(518,235,513,235);
          Line(513,235,513,200);

          setcolor(lightblue);
          Line(519,226,521,235);
          Line(521,235,519,235); {FIN}
          Line(519,235,519,226);

          Line(512,226,512,235);
          Line(512,235,510,235); {FIN}
          Line(510,235,512,226);

          Line(515,226,516,235);
          Line(516,235,515,235); {FIN}
          Line(515,235,515,226);

          Setcolor(red);
          Line(513,199,515,190);
          Line(515,190,516,190); {WARHEAD}
          Line(516,190,518,199);

          IF SOUNDS = 'Y' THEN BEGIN
          Sound(200);{1}
          delay(500);
          nosound;
          delay(100);
          sound(200);{2}
          delay(500);
          nosound;
          delay(100);
          sound(200);{3}
          delay(500);
          nosound;
          delay(80);
          sound(170);{4}
          delay(325);
          nosound;
          delay(50);
          sound(255);{5}
          delay(170);
          nosound;
          delay(100);
          sound(200);{6}
          delay(500);
          nosound;
          delay(100);
          sound(170);{7}
          delay(300);
          nosound;
          delay(70);
          sound(255);{8}
          delay(200);
          nosound;
          delay(70);
          sound(200);{9}
          delay(1000);
          nosound;
          END ELSE DELAY(1000);

          end;
(***************************************************************************)

Procedure Mine1;
          Begin
          Setcolor(lightgray);
          Circle(100,230,5);
          Putpixel(100,230,white);
          Putpixel(103,230,white);
          Putpixel(97,230,white);
          Putpixel(100,233,white);
          Putpixel(100,227,white);
          Putpixel(100,224,white);
          Putpixel(100,236,white);
          Putpixel(106,230,white);
          Putpixel(94,230,white);
          delay (600);
          end;
(***************************************************************************)

Procedure Mine2;
          Begin
          Setcolor(lightgray);
          Circle(500,230,5);
          Putpixel(500,230,white);
          Putpixel(503,230,white);
          Putpixel(497,230,white);
          Putpixel(500,233,white);
          Putpixel(500,227,white);
          Putpixel(500,224,white);
          Putpixel(500,236,white);
          Putpixel(506,230,white);
          Putpixel(494,230,white);
          delay (600);
          end;
(***************************************************************************)
Procedure Clear1;
          Begin
          SETCOLOR(BLACK);
          Setfillstyle(solidfill,0);
          fillellipse(100,210,35,35);  {CLEARS ATT1 GRAPHICS}
          SETCOLOR(white);
          end;
(***************************************************************************)
Procedure Clear2;
          Begin
          Setcolor(0);
          setfillstyle(solidfill,0);
          fillellipse(500,210,35,35);  {CLEARS ATT2 GRAPHICS}
          setcolor(white);
          end;
(***************************************************************************)
procedure clearsat;
begin
setcolor (black);
line (580,75,610,60);
line (580,65,610,50);
line (580,75,580,65);
line (610,60,610,50);
line (584,62,580,45);
line (580,45,584,42);
line (584,42,588,60);
line (585,70,615,70);
line (588,67,619,67);
line (615,70,619,67);
line (580,75,576,90);
line (576,90,584,87);
line (584,87,588,70);
line (580,70,575,75);
setcolor (white);
end;
(***************************************************************************)
procedure anim;
begin     (*upperleft, lowerright*)
setcolor (white);
line (X+5,235,X+5,220);
Size := Imagesize (X+5,215,X+5,240);
Getmem (P,Size);
GetImage (X+5,215,X+5,240,P^);
T := 215;


repeat
PutImage (X,T,P^,Xorput);
PutImage (X,T-5,P^,Xorput);
setcolor (BLACK);line (X+5,235,X+5,220);line (X,235,X,220);setcolor(white);
delay (50);
T := T-5;
until T = 0;
PutImage (X,T,P^,Xorput);

repeat
PutImage (Y,T,P^,Xorput);
setcolor (black);line (Y,0,Y,20);setcolor (white);
PutImage (Y,T+5,P^,Xorput);
delay (50);
T := T+5;
until T = 215;
if Y = 540 then explode2;
if Y = 25 then explode1;



end;
(***************************************************************************)
Procedure Buildfleet1;
          Begin
          Setcolor(lightgray);
          Line(80,235,120,235);
          Line(120,235,130,220);
          Line(130,220,70,220);
          Line(70,220,80,235);
          Line(85,220,85,210);
          Line(85,210,105,210);
          Line(105,210,105,220);
          Line(105,215,125,205);
          Line(125,205,127,207);
          Line(127,207,105,217);

          IF SOUNDS = 'Y' THEN BEGIN
          SOUND(300); {1}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(400); {2}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(500); {3}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(600); {4}
          DELAY(400);
          NOSOUND;
          DELAY(85);
          SOUND(500); {5}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(600); {6}
          DELAY(400);
          NOSOUND;
          DELAY(200);
          END ELSE DELAY(1000);

          end;

(***************************************************************************)
Procedure Buildfleet2;
          Begin
          Setcolor(lightgray);
          Line(480,235,520,235);
          Line(520,235,530,220);
          Line(530,220,470,220);
          Line(470,220,480,235);
          Line(485,220,485,210);
          Line(485,210,505,210);
          Line(505,210,505,220);
          Line(505,215,525,205);
          Line(525,205,527,207);
          Line(527,207,505,217);

          IF SOUNDS = 'Y' THEN BEGIN
          SOUND(300); {1}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(400); {2}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(500); {3}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(600); {4}
          DELAY(400);
          NOSOUND;
          DELAY(85);
          SOUND(500); {5}
          DELAY(250);
          NOSOUND;
          DELAY(150);
          SOUND(600); {6}
          DELAY(400);
          NOSOUND;
          DELAY(200);
          END ELSE DELAY (1000);

          end;
(***************************************************************************)
procedure sattilite;
begin
setcolor (white);
line (580,75,610,60);
line (580,65,610,50);
line (580,75,580,65);
line (610,60,610,50);
setcolor (yellow);
line (584,62,580,45);
line (580,45,584,42);
line (584,42,588,60);

line (585,70,615,70);
line (588,67,619,67);
line (615,70,619,67);

line (580,75,576,90);
line (576,90,584,87);
line (584,87,588,70);

setcolor (lightgray);
line (580,70,575,75);
end;
(***************************************************************************)
procedure Player1sdi;
begin
setcolor (white);
line (130,75,160,60);
line (130,65,160,50);
line (130,75,130,65);
line (160,60,160,50);
setcolor (yellow);
line (134,62,130,45);
line (130,45,134,42);
line (134,42,138,60);

line (135,70,165,70);
line (138,67,169,67);
line (165,70,169,67);

line (130,75,126,90);
line (126,90,134,87);
line (134,87,138,70);

setcolor (lightgray);
line (130,70,125,75);
end;
(***************************************************************************)
procedure Idlesat;
begin
setcolor (black);
line (130,75,160,60);
line (130,65,160,50);
line (130,75,130,65);
line (160,60,160,50);
line (134,62,130,45);
line (130,45,134,42);
line (134,42,138,60);
line (135,70,165,70);
line (138,67,169,67);
line (165,70,169,67);
line (130,75,126,90);
line (126,90,134,87);
line (134,87,138,70);
line (130,70,125,75);
setcolor (white);
end;
(***************************************************************************)

procedure sdi1hit;
begin
X := 25;
setcolor (white);
line (X+5,235,X+5,220);
Size := Imagesize (X+5,215,X+5,240);
Getmem (P,Size);
GetImage (X+5,215,X+5,240,P^);
T := 215;

repeat
PutImage (X,T,P^,Xorput);
PutImage (X,T-5,P^,Xorput);
setcolor (BLACK);line (X+5,235,X+5,220);line (X,235,X,220);setcolor(white);
delay (50);
T := T-5;
until T = 0;
PutImage (X,T,P^,Xorput);

sattilite;
repeat
PutImage (540,T,P^,Xorput);
setcolor (black);line (540,0,540,20);setcolor (white);
PutImage (540,T+5,P^,Xorput);
delay (50);
T := T+5;
until T = 75;
setcolor (green);
line (575,75,540,75);
delay (50);
setcolor (black);
line (575,75,540,75);
X := 10;
repeat
setcolor (black);
SetFillStyle (SolidFill,yellow);
FillEllipse (540,75,X,X);
delay (50);
SetFillStyle (SolidFill,red);
FillEllipse (540,75,X+5,X+5);
delay (50);
X := X+5;
until X = 75;
SetFillStyle (SolidFill,black);
FillEllipse (540,75,X+5,X+5);
SetColor (White);
end;
(***************************************************************************)
procedure sdi2hit;
begin
X := 540;
setcolor (white);
line (X+5,235,X+5,220);
Size := Imagesize (X+5,215,X+5,240);
Getmem (P,Size);
GetImage (X+5,215,X+5,240,P^);
T := 215;

repeat
PutImage (X,T,P^,Xorput);
PutImage (X,T-5,P^,Xorput);
setcolor (BLACK);line (X+5,235,X+5,220);line (X,235,X,220);setcolor(white);
delay (50);
T := T-5;
until T = 0;
PutImage (X,T,P^,Xorput);

Player1sdi;
repeat
PutImage (25,T,P^,Xorput);
setcolor (black);line (25,0,25,20);setcolor (white);
PutImage (25,T+5,P^,Xorput);
delay (50);
T := T+5;
until T = 75;
setcolor (green);
line (125,75,25,75);
delay (50);
setcolor (black);
line (125,75,25,75);
X := 10;
repeat
setcolor (black);
SetFillStyle (SolidFill,yellow);
FillEllipse (25,75,X,X);
delay (50);
SetFillStyle (SolidFill,red);
FillEllipse (25,75,X+5,X+5);
delay (50);
X := X+5;
until X = 75;
SetFillStyle (SolidFill,black);
FillEllipse (25,75,X+5,X+5);
SetColor (White);
Idlesat;
end;
(***************************************************************************)
Procedure gun1;
          Begin
          Setcolor(red);
          fillellipse(600,210,10,10);
          Sound(200);
          delay(175);
          nosound;
          delay(55);
          setcolor(yellow);
          fillellipse(600,210,12,12);
          sound(200);
          delay(200);
          nosound;
          delay(55);
          setcolor(black);
          fillellipse(600,210,10,10);
          fillellipse(600,210,12,12);
          end;
Procedure gun2; begin

          Setcolor(red);
          fillellipse(155,210,10,10);
          Sound(200);
          delay(175);
          nosound;
          delay(55);
          setcolor(yellow);
          fillellipse(155,210,12,12);
          sound(200);
          delay(200);
          nosound;
          delay(55);
          setcolor(black);
          fillellipse(155,210,10,10);
          fillellipse(155,210,12,12);
          end;
(***************************************************************************)
Procedure Fl_att1;
          Begin
          buildfleet1;
          Size:=Imagesize(64,200,136,236);
          Getmem(P,Size);
          Getimage(64,200,136,236,P^);
          PUTIMAGE(64,200,p^,XORPUT);
          Putimage(94,200,P^,xorput);
          Delay(75);
          putimage(94,200,P^,xorput);
          Putimage(104,200,P^,xorput);
          delay(75);
          putimage(104,200,P^,xorput);
          Putimage(114,200,P^,xorput);
          delay(75);
          putimage(114,200,P^,xorput);
          Putimage(124,200,P^,xorput);
          delay(75);
          putimage(124,200,P^,xorput);
          Putimage(134,200,P^,xorput);
          delay(75);
          putimage(134,200,P^,xorput);
          Putimage(144,200,P^,xorput);
          delay(75);
          putimage(144,200,P^,xorput);
          Putimage(154,200,P^,xorput);
          delay(75);
          putimage(154,200,P^,xorput);
          Putimage(164,200,P^,xorput);
          delay(75);
          putimage(164,200,P^,xorput);
          Putimage(174,200,P^,xorput);
          delay(75);
          putimage(174,200,P^,xorput);
          Putimage(184,200,P^,xorput);
          delay(75);
          putimage(184,200,P^,xorput);
          Putimage(194,200,P^,xorput);
          delay(75);
          putimage(194,200,P^,xorput);
          Putimage(204,200,P^,xorput);
          delay(75);
          putimage(204,200,P^,xorput);
          Putimage(214,200,P^,xorput);
          delay(75);
          putimage(214,200,P^,xorput);
          Putimage(224,200,P^,xorput);
          delay(75);
          putimage(224,200,P^,xorput);
          Putimage(234,200,P^,xorput);
          delay(75);
          putimage(234,200,P^,xorput);
          Putimage(244,200,P^,xorput);
          delay(75);
          putimage(244,200,P^,xorput);
          Putimage(254,200,P^,xorput);
          delay(75);
          putimage(254,200,P^,xorput);
          Putimage(264,200,P^,xorput);
          delay(50);
          putimage(264,200,P^,xorput);
          Putimage(274,200,P^,xorput);
          delay(50);
          putimage(274,200,P^,xorput);
          Putimage(284,200,P^,xorput);
          delay(50);
          putimage(284,200,P^,xorput);
          Putimage(294,200,P^,xorput);
          delay(50);
          putimage(294,200,P^,xorput);
          Putimage(304,200,P^,xorput);
          delay(50);
          putimage(304,200,P^,xorput);
          Putimage(314,200,P^,xorput);
          delay(50);
          putimage(314,200,P^,xorput);
          Putimage(324,200,P^,xorput);
          delay(50);
          putimage(324,200,P^,xorput);
          Putimage(334,200,P^,xorput);
          delay(50);
          putimage(334,200,P^,xorput);
          Putimage(344,200,P^,xorput);
          delay(50);
          putimage(344,200,P^,xorput);
          Putimage(354,200,P^,xorput);
          delay(50);
          putimage(354,200,P^,xorput);
          Putimage(364,200,P^,xorput);
          delay(50);
          putimage(364,200,P^,xorput);
          Putimage(374,200,P^,xorput);
          delay(50);
          putimage(374,200,P^,xorput);
          Putimage(384,200,P^,xorput);
          delay(50);
          putimage(384,200,P^,xorput);
          Putimage(394,200,P^,xorput);
          delay(50);
          putimage(394,200,P^,xorput);
          Putimage(404,200,P^,xorput);
          delay(50);
          putimage(404,200,P^,xorput);
          Putimage(414,200,P^,xorput);
          delay(50);
          putimage(414,200,P^,xorput);
          Putimage(424,200,P^,xorput);
          delay(50);
          putimage(424,200,P^,xorput);
          Putimage(434,200,P^,xorput);
          delay(50);
          putimage(434,200,P^,xorput);
          Putimage(444,200,P^,xorput);
          delay(50);
          putimage(444,200,P^,xorput);
          Putimage(454,200,P^,xorput);
          delay(50);
          putimage(454,200,P^,xorput);
          Putimage(464,200,P^,xorput);
          delay(50);
          putimage(464,200,P^,xorput);
          Putimage(474,200,P^,xorput);
          delay(50);
          putimage(474,200,P^,xorput);
          Putimage(484,200,P^,xorput);
          delay(50);
          putimage(484,200,P^,xorput);
          Putimage(494,200,P^,xorput);
          delay(50);
          putimage(494,200,P^,xorput);
          Putimage(504,200,P^,xorput);
          delay(50);
          Gun1;
          putimage(504,200,P^,xorput);
          end;
(****************************************************************************)
Procedure Fl_att2;
          Begin
          buildfleet2;
          Size:=Imagesize(467,200,551,240);
          Getmem(P,Size);
          Getimage(467,200,551,240,P^);
          PUTIMAGE(467,200,p^,XORPUT);
          Putimage(489,200,P^,xorput);
          Delay(75);
          putimage(489,200,P^,xorput);
          Putimage(499,200,P^,xorput);
          delay(75);
          putimage(499,200,P^,xorput);
          Putimage(509,200,P^,xorput);
          delay(75);
          putimage(509,200,P^,xorput);
          Putimage(519,200,P^,xorput);
          delay(75);
          putimage(519,200,P^,xorput);
          Putimage(529,200,P^,xorput);
          delay(75);
          putimage(529,200,P^,xorput);
          Putimage(539,200,P^,xorput);
          delay(75);
          putimage(539,200,P^,xorput);
          Putimage(549,200,P^,xorput);
          delay(75);
          putimage(549,200,P^,xorput);
          Putimage(559,200,P^,xorput);
          delay(75);
          putimage(559,200,P^,xorput);
          Putimage(569,200,P^,xorput);
          delay(75);
          putimage(569,200,P^,xorput);
          Putimage(579,200,P^,xorput);
          delay(75);
          putimage(579,200,P^,xorput);
          Putimage(589,200,P^,xorput);
          delay(75);
          putimage(589,200,P^,xorput);
          Putimage(599,200,P^,xorput);
          delay(75);
          putimage(599,200,P^,xorput);
          Putimage(609,200,P^,xorput);
          delay(75);
          putimage(609,200,P^,xorput);
          Putimage(9,200,P^,xorput);
          delay(75);
          putimage(9,200,P^,xorput);
          Putimage(19,200,P^,xorput);
          delay(75);
          putimage(19,200,P^,xorput);
          Putimage(29,200,P^,xorput);
          delay(75);
          putimage(29,200,P^,xorput);
          Putimage(39,200,P^,xorput);
          delay(75);
          putimage(39,200,P^,xorput);
          Putimage(49,200,P^,xorput);
          delay(50);
          putimage(49,200,P^,xorput);
          Putimage(59,200,P^,xorput);
          delay(50);
          putimage(59,200,P^,xorput);
          Putimage(69,200,P^,xorput);
          delay(50);
          putimage(69,200,P^,xorput);
          Putimage(79,200,P^,xorput);
          delay(50);
          putimage(79,200,P^,xorput);
          delay(50);
          putimage(81,200,P^,xorput);
          delay(50);
          GUN2;
          putimage(81,200,P^,xorput);
          end;
(****************************************************************************)
Procedure Expl1;
           Begin
          buildfleet1;
          Size:=Imagesize(64,200,136,236);
          Getmem(P,Size);
          Getimage(64,200,136,236,P^);
          PUTIMAGE(64,200,p^,XORPUT);
          Putimage(94,200,P^,xorput);
          Delay(75);
          putimage(94,200,P^,xorput);
          Putimage(104,200,P^,xorput);
          delay(75);
          putimage(104,200,P^,xorput);
          Putimage(114,200,P^,xorput);
          delay(75);
          putimage(114,200,P^,xorput);
          Putimage(124,200,P^,xorput);
          delay(75);
          putimage(124,200,P^,xorput);
          Putimage(134,200,P^,xorput);
          delay(75);
          putimage(134,200,P^,xorput);
          Putimage(144,200,P^,xorput);
          delay(75);
          putimage(144,200,P^,xorput);
          Putimage(154,200,P^,xorput);
          delay(75);
          putimage(154,200,P^,xorput);
          Putimage(164,200,P^,xorput);
          delay(75);
          putimage(164,200,P^,xorput);
          Putimage(174,200,P^,xorput);
          delay(75);
          putimage(174,200,P^,xorput);
          Putimage(184,200,P^,xorput);
          delay(75);
          putimage(184,200,P^,xorput);
          Putimage(194,200,P^,xorput);
          delay(75);
          putimage(194,200,P^,xorput);
          Putimage(204,200,P^,xorput);
          delay(75);
          putimage(204,200,P^,xorput);
          Putimage(214,200,P^,xorput);
          delay(75);
          putimage(214,200,P^,xorput);
          Putimage(224,200,P^,xorput);
          delay(75);
          putimage(224,200,P^,xorput);
          Putimage(234,200,P^,xorput);
          delay(75);
          putimage(234,200,P^,xorput);
          Putimage(244,200,P^,xorput);
          delay(75);
          putimage(244,200,P^,xorput);
          Putimage(254,200,P^,xorput);
          delay(75);
          putimage(254,200,P^,xorput);
          Putimage(264,200,P^,xorput);
          delay(50);
          putimage(264,200,P^,xorput);
          Putimage(274,200,P^,xorput);
          delay(50);
          putimage(274,200,P^,xorput);
          Putimage(284,200,P^,xorput);
          delay(50);
          putimage(284,200,P^,xorput);
          Putimage(294,200,P^,xorput);
          delay(50);
          putimage(294,200,P^,xorput);
          Putimage(304,200,P^,xorput);
          delay(50);
          putimage(304,200,P^,xorput);
          Putimage(314,200,P^,xorput);
          delay(50);
          putimage(314,200,P^,xorput);
          Putimage(324,200,P^,xorput);
          delay(50);
          putimage(324,200,P^,xorput);
          Putimage(334,200,P^,xorput);
          delay(50);
          putimage(334,200,P^,xorput);
          Putimage(344,200,P^,xorput);
          delay(50);
          putimage(344,200,P^,xorput);
          Putimage(354,200,P^,xorput);
          delay(50);
          putimage(354,200,P^,xorput);
          Putimage(364,200,P^,xorput);
          delay(50);
          putimage(364,200,P^,xorput);
          Putimage(374,200,P^,xorput);
          delay(50);
          putimage(374,200,P^,xorput);
          Putimage(384,200,P^,xorput);
          delay(50);
          putimage(384,200,P^,xorput);
          Putimage(394,200,P^,xorput);
          delay(50);
          putimage(394,200,P^,xorput);
          Putimage(404,200,P^,xorput);
          delay(50);
          putimage(404,200,P^,xorput);
          Putimage(414,200,P^,xorput);
          delay(50);
          putimage(414,200,P^,xorput);
          Putimage(424,200,P^,xorput);
          delay(50);
          putimage(424,200,P^,xorput);
          Putimage(434,200,P^,xorput);
          delay(50);
          MINE2;
          putimage(434,200,P^,xorput);
          EXPLODE2;
          end;
(****************************************************************************)
Procedure Expl2;
          begin
          buildfleet2;
          Size:=Imagesize(467,200,551,240);
          Getmem(P,Size);
          Getimage(467,200,551,240,P^);
          PUTIMAGE(467,200,p^,XORPUT);
          Putimage(489,200,P^,xorput);
          Delay(75);
          putimage(489,200,P^,xorput);
          Putimage(499,200,P^,xorput);
          delay(75);
          putimage(499,200,P^,xorput);
          Putimage(509,200,P^,xorput);
          delay(75);
          putimage(509,200,P^,xorput);
          Putimage(519,200,P^,xorput);
          delay(75);
          putimage(519,200,P^,xorput);
          Putimage(529,200,P^,xorput);
          delay(75);
          putimage(529,200,P^,xorput);
          Putimage(539,200,P^,xorput);
          delay(75);
          putimage(539,200,P^,xorput);
          Putimage(549,200,P^,xorput);
          delay(75);
          putimage(549,200,P^,xorput);
          Putimage(559,200,P^,xorput);
          delay(75);
          putimage(559,200,P^,xorput);
          Putimage(569,200,P^,xorput);
          delay(75);
          putimage(569,200,P^,xorput);
          Putimage(579,200,P^,xorput);
          delay(75);
          putimage(579,200,P^,xorput);
          Putimage(589,200,P^,xorput);
          delay(75);
          putimage(589,200,P^,xorput);
          Putimage(599,200,P^,xorput);
          delay(75);
          putimage(599,200,P^,xorput);
          Putimage(609,200,P^,xorput);
          delay(75);
          putimage(609,200,P^,xorput);
          Putimage(9,200,P^,xorput);
          delay(75);
          putimage(9,200,P^,xorput);
          Putimage(19,200,P^,xorput);
          delay(75);
          putimage(19,200,P^,xorput);
          Putimage(29,200,P^,xorput);
          delay(75);
          putimage(29,200,P^,xorput);
          Putimage(39,200,P^,xorput);
          delay(75);
          putimage(39,200,P^,xorput);
          Putimage(49,200,P^,xorput);
          delay(50);
          putimage(49,200,P^,xorput);
          Putimage(59,200,P^,xorput);
          delay(50);
          MINE1;
          putimage(59,200,P^,xorput);
          Putimage(69,200,P^,xorput);
          explode11;
          end;
Procedure Game;
          Begin
          CLEAR1;
          Setcolor(white);
          Pop1:=50000;
          Pop2:=50000;
          Nuke1:=0;
          Nuke2:=0;
          Ship1:=0;
          Ship2:=0;
          OVERPOP:=50000;
          repeat
          Str (Pop1:5, Pop1str);
          Str (Pop2:5, Pop2str);
          Str (Nuke1:1, Nuke1str);
          Str (Nuke2:1, Nuke2str);
          Str (Ship1:1, Ship1str);
          Str (Ship2:1, Ship2str);

          settextstyle(defaultfont,horizdir,1);
          outtextxy(25,250,Name1);
          Outtextxy(25,260,'of');
          Outtextxy(50,260,Country1);
          Outtextxy(400,250,name2);
          outtextxy(400,260,'of');
          outtextxy(425,260,country2);
          OutTextXY(25,280,'Population:');
          OutTextXY(25,290,pop1str);
          OutTextXY(25,380,'Nuke Supply:');
          OutTextXY(25,390,nuke1str);
          OutTextXY(25,400,'Fleets in Navy:');
          OutTextXY(25,410,ship1str);

          OUttextxy(25,310,'Enter your attack choice.');
          outtextxy(25,320,'(Q).....Use Propoganda');
          Outtextxy(25,330,'(A).....Build Nuke');
          outtextxy(25,340,'(Z).....Build Fleet');
          outtextxy(25,350,'(W).....Launch Nuke');
          outtextxy(25,360,'(S).....Launch Coastal Strike');

          OutTextXY(400,280,'Population:');
          OutTextXY(400,290,pop2str);
          OutTextXY(400,380,'Nuke Supply:');
          OutTextXY(400,390,nuke2str);
          OutTextXY(400,400,'Fleets in Navy:');
          OutTextXY(400,410,ship2str);
          OutTextXY(150,460,'Press X and <RETURN> to exit program.');
          OUttextxy(400,310,'Enter your attack choice.');
          outtextxy(400,320,'(9).....Use Propoganda');
          Outtextxy(400,330,'(6).....Build Nuke');
          outtextxy(400,340,'(3).....Build Fleet');
          outtextxy(400,350,'(8).....Launch Nuke');
          outtextxy(400,360,'(5).....Launch Coastal Strike');
          OUTTEXTXY(150,450,'Enter your attack, Player 1');
          Att1:=readkey;
          setcolor(0);
          outtextxy(150,450,'Enter your attack, Player 1');
          setcolor(white);
          outtextxy(150,450,'Enter your attack, Player 2');
          att2:=readkey;
          setcolor(0);
          outtextxy(150,450,'Enter your attack, Player 2');
          setcolor(white);
          Case att1 of

           'Q':pop2:=pop2-10000;
           'A':nuke1:=nuke1+1;
           'Z':Ship1:=ship1+1;
           'W':if nuke1>0 then begin pop2:=pop2-25000;nuke1:=nuke1-1;end;
           'S':if ship1>0 then begin pop2:=pop2-15000;ship1:=ship1-1;end;
           'X':halt;
           else  BEGIN
            outtextxy(150,450,'Aborting Player 1''s move.(INVALID CHARACTER)');
SETCOLOR(0);
           outtextxy(150,450,'Aborting Player 1''s move.(INVALID CHARACTER)');
           SETCOLOR(WHITE);
          end;        END;


          Case att2 of

           '9':pop1:=pop1-10000;
           '6':nuke2:=nuke2+1;
           '3':Ship2:=ship2+1;
           '8':if nuke2>0 then begin pop1:=pop1-25000;nuke2:=nuke2-1;end;
           '5':if ship2>0 then begin pop1:=pop1-15000;ship2:=ship2-1;end;
           'X':halt;
           else
            outtextxy(150,450,'Aborting Player 2''s move.(INVALID CHARACTER)');
SETCOLOR(0);
           outtextxy(150,450,'Aborting Player 2''s move.(INVALID CHARACTER)');
           SETCOLOR(WHITE);
          end;

          blackout;


          OUttextxy(25,310,'Enter your defend choice.');
          outtextxy(25,320,'(Q).....Brainwash Citizens');
          outtextxy(25,330,'(A).....Launch SDI Defense');
          outtextxy(25,340,'(Z).....Lay Mines');
          OUttextxy(400,310,'Enter your defend choice.');
          outtextxy(400,320,'(9).....Brainwash Citizens');
          Outtextxy(400,330,'(6).....Launch SDI Defense');
          outtextxy(400,340,'(3).....Lay Mines');
          OUTTEXTXY(150,450,'Enter your defense, Player 1');
          DEF1:=readkey;
          setcolor(0);
          outtextxy(150,450,'Enter your defense, Player 1');
          setcolor(white);
          outtextxy(150,450,'Enter your defense, Player 2');
          DEF2:=readkey;
          setcolor(0);
          outtextxy(150,450,'Enter your defense, Player 2');
          setcolor(white);

          Case def1 of
          'Q':if att2='9' then pop1:=pop1+10000;
          'A':if (att2='8') then pop1:=pop1 + 25000;
          'Z':if (att2='5') then pop1:=pop1 + 15000;
          'X':halt;
           else
           outtextxy(150,450,'Aborting Player 1''s move.(INVALID CHARACTER)');
           SETCOLOR(0);
           outtextxy(150,450,'Aborting Player 1''s move.(INVALID CHARACTER)');
           SETCOLOR(WHITE);
          end;

          Case def2 of
          '9':if att1='Q' then pop2:=pop2+10000;
          '6':if (att1='W') and (nuke1>0) then pop2:=pop2 + 25000;
          '3':if (att1='S') and (ship1>0) then pop2:=pop2 + 15000;
          'X':halt;
else
outtextxy(150,450,'Aborting Player 2''s move.(INVALID CHARACTER)');
SETCOLOR(0);
           outtextxy(150,450,'Aborting Player 2''s move.(INVALID CHARACTER)');
           SETCOLOR(WHITE);
          end;
          black_the_Def_choice;
          setcolor (black);
          OutTextXY(25,290,pop1str);
          OutTextXY(400,290,pop2str);
          OutTextXY(25,390,nuke1str);
          OutTextXY(400,390,nuke2str);
          OutTextXY(25,410,ship1str);
          OutTextXY(400,410,ship2str);
          setcolor (white);
          str (pop1:5,pop1str);
          str (pop2:5,pop2str);
          readkey;
          {RESTORECRTMODE;
          writeln ('att1=',att1);
          writeln ('nuke1=',nuke1);
          writeln ('def2=',def2);
          readln;
          SETGRAPHMODE (GRMODE);}
         {if (att1 = 'Q') and (def2 = '9') then brain1;}
          if (att1 = 'Q') and (def2 <> '9') then begin propaganda1;clear1;end;
          if (att1 = 'A') then begin buildnuke1;clear1;end;
          if att1 = 'Z' then begin buildfleet1;clear1;end;
          if (att1 = 'W') and (nuke1>0) and (def2='6') then sdi1hit;
          if (nuke1>0) and (att1='W') and (def2<>'6') then begin X:=25;Y:=540;anim;end;
          if def1='Z' then begin mine1; clear1; end;
          if (def1='A') and (att2<>'8') then begin Player1sdi; delay (500); Idlesat; end;
          if (att1='S') and (ship1>0) and (def2<>'3') then fl_att1;
          if (att1='S') and (ship1>0) and (def2='3') then expl1;

{         if (att2='9') and (def1='Q') then brain2;}
          if (att2='9') and (def1<>'Q') then begin propaganda2;clear2;end;
          if att2='6' then begin buildnuke2;clear2;end;
          if att2='3' then begin buildfleet2;clear2;end;
          if (att2='8') and (nuke2>0) and (def1='A') then sdi2hit;
          if (nuke2>0) and (att2='8') and (def1<>'A') then begin X:=540;Y:=25;anim;end;
          if (def2='6') and (att1<>'W') then begin sattilite; delay (500); clearsat; end;
          if (def2='3') and (att1<>'S') then begin mine2; clear2; end;
          if (att2='5') and (ship2>0) and (def1<>'Z') then fl_att2;
          if (att2='5') and (ship2>0) and (def1='Z') then expl2;

          {overpop:=0;}
          IF POP1<=0 then overpop:=0;
          if pop2<=0 then overpop:=0;
          until overpop = 0;
          cleardevice;
          if pop1 = 0 then loser := name1;
          if pop2 = 0 then loser := name2;
          if name1 = loser then winner := name2;
          if name2 = loser then winner := name1;
          SetTextStyle (SANSserifFont, HORIZdir, 5);
          OutTextXY (100,100,winner);
          OutTextXY (100,140,'Has Anihillated');
          OutTextXY (100,180,loser);
          end;
(***************************************************************************)


begin
Title;
Missile;
Randomize;
Buildpath;
Flames;

cleardevice;
GrDriver := Detect;
InitGraph (GrDriver, GrMode, 'c:\tp\bgi');
GrError := GraphResult;
if GrError <> GrOk
   then writeln ('Graphics Error: ', GraphErrorMsg (GrError))
   else begin
(*************************************************************************)
        Credits;
        Names;
        SetColor (Blue);
        SetFillStyle (SolidFill, Blue);
        FillEllipse (320,164,150,150);
        SetColor (Green);
        SetFillStyle (SolidFill, Green);
        FillPoly (10,Count1);
        FillPoly (10,Count2);
        fillpoly(7,count3);
        fillpoly(5,count4);
        game;
        readkey;
(***************************************************************************)

        end;


Closegraph;
end.
