#include "libs/data_structures/matrix/matrix.c"
#include <limits.h>
#include "libs/util/util.c"
#include <math.h>

// Task1
void swapMaxElementRowAndMinElementRow(matrix matrix) {
    int min = INT_MAX, minRow = -1, max = 0, maxRow = -1;

    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            int value = matrix.values[i][j];

            if (value < min) {
                min = value;
                minRow = i;
            } else if (value > max) {
                max = value;
                maxRow = i;
            }
        }
    }

    swapRows(matrix, minRow, maxRow);
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


void tests() {
    test_ex1();
}


int main() {
    tests();
}