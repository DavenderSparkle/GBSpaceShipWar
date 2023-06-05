mkdir result

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\maptiles.o sprites\maptiles.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\chars.o sprites\chars.c

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\map.o background\map.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\mapObjs.o background\mapObjs.c

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\main.o main.c

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wm-yn"ShipWar" -o ShipWar.gb result\main.o ^
result\map.o result\mapObjs.o ^
result\chars.o result\maptiles.o 