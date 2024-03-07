#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <stdio.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int rows; // количество рядов
    int cols; // количество столбцов
} matrix;


typedef struct position {
    int rowIndex;
    int colIndex;
} position;


matrix getMemMatrix(int rows, int cols);


matrix *getMemArrayOfMatrices(int matrices_amount, int rows, int cols);


void freeMemMatrix(matrix *m);


void freeMemMatrices(matrix *ms, int matrices_amount);


#endif