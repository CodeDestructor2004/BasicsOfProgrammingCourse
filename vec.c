#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/algorithms/array/array.c"
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
    printf("test_popBack_notEmptyVector\n");

    vector vec = createVector(0);
    pushBack(&vec, 10);

    assert(vec.size == 1);
    popBack(&vec);
    assert(vec.size == 0);
    assert(vec.capacity == 1);
    printf("OK\n\n");
}


void test_atVector_notEmptyVector() {
    printf("test_atVector_notEmptyVector\n");

    vector vec = createVector(4);
    int input_data[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        pushBack(&vec, input_data[i]);
    }
    printf("Data in vec: ");
    outputArray_(input_data, 4);

    int index = 2;

    printf("Element in position %d: %d (address %d)\n\n", index, *atVector(&vec, index), atVector(&vec, index));
}


void test_atVector_requestToLastElement() {
    printf("test_atVector_requestToLastElement\n");

    vector vec = createVector(4);
    int input_data[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        pushBack(&vec, input_data[i]);
    }
    printf("Data in vec: ");
    outputArray_(input_data, 4);

    int index = 3;

    printf("Element in position %d: %d (address %d)\n\n", index, *atVector(&vec, index), atVector(&vec, index));
}


void test_back_oneElementInVector() {
    printf("test_back_oneElementInVector\n");

    vector vec = createVector(0);
    pushBack(&vec, 5);

    printf("Element in last position: %d (address %d)\n\n", *back(&vec), back(&vec));
}


void test_front_oneElementInVector() {
    printf("test_front_oneElementInVector\n");

    vector vec = createVector(0);
    pushBack(&vec, 5);

    printf("Element in first position: %d (address %d)\n\n", *front(&vec), front(&vec));
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}


int main() {
    test();
    return 0;
}
