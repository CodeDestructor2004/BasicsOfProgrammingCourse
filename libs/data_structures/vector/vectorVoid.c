#include "vectorVoid.h"


vectorVoid createVectorV(size_t capacity, size_t type_size) {
    vectorVoid vec;

    vec.data = malloc(capacity * type_size);
    vec.size = 0;
    vec.capacity = capacity;
    vec.baseTypeSize = type_size;

    return vec;
}


void reserveV(vectorVoid *vec, size_t new_capacity) {
    if (new_capacity > vec->capacity) {
        void* new_data = realloc(vec->data, new_capacity * vec->baseTypeSize);

        if (new_data) {
            vec->data = new_data;
            vec->capacity = new_capacity;
        }
    }
}


void shrinkToFitV(vectorVoid *vec) {
    vec->capacity = vec->size;
}


void clearV(vectorVoid *vec) {
    vec->size = 0;
}


void deleteVectorV(vectorVoid *vec) {
    free(vec->data);

    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->baseTypeSize = 0;
}


bool isEmptyV(vectorVoid *vec) {
    return vec->size == 0;
}


bool isFullV(vectorVoid *vec) {
    return vec->size == vec->capacity;
}


void getVectorValueV(vectorVoid *vec, size_t index, void *destination) {
    if (index >= vec->size) {
        fprintf(stderr, "Invalid index %zu for size %zu", index, vec->size);
        exit(1);
    }

    memcpy(destination, vec->data + index * vec->baseTypeSize, vec->baseTypeSize);
}


void setVectorValueV(vectorVoid *vec, size_t index, void *source) {
    if (index >= vec->size) {
        fprintf(stderr, "Invalid index %zu for size %zu", index, vec->size);
        exit(1);
    }

    memcpy(vec->data + index * vec->baseTypeSize, source, vec->baseTypeSize);
}


void popBackV(vectorVoid *vec) {
    if (vec->size == 0) {
        fprintf(stderr, "vector is empty!");
        exit(1);
    }

    vec->size--;
}


void pushBackV(vectorVoid *vec, void *source) {
    if (isFullV(vec)) {
        if (vec->capacity == 0)
            vec->capacity = 1;
        else
            reserveV(vec, vec->capacity << 1);
    }

    memcpy(vec->data + vec->size++ * vec->baseTypeSize, source, vec->baseTypeSize);
}