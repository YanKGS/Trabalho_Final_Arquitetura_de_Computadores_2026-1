#include <stdio.h>
#include <stdlib.h>

#define N     1024
#define BLOCK   256

void multiplica_por_blocos(long A[N][N], long B_mat[N][N], long C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = 0;

    for (int i = 0; i < N; i += BLOCK) {
        for (int j = 0; j < N; j += BLOCK) {
            for (int k = 0; k < N; k += BLOCK) {
                for (int i_b = i; i_b < i + BLOCK; i_b++) {
                    for (int k_b = k; k_b < k + BLOCK; k_b++) {
                        long a_ik = A[i_b][k_b];
                        for (int j_b = j; j_b < j + BLOCK; j_b++) {
                            C[i_b][j_b] += a_ik * B_mat[k_b][j_b];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    static long A[N][N];
    static long B_mat[N][N];
    static long C[N][N];
    srand(0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j]     = rand() % N;
            B_mat[i][j] = rand() % N;
        }
    }

    multiplica_por_blocos(A, B_mat, C);


    return 0;
}