#include "board.h"
#include "player.h"
#include "cars.h"
#include "rules.h"
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
/*
 * One point of contact between all of our files
 * This is where the game is played/setUp and the rules are placed
 */

int isLose = FALSE;
int isWin = FALSE;

int lose(void)
{
    return isLose;
}

void setUp(int row, int col)
{
    /*
     * Call once to set everthing up all at once!
    */

    setUpBoard(row, col);
    setUpPlayer();
    setUpCars(row, col);
}

void update(void)
{
    int i;
    int* carIdx = getCarRows();
    int row = getBoardRow();
    int col = getBoardCol();

    createEmptyBoard(row, col);

    /*add cars*/
    for (i = 0; i < getNumberOfCars(); i++)
    {
        int carRow = carIdx[i];
        int carCol = getCarCol(i);
        int carDir = getCarDirection(i);

        if (carDir == 1)
        {
            /*Car going right*/
            getBoard()[carRow][carCol] = '>';
        }
        else
        {
            /*Car going left*/
            getBoard()[carRow][carCol] = '<';
        }
    }
    /*add player*/
    getBoard()[getPlayerRow()][getPlayerCol()] = 'P';
    free(carIdx);
}

void display(){
    displayBoard();
}

void rulesExit(void)
{
    /*To be called when program finishes!*/
    boardExit();
    playerExit();
    carExit();
}

int legalMove(char direction)
{
    /*
     * An illegal move is when the player tries to move out of bounds
    */
    int isLegal = FALSE;
    switch (direction)
    {
        case 'w':
            /*player move north if can*/
            if ((getPlayerRow()) - 1 >= 1)
            {
                isLegal = TRUE;
            }
            break;

        case 's':
            if ((getPlayerRow() + 1) <= getBoardRow() - 2)
            {
                isLegal = TRUE;
            }
            break;
        
        case 'a':
            if ((getPlayerCol() - 1) >= 1)
            {
                isLegal = TRUE;
            }
            break;

        case 'd':
            if ((getPlayerCol() + 1) <= getBoardCol() - 2)
            {
                isLegal = TRUE;
            }
            break;

        default:
            isLegal = FALSE;
            break;
    }
    return isLegal;
}

int collided(void){
    /*
     * Checks if the player is hit by a car, the game player loses
     * The player is hit by a car if any car is in the same coordinates as the player
    */

    int i, collided = FALSE;
    int* carRowIdx = getCarRows();
    for (i = 0; i < getNumberOfCars(); i++)
    {
        int carRowPos = carRowIdx[i];
        int carColPos = getCarCol(i);

        if ((carRowPos == getPlayerRow()) && (carColPos == getPlayerCol()))
        {
            collided = TRUE;
        }
    }
    free(carRowIdx);
    return collided;
}

int goalReached(void)
{
    int win = FALSE;
    if ((getPlayerRow() == getBoardRow() - 2) && getPlayerCol() == getBoardCol() - 2)
    {
        win = TRUE; /*Player has reached the goal!*/
    }
    return win;
}

int win(void)
{
    return isWin;
}

void cMove(void)
{
    int i;

    for(i = 0; i < getNumberOfCars(); i++)
    {
        int carColPos = getCarCol(i);
        int carDir = getCarDirection(i);

        if (carDir == 1)
        {
            /*Car going right*/
            if (carColPos == getBoardCol() - 2)
            {
                /*
                 * Car already at edge
                 * switch directions
                 */
                changeDirection(i);
            }
            else
            {
                *(getCar(i) + 1) += 1;
            }
        }
        else
        {
            /*Car going left*/
            if (carColPos == 1)
            {
                changeDirection(i);
            }
            else
            {
                *(getCar(i) + 1) -= 1;
            }
        }
    }
}


void pMove(char direction)
{
    /*
     * Each time a player moves, the cars move
     * If the player is hit by a car, the game player loses
     * If the player reaches the goal, the game player wins
    */
    if (legalMove(direction))
    {
        playerMove(direction);
        cMove();
        update();
        if (collided() == TRUE)
        {
            isLose = TRUE;
        }
        else if (goalReached() == TRUE)
        {
            isWin = TRUE;
        }
    }
}












