#include "libs/data_structures/matrix/matrix.c"
#include <limits.h>
#include "libs/util/util.c"
#include <math.h>

// Task1
void swapMaxElementRowAndMinElementRow(matrix matrix) {
    int min = INT_MAX, min_row = -1, max = 0, max_row = -1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            int value = matrix.values[i][j];

            if (value < min) {
                min = value;
                min_row = i;
            } else if (value > max) {
                max = value;
                max_row = i;
            }
        }
    }

    swapRows(matrix, min_row, max_row);
}

// Task2
void sortRowsByMaxElement(matrix matrix) {
    insertionSortRowsMatrixByRowCriteria(matrix, getMax);
}

// Task3
void sortColsByMinElement(matrix matrix) {
    selectionSortColsMatrixByColCriteria(matrix, getMin);
}

// Task4
void getSquareOfMatrixIfSymmetric(matrix* matrix) {
    if (isSymmetricMatrix(matrix)) {
        *matrix = multiplyMatrices(*matrix, *matrix);
    }
}

// Task5
void transposeIfMatrixHasNotEqualSumOfRows(matrix* matrix) {
    long long sums[matrix->rows];

    for (int i = 0; i < matrix->rows; ++i) {
        sums[i] = getSum(matrix->values[i], matrix->cols);
    }

    if (isSet(sums, matrix->rows)) {
        transposeMatrix(matrix);
    }
}

// Task6
bool isMutuallyInverseMatrices(matrix left, matrix right) {
    matrix multiplication = multiplyMatrices(left, right);

    return isEMatrix(&multiplication);
}


void test_ex1() {
    printf("test_ex1\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        }, 3, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    swapMaxElementRowAndMinElementRow(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex2() {
    printf("test_ex2\n");
    matrix m = createMatrixFromArray((int[]) {
        7, 1, 2,
        1, 8, 1,
        3, 2, 3,
        }, 3, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    sortRowsByMaxElement(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex3() {
    printf("test_ex3\n");
    matrix m = createMatrixFromArray((int[]) {
        3, 5, 2, 4, 3, 3,
        2, 5, 1, 8, 2, 7,
        6, 1, 4, 4, 8, 3,
        }, 3, 6
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    sortColsByMinElement(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex4() {
    printf("test_ex4\n");
    matrix m = createMatrixFromArray((int[]) {
        2, 0, 0, 2,
        0, 2, 2, 0,
        0, 2, 2, 0,
        2, 0, 0, 2,
        }, 4, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    getSquareOfMatrixIfSymmetric(&m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex5() {
    printf("test_ex5\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16,
        }, 4, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}

void test_ex6() {
    printf("test_ex6\n");
    matrix m1 = createMatrixFromArray((int[]) {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        }, 3, 3
    );

    matrix m2 = createMatrixFromArray((int[]) {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        }, 3, 3
    );
    
    printf("test matrix 1:\n");
    outputMatrix(m1);
    printf("test matrix 2:\n");
    outputMatrix(m2);

    printf("Answer: %d", isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    printf("\n\n");
}


void test_ex6_1() {
    printf("test_ex6_1\n");
    matrix m1 = createMatrixFromArray((int[]) {
        1, 8, 7,
        4, 2, 3,
        7, 6, 5,
        }, 3, 3
    );

    matrix m2 = createMatrixFromArray((int[]) {
        4, 2, 9,
        4, 4, 3,
        0, 8, 1,
        }, 3, 3
    );
    
    printf("test matrix 1:\n");
    outputMatrix(m1);
    printf("test matrix 2:\n");
    outputMatrix(m2);

    printf("Answer: %d", isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    printf("\n\n");
}


void tests() {
    test_ex1();
    test_ex2();
    test_ex3();
    test_ex4();
    test_ex5();
    test_ex6();
    test_ex6_1();
}


int main() {
    tests();
}