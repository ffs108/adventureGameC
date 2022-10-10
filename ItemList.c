/*****************************************************
 *
 *  CSCV352 - ItemList.c
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ItemList.h"



void ItemListInit(ItemList *pItemList)
{
    //array inside already made
    pItemList->itemCount = 0;
}

int ItemListAddItem(ItemList *pItemList, int itemNumber)
{
    pItemList->items[pItemList->itemCount] = itemNumber;
    pItemList->itemCount++;
    //printf("Item %d added! \n", itemNumber);
    return pItemList->itemCount;
}

int ItemListRemoveItem(ItemList *pItemList, int itemNumber)
{
    for (int i = 0; i < pItemList->itemCount; i++)
    {
        if (pItemList->items[i] == itemNumber)
        {
            //array shift to left
            for (int j = i; j != pItemList->itemCount; j++) 
            {
                //printf("item %d is now ",pItemList->items[j]);
                pItemList->items[j] = pItemList->items[j + 1];
                //printf("%d \n",pItemList->items[j]);
            }
            pItemList->itemCount --;
        }
    }
    return pItemList->itemCount;
}

bool ItemListHasItem(ItemList *pItemList, int itemNumber)
{
    int len = pItemList->itemCount;
    for (int i = 0; i < len; i++)
    {
        if (pItemList->items[i] == itemNumber)
        {
            return true;
        }
    }
    return false;
}