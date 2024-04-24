#include "string_.h"
#include <stdio.h>
#include <stdlib.h>
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
        } 
        else {
            *rec_position = *read_position;
            rec_position += sizeof(char);
        }
    }
    *rec_position = '\0';
}


int findWord(char *begin_search, WordDescriptor *pattern_word, WordDescriptor *res_word) {
    int counter = 0;
    int word_len = pattern_word->end - pattern_word->begin;
    char *search_position = pattern_word->begin;;
    while (*begin_search != '\0') {
        if (*begin_search == *search_position) {
            counter++;
            search_position += sizeof(char);
        } else {
            counter = 0;
            search_position = pattern_word->begin;
        }

        if (counter == word_len) {
            res_word->begin = begin_search - word_len + 1;
            res_word->end = begin_search + 1;
            return 1;
        }
        begin_search += sizeof(char);
    }
    return 0;
}


void replace(char *source, char *w1, char *w2) {
    size_t w1_size = strlen_(w1);
    size_t w2_size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1_size * sizeof(char)};
    WordDescriptor word2 = {w2, w2 + w2_size * sizeof(char)};
    WordDescriptor wordRes;

    char *read_position, *rec_position;

    if (w1_size >= w2_size) {
        read_position = source;
        rec_position = source;
    } 
    else {
        copy(source, getEndOfString(source), _string_buffer);
        read_position = _string_buffer;
        rec_position = source;
    }

    while (findWord(read_position, &word1, &wordRes)) {
        if (read_position != wordRes.begin) {
            rec_position = copy(read_position, wordRes.begin - 1, rec_position);
        }
        rec_position = copy(word2.begin, word2.end - 1, rec_position);
        read_position = wordRes.end;
    }

    char *read_position_end = getEndOfString(read_position);
    if (read_position >= read_position_end) {
        read_position = copy(read_position, read_position_end, rec_position);
    }
    *read_position = '\0';
}


int isOrdered(char *source) {
    WordDescriptor word_res;
    WordDescriptor prev_word_res;

    if (!getWord(source, &prev_word_res)) {
        return 1;
    }

    source = prev_word_res.end;
    while (getWord(source, &word_res)) {
        unsigned long len1 = prev_word_res.end - prev_word_res.begin;
        unsigned long len2 = word_res.end - word_res.begin;
        unsigned long min_len = len1;
        if (min_len > len2) {
            min_len = len2;
        }

        int res = memcmp(prev_word_res.begin, word_res.begin, min_len);

        if (res > 0) {
            return 0;
        }
        if ((res == 0) && (len1 > len2)) {
            return 0;
        }

        prev_word_res = word_res;
        source = word_res.end;
    }
    return 1;
}


void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word_res;

    int i = 0;
    while (getWord(s, &word_res)) {
        bag->words[i++] = word_res;
        bag->size++;

        s = word_res.end;
    }
}


void printWord(WordDescriptor word) {
    if (*word.begin == '\0') {
        return;
    }

    while (word.begin != word.end) {
        putc(*word.begin, stdout);
        word.begin++;
    }
    putc('\n', stdout);
}


void outputWordsInReverseOrder(char* string) {
    getBagOfWords(&_bag, string);

    for (size_t i = _bag.size - 1; i != -1; i--) {
        printWord(_bag.words[i]);
    }
}


char* findComma(char *begin) {
    char *ptr = begin;

    while (*ptr != '\0') {
        int res = 0;
        res = *ptr == ',';
        if (res) {
            return ptr;
        }

        ptr += sizeof(char);
    }
    return ptr;
}

char* findNonComma(char *begin) {
    char *ptr = begin;

    while (*ptr != '\0') {
        int res = 0;
        res = *ptr == ',';
        if (!res) {
            return ptr;
        }

        ptr += sizeof(char);
    }
    return ptr;
}


int getWordByComma(char *begin_search, WordDescriptor *word) {
    word->begin = findNonComma(begin_search);
    if (*word->begin == '\0')
        return 0;
    word->end = findComma(word->begin);
    return 1;
}


int isPalindrom(WordDescriptor *word_res) {
    int is_palindrom = 1;
    unsigned long len = (*word_res).end - (*word_res).begin;
    (*word_res).end -= sizeof(char);

    for (int i = 0; i < len / 2; i++) {
        if (*(*word_res).begin != *(*word_res).end) {
            is_palindrom = 0;
            break;
        }
        (*word_res).begin += sizeof(char);
        (*word_res).end -= sizeof(char);
    }
    return is_palindrom;
}


int countPalindroms(char *s) {
    WordDescriptor wordRes;

    int counter = 0;

    while (getWordByComma(s, &wordRes)) {
        s = wordRes.end;
        counter += isPalindrom(&wordRes);
    }
    return counter;
}


