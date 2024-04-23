#include "string_.h"
#include <stdio.h>
#include <ctype.h>


void assertString(const char *expected, const char *got,
char const *fileName, char const *funcName,
int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } 
    else
        fprintf(stderr, "%s - OK\n", funcName);
}


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


int strcmp_(const char* left, const char* right) {
    while (*left++ == *right++);

    if (*left != 0 && *right != 0) return 0;

    return (*right > *left) ? 1 : -1;
}


char* copy(const char* begin, const char* end, char* destination) {
    size_t length = end - begin;

    memcpy(destination, begin, CHAR_SIZE * length);

    return destination + length;
}


char* copyIf(char* begin, const char* end, char* destination, int (*f)(int)) {
    while(begin != end) {
        if (f(*begin))
            memcpy(destination++, begin, CHAR_SIZE);

        begin++;
    }

    return destination;
}


char* copyIfReverse(char* rbegin, const char* rend, char* destination, int (*f)(int)) {
    while(rbegin != rend - 1) {
        if (f(*rbegin)) 
            memcpy(destination++, rbegin, CHAR_SIZE);

        rbegin--;
    }

    return destination;
}


char* getEndOfString(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end += sizeof(char);
    return end;
}


void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}


void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s);
    char prev = *s;
    char *destination = s;

    for (char *i = s + sizeof(char); i <= endSource; i += sizeof(char)) {
        if(*i != prev) {
            *destination = prev;
            destination += sizeof(char);
            prev = *i;
        }
    }

    *destination = *endSource;
    destination += sizeof(char);
    *destination = '\0';
}


int getWord(char *begin_search, WordDescriptor *word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}


void digitToStart(WordDescriptor word) {
    char *end_string_buffer = copy(word.begin, word.end,
    _string_buffer);
    char *rec_position = copyIfReverse(end_string_buffer - 1,
    _string_buffer - 1,
    word.begin, isdigit);
    copyIf(_string_buffer, end_string_buffer, rec_position, isalpha);
}


int getWordReverse(char *begin_search, char *end_search, WordDescriptor *word) {
    word->begin = findNonSpaceReverse(begin_search, end_search);
    if (word->begin == begin_search)
        return 0;
    word->end = begin_search;
    return 1;
}


void digitToEnd(WordDescriptor word) {
    char *end_string_buffer = copy(word.begin, word.end,
                                 _string_buffer);
    char *rec_position = copyIf(_string_buffer, end_string_buffer - 1, word.begin, isalpha);
    copyIf(_string_buffer, end_string_buffer - 1, rec_position, isdigit);
    *word.end = ' ';
}


void numToSpace(char *source) {
    copy(source, getEndOfString(source), _string_buffer);
    char *end_source = getEndOfString(_string_buffer);
    char *rec_position = source;

    for (char *read_position = _string_buffer; read_position <= end_source; read_position += sizeof(char)) {
        if (isdigit(*read_position)) {
            int num = *read_position - '0' - 1;
            for (int j = 0; j <= num; j++) {
                *rec_position = ' ';
                rec_position += sizeof(char);
            }
        } else {
            *rec_position = *read_position;
            rec_position += sizeof(char);
        }
    }
    *rec_position = '\0';
}