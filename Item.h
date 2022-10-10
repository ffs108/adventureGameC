/*****************************************************
 *
 *  CSCV352 - Item.h
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

#define MAX_ITEM_NAME_STRING 25
#define MAX_ITEM_DESCRIPTION_STRING 80

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

typedef struct Item{
char name[MAX_ITEM_NAME_STRING];
char description[MAX_ITEM_DESCRIPTION_STRING];
} Item;

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////

int ItemReadItems(Item items[], int maxItems, char *filename);
// Loads the list of items from a text file with comma delimited fields. Returns the
// number of objects loaded from the filename (or -1 if unable to open the file and
// load the data). Fills the Item array items with the contents of a file entitled
// "items.txt".

int ItemGetItemNumber(Item items[], int maxItems, char *itemName);
// Finds an item by itemName and returns the item number of the item
// itemName. The function returns -1 if an item with the specified itemName is not
// present. The item number is the index of the item in the items array

#endif