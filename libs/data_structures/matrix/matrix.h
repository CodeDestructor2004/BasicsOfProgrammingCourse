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


void inputMatrix(matrix *m);


void inputMatrices(matrix *ms, int matrices_amount);


void outputMatrix(matrix m);


void outputMatrices(matrix *ms, int matrices_amount);


void swapRows(matrix m, int i1, int i2);


void swapColumns(matrix m, int j1, int j2);


void insertionSortRowsMatrixByRowCriteria(matrix m,
int (*criteria)(int*, int));


void selectionSortColsMatrixByColCriteria(matrix m,
int (*criteria)(int*, int));


#endif