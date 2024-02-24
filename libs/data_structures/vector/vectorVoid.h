#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <malloc.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;


vectorVoid createVectorV(size_t n, size_t type_size);


void reserveV(vectorVoid *vec, size_t new_capacity);


void shrinkToFitV(vectorVoid *vec);


void clearV(vectorVoid *vec);


void deleteVectorV(vectorVoid *vec);


#endif