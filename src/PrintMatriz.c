#include "../include/PrintMatriz.h"

void mostrarMatriz(int nLinhas, int nColunas, int **matriz) {
  for (int i = 0; i < nLinhas; i++) {
    for (int j = 0; j < nColunas; j++) {
      printf("%d  ", matriz[i][j]);
    }
    printf("\n");
  }
}