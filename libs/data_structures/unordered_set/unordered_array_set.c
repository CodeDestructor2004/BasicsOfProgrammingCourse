# include <stdio.h>
# include <assert.h>
# include "unordered_array_set.h"
# include <stdbool.h>
#include <malloc.h>
# include "..\..\..\libs\algorithms\array\array.h"


int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) 
        return -1;
    if (arg1 > arg2) 
        return 1;
    
    return 0;
}


typedef struct unordered_array_set {
    int *data; // Элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество
} unordered_array_set;


unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
        malloc(sizeof(int) * capacity),
        0,
        capacity
    };
}


unordered_array_set unordered_array_set_create_from_array(const int* a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);

    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    
    return set;
}


size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}


bool unordered_array_set_isSubset(unordered_array_set subset,
unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++)
        if (unordered_array_set_in(&set, subset.data[i]) == set.size)
            return false;
    
    return true;
}


bool unordered_array_set_isEqual ( unordered_array_set set1 ,unordered_array_set set2 ) {
    if (set1.size != set2.size)
        return 0;
    
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);

    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}


void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}


void unordered_array_set_insert(unordered_array_set* set, int element) {
    if (unordered_array_set_in(set, element) != set->size) {
        unordered_array_set_is_able_append(set);
        append_(set->data, set->size, element);
    }
}


void unordered_array_set_deleteElement(unordered_array_set* set, int value) {
    size_t index = unordered_array_set_in(&set, value);

    if (index < set->size) {
        set->data[index] = set->data[set->size - 1];
        set->size--;
    }
}


unordered_array_set unordered_array_set_union(unordered_array_set set1,
unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size +
    set2.size);

    for (size_t i = 0; i < set1.size; i++) {
            unordered_array_set_insert(&result, set1.data[i]);
    }
    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&result, set2.data[i]);
    }

    return result;
}


unordered_array_set unordered_array_set_intersection(unordered_array_set
set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }

    return result;
}


unordered_array_set unordered_array_set_difference(unordered_array_set set1,
unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }

    return result;
}


unordered_array_set unordered_array_set_complement(unordered_array_set set,
unordered_array_set universumSet) {
    unordered_array_set result =
    unordered_array_set_create(universumSet.size);

    for (size_t i = 0; i < universumSet.size; i++) {
        if (unordered_array_set_in(&set, universumSet.data[i]) == set.size) {
            unordered_array_set_insert(&result, universumSet.data[i]);
        }
    }

    return result;
}


unordered_array_set
unordered_array_set_symmetricDifference(unordered_array_set set1,
unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_union(
        unordered_array_set_difference(set1, set2),
        unordered_array_set_difference(set2, set1)
    );

    return result;
}


void unordered_array_set_print(unordered_array_set set) {
    printf("{");

    for (size_t i = 0; i < set.size; i++) {
        printf("%d", set.data[i]);
        if (i < set.size - 1) {
            printf(", ");
        }
    }

    printf("}\n");
}


void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}
