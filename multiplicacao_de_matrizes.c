#include <stdio.h>
#include <stdlib.h>
 
#define N 1024
 
int main() {
    static double A[N][N];
    static double B_mat[N][N];
    static double C[N][N];
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j]     = 1.0;
            B_mat[i][j] = 2.0;
        }
    }
 
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int x = 0; x < N; x++) {
                C[i][j] += A[i][x] * B_mat[x][j];
            }
        }
    }
 
    return 0;
}