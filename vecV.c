#include "libs/data_structures/vector/vectorVoid.c"
#include "libs/algorithms/array/array.c"
#include <assert.h>


void test_pushBackV_emptyVector() {
    printf("test_pushBackV_emptyVector\n");

    vectorVoid vec = createVectorV(4, sizeof(int));
    printf("is vec empty: %d\n", isEmptyV(&vec));

    int x = 10;
    pushBackV(&vec, &x);
    printf("insert %d\n", x);

    printf("is vec empty: %d\n\n", isEmptyV(&vec));
}


void test_pushBackV_fullVector() {
    printf("test_pushBack_fullVector\n");

    vectorVoid vec = createVectorV(4, sizeof(float));
    int input_data[] = {1.0f, 1.5f, 2.0f, 2.5f};
    for (int i = 0; i < 4; i++) {
        pushBackV(&vec, &input_data[i]);
    }
    printf("is vec full: %d\n", isFullV(&vec));

    float x = 3.0f;
    pushBackV(&vec, &x);
    printf("insert %f\n", x);

    printf("is vec full: %d\n\n", isFullV(&vec));
}


void test_popBackV_notEmptyVector() {
    printf("test_popBackV_notEmptyVector\n");

    vectorVoid vec = createVectorV(0, sizeof(int));
    int x = 10;
    pushBackV(&vec, &x);

    assert(vec.size == 1);
    popBackV(&vec);
    assert(vec.size == 0);
    assert(vec.capacity == 1);
    printf("OK\n\n");
}


void test_getVectorValueV_notEmptyVector() {
    printf("test_getVectorValueV_notEmptyVector\n");

    vectorVoid vec = createVectorV(4, sizeof(int));
    int input_data[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        pushBackV(&vec, &input_data[i]);
    }
    printf("Data in vec: ");
    outputArray_(input_data, 4);

    int index = 2;
    int x = 0;
    getVectorValueV(&vec, index, &x);

    printf("Element in position %d: %d\n\n", index, x);
}


void test_getVectorValueV_requestToLastElement() {
    printf("test_getVectorValueV_requestToLastElement\n");

    vectorVoid vec = createVectorV(4, sizeof(int));
    int input_data[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        pushBackV(&vec, &input_data[i]);
    }
    printf("Data in vec: ");
    outputArray_(input_data, 4);

    int index = 3;
    int x = 0;
    getVectorValueV(&vec, index, &x);

    printf("Element in position %d: %d\n\n", index, x);
}


void test_setVectorValueV_notEmptyVector() {
    printf("test_setVectorValueV_notEmptyVector\n");

    vectorVoid vec = createVectorV(4, sizeof(int));
    int input_data[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        pushBackV(&vec, &input_data[i]);
    }

    int index = 2;
    int answer = 0;
    getVectorValueV(&vec, index, &answer);
    printf("Element in position %d: %d\n", index, answer);
    
    int x = 15;
    setVectorValueV(&vec, index, &x);

    printf("insert %d\n", x);

    getVectorValueV(&vec, index, &answer);

    printf("Element in position %d: %d\n\n", index, answer);
}


void test() {
    test_pushBackV_emptyVector();
    test_pushBackV_fullVector();
    test_popBackV_notEmptyVector();
    test_getVectorValueV_notEmptyVector();
    test_getVectorValueV_requestToLastElement();
    test_setVectorValueV_notEmptyVector();
}


int main() {
    test();
    return 0;
}
