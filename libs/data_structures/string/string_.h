#ifndef STRING__H
#define STRING__H

#define CHAR_SIZE sizeof(char)

#include <memory.h>
#include <stdbool.h>
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20


char _string_buffer[MAX_STRING_SIZE + 1];

// Функция теста строк
void assertString(const char *expected, const char *got,
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

// Удаляет пробелы из строки по адресу s
void removeNonLetters(char *s);

// Преобразует строку, оставляя только один символ в каждой последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);


typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

// вернёт значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *begin_search, WordDescriptor *word);


// преобразует строку таким образом, чтобы цифры каждого слова были перенесены
// в начало слова и изменить порядок следования цифр в слове на обратный
void digitToStart(WordDescriptor word);

// Аналогично getWord, но считывает слова с конца строки
int getWordReverse(char *begin_search, char *end_search, WordDescriptor *word);

// Преобразовать строку таким образом, чтобы цифры каждого слова были
// перенесены в конец слова без изменения порядка следования их в слове, а
// буквы – в начало
void digitToEnd(WordDescriptor word);

// Преобразует строку, заменяя каждую 
// цифру соответствующим ей числом пробелов
void numToSpace(char *source);

// Заменяет все вхождения слова w1 на слово w2
void replace(char *source, char *w1, char *w2);

// Определяет, упорядочены ли лексикографически слова данного предложения
int isOrdered(char *source);


typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;


BagOfWords _bag;
BagOfWords _bag2;

// Получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s);

// Выводит слова данной строки в обратном порядке по одному в строке экрана
void outputWordsInReverseOrder(char* string);

// Определяет количество слов-палиндромов в строке, где слова разделены запятыми
int countPalindroms(char *s);

// Получает строку, в которой чередуются слова первой и второй строки
void getMixedString(char *res, char *s1, char *s2);

// Изменяет порядок следования слов в строке на обратный
void stringReverse(char *s);


typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

// Выводит слово данной строки, предшествующее первому из слов, содержащих букву "а"
void printWordBeforeFirstWordWithA(char *s);

// Определяет последнее из слов первой строки, которое есть во второй строке
void findLastWord(char *string_1, char *string_2);

#endif //STRING__H
