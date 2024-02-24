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