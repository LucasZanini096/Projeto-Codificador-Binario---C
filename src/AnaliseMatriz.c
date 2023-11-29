#include "../include/AnaliseMatriz.h"
#include "../include/PrintMatriz.h"

void printBinario(int linhasOriginal, int colunasOriginal, int **matriz){
  
  //Calculo do número de elementos da matriz caso ela seja coluna ou linha
  if(linhasOriginal == 0) linhasOriginal++;
  if(colunasOriginal == 0) colunasOriginal++;

  int totalDeElementos = linhasOriginal * colunasOriginal;
  int n_pretos = 0;
  int i, j;

  for (i = 0; i < linhasOriginal; i++) {
    for (j = 0; j < colunasOriginal; j++) {
      if (matriz[i][j] == 1) n_pretos++;
    }
  }

  if(n_pretos == totalDeElementos) printf("P");
  else printf("B");

}

void cortarMatriz(int linhasOriginal, int colunasOriginal,
                  int **matrizOriginal,
                  int linhasCortada, int colunasCortada, int **matrizCortada,
                  int inicioLinha, int inicioColuna) {

    //if (inicioLinha > linhasCortada || inicioColuna > colunasCortada) return;

    for (int i = 0; i < linhasCortada; i++) {
    for (int j = 0; j < colunasCortada; j++) {
      matrizCortada[i][j] = matrizOriginal[inicioLinha + i][inicioColuna + j];
    }
  }
  //printf("\n");
  //mostrarMatriz(linhasCortada, colunasCortada, matrizCortada);
  analiseMatriz(linhasCortada, colunasCortada, matrizCortada);
  } 


void analiseMatriz(int linhasOriginal, int colunasOriginal, int **matriz) 
{

  //Passo - Verficar se é uma matriz linha ou coluna
  /*
  int a,b;
  int validador1, validador2 = 0;

  int **matrizCortada1 = (int **)malloc(linhasOriginal * sizeof(int *));

    for (int i = 0; i < linhasOriginal; i++) {
      matrizCortada1[i] = (int *)malloc(colunasOriginal * sizeof(int));
    }

  //Caso - matriz é 1x1
  if ((linhasOriginal == 0) && (colunasOriginal == 0)) {
    printBinario(linhasOriginal, colunasOriginal, matriz);
  }

  //Caso - Matriz Linha

  if(linhasOriginal == 0) {
    //Se for verdadeiro - terá que analisar se há algum elemento distinto
    for(a = 0; a < colunasOriginal - 1; a++){
      
      if(matriz[0][a] != matriz[0][a + 1]){

          int l_inicio = 0;
          int c_inicio = 0;
          int c_corte = a + 1;

          cortarMatriz(linhasOriginal, colunasOriginal, matriz, 
          l_inicio, c_corte, matrizCortada1, l_inicio, c_inicio);

      } else {

        printBinario(linhasOriginal, colunasOriginal, matriz);

      }
    }
  }

    //Caso Matriz Coluna
    if(colunasOriginal == 0) {
      
      for (b = 0; b < linhasOriginal -1; b++){
        if(matriz[b][0] != matriz[b + 1][0]) {

          int l_inicio = 0;
          int c_inicio = 0;
          int l_corte = b + 1;

          cortarMatriz(linhasOriginal, colunasOriginal, matriz, 
          l_corte, c_inicio, matrizCortada1, l_inicio, c_inicio);

        } else {

          printBinario(linhasOriginal, colunasOriginal, matriz);

        }
      }
    }

*/

  // Passo - Declarar Variáveis:
  int i, j;
  int validacao_corte_matriz = 0;


  //Passo - Verificar se há um elemento distinto na matriz
  for (i = 0; i < linhasOriginal; i++) {
    for (j = 0; j < colunasOriginal - 1; j++) {
      if (matriz[i][j] != matriz[i][j + 1]) { 
      //Se tiver haverá o corte e o fim da análise
        validacao_corte_matriz = 1;
        break;
      }
    }
  }

//Se não tiver o corte, deverá descobrir se ele é P ou B
    
  if (validacao_corte_matriz) {

    printf("X");

    int **matrizCortada1 = (int **)malloc(linhasOriginal * sizeof(int *));

    for (int i = 0; i < linhasOriginal; i++) {
      matrizCortada1[i] = (int *)malloc(colunasOriginal * sizeof(int));
    }

    int inicioLinha, inicioColuna, linhaCortada, colunaCortada;
    int valor_adicional_linha = (linhasOriginal % 2 != 0) ? 1 : 0;
    int valor_adicional_coluna = (colunasOriginal % 2 != 0) ? 1 : 0;


    // Primeiro Quadrante
    inicioLinha = 0;
    inicioColuna = 0;

    cortarMatriz(linhasOriginal, colunasOriginal, matriz,
                 ((linhasOriginal / 2) + valor_adicional_linha) - inicioLinha,
                 ((colunasOriginal / 2) + valor_adicional_coluna) -
                     inicioColuna,
                 matrizCortada1, inicioLinha, inicioColuna);

    // Segundo Quadrante
    inicioLinha = 0;
    inicioColuna = (colunasOriginal / 2) + valor_adicional_coluna;

    cortarMatriz(linhasOriginal, colunasOriginal, matriz,
                 ((linhasOriginal / 2) + valor_adicional_linha) - inicioLinha,
                 colunasOriginal - inicioColuna, matrizCortada1, inicioLinha,
                 inicioColuna);

    // Terceiro Quadrante
   inicioLinha = (linhasOriginal / 2) + valor_adicional_linha;
   inicioColuna = 0;

   //Matriz linha ou coluna não pode passar deste ponto 

    cortarMatriz(linhasOriginal, colunasOriginal, matriz,
                 linhasOriginal - inicioLinha,
                 ((colunasOriginal / 2) + valor_adicional_coluna) -
                     inicioColuna,
                 matrizCortada1, inicioLinha, inicioColuna);

    // Quarto Quadrante

    inicioLinha = (linhasOriginal / 2) + valor_adicional_linha;
    inicioColuna = (colunasOriginal / 2) + valor_adicional_coluna;

    cortarMatriz(linhasOriginal, colunasOriginal, matriz,
                 linhasOriginal - inicioLinha, colunasOriginal - inicioColuna,
                 matrizCortada1, inicioLinha, inicioColuna);

    for (int i = 0; i < linhasOriginal; i++) {
      free(matrizCortada1[i]);
    }

    free(matrizCortada1);
  }

  else printBinario(linhasOriginal, colunasOriginal, matriz);
}

