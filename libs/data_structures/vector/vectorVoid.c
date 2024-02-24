#include "vectorVoid.h"


vectorVoid createVectorV(size_t capacity, size_t type_size) {
    vectorVoid vec;

    vec.data = malloc(capacity * type_size);
    vec.size = 0;
    vec.capacity = capacity;
    vec.baseTypeSize = type_size;

    return vec;
}


