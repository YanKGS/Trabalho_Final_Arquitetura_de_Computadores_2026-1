#include <stdio.h>
#include <string.h>
#include <time.h>
 
#define ROWS  5000
#define COLS   100
#define K_MAX  100

 
static double x[ROWS][COLS];
 
int main(void) {
 
 
    memset(x, 1, sizeof(x));
 
    int i, j, k;
    /* for (k = 0; k < K_MAX; k++)      
        for (j = 0; j < COLS; j++)
            for (i = 0; i < ROWS; i++)
                x[i][j] = 2 * x[i][j]; */
 
                               
 
    memset(x, 1, sizeof(x));
 
    for (k = 0; k < K_MAX; k++)
        for (i = 0; i < ROWS; i++)
            for (j = 0; j < COLS; j++)
                x[i][j] = 2 * x[i][j];
 
 
 
    return 0;
}