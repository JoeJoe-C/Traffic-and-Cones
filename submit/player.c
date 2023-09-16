#include "player.h"
#include <stdlib.h>
#include <stdio.h>

int* playerPos;

void setUpPlayer(){
    playerPos = (int*)malloc(sizeof(int) * 2);
    playerPos[0] = 1;
    playerPos[1] = 1;
}

void playerMove(char direction)
{
    /*
     * Player can move in 4 directions:
     * North, South, East, West
     * We do this by manipulating the player position
    */

   switch (direction)
   {
        case 'w':
            /*player move north if can*/
            playerPos[0] -= 1;
            break;
        case 's':
            /*player move south if can*/
            playerPos[0] += 1;
            break;
        case 'd':
            /*player move east if can*/
            playerPos[1] += 1;
            break;
        case 'a':
            /*player move west if can*/
            playerPos[1] -= 1;
            break;
   }
}

int getPlayerRow(void){
    return playerPos[0];
}

int getPlayerCol(void){
    return playerPos[1];
}

void playerExit(void){
    free(playerPos);
}