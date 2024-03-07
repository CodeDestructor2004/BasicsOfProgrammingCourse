#include "matrix.h"
#include <stdio.h>
#include <malloc.h>

matrix getMemMatrix(int rows, int cols) {
    int **values = (int **) malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++)
    values[i] = (int *) malloc(sizeof(int) * cols);
    return (matrix){values, rows, cols};
}


matrix *getMemArrayOfMatrices(int matrices_amount, int rows, int cols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * matrices_amount);
    for (int i = 0; i < matrices_amount; i++)
    ms[i] = getMemMatrix(rows, cols);
    return ms;
}


void freeMemMatrix(matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->values[i]);
    }

    free(m->values);

    m->rows = 0;
    m->cols = 0;
}


void freeMemMatrices(matrix* ms, int matrices_amount) {
    for (int i = 0; i < matrices_amount; i++) {
        freeMemMatrix(ms + i);
    }
}


void inputMatrix(matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        printf("Input matrix row #%d:\n", i);

        int* row = m->values[i];

        for (int j = 0; j < m->cols; j++) {
            scanf("%d", row + j);
        }
    }
}


void inputMatrices(matrix* ms, int matrices_amount) {
    for (int i = 0; i < matrices_amount; i++) {
        inputMatrix(ms + i);
    }
}


void outputMatrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        int* row = m.values[i];

        printf("[");

        for (int j = 0; j < m.cols; j++) {
            printf("%d", row[j]);

            if (j != (m.cols - 1)) {
                printf(", ");
            }
        }

        printf("]\n");
    }
}


void outputMatrices(matrix* ms, int matrices_amount) {
    for (int i = 0; i < matrices_amount; i++) {
        outputMatrix(ms[i]);
    }
}


void swapRows(matrix m, int i1, int i2) {
    if (i1 == i2) {
        return;
    }

    assert(0 < i1 < m.rows);
    assert(0 < i2 < m.rows);

    int* row1 = m.values[i1];
    int* row2 = m.values[i2];

    m.values[i1] = row2;
    m.values[i2] = row1;
}


void swapColumns(matrix m, int j1, int j2) {
    if (j1 == j2) {
        return;
    }

    assert(0 < j1 < m.cols);
    assert(0 < j2 < m.cols);

    for (int i = 0; i < m.rows; ++i) {
        int* row = m.values[i];
        int value1 = row[j1];
        int value2 = row[j2];

        row[j1] = value2;
        row[j2] = value1;
    }
}
