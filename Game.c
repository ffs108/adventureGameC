/*****************************************************
 *
 *  CSCV352 - Game.c
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Game.h"
#include "Player.h"
#include "Location.h"
#include "Item.h"



int GameInitialize(Game *pGame)
{
    srand(clock());
    pGame->numLocations = LocationReadMap(pGame->map, MAX_MAP_LOCATIONS, "map.txt");
    pGame->itemCount = ItemReadItems(pGame->items, MAX_ITEM_COUNT, "items.txt");
    //generate items in locations:
    for (int i = 0; i < pGame->numLocations; i++)
    {
        int item = rand() % pGame->itemCount;
        LocationAddItem(&pGame->map[i], item);
    }
    PlayerInit(&pGame->player,0);
    return 1;
}
