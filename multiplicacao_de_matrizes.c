#include <stdio.h>
#include <string.h>
 
#define N  512

int main() 
{
    static long A[N][N];
    static long B[N][N];
    static long C[N][N];

    memset(A, 2, sizeof(A));
    memset(B, 3, sizeof(B));
    memset(C, 0, sizeof(C));

    for (int lin = 0; lin < N; lin++)
        for (int col = 0; col < N; col++)
            for (int k = 0; k < N; k++)
                C[lin][col] += A[lin][k] * B[k][col];

    return (0);
}