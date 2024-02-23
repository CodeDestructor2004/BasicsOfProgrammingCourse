#include "libs/data_structures/bitset/bitset.c"
#include <stdio.h>


void test1_bitset_checkValue() {
    printf("test1_bitset_checkValue\n");
    int data[] = {1, 2, 3, 4, 6, 10};
    size_t size = sizeof(data) / sizeof(data[0]);

    bitset test_set = bitset_create(26);

    printf("test_set: ");
    for (int i = 0; i < size; i++)
        bitset_insert(&test_set, data[i]);
    bitset_print(test_set);

    int x = 4;
    printf("is %d in test_set: ", x);
    bool set_in = bitset_in(test_set, x);
    printf("%d\n", set_in);
    printf("\n");
}


void test2_bitset_checkValue() {
    printf("test2_bitset_checkValue\n");
    int data[] = {1, 4, 5, 6};
    size_t size = sizeof(data) / sizeof(data[0]);

    bitset test_set = bitset_create(26);

    printf("test_set: ");
    for (int i = 0; i < size; i++)
        bitset_insert(&test_set, data[i]);
    bitset_print(test_set);

    int x = 3;
    printf("is %d in test_set: ", x);
    bool set_in = bitset_in(test_set, x);
    printf("%d\n", set_in);
    printf("\n");
}


void test_bitset_checkValue() {
    test1_bitset_checkValue();
    test2_bitset_checkValue();
}


void test1_bitset_isEqual() {
    printf("test1_bitset_isEqual\n");
    int data_1[] = {1, 2, 3, 4, 6, 10};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 4, 5, 6};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("is test_set_1 equal test_set_2: ");
    bool set_equal = bitset_isEqual(test_set_1, test_set_2);
    printf("%d\n", set_equal);
    printf("\n");
}


void test2_bitset_isEqual() {
    printf("test2_bitset_isEqual\n");
    int data_1[] = {2, 4, 5};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {2, 4, 5};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("is test_set_1 equal test_set_2: ");
    bool set_equal = bitset_isEqual(test_set_1, test_set_2);
    printf("%d\n", set_equal);
    printf("\n");
}


void test_bitset_isEqual() {
    test1_bitset_isEqual();
    test2_bitset_isEqual();
}


void test1_bitset_isSubset() {
    printf("test1_bitset_isSubset\n");
    int data_1[] = {1, 2, 3, 6, 9, 10};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 4, 5, 6};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("is test_set_1 in test_set_2: ");
    bool set1_in_set2 = bitset_isSubset(test_set_1, test_set_2);
    printf("%d\n", set1_in_set2);
    printf("\n");
}


void test2_bitset_isSubset() {
    printf("test2_bitset_isSubset\n");
    int data_1[] = {1, 4, 6};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 2, 3, 4, 6, 10};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("is test_set_1 in test_set_2: ");
    bool set1_in_set2 = bitset_isSubset(test_set_1, test_set_2);
    printf("%d\n", set1_in_set2);
    printf("\n");
}


void test_bitset_isSubset() {
    test1_bitset_isSubset();
    test2_bitset_isSubset();
}


void test1_bitset_insert() {
    printf("test1_bitset_insert\n");
    int data[] = {1, 4, 5, 6};
    size_t size = sizeof(data) / sizeof(data[0]);

    bitset test_set = bitset_create(26);

    printf("test_set: ");
    for (int i = 0; i < size; i++)
        bitset_insert(&test_set, data[i]);
    bitset_print(test_set);

    int x = 3;
    bitset_insert(&test_set, x);
    printf("insert %d in test_set: ", x);
    bitset_print(test_set);
    printf("\n");
}


void test_bitset_insert() {
    test1_bitset_insert();
}


void test1_bitset_deleteElement() {
    printf("test1_bitset_deleteElement\n");
    int data[] = {1, 2, 3, 4, 6, 10};
    size_t size = sizeof(data) / sizeof(data[0]);

    bitset test_set = bitset_create(26);

    printf("test_set: ");
    for (int i = 0; i < size; i++)
        bitset_insert(&test_set, data[i]);
    bitset_print(test_set);

    int x = 4;
    bitset_deleteElement(&test_set, x);
    printf("delete %d in test_set: ", x);
    bitset_print(test_set);
    printf("\n");
}


void test_bitset_deleteElement() {
    test1_bitset_deleteElement();
}


void test1_bitset_union() {
    printf("test1_bitset_union\n");
    int data_1[] = {1, 2, 3, 4, 6, 10};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 4, 5, 6};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 or test_set_2: ");
    bitset set1_or_set2 = bitset_union(test_set_1, test_set_2);
    bitset_print(set1_or_set2);
    printf("\n");
}


