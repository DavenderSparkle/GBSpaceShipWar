#include <gb/gb.h>
#include <stdio.h>

#include "./background/map.h"
#include "./background/mapObjs.h"
#include "./sprites/maptiles.h"
#include "./sprites/chars.h"

#include "gameCharacter.c"
#include "linkManager.c"

unsigned int i;

struct gameCharacter player;
struct gameCharacter enemy;

void setupPlayer()
{
    player.x = ((i % mapWidth)<<3) + 8;
    player.y = ((i / mapWidth)<<3) + 16;
    player.width = 8;
    player.height = 8;
    
    set_sprite_tile(0,0);
}

void setupEnemy()
{
    enemy.x = ((i % mapWidth)<<3) + 8;
    enemy.y = ((i / mapWidth)<<3) + 16;
    enemy.width = 8;
    enemy.height = 8;
    
    enemX = enemy.x;
    enemY = enemy.y;

    set_sprite_tile(1,1);
}


void setupObjts()
{
    for(i = 0; i<(mapWidth*mapHeight); i++)
    {
        if(mapObjs[i] == 3) {setupPlayer();}
        if(mapObjs[i] == 4) {setupEnemy();}
    }
}

void main()
{
    set_sprite_data(0,4,chars);

    set_bkg_data(0,5,maptiles);
    set_bkg_tiles(0,0, mapWidth, mapHeight, map);

    setupObjts();

    move_sprite(0, player.x, player.y);
    move_sprite(1, enemy.x, enemy.y);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);
    while(1)
    {
        UpdateMult();
        
        if(joypad() & J_LEFT) 
        {
            --player.x;
            ByteSend = InputLeft;
        }
        if(joypad() & J_RIGHT)
        {
            ++player.x;
            ByteSend = InputRight;
        }
        if(joypad() & J_UP)
        {
            --player.y;
            ByteSend = InputUp;
        }

        move_sprite(0, player.x, player.y);
        delay(10);
    }
}
