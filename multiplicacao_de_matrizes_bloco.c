#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N     512
#define BLOCK   64

void multiplica_por_blocos(long A[N][N], long B[N][N], long C[N][N]) 
{
    for (int lin = 0; lin < N; lin += BLOCK) 
    {
        for (int col = 0; col < N; col += BLOCK) 
        {
            for (int k = 0; k < N; k += BLOCK) 
            {
                for (int lin_b = lin; lin_b < lin + BLOCK; lin_b++) 
                {
                    for (int col_b = col; col_b < col + BLOCK; col_b++)  
                    {
                        for (int k_b = k; k_b < k + BLOCK; k_b++)
                            C[lin_b][col_b] += A[lin_b][k_b] * B[k_b][col_b];
                    }
                }
            }
        }
    }
}

int main() 
{
    static long A[N][N];
    static long B[N][N];
    static long C[N][N];

    memset(A, 2, sizeof(A));
    memset(B, 3, sizeof(B));
    memset(C, 0, sizeof(C));

    multiplica_por_blocos(A, B, C);

    return (0);
}