#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define max 1000
#define blockSize 100

void initializeMatrix(int matrix[max][max], int value) {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            matrix[i][j] = value;
        }
    }
}

int main() {
    int a[max][max];
    int b[max][max];
    int c[max][max];
    int pares = 0;
    int iInner, kInner, jInner;

    struct timeval tv;
    double start_t, end_t, tempo_gasto;

    // Inicializando Matrizes
    initializeMatrix(a, 0); // Inicializa a matriz a com zeros
    initializeMatrix(b, 0); // Inicializa a matriz b com zeros
    initializeMatrix(c, 0); // Inicializa a matriz c com zeros

    // Inicializa matriz 'a' e 'b' com valores específicos
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            a[i][j] = i + j;
            b[i][j] = i * j;
        }
    }

    // Execução do Programa
    printf("=========== Iniciando execucao ============\n");
    gettimeofday(&tv, NULL);

    start_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (a[i][j] % 2 == 0) {
                pares += 1;
            }
        }
    }

    for (int i = 0; i < max; i += blockSize) {
        for (int k = 0; k < max; k += blockSize) {
            for (int j = 0; j < max; j += blockSize) {
                for (iInner = i; iInner < i + blockSize; iInner++) {
                    for (kInner = k; kInner < k + blockSize; kInner++) {
                        for (jInner = j; jInner < j + blockSize; jInner++) {
                            c[iInner][jInner] += a[iInner][kInner] * b[kInner][jInner];
                        }
                    }
                }
            }
        }
    }

    gettimeofday(&tv, NULL);
    end_t = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    tempo_gasto = end_t - start_t;
    printf("Tempo gasto: %f segundos\n", tempo_gasto);

    // Impressão das Matrizes (Omissa para evitar uma saída extensa)

    return 0;
}
