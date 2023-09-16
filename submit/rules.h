#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

void setUp(int row, int col);
void update(void);
void display(void);
void rulesExit(void);
int lose(void);
void pMove(char direction);
int win(void);
