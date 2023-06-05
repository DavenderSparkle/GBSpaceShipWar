#include <gb/gb.h>
#include <stdio.h>

#include "./background/map.h"
#include "./background/mapObjs.h"
#include "./sprites/maptiles.h"

void main()
{
    set_bkg_data(0,5,maptiles);
    set_bkg_tiles(0,0, mapWidth, mapHeight, mapPLN0);

    SHOW_BKG;
    DISPLAY_ON;
}
