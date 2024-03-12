#include "libs/data_structures/matrix/matrix.c"
#include <assert.h>


void test_countZeroRows() {
    printf("test_countZeroRows\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 1, 0,
        0, 0, 0,
        0, 0, 1,
        0, 0, 0,
        0, 1, 1,
        }, 5, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(&m);

    printf("OK\n\n");
}


void test_swapRows() {
    printf("test_swapRows\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        }, 3, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    swapRows(m, 1, 2);

    printf("Swap 2 and 3 rows:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_swapColumns() {
    printf("test_swapColumns\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        }, 3, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    swapColumns(m, 1, 2);

    printf("Swap 2 and 3 columns:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


int getSum(int *a, int n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        result += a[i];
    return result;
}


void test_insertionSortRowsMatrixByRowCriteria() {
    printf("test_insertionSortRowsMatrixByRowCriteria\n");
    matrix m = createMatrixFromArray((int[]) {
        7, 8, 9,
        1, 2, 3,
        4, 5, 6,
        }, 3, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    insertionSortRowsMatrixByRowCriteria(m, getSum);

    printf("Sorted by row sum:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_selectionSortColsMatrixByColCriteria() {
    printf("test_selectionSortColsMatrixByColCriteria\n");
    matrix m = createMatrixFromArray((int[]) {
        3, 6, 4,
        3, 6, 4,
        3, 6, 4,
        }, 3, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    selectionSortColsMatrixByColCriteria(m, getSum);

    printf("Sorted by col sum:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_isSquareMatrix() {
    printf("test_isSquareMatrix\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 1, 0,
        0, 0, 0,
        0, 0, 1,
        0, 0, 0,
        0, 1, 1,
        }, 5, 3
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    printf("is matrix square: %d", isSquareMatrix(&m));

    freeMemMatrix(&m);

    printf("\n\n");
}


void test_areTwoMatricesEqua() {
    printf("test_areTwoMatricesEqua\n");
    matrix m1 = createMatrixFromArray((int[]) {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        }, 3, 3
    );

    matrix m2 = createMatrixFromArray((int[]) {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        }, 3, 3
    );
    
    printf("test matrix 1:\n");
    outputMatrix(m1);
    printf("test matrix 2:\n");
    outputMatrix(m2);

    printf("are matrices equal: %d", areTwoMatricesEqual(&m1, &m2));

    freeMemMatrix(&m1);

    printf("\n\n");
}


void test_isEMatrix() {
    printf("test_isEMatrix\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1,
        }, 4, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    printf("is matrix E: %d", isEMatrix(&m));

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_isSymmetricMatrix() {
    printf("test_isSymmetricMatrix\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 0, 0, 1,
        0, 1, 1, 0,
        0, 1, 1, 0,
        1, 0, 0, 1,
        }, 4, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    printf("is matrix symmetric: %d", isSymmetricMatrix(&m));

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_transposeMatrix() {
    printf("test_transposeMatrix\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16,
        17, 18, 19, 20,
        }, 5, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    transposeMatrix(&m);

    printf("Transposed_matrix:\n");
    outputMatrix(m);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_getMinValuePos() {
    printf("test_getMinValuePos\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 4, 1,
        1, 1, 1, 1,
        1, 1, 1, 0,
        }, 5, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    position pos = getMinValuePos(m);

    printf("Min value in matrix: %d, %d", pos.colIndex, pos.rowIndex);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test_getMaxValuePos() {
    printf("test_getMaxValuePos\n");
    matrix m = createMatrixFromArray((int[]) {
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 4, 1,
        1, 1, 1, 1,
        1, 1, 1, 0,
        }, 5, 4
    );
    
    printf("test matrix:\n");
    outputMatrix(m);

    position pos = getMaxValuePos(m);

    printf("Max value in matrix: %d, %d", pos.colIndex, pos.rowIndex);

    freeMemMatrix(&m);
    printf("\n\n");
}


void test() {
    test_countZeroRows();
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix();
    test_areTwoMatricesEqua();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test();
}
