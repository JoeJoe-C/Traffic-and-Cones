#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "board.h"

char** board;
int boardRow;
int boardCol;

void createEmptyBoard(int row, int column)
{
    /*
     * Creates an empty board and populates it with
     * border tiles and road tiles    
    */
    int i, j;

    board = (char**)malloc(sizeof(char*) * row);
    for (i = 0; i < row; i++){
        board[i] = (char*)malloc(sizeof(char) * column);
        for (j = 0; j < column; j++){
            if (i == 0 || i == row - 1 || j == 0 || j == column - 1){
                board[i][j] = '*';
            }
            else if (i % 2 == 0){
                board[i][j] = '-';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }
    board[boardRow - 2][boardCol - 2] = 'G';
}

void setUpBoard(int row, int col)
{
    /*To be called once only!*/
    boardRow = row;
    boardCol = col;
    createEmptyBoard(row, col);
}

void displayBoard(void)
{
    int i, j;
    for (i = 0; i <= boardRow - 1; i++){
        for (j = 0; j <= boardCol - 1; j++){
            char c = board[i][j];
            printf("%c", c);
        }
        printf("\n");
    }
}

int getBoardRow(void)
{
    return boardRow;
}

int getBoardCol(void)
{
    /*We are hiding the board details so we want to return the value to prevent from setting*/
    return boardCol;
}

void boardExit(void)
{
    int i;
    for (i = 0; i < boardRow; i++){
        free(board[i]);
    }
    free(board);
}

char** getBoard(void)
{
    return board;
}

void setBoard(char** board){
    int i;
    for (i = 0; i < boardRow; i++){
        free(board[i]);
    }
    free(board);
    board = board;
}


