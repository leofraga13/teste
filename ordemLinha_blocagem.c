//Leonardo Fraga 32158841 -- 05n11

#include <stdio.h>
#include <sys/time.h> 
#include <stdlib.h>

#define blockSize 1000

int main(void) {
  struct timeval tv;
  double start_t, end_t, tempo_gasto;
  
  gettimeofday(&tv, NULL);
  start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
  
  int n = 1000;
  int par = 0;
  int iInner, kInner, jInner;
  
  int **a = calloc(n, sizeof(int* ));
  int **b = calloc(n, sizeof(int* ));
  int **c = calloc(n, sizeof(int* ));
  
  
  for(int i=0; i< n; i++){ 
    a[i] = calloc(n, sizeof(int *));
    b[i] = calloc(n, sizeof(int *));
    c[i] = calloc(n, sizeof(int *));
  }

  //Inicializando Matriz
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      a[i][j]= i + j;
      b[i][j]= i * j;
    }
  }

  
  //verificaando quantos elementos são pares
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i][j] % 2 == 0){
        par += 1;
      }
    }
  }

  //Multiplicando as Matrizes
  for (int i = 0; i < n; i+=blockSize){ 
    for (int k=0; k<n ; k+= blockSize){ 
      for (int j = 0 ; j < n; j+=blockSize){       
        for (iInner = i; iInner<j+blockSize; iInner++){      
          for (kInner = k ; kInner<k+blockSize; kInner++){ 
            for (jInner = j; jInner<j+blockSize ; jInner++){ 
              c[iInner][jInner] += a[iInner][kInner] * b[kInner][jInner];
            }
          }
        }
      }
    }
  }
      
  printf("Numeros Pares: %d", par);
  gettimeofday(&tv,NULL); 
  end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
  tempo_gasto = end_t - start_t;
  printf("\nTempo %f usecs\n", tempo_gasto);

  for (int i = 0; i < n; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);
  return 0;
}