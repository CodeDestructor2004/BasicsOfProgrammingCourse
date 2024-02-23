#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.c"


void test_pushBack_emptyVector() {
    printf("test_pushBack_emptyVector\n");
    vector vec = createVector(4);
    printf("is vec empty: %d\n", isEmpty(&vec));

    int x = 10;
    pushBack(&vec, x);
    printf("insert %d\n", x);

    printf("is vec empty: %d\n\n", isEmpty(&vec));
}


void test_pushBack_fullVector() {
    printf("test_pushBack_fullVector\n");
    vector vec = createVector(4);
    int input_data[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        pushBack(&vec, input_data[i]);
    }
    printf("is vec full: %d\n", isFull(&vec));

    int x = 10;
    pushBack(&vec, x);
    printf("insert %d\n", x);

    printf("is vec full: %d\n\n", isFull(&vec));
}


void test_popBack_notEmptyVector() {
    vector vec = createVector(1);
    pushBack(&vec, 10);

    assert(vec.size == 1);
    popBack(&vec);
    assert(vec.size == 0);
    assert(vec.capacity == 1);
}



void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}


int main() {
    test();
    return 0;
}