void test2_bitset_union() {
    printf("test2_bitset_union\n");
    int data_1[] = {1, 2, 6, 7, 11, 13};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {7, 8, 9, 16};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 or test_set_2: ");
    bitset set1_or_set2 = bitset_union(test_set_1, test_set_2);
    bitset_print(set1_or_set2);
    printf("\n");
}


void test_bitset_union() {
    test1_bitset_union();
    test2_bitset_union();
}


void test1_bitset_intersection() {
    printf("test1_bitset_intersection\n");
    int data_1[] = {1, 2, 3, 4, 6, 10};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 4, 5, 6};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 and test_set_2: ");
    bitset set1_and_set2 = bitset_intersection(test_set_1, test_set_2);
    bitset_print(set1_and_set2);
    printf("\n");
}


void test2_bitset_intersection() {
    printf("test2_bitset_intersection\n");
    int data_1[] = {1, 2, 6, 7, 11, 13};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {7, 8, 9, 16};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 and test_set_2: ");
    bitset set1_and_set2 = bitset_intersection(test_set_1, test_set_2);
    bitset_print(set1_and_set2);
    printf("\n");
}


void test_bitset_intersection() {
    test1_bitset_intersection();
    test2_bitset_intersection();
}


void test1_bitset_difference() {
    printf("test1_bitset_difference\n");
    int data_1[] = {1, 2, 3, 4, 6, 10};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 4, 5, 6};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 and not test_set_2: ");
    bitset set1_and_not_set2 = bitset_difference(test_set_1, test_set_2);
    bitset_print(set1_and_not_set2);
    printf("\n");
}


void test2_bitset_difference() {
    printf("test2_bitset_difference\n");
    int data_1[] = {1, 2, 6, 7, 11, 13};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {7, 8, 9, 16};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 and not test_set_2: ");
    bitset set1_and_not_set2 = bitset_difference(test_set_1, test_set_2);
    bitset_print(set1_and_not_set2);
    printf("\n");
}


void test_bitset_difference() {
    test1_bitset_difference();
    test2_bitset_difference();
}


void test1_bitset_symmetricDifference() {
    printf("test1_bitset_symmetricDifference\n");
    int data_1[] = {1, 2, 3, 4, 6, 10};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {1, 4, 5, 6};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 xor test_set_2: ");
    bitset set1_xor_set2 = bitset_symmetricDifference(test_set_1, test_set_2);
    bitset_print(set1_xor_set2);
    printf("\n");
}


void test2_bitset_symmetricDifference() {
    printf("test2_bitset_symmetricDifference\n");
    int data_1[] = {1, 2, 6, 7, 11, 13};
    size_t size_1 = sizeof(data_1) / sizeof(data_1[0]);
    int data_2[] = {7, 8, 9, 16};
    size_t size_2 = sizeof(data_2) / sizeof(data_2[0]);

    bitset test_set_1 = bitset_create(26);
    bitset test_set_2 = bitset_create(26);

    printf("test_set_1: ");
    for (int i = 0; i < size_1; i++)
        bitset_insert(&test_set_1, data_1[i]);
    bitset_print(test_set_1);
    printf("test_set_2: ");
    for (int i = 0; i < size_2; i++)
        bitset_insert(&test_set_2, data_2[i]);
    bitset_print(test_set_2);

    printf("test_set_1 xor test_set_2: ");
    bitset set1_xor_set2 = bitset_symmetricDifference(test_set_1, test_set_2);
    bitset_print(set1_xor_set2);
    printf("\n");
}


void test_bitset_symmetricDifference() {
    test1_bitset_symmetricDifference();
    test2_bitset_symmetricDifference();
}


void test1_bitset_complement() {
    printf("test1_bitset_complement\n");
    int data[] = {1, 2, 3, 4, 6, 10};
    size_t size = sizeof(data) / sizeof(data[0]);

    bitset test_set = bitset_create(26);

    printf("test_set: ");
    for (int i = 0; i < size; i++)
        bitset_insert(&test_set, data[i]);
    bitset_print(test_set);

    printf("not test_set: ");
    bitset not_set = bitset_complement(test_set);
    bitset_print(not_set);
    printf("\n");
}


void test_bitset_complement() {
    test1_bitset_complement();
}


void test() {
    test_bitset_checkValue();
    test_bitset_isEqual();
    test_bitset_isSubset();
    test_bitset_insert();
    test_bitset_deleteElement();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetricDifference();
    test_bitset_complement();
}


int main() {
    test();

    return 0;
}