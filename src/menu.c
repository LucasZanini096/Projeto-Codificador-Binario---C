#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/ConstrucaoMatriz.h"
#include "../include/AnaliseMatriz.h"
#include "../include/PrintMatriz.h"
#include "../include/file.h"

void help();

void manual() {

  //Construção de uma matriz
  int linhas, colunas;

  printf("Digite o número de linhas de uma matriz: ");
  scanf("%d", &linhas);

  printf("\nDigite o número de colunas de uma matriz: ");
  scanf("%d", &colunas);

  int **matriz = (int **)malloc(linhas * sizeof(int *));

  for (int i = 0; i < linhas; i++) {
    matriz[i] = (int *)malloc(colunas * sizeof(int));
  }

  construirMatriz(linhas, colunas, matriz);

  analiseMatriz(linhas, colunas, matriz);

  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }

  free(matriz);

}

void file(int argc, char *argv[]) {

  const char *filename = argv[2];
  //Tentativa de colocar o caminho completo do arquivo
  const char *inicioCaminho = "C:/Mackenzie/Segundo Semestre/Algoritmos 2/Projeto Codificador/Images/";
  
  char *caminhoCompleto = malloc(strlen(inicioCaminho) + strlen(filename) + 1);
    if (caminhoCompleto == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    // Copiar a string inicial para o caminho completo
    strcpy(caminhoCompleto, inicioCaminho);

    // Concatenar o nome do arquivo ao caminho completo
    strcat(caminhoCompleto, filename);

    PBMData *data = readPBM(caminhoCompleto);

    if (data != NULL) {
        // Acessar os dados como variáveis separadas
        int rows = data->rows;
        int cols = data->cols;
        int **matrix = data->matrix;

        // Exemplo: Imprimir as variáveis
        printf("Linhas: %d\n", rows);
        printf("Colunas: %d\n", cols);
        
        printf("Matriz:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        analiseMatriz(rows, cols, matrix);

        freePBMData(data);
    }

    free(caminhoCompleto);
}


int main(int argc, char *argv[]){

  printf("argc = %d\n", argc); 

  
    if (argc == 2)
    {
        if ((strcmp(argv[1], "-?") == 0) || (strcmp(argv[1], "--help") == 0))
        
        {
            help();
            return 0;
        }

        if ((strcmp(argv[1], "-m") == 0) || (strcmp(argv[1], "--manual") == 0))
        
        {
          manual();
          return 0;
        }
    }

    if (argc == 3)

    {
        if((strcmp(argv[1], "-f") == 0) || (strcmp(argv[1], "--file") == 0))
        file(argc, argv);
        return 0;
    }

  //Caso o usuário digite algo incorreto ele volta para o menu
  help();
  return 0;
}

void help() 
{  
      puts("Uso: ImageEncoder [-? | -m | -f ARQ]");
      puts("Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.");
      puts("Argumentos:");
      puts("-?, --help  : apresenta essa orientação na tela.");
      puts("-m, --manual: ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem informando-os através do teclado.");
      puts("-f, --file: considera a imagem representada no arquivo PBM (Portable bitmap).");
}

