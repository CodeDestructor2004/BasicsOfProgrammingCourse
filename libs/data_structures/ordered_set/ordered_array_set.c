#include <malloc.h>
#include <stdio.h>
# include "ordered_array_set.h"
#include "..\..\..\libs\algorithms\array\array.h"
#include <stdbool.h>
#include <assert.h>


typedef struct ordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} ordered_array_set;


ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
        malloc(sizeof(int) * capacity),
        0,
        capacity
    };
}


ordered_array_set ordered_array_set_create_from_array(const int *a, size_t
size) {
    ordered_array_set set;
    set.data = (int *) malloc(size * sizeof(int));
    set.size = size;
    set.capacity = size;
    
    for (size_t i = 0; i < size; i++) {
        set.data[i] = a[i];
    }

    return set;
}


size_t ordered_array_set_in(ordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++) 
        if (set->data[i] == value) 
            return i;

    return set->size;
}


bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set
set2) {
    if (set1.size != set2.size) 
        return false;

    for (size_t i = 0; i < set1.size; ++i) 
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size) 
            return false;
        
    return true;
}


bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++)
        if (ordered_array_set_in(&set, subset.data[i]) == set.size)
            return false;
    
    return true;
}


void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}


void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    set->data[set->size] = value;
    set->size++;
}


void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t index = ordered_array_set_in(set, value);

    if (index < set->size) {
        set->data[index] = set->data[set->size - 1];
        set->size--;
    }
}


ordered_array_set ordered_array_set_union(ordered_array_set set1,
ordered_array_set set2) {
 ordered_array_set result = ordered_array_set_create(set1.size +
set2.size);

    for (size_t i = 0; i < set1.size; i++) {
        ordered_array_set_insert(&result, set1.data[i]);
    }

    for (size_t i = 0; i < set2.size; i++) {
        ordered_array_set_insert(&result, set2.data[i]);
    }

    return result;
}


ordered_array_set ordered_array_set_intersection(ordered_array_set set1,
ordered_array_set *set2) {
    ordered_array_set result = ordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) 
        if (ordered_array_set_in(set2, set1.data[i]) != set2->size) 
            ordered_array_set_insert(&result, set1.data[i]);
    
    return result;
}


ordered_array_set ordered_array_set_difference(ordered_array_set set1,
ordered_array_set *set2) {
    ordered_array_set result = ordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) 
        if (ordered_array_set_in(set2, set1.data[i]) == set2->size) 
            ordered_array_set_insert(&result, set1.data[i]);

    return result;
}


ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set
*set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_union(
        ordered_array_set_difference(*set1, &set2),
        ordered_array_set_difference(set2, set1)
    );
    
    return result;
}


ordered_array_set ordered_array_set_complement(ordered_array_set *set,
ordered_array_set universumSet) {
    ordered_array_set result = ordered_array_set_create(universumSet.size);

    for (size_t i = 0; i < universumSet.size; i++) 
        if (ordered_array_set_in(set, universumSet.data[i]) == set->size) 
            ordered_array_set_insert(&result, universumSet.data[i]);

    return result;
}


void ordered_array_set_print(ordered_array_set set) {
    printf("{");

    for (size_t i = 0; i < set.size; i++) {
        printf("%d", set.data[i]);

        if (i < set.size - 1)
            printf(", ");
    }

    printf("}\n");
}


void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}
