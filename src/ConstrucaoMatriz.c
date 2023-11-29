#include "../include/ConstrucaoMatriz.h"
#include "../include/PrintMatriz.h"


void construirMatriz(int linhasOriginal, int colunasOriginal, int **matriz) {

  int i, j;
  for (i = 0; i < linhasOriginal; i++) {
    for (j = 0; j < colunasOriginal; j++) {
      printf("Digite o valor da posição [%d] [%d]:", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
  mostrarMatriz(linhasOriginal, colunasOriginal, matriz);
}


