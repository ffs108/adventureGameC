/*****************************************************
 *
 *  CSCV352 - Item.c
 *
 *  Student:  Francisco Figueroa
 *
******************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

#define MAX_LINE_SIZE 125 //105 + , + ""s(4) + \n + 14 for white space


int ItemReadItems(Item items[], int maxItems, char *filename)
{
    FILE *in;
    in = fopen(filename, "r");
    int count = 0;
    char *line = NULL ;
    char *token;
    size_t size = MAX_LINE_SIZE;
    while (getline(&line, &size, in) != EOF && count <= maxItems)
    {
        //sscanf(line,"%s[^,] %s",items[count].name,items[count].description);
        //printf("%s",line);
        token = strtok(line,"\",");//from quotes to comma
        strcpy(items[count].name,token);
        token = strtok(NULL,",\"");//remove remaining quotes ignore comma
        strcpy(items[count].description,token);
        //printf("This is what it thinks name is: %s\n",items[count].name);
        count++;
    }
    fclose(in);
    return count;
}

int ItemGetItemNumber(Item items[], int maxItems, char *itemName)
{
    for(int num = 0; num < maxItems; num++)
    {
        if (strcmp(items[num].name, itemName) == 0)
        {
            return num;
        }
    }
    return -1;
}