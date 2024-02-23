#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;


// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t capacity);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *vec, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *vec);

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *vec);

// освобождает память, выделенную вектору
void deleteVector(vector *vec);

// функция проверки на то, является ли вектор пустым
bool isEmpty(vector *vec);

// функция проверки на то, является ли вектор полным
bool isFull(vector *vec);

// возвращает i-ый элемент вектора vec
int getVectorValue(vector *vec, size_t i);

// добавляет элемент x в конец вектора v
void pushBack(vector *vec, int x);

// удаляет последний элемент из вектора
void popBack(vector *vec);

// возвращает указатель на index-ый элемент вектора
int* atVector(vector *vec, size_t index);

// возвращает указатель на последний элемент вектора
int* back(vector *v);

// возвращает указатель на нулевой элемент вектора
int* front(vector *v);