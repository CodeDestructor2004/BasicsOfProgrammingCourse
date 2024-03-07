#include "matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

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


void insertionSortRowsMatrixByRowCriteria(matrix m,
int (*criteria)(int*, int)) {
    for (int i = 0; i < m.rows; i++) {
        int* row = m.values[i];
        int weight = criteria(row, m.cols);
        int j = i + 1;
        int current_weight;

        while (j >= 0 && (current_weight = criteria(m.values[j], m.cols)) > weight) {
            m.values[j + 1] = m.values[j];
            weight = current_weight;
            j--;
        }

        m.values[j + 1] = row;
    }
}


int* getColumn(matrix m, int index) {
    int* column = malloc(sizeof(int) * m.rows);

    for (int i = 0; i < m.rows; i++) {
        column[i] = m.values[i][index];
    }

    return column;
}


int indexOfMaxColumnByCriteria(matrix matrix, int start, 
int end, int (*criteria)(const int*, int)) {
    int max_index = 0;
    int max_weight = criteria(getColumn(matrix, start), matrix.rows);

    for (int i = start + 1; i < end; i++) {
        int weight = criteria(getColumn(matrix, i), matrix.rows);

        if (weight > max_weight) {
            max_index = i;
            max_weight = weight;
        }
    }

    return max_index;
}


void selectionSortColsMatrixByColCriteria(matrix m,
int (*criteria)(int*, int)) {
    for (int i = 0; i < m.cols; i++) {
        swapColumns(m, i, indexOfMaxColumnByCriteria(m, i + 1, m.cols, criteria));
    }
}


bool isSquareMatrix(matrix* m) {
    return m->rows == m->cols;
}


bool areTwoMatricesEqual(matrix* m1, matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->rows) {
        return false;
    }

    for (int i = 0; i < m1->rows; i++) {
        if (!memcpy(m1->values[i], m2->values[i], m1->cols)) {
            return false;
        }
    }

    return true;
}


bool isEMatrix(matrix* m) {
    if (!isSquareMatrix(m)) {
        return false;
    }

    for (int i = 0; i < m->rows; i++) {
        int* row = m->values[i];

        for (int j = 0; j < m->cols; j++) {
            if (row[j] != ((i == j) ? 1 : 0)) {
                return false;
            }
        }
    }

    return true;
}


bool isSymmetricMatrix(matrix* m) {
    if (!isSquareMatrix(m)) {
        return false;
    }

    for (int i = 0; i < m->rows; i++) {
        int* row = m->values[i];

        for (int j = 0; j < m->cols; j++) {
            if (i == j) {
                continue;
            }

            if (row[j] != m->values[j][i]) {
                return false;
            }
        }
    }

    return true;
}


int** allocateValues(int rows, int cols) {
    int** values = (int**) malloc(sizeof(int*) * rows);

    for (int i = 0; i < rows; i++) {
        values[i] = (int*) malloc(sizeof(int) * cols);
    }

    return values;
}



void transposeSquareMatrix(matrix* m) {
    int** new_values = allocateValues(m->rows, m->cols);

    for (int i = 0; i < m->rows; i++) {
        int* row = m->values[i];

        for (int j = 0; j < m->cols; j++) {
            new_values[j][i] = row[j];
        }
    }

    m->values = new_values;
}


void transposeMatrix(matrix* m) {
    int** new_values = allocateValues(m->cols, m->rows);

    for (int i = 0; i < m->rows; i++) {
        int* row = m->values[i];

        for (int j = 0; j < m->cols; j++) {
            new_values[j][i] = row[j];
        }
    }

    m->values = new_values;
}


position getMinValuePos(matrix m) {
    int value = m.values[0][0];
    int row_index = 0;
    int col_index = 0;

    for (int i = 0; i < m.rows; i++) {
        int* row = m.values[i];

        for (int j = 0; j < m.cols; j++) {
            if (row[j] < value) {
                row_index = i;
                col_index = j;
            }
        }
    }

    return (position) {row_index, col_index};
}


position getMaxValuePos(matrix m)  {
    int value = m.values[0][0];
    int row_index = 0;
    int col_index = 0;

    for (int i = 0; i < m.rows; i++) {
        int* row = m.values[i];

        for (int j = 0; j < m.cols; j++) {
            if (row[j] > value) {
                row_index = i;
                col_index = j;
            }
        }
    }

    return (position) {row_index, col_index};
}


matrix createMatrixFromArray(const int *a,
size_t rows, size_t cols) {
    matrix m = getMemMatrix(rows, cols);

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m.values[i][j] = a[k++];
    
    return m;
}


matrix *createArrayOfMatrixFromArray(const int *values,
size_t matrices_amount, size_t rows, size_t cols) {
    matrix *ms = getMemArrayOfMatrices(matrices_amount, rows, cols);
    
    int l = 0;
    for (size_t k = 0; k < matrices_amount; k++)
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                ms[k].values[i][j] = values[l++];
    
    return ms;
}