void getMixedString(char *res, char *s1, char *s2) {
    WordDescriptor word1, word2;
    bool is_w1_found, is_w2_found;
    char *begin_search1 = s1;
    char *begin_search2 = s2;
    while ((is_w1_found = getWord(begin_search1, &word1)),
            (is_w2_found = getWord(begin_search2, &word2)),
            is_w1_found || is_w2_found) {

        if (is_w1_found) {
            if (*word1.end == '\0') {
                *word1.end = ' ';
            }

            copy(word1.begin, word1.end, res);
            res += word1.end - word1.begin + 1;
            begin_search1 = word1.end;
        }
        if (is_w2_found) {
            if (*word2.end == '\0') {
                *word2.end = ' ';
            }

            copy(word2.begin, word2.end, res);
            res += word2.end - word2.begin + 1;
            begin_search2 = word2.end;
        }

    }
    res -= sizeof(char);
    *res = '\0';
}


void stringReverse(char *s) {
    copy(s, getEndOfString(s), _string_buffer);

    WordDescriptor wordRes;
    char *end = getEndOfString(_string_buffer) + sizeof(char);

    while ((end >= _string_buffer) && getWordReverse(end, _string_buffer,&wordRes)) {
        end = wordRes.begin - sizeof(char);

        copy(wordRes.begin, wordRes.end, s);
        s += wordRes.end - wordRes.begin;
        *s = ' ';
        s += sizeof(char);
    }
    s -= sizeof(char);
    *s = '\0';
}

int hasWordLetter(WordDescriptor *word, char letter) {
    for (char *i = word->begin; i <= word->end; i += sizeof(char)) {
        if (*i == letter) {
            return 1;
        }
    }
    return 0;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *source, WordDescriptor *w) {
    WordDescriptor word_res;
    WordDescriptor prev_word_res;

    if (!getWord(source, &prev_word_res)) {
        return EMPTY_STRING;
    }

    if (hasWordLetter(&prev_word_res, 'a') || hasWordLetter(&prev_word_res, 'A')) {
        w->begin = prev_word_res.begin;
        w->end = prev_word_res.end;
        return FIRST_WORD_WITH_A;
    }

    source = prev_word_res.end;
    while (getWord(source, &word_res)) {

        if (hasWordLetter(&word_res, 'a') || hasWordLetter(&word_res, 'A')) {
            w->begin = prev_word_res.begin;
            w->end = prev_word_res.end;
            return WORD_FOUND;
        }

        prev_word_res = word_res;
        source = word_res.end;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor word;
    WordBeforeFirstWordWithAReturnCode result = getWordBeforeFirstWordWithA(s, &word);

    switch (result) {
        case EMPTY_STRING:
            printf("String without words");
            break;
        case FIRST_WORD_WITH_A:
            printf("The first word with 'a' is first in string\n");
            printWord(word);
            break;
        case WORD_FOUND:
            printf("There is a string with word with 'a'\n");
            printWord(word);
        case NOT_FOUND_A_WORD_WITH_A:
            printf("There is a string without word with 'a'");
            break;
    }
}


void clearBagOfWords(BagOfWords *bag) {
    bag->size = 0;
}


void findLastWord(char *string_1, char *string_2) {
    clearBagOfWords(&_bag);
    clearBagOfWords(&_bag2);
    getBagOfWords(&_bag, string_1);
    getBagOfWords(&_bag2, string_2);

    size_t len1 = 0;
    size_t len2 = 0;

    for (int i = _bag.size - 1; i >= 0; i--) {
        for (int j = _bag2.size - 1; j >= 0; j--) {
            len1 = &_bag.words[i].end - &_bag.words[i].begin;
            len2 = &_bag2.words[j].end - &_bag2.words[j].begin;

            if (len1 != len2) {
                continue;
            }

            int res = memcmp(_bag.words[i].begin, _bag2.words[j].begin, len1);

            if (res == 0) {
                printWord(_bag.words[i]);
            }
        }
    }
}


int compareWordDescriptors(const void *word_ptr_1, const void *word_ptr_2) {
    WordDescriptor *word1 = (WordDescriptor *)word_ptr_1;
    WordDescriptor *word2 = (WordDescriptor *)word_ptr_2;

    unsigned long len1 = word1->end - word1->begin;
    unsigned long len2 = word2->end - word2->begin;
    unsigned long min_len = len1;
    if (min_len > len2) {
        min_len = len2;
    }

    int res = memcmp(word1->begin, word2->begin, min_len);

    if (res == 0) {
        if (len1 != len2) {
            res = len1 > len2 ? 1 : -1;
        }
    }
    return res;
}


int hasSameWords(char *string) {
    clearBagOfWords(&_bag);
    getBagOfWords(&_bag, string);
    qsort(_bag.words, _bag.size, sizeof(WordDescriptor), compareWordDescriptors);

    for (int i = 1; i <= _bag.size; i++) {
        int res = compareWordDescriptors(&_bag.words[i - 1], &_bag.words[i]);

        if (res == 0) {
            return 0;
        }
    }
    return 1;
}


int compareLetters(const void* char_ptr_1, const void* char_ptr_2) {
    const char *char1 = (const char*)char_ptr_1;
    const char *char2 = (const char*)char_ptr_2;

    return *char1 - *char2;
}


int hasWordsWithSameLetters(char *string) {
    copy(string, getEndOfString(string), _string_buffer);
    clearBagOfWords(&_bag);

    for (int i = 0; i <= _bag.size; i++) {
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), compareLetters);
    }

    qsort(_bag.words, _bag.size, sizeof(WordDescriptor), compareWordDescriptors);

    for (int i = 1; i <= _bag.size; i++) {
        int res = compareWordDescriptors(&_bag.words[i - 1], &_bag.words[i]);

        if (res == 0) {
            return 1;
        }
    }
    return 0;
}


