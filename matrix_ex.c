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

// Task7
long long findSumOfMaxesOfPseudoDiagonal(matrix matrix) {
    int arraySize = matrix.rows + matrix.cols - 1;
    int maxes[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        maxes[i] = INT_MIN;
    }

    int increment = matrix.cols - 1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            int index = i - j + increment;

            maxes[index] = maxValue(maxes[index], matrix.values[i][j]);
        }
    }

    long long sum = 0;

    for (int i = 0; i < arraySize; ++i) {
        if (i != increment) {
            sum += maxes[i];
        }
    }

    return sum;
}

//Task8
int getMinInArea(matrix matrix) {
    position maximum_position = getMaxValuePos(matrix);
    int min = INT_MAX;

    for (int i = 0; i <= maximum_position.rowIndex; ++i) {
        int column_offset = (maximum_position.rowIndex - i) << 1;
        int start_column = maxValue(0, maximum_position.colIndex - column_offset);
        int end_column = minValue(matrix.cols - 1, maximum_position.colIndex + column_offset);

        for (int j = start_column; j <= end_column; ++j) {
            min = minValue(min, matrix.values[i][j]);
        }
    }

    return min;
}

// Task 9
float getDistance(const int* values, int value_amount) {
    float squared_distance = 0;

    for (int i = 0; i < value_amount; ++i) {
        int value = values[i];

        squared_distance += ((float) (value * value));
    }

    return sqrtf(squared_distance);
}


void insertionSortRowsMatrixByRowCriteriaF(matrix m, 
float (*criteria)(const int*, int)) {
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


void sortByDistances(matrix matrix) {
    insertionSortRowsMatrixByRowCriteriaF(matrix, getDistance);
}

// Task10
int countEqClassesByRowsSum(matrix matrix) {
    long long row_sums[matrix.rows];

    for (int i = 0; i < matrix.rows; ++i) {
        row_sums[i] = getSum(matrix.values[i], matrix.cols);
    }

    return countUniques(row_sums, matrix.rows);
}

// Task11
int countSpecialElements(matrix matrix) {
    int amount = 0;

    for (int i = 0; i < matrix.cols; ++i) {
        int* row = matrix.values[i];

        for (int j = 0; j < matrix.rows; ++j) {
            int sum_other = 0;

            for (int k = 0; k < matrix.rows; k++) {
                if (k != j) {
                    sum_other += row[k];
                }
            }

            if (row[j] > sum_other) {
                amount++;
                break;
            }
        }
    }

    return amount;
}

// Task12
void swapPenultimateRow(matrix matrix) {
    if (matrix.rows == 1) {
        return;
    }

    int min_column = getMinValuePos(matrix).colIndex;
    int column[matrix.rows];

    for (int i = 0; i < matrix.rows; ++i) {
        column[i] = matrix.values[i][min_column];
    }

    int destination_row = matrix.rows - 2;

    for (int i = 0; i < matrix.cols; ++i) {
        matrix.values[destination_row][i] = column[i];
    }
}


// Task 13
static bool hasAllNonDescendingRows(matrix matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        if (!isNonDescending(matrix.values[i], matrix.cols)) {
            return false;
        }
    }

    return true;
}


int countNonDescendingRowsMatrices(const matrix* matrices, int matrix_amount) {
    int amount = 0;

    for (int i = 0; i < matrix_amount; ++i) {
        if (hasAllNonDescendingRows(matrices[i])) {
            amount++;
        }
    }

    return amount;
}

// Task14
void printMatrixWithMaxZeroRows(const matrix* matrices, int matrix_amount) {
    int max_amount;
    int zero_row_amounts[matrix_amount];

    for (int i = 0; i < matrix_amount; ++i) {
        int amount = countZeroRows(matrices[i]);

        zero_row_amounts[i] = amount;
        max_amount = maxValue(max_amount, amount);
    }

    for (int i = 0; i < matrix_amount; ++i) {
        if (zero_row_amounts[i] == max_amount) {
            outputMatrix(matrices[i]);
            printf("----------\n");
        }
    }
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


void test_ex7() {
    printf("test_ex7\n");
    matrix m = createMatrixFromArray((int[]) {
        3, 2, 5, 4,
        1, 3, 6, 3,
        3, 2, 1, 2,
        }, 3, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = findSumOfMaxesOfPseudoDiagonal(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex8() {
    printf("test_ex8\n");
    matrix m = createMatrixFromArray((int[]) {
        10, 7, 5, 6,
        3, 11, 8, 9,
        4, 1, 12, 2,
        }, 3, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = getMinInArea(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex9() {
    printf("test_ex9\n");
    matrix m = createMatrixFromArray((int[]) {
        3, 5, 2, 4,
        2, 5, 1, 8,
        6, 1, 4, 4,
        }, 3, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    sortByDistances(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex10() {
    printf("test_ex10\n");
    matrix m = createMatrixFromArray((int[]) {
        7, 1, 
        2, 7, 
        5, 4, 
        4, 3, 
        1, 6, 
        8, 0, 
        }, 6, 2
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = countEqClassesByRowsSum(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex11() {
    printf("test_ex11\n");
    matrix m = createMatrixFromArray((int[]) {
        3, 5, 5, 4,
        2, 3, 6, 7,
        12, 2, 1, 2,
        }, 3, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    long long answer = countSpecialElements(m);

    printf("Answer: %d\n", answer);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex12() {
    printf("test_ex12\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 2, 3,
        4, 5, 6,
        7, 8, 1,
        }, 3, 3
    );

    printf("test matrix:\n");
    outputMatrix(m);

    swapPenultimateRow(m);

    printf("Answer:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_ex13() {
    printf("test_ex12\n");
    matrix *ms = createArrayOfMatrixFromArray((int[]) {
            7, 1, 1, 1, 
            1, 6, 2, 2, 
            5, 4, 2, 3, 
            1, 3, 7, 9
        }, 4, 2, 2
    );

    printf("test matrices:\n");
    outputMatrices(ms, 4);

    long long answer = countNonDescendingRowsMatrices(ms, 4);
    printf("Answer: %d\n", answer);

    freeMemMatrices(ms, 4);
    printf("\n\n");
}


void test_ex14() {
    printf("test_ex12\n");
    matrix *ms = createArrayOfMatrixFromArray((int[]) {
            0, 1, 1, 0, 0, 0,
            1, 1, 2, 1, 1, 1,
            0, 0, 0, 0, 4, 7,
            0, 0, 0, 1, 0, 0,
            0, 1, 0, 2, 0, 3,
        }, 5, 3, 2
    );

    printf("test matrices:\n");
    outputMatrices(ms, 5);

    printf("Answer: \n");
    printMatrixWithMaxZeroRows(ms, 5);

    freeMemMatrices(ms, 5);
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
    test_ex7();
    test_ex8();
    test_ex9();
    test_ex10();
    test_ex11();
    test_ex12();
    test_ex13();
    test_ex14();
}


int main() {
    tests();
}