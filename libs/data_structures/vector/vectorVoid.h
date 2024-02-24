#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>


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

// возвращает структуру-дескриптор вектор из n значений
vectorVoid createVectorV(size_t n, size_t type_size);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserveV(vectorVoid *vec, size_t new_capacity);

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid *vec);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clearV(vectorVoid *vec);

// освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *vec);

// функция проверки на то, является ли вектор пустым
bool isEmptyV(vectorVoid *vec);

// функция проверки на то, является ли вектор полным
bool isFullV(vectorVoid *vec);

// записывает по адресу destination index-ый элемент вектора vec
void getVectorValueV(vectorVoid *vec, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *vec, size_t index, void *source);

// удаляет последний элемент из вектора
void popBackV(vectorVoid *vec);

// добавляет элемент по адресу source в конец вектора v
void pushBackV(vectorVoid *vec, void *source);


#endif