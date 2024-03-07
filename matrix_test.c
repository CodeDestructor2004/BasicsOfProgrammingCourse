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

void test() {
    test_countZeroRows();
}

int main() {
    test();
}
