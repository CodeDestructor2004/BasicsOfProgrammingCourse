#include "string_.h"
#include <ctype.h>


size_t strlen_(char* begin) {
    char* end = begin;

    while (*end != '\0')
        end++;

    return end - begin;
}


char* find(char* begin, const char* end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}


char* findNonSpace(char* begin) {
    while (isspace(*begin))
        begin++;

    return begin;
}


char* findSpace(char* begin) {
    while (!isspace(*begin))
        begin++;

    return begin;
}


char* findNonSpaceReverse(char* rbegin, const char* rend) {
    while (isspace(*rbegin) && rbegin != rend)
        rbegin--;

    return rbegin;
}


char* findSpaceReverse(char* rbegin, const char* rend) {
    while (!isspace(*rbegin) && rbegin != rend)
        rbegin--;

    return rbegin;
}


int strAreEqual(char* left, char* right) {
    while (*left++ == *right++);

    if (*left != 0 && *right != 0) return 0;

    return (*right > *left) ? 1 : -1;
}


char* copy(const char* begin, const char* end, char* destination) {
    size_t length = end - begin;

    memcpy(destination, begin, CHAR_SIZE * length);

    return destination + length;
}


char* copyIf(char* begin, const char* end, char* destination, int (*f)(char)) {
    while(begin != end) {
        if (f(*begin))
            memcpy(destination++, begin, CHAR_SIZE);

        begin++;
    }

    return destination;
}


char* copyIfReverse(char* rbegin, const char* rend, char* destination, int (*f)(char)) {
    while(rbegin != rend - 1) {
        if (f(*rbegin)) 
            memcpy(destination++, rbegin, CHAR_SIZE);

        rbegin--;
    }

    return destination;
}
