#ifndef STRING__H
#define STRING__H

#define CHAR_SIZE sizeof(char)

#include <memory.h>
#include <stdbool.h>

// Функция теста строк
void assertString(const char *expected, char *got,
char const *fileName, char const *funcName,
int line);

// Поиск длины строки по адресу begin
size_t strlen_(char* begin);

// Возвращает указатель на первый элемент с кодом ch, 
// расположенным на ленте памяти между адресами begin и end
// не включая end. Если символ не найден, возвращается значение end
char* find(char* begin, const char* end, int ch);

// Возвращает указатель на первый символ, отличный от пробельных, 
// расположенный на ленте памяти, начиная с begin и заканчивая 
// ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char* begin);

// Возвращает указатель на первый пробельный символ, 
// расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.
char* findSpace(char* begin);

// Возвращает указатель на первый справа символ, отличный от пробельных, 
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend. 
// Если символ не найден, возвращается адрес rend
char* findNonSpaceReverse(char* rbegin, const char* rend);

// Возвращает указатель на первый пробельный символ справа, 
// расположенный на ленте памяти, начиная с rbegin и 
// заканчивая rend. Если символ не найден, возвращается адрес rend
char* findSpaceReverse(char* rbegin, const char* rend);

// Проверка строк по адресу left и right на равенство
int strcmp_(const char* left, const char* right);

// Записывает по адресу destination фрагмент памяти, начиная 
// с адреса begin до end. Возвращает 
// указатель на следующий свободный фрагмент памяти в destination
char* copy(const char* begin, const char* end, char* destination);

// Записывает по адресу destination элементы из фрагмента памяти 
// начиная с begin заканчивая end, удовлетворяющие функции-предикату f. Функция
// возвращает указатель на следующий свободный для записи фрагмент в памяти.
char* copyIf(char* begin, const char* end, char* destination, int (*f)(int));

// записывает по адресу destination элементы из фрагмента памяти 
// начиная с rbegin заканчивая rend, удовлетворяющие функции-предикату f. 
// Функция возвращает значение destination по окончанию работы функции.
char* copyIfReverse(char* rbegin, const char* rend, char* destination, int (*f)(int));


void removeNonLetters(char *s);

#endif //STRING__H
