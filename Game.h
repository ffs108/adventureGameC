/*****************************************************
 *
 *  CSCV352 - Game.h
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Player.h"
#include "Location.h"
#include "Item.h"

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

#define MAX_MAP_LOCATIONS 25
#define MAX_ITEM_COUNT 10

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

typedef struct Game{
    int numLocations;
    Location map[MAX_MAP_LOCATIONS];
    int itemCount;
    Item items[MAX_ITEM_COUNT];
    Player player;
} Game;


///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////

// Initializes the game structure and calls the initialize routines for the game’s map
// and the game’s items. The player object is also initialized.
int GameInitialize(Game *pGame);


#endif