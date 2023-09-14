#include <stdio.h>
#include <sys/time.h> 
#include <stdlib.h>

int main(void) {
  int n = 500;
  int par = 0;
  int a[n][n];
  int b[n][n];
  int c[n][n];

  struct timeval tv;
  double start_t, end_t, tempo_gasto;

  //Inicializando Matriz
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      a[i][j]= i + j;
      b[i][j]= i * j;
    }
  }
  
  //EXECUÇÃO DO PROGRAMA
  
  gettimeofday(&tv, NULL);
  start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
  
  //verificaando quantos elementos são pares
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i][j] % 2 == 0){
        par += 1;
      }
    }
  }

  //Multiplicando as Matrizes
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("Numeros Pares: %d", par);
  gettimeofday(&tv,NULL); 
  end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
  tempo_gasto = end_t - start_t;
  printf("\nTempo %f usecs\n", tempo_gasto);
  return 0;
}