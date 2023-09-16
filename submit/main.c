#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rules.h"
#include "terminal.h"

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

void termClear(void);
void displayhelp(void);
void displayCommands(void);

int main(int argc, char* argv[])
{
    int mapRow, mapColumn;
    int gameStart = FALSE;
    char input;
    /* check arguements */
    if (argc == 1)
    {
        displayhelp();
    }
    else if (argc > 3 || argc < 3) /* it also includes program name */
    {
        printf("You need to have two arguements to start the program properly\n");
    }
    else
    {
        /* correct number of arguements */
        mapRow = atoi(argv[1]); /*We make the assumption that these two values ARE valid therefore this is okay :)*/
        mapColumn = atoi(argv[2]);
        
        if ((mapRow >= 3) && (mapColumn >= 5))
        {
            /*valid row val can start program now*/
            if (mapRow % 2 == 0)
            {
                printf("Please enter a row with an odd value\n");
            }
            else{
                mapRow += 2;
                mapColumn += 2;
                gameStart = TRUE;
                
                setUp(mapRow, mapColumn);
                
                while(gameStart == TRUE)
                {
                    termClear();
                    update();
                    display();
                    displayCommands();

                    disableBuffer();
                    scanf("%c", &input);
                    enableBuffer();
                    switch (input)
                    {
                        case 'w':
                            pMove(input);
                            break;
                        case 's':
                            pMove(input);
                            break;
                        case 'd':
                            pMove(input);
                            break;
                        case 'a':
                            pMove(input);
                            break;
                        case 'q':
                            printf("Thank you for playing :)!\n");
                            rulesExit();
                            gameStart = FALSE;
                            break;
                        default:
                            printf("Not a valid input\n");
                            break;
                    }
                    if (win() == TRUE)
                    {
                        termClear();
                        display();
                        printf("You win!\n");
                        rulesExit();
                        gameStart = FALSE;
                    }
                    else if (lose() == TRUE)
                    {
                        termClear();
                        display();
                        printf("You lose!\n");
                        rulesExit();
                        gameStart = FALSE;
                    }
                }
            }
        }
        else
        {
            printf("Minimum value for row, col is 3, 5 respectively\n");
        }
    }
    
    return 0;
}

void displayhelp(void)
{
    printf("Usage: ./traffic <map_row> <map_col>\n");
}

void termClear(void)
{
    system("clear");
}

void displayCommands(void)
{
    printf("Commands:\n");
    printf("w - Move North\n");
    printf("a - Move West\n");
    printf("s - Move South\n");
    printf("d - Move East\n");
    printf("q - Quit\n");
}









