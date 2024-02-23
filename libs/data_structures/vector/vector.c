#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void* validateMemory(void* memory) {
    if (memory == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return memory;
}


vector createVector(size_t capacity) {
    return (vector) {
        validateMemory(malloc(capacity * sizeof(int))),
        0,
        capacity,
    };
}


void setIntVectorCapacity(vector *vec, size_t new_capacity) {
    if (new_capacity == 0) {
        free(vec->data);
        vec->data = NULL;
    } else if (new_capacity < vec->size) {
        vec->size = new_capacity;
    }

    vec->data = validateMemory(realloc(vec->data, new_capacity * sizeof(int)));
    vec->capacity = new_capacity;
}


void clear(vector *vec) {
    vec->size = 0;
}


void shrinkToFit(vector *vec) {
    vec->capacity = vec->size;
}


void deleteVector(vector *vec) {
    free(vec->data);

    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}
