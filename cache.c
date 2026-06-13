#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KB 1024
#define MB (1024 * 1024)
#define STRIDE 64
#define REPETICOES 10000

int main() {
  clock_t inicio;
  double temp_total;
  int i;

  for (i = KB; i <= 64 * MB; i *= 2) {
    volatile char* vet = malloc(i);
    if (!vet) {
      return -1;
    }

    // Inicializa fora da medicao
    for (int j = 0; j < i; j++) {
      vet[j] = 1;
    }

    // Medicao
    inicio = clock();

    for (int r = 0; r < REPETICOES; r++) {
      for (int j = 0; j < i; j += STRIDE) {
        (void)vet[j];
      }
    }

    temp_total = ((double)(clock() - inicio) / CLOCKS_PER_SEC) * 1e9;
    double ciclos_por_acesso = temp_total / ((double)REPETICOES * (i / STRIDE));
    printf("Buffer: %6d KB | Tempo por acesso: %.4f ns\n", i / KB,
           ciclos_por_acesso);

    free((void*)vet);
  }

  return 0;
}