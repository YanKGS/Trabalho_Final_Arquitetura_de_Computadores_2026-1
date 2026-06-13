#include <stdio.h>
#include <time.h>

#define KB 1024
#define MB 1048576 * 64
#define STRIDE_FIX 64

int main() {
  long inicio = STRIDE_FIX;
  int vet_tam = 8 * MB - 1;
  double temp_total, temp_gasto;
  volatile int aux = 0;

  static int vet[STRIDE_FIX];
  int i, j;
  unsigned int k;

  for (i = STRIDE_FIX; i <= MB; i *= 2) {
    temp_total = 0;
    for (j = 0; j < 6; j++) {
      inicio = clock();

      temp_gasto = (double)(clock() - inicio) / CLOCKS_PER_SEC;
      temp_total += temp_gasto;
    }
    temp_total /= 6;
    printf("Para i valendo: %d Tempo gasto:%lf\n", i, temp_total);
  }
}