#include <stdio.h>
#include <time.h>

#define KB 1024
#define MB 1048576

int main()
{
   long inicio;
   int vet_tam = 8*MB -1;
   double temp_total, temp_gasto;
   volatile int aux = 0;

   static int vet[8*MB];
   int i, j;
   unsigned int k;

   for(i = 1; i <= MB; i *= 2)
   {
      temp_total=0;
      for(j = 0; j < 6; j++)
      {
         inicio = clock();
         for(k = 0; k < 1024*MB; k += 7)
            aux += vet[(k*i)&vet_tam];   
         
         temp_gasto = (double)(clock() - inicio)/CLOCKS_PER_SEC;
         temp_total += temp_gasto;
      }
      temp_total /= 6;
      printf("Para i valendo: %d Tempo gasto:%lf\n",i,temp_total);
   } 
}