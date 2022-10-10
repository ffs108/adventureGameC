/*****************************************************
 *
 *  CSCV352 - Player.c
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "Player.h"
#include "ItemList.h"

void PlayerInit(Player *pPlayer, int locationNumber)
{
    pPlayer->location = locationNumber;
}

void PlayerAddItem(Player *pPlayer, int itemNumber)
{
    int curItems;
    curItems = ItemListAddItem(&pPlayer->items, itemNumber);
    pPlayer->items.itemCount = curItems;
}

void PlayerRemoveItem(Player *pPlayer, int itemNumber)
{
    int curItems;
    if (ItemListHasItem(&pPlayer->items, itemNumber))
    {
        curItems = ItemListRemoveItem(&pPlayer->items, itemNumber);
        pPlayer->items.itemCount = curItems;
    }
    
}

bool PlayerHasItem(Player *pPlayer, int itemNumber)
{
    return ItemListHasItem(&pPlayer->items, itemNumber);
}