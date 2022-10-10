/*****************************************************
 *
 *  CSCV352 - ItemList.h
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#ifndef ITEM_LIST_H
#define ITEM_LIST_H
#include <stdio.h>
#include <stdbool.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

#define MAX_ITEM_LIST 10

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

typedef struct ItemList{
    int items[MAX_ITEM_LIST]; // the itemNumbers in the list
    int itemCount; // the number of items in the list
} ItemList;

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////

void ItemListInit(ItemList *pItemList);
// Initializes the ItemList structure pointed to by pItemList as an empty list.

int ItemListAddItem(ItemList *pItemList, int itemNumber);
// Adds item identified by itemNumber to the end of the list. Have the function
// return the current count of items in the list.

int ItemListRemoveItem(ItemList *pItemList, int itemNumber);
// Removes item identified by itemNumber from the list. Have the function return
// the current number of items in the list.

bool ItemListHasItem(ItemList *pItemList, int itemNumber);
// Determines if the list pointed to by pItemList contains the item identified by
// itemNumber.

#endif