void getStringWithoutEndWords(char *string) {
    copy(string, getEndOfString(string), _string_buffer);
    clearBagOfWords(&_bag);
    getBagOfWords(&_bag, _string_buffer);
    WordDescriptor last_word = _bag.words[_bag.size - 1];

    for (int i = 0; i < _bag.size - 1; i++) {
        WordDescriptor current_word = _bag.words[i];
        int res = compareWordDescriptors(&current_word, &last_word);

        if (res != 0) {
            copy(current_word.begin, current_word.end, string);
            string += current_word.end - current_word.begin;
            *string = ' ';
            string += sizeof(char);
        }
    }
    string -= sizeof(char);
    *string = '\0';
}


int findWordBefore(char *string_1, char *string_2, char *res) {
    clearBagOfWords(&_bag);
    clearBagOfWords(&_bag2);
    getBagOfWords(&_bag, string_1);
    getBagOfWords(&_bag2, string_2);

    int get;
    for (int i = 1; i < _bag.size - 1; i++) {
        WordDescriptor line_word_1 = _bag.words[i];
        for (int j = 0; j < _bag2.size - 1; j++) {
            WordDescriptor line_word_2 = _bag2.words[j];
            get = compareWordDescriptors(&line_word_1, &line_word_2);

            if (get == 0) {
                WordDescriptor res_word = _bag.words[i - 1];
                copy(res_word.begin, res_word.end, res);
                res += res_word.end - res_word.begin;
                *res = '\0';
                return 1;
            }
        }
    }
    return 0;
}


void deletePalindromes(char *string) {
    copy(string, getEndOfString(string) + sizeof (char), _string_buffer);
    clearBagOfWords(&_bag);
    getBagOfWords(&_bag, _string_buffer);

    for (int i = 0; i < _bag.size; i++) {
        WordDescriptor line_word = _bag.words[i];

        int isPal = isPalindrom(&line_word);

        if (!isPal) {
            copy(line_word.begin, line_word.end, string);
            string += line_word.end - line_word.begin + 1;
            *string = ' ';
            string += sizeof(char);
        }
    }
    string -= sizeof(char);
    *string = '\0';
}


void appendMissingWords(char *string_1, char *string_2) {
    clearBagOfWords(&_bag);
    clearBagOfWords(&_bag2);
    getBagOfWords(&_bag, string_1);
    getBagOfWords(&_bag2, string_2);

    size_t min_len = 0;
    BagOfWords *max_ptr;
    char *res_string;

    if (_bag.size < _bag2.size) {
        min_len = _bag.size;
        max_ptr = &_bag2;
        res_string = string_1;
    } else {
        min_len = _bag2.size;
        max_ptr = &_bag;
        res_string = string_2;
    }

    res_string += strlen_(res_string);
    *res_string = ' ';
    res_string += sizeof(char);

    WordDescriptor word;
    for (int i = min_len; i < max_ptr->size; i++) {
        word = max_ptr->words[i];
        copy(word.begin, word.end, res_string);
        res_string += word.end - word.begin + 1;
    }
}


int isStringIncludeLetters(char *string, char *word) {
    copy(string, getEndOfString(string), _string_buffer);
    copy(word, getEndOfString(word), _string_buffer2);

    size_t len_string = strlen_(_string_buffer);
    qsort(_string_buffer, len_string, sizeof(char), compareLetters);
    size_t len_string_1 = strlen_(_string_buffer2);
    qsort(_string_buffer2, len_string_1, sizeof(char), compareLetters);

    int amount = 0;
    char *end_string_ptr = _string_buffer + len_string;
    char *current_char = _string_buffer2;
    for (char *i = _string_buffer; i <= end_string_ptr; i += sizeof(char)) {
        if (*i == *current_char) {
            amount++;

            if (amount == len_string_1) {
                return 1;
            }
            current_char += sizeof(char);
        }

    }
    return 0;
}