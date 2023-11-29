#include "../include/file.h"

PBMData *readPBM(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    char magic[3];
    fscanf(file, "%2s", magic);
    if (magic[0] != 'P' || magic[1] != '1') {
        fprintf(stderr, "Formato de arquivo PBM inválido\n");
        fclose(file);
        return NULL;
    }

    PBMData *data = (PBMData *)malloc(sizeof(PBMData));
    if (data == NULL) {
        perror("Erro ao alocar memória para os dados");
        fclose(file);
        return NULL;
    }

    int break_char;
    while ((break_char = fgetc(file)) == '#' || isspace(break_char))
    {
        if (break_char == '#')
        {
            fscanf(file, "%*[^\n]"); // Pular a linha de comentário
        }
    }
    ungetc(break_char, file); // Devolver o caractere que encerrou o loop

    // Lê largura e altura
    fscanf(file, "%d %d", &data->cols, &data->rows);

    // Aloca espaço para a matriz
    data->matrix = (int **)malloc(data->rows * sizeof(int *));
    if (data->matrix == NULL) {
        perror("Erro ao alocar memória para a matriz");
        free(data);
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < data->rows; i++) {
        data->matrix[i] = (int *)malloc(data->cols * sizeof(int));
        if (data->matrix[i] == NULL) {
            perror("Erro ao alocar memória para a matriz");
            free(data);
            fclose(file);
            return NULL;
        }
    }

// Lê os pixels
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            fscanf(file, "%d", &data->matrix[i][j]);
        }
    }

    fclose(file);
    return data;
}

void freePBMData(PBMData *data) {
    if (data != NULL) {
        for (int i = 0; i < data->rows; i++) {
            free(data->matrix[i]);
        }
        free(data->matrix);
        free(data);
    }
}