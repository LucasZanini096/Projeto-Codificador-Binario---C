#ifndef ANALISEMATRIZ_H
#define ANALISEMATRIZ_H

#include <stdio.h>
#include <stdlib.h>

void cortarMatriz(int linhasOriginal, int colunasOriginal,
                  int **matrizOriginal,
                  int linhasCortada, int colunasCortada, int **matrizCortada,
                  int inicioLinha, int inicioColuna);

void analiseMatriz(int linhasOriginal, int colunasOriginal, int **matriz);

#endif