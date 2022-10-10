/*****************************************************
 *
 *  CSCV352 - Location.c
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Location.h"
#include "ItemList.h"

#define MAX_LINE_SIZE 300 //250+25+25padding


char* formatHelper(char * str)
{
    //printf("Entering: %s\n",str);
    if (*str == ' ')
    {
        str = str + 1;
    }
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\"' && str[i+1] == '\0')
        {
            str[i] = '\0';
        }
        
        else if (str[i] == '\"')
        {
            str = str + 1;
        }
        i++;
    }
    return str;
}

int LocationReadMap(Location map[], int maxLocations, char *filename)
{
    FILE *in;
    in = fopen(filename, "r");
    int count = 0;
    if(in != NULL)
    {
        char *line = NULL ;
        char *token;
        size_t size = MAX_LINE_SIZE;
        while (getline(&line, &size, in) != EOF && count <= maxLocations)
        {
            //sscanf(line,"%s[^,] %s",items[count].name,items[count].description);
            //printf("%s\n",line);
            token = strtok(line,",");
            //printf("%s\n",token);
            map[count].north = atoi(token);
            token = strtok(NULL,",");
            map[count].east = atoi(token);
            token = strtok(NULL,",");
            map[count].south = atoi(token);
            token = strtok(NULL,", "); 
            map[count].west = atoi(token);          
            token = strtok(NULL,",");
            //printf("This is what is left over: %s\n",line);
            strcpy(map[count].name,formatHelper(token));
            token = strtok(NULL,",\"");
            //printf("%s\n",token);
            strcpy(map[count].description,token);
            count++;
        }
    }
    fclose(in);
    return count;
}
void LocationAddItem(Location *pLocation, int itemNumber)
{
    //printf("\n(add)Item count before: %d\n",pLocation->items.itemCount);
    ItemListAddItem(&pLocation->items, itemNumber);
    //pLocation->items.itemCount = curItems;
    //printf("This is the itemCount returned: %d",some);
    //printf("\n(add)Item count after: %d\n",pLocation->items.itemCount);
}
void LocationRemoveItem(Location *pLocation, int itemNumber)
{
    //printf("\nItem count before: %d\n",pLocation->items.itemCount);
    ItemListRemoveItem(&pLocation->items, itemNumber);
    //pLocation->items.itemCount = curItems;
    //printf("\nItem count after: %d\n",pLocation->items.itemCount);
}
bool LocationHasItem(Location *pLocation, int itemNumber)
{
    //printf("For the int %d the func returned: %d\n",itemNumber,ItemListHasItem(&pLocation->items, itemNumber));
    return ItemListHasItem(&pLocation->items, itemNumber);
}

