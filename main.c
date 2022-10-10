/*****************************************************
 *
 *  CSCV352 - main.c
 *
 *  Student:  Francisco Figueroa
 *
 ******************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "Game.h"

#define MAX_COMMAND_LEN 30

char* strToLower(char *word)
{
    for (int i = 0; i < word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}


int main(void)
{
    printf("\nCHARACTER\tDESCRIPTION\n");
    printf("--------------------------------------\n");
    printf("n, N\tNorth: Go North\n");
    printf("e, E\tEast: Go East\n");
    printf("w, W\tWest: Go West\n");
    printf("s, S\tSouth: Go South\n");
    printf("g, G\tGet <item>: Get the item (if it exists) and put in user item list\n");
    printf("d, D\tDrop <item>: Drop the item (if carrying it) in current location\n");
    printf("i, I\tInventory: list the items the user is carrying\n");
    printf("l, L\tLook: Describe the current location (and its associated items).\n");
    printf("x, X\tExit: Quit game.\n\n");

    printf("You awaken in a strange place with no memories of who you are and how you got here.\n");
    printf("Your eyes sting as the light hits them for the first time in what could be forever. <You should look around>\n");

    Game game;
    GameInitialize(&game);
    //int cur = game.player.location;
    //int location [] = {game.map[cur].north, game.map[cur].east, game.map[cur].south, game.map[cur].west};
    char command[MAX_COMMAND_LEN], result[MAX_COMMAND_LEN];
    printf("\nWhat do you do? ");
    scanf("%s",command);
    while (strcmp(strtok(strToLower(command)," "), "x"))
    {
        strcpy(result,command);
        //printf("the result val is: %s\n",result);
        //printf("Your in the %s, what is your next action?\n", game.map[cur].name);
        if(strcmp(result, "n") == 0){
            if (game.map[game.player.location].north != -1)
            {
                game.player.location = game.map[game.player.location].north;
                printf("<You proceed to go North.>\n");
            }
            else
            {
                printf("<You can't go North.>\n");
            }
        }   
        else if(strcmp(result, "e") == 0){
            if (game.map[game.player.location].east != -1)
            {
                game.player.location = game.map[game.player.location].east;
                printf("<You proceed to go East.>\n");
            }
            else
            {
                printf("<You can't go East.>\n");
            }
        }    
        else if(strcmp(result, "w") == 0){
            if (game.map[game.player.location].west != -1)
            {
                game.player.location = game.map[game.player.location].west;
                printf("<You proceed to go West.>\n");
            }
            else
            {
                printf("<You can't go West.>\n");
            }
        }    
        else if(strcmp(result, "s") == 0){
            if (game.map[game.player.location].south != -1)
            {
                game.player.location = game.map[game.player.location].south;
                printf("<You proceed to go South.>\n");
            }
            else
            {
                printf("<You can't go South.>\n");
            }
        }    
        else if(strcmp(result, "g") == 0){
            char token[MAX_COMMAND_LEN];
            scanf("%s",token);
            strToLower(token);
            int itemVal = -1;
            int cur = game.player.location;
            for (int i = 0; i < MAX_ITEM_COUNT; i++) //<= might be issue
            {
                if (strcmp(token,game.items[i].name) == 0)
                {
                    itemVal = i;
                    break;
                }    
            }
            
            if (itemVal != -1 && LocationHasItem(&game.map[cur], itemVal))
            {
                LocationRemoveItem(&game.map[cur], itemVal);
                PlayerAddItem(&game.player, itemVal);
                printf("<You pick up the %s from location.>\n", token);

            }
            else
            {
                printf("<No %s item in this location.>\n", token);
            }
        }    
        else if(strcmp(result, "d") == 0){
            char token[MAX_COMMAND_LEN];
            scanf("%s",token);
            strToLower(token);
            int itemVal = -1;
            int cur = game.player.location;
            for (int i = 0; i < MAX_ITEM_COUNT; i++) //<= might be issue
            {
                if (strcmp(token,game.items[i].name) == 0)
                {
                    itemVal = i;
                    break;
                }    
            }
            
            if (itemVal != -1 && PlayerHasItem(&game.player, itemVal))
            {
                PlayerRemoveItem(&game.player, itemVal);
                LocationAddItem(&game.map[cur], itemVal);
                printf("<You drop the %s in this location.>\n", token);
            }
            else
            {
                printf("<You have no %s item in your inventory.>\n", token);
            }
        }    
        else if(strcmp(result, "i") == 0){
            printf("<Current inventory:>\n");
            int size = game.player.items.itemCount;
            //printf("The itemcount is: %d\n", size);
            for (int i = 0; i < size; i++)
            {
                int item = game.player.items.items[i];
                //printf("Numerical val of item: %d\n", item);
                char *element;
                element = game.items[item].name;
                printf("\t\t<%s>\n", element);
            }
            
        }    
        else if(strcmp(result, "l") == 0){
            
            char *locDesc;
            char *itemDesc;
            int cur = game.player.location;
            locDesc = game.map[cur].description;
            printf("<You look around, %s>\n",locDesc);
            for (int i = 0; i < game.map[cur].items.itemCount; i++)
            {
                int item = game.map[cur].items.items[i];
                itemDesc = game.items[item].description;
                printf("\t<You see %s>\n",itemDesc);
            }
            

        } 
        else {
            printf("<I don't know what you want to do.>\n");
        }
        printf("\nWhat do you do? ");
        scanf("%s",command);
    }
}