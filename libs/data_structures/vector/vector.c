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


void validateIndex(vector* vec, size_t index) {
    if (index >= vec->size) {
        fprintf(stderr, "Invalid index %zu for size %zu", index, vec->size);
        exit(1);
    }
}


vector createVector(size_t capacity) {
    return (vector) {
        validateMemory(malloc(capacity * sizeof(int))),
        0,
        capacity,
    };
}


void reserve(vector *vec, size_t new_capacity) {
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


bool isEmpty(vector *vec) {
    return vec->size == 0;
}


bool isFull(vector *vec) {
    return vec->size >= vec->capacity;
}


int getVectorValue(vector *vec, size_t i) {
    return vec->data[i];
}


void pushBack(vector *vec, int x) {
    if (isFull(vec)) {
        if (vec->capacity == 0)
            vec->capacity = 1;
        else
            reserve(vec, vec->capacity << 1);
    }
        
    vec->data[vec->size++] = x;
}


void popBack(vector *vec) {
    if (vec->size == 0) {
        fprintf(stderr, "vector is empty!");
        exit(1);
    }

    vec->size--;
}


int* atVector(vector *vec, size_t index) {
    validateIndex(vec, index);
    return &(vec->data[index]);
}


int* back(vector* vec) {
    return atVector(vec, vec->size - 1);
}


int* front(vector* vec) {
    return atVector(vec, 0);
}
