mkdir result

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\maptiles.o sprites\maptiles.c

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\map.o background\map.c

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o result\main.o main.c

c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wm-yn"ShipWar" -o ShipWar.gb result\map.o result\maptiles.o result\main.o