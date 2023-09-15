#include "random.h"
#include "cars.h"
#include <stdlib.h>
#include <stdio.h>

int numberOfCars;
int** carPos;


void setUpCars(int row, int col)
{
    /*
     * To be called once upon setup
     */

    int i;
    numberOfCars = (row - 2) / 2;
    carPos = (int**)malloc(sizeof(int*) * numberOfCars);

    initRandom();
    for (i = 0; i < numberOfCars; i++)
    {
        int rowIndex = (3 + (2 *(i)) - 1); /*we minus 1 to translate the index placement*/
        int* rowPtr = (int*)malloc(sizeof(int) * 3);

        rowPtr[0] = rowIndex;
        rowPtr[1] = randomUCP(1, col - 2);
        rowPtr[2] = randomUCP(0, 1); /*1 for right, 0 for left*/

        carPos[i] = rowPtr;
    }
}

int getCarDirection(int index){
    return carPos[index][2];
}

int getCarCol(int index){
    return carPos[index][1];
}

int* getCarRows(void){
    int i;
    int* row = (int*)malloc(sizeof(int) * numberOfCars);
    
    for (i = 0; i < numberOfCars; i++)
    {
        row[i] = carPos[i][0];
    }
    return row;
}

int* getCar(int index){
    return carPos[index];
}

void carExit(void){
    int i;
    for (i = 0; i < numberOfCars; i++)
    {
        free(carPos[i]);
    }
    free(carPos);
}

int getNumberOfCars(void){
    return numberOfCars;
}

void changeDirection(int index){
    int dir = carPos[index][2];
    switch (dir)
    {
        case 0:
            carPos[index][2] = 1;
            break;
        case 1:
            carPos[index][2] = 0;
            break;
    }
}

