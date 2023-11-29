#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} PBMData;

PBMData *readPBM(const char *filename);

void freePBMData(PBMData *data);

#endif