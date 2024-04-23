#include <stdio.h>
#include "../string_.c"
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)


void test_removeNonLetters_1() {
    char test_string[] = "ab1 1";
    
    removeNonLetters(test_string);
    
    ASSERT_STRING("ab11", test_string);
}


void test_removeNonLetters_2() {
    char test_string[] = "qwe r  ty";
    
    removeNonLetters(test_string);
    
    ASSERT_STRING("qwerty", test_string);
}


void test_removeAdjacentEqualLetters_1() {
    char test_string[] = "abbcccdddd";
    
    removeAdjacentEqualLetters(test_string);

    ASSERT_STRING("abcd", test_string);
}


void test_removeAdjacentEqualLetters_2() {
    char test_string[] = "123 333 112 111";
    
    removeAdjacentEqualLetters(test_string);

    ASSERT_STRING("123 3 12 1", test_string);
}


void test_numToSpace_1() {
    char test_string[] = "amo3gus!1!";

    numToSpace(test_string);

    ASSERT_STRING("amo   gus! !", test_string);
}


void test_numToSpace_2() {
    char test_string[] = "1van";

    numToSpace(test_string);

    ASSERT_STRING(" van", test_string);
}


void test_replace_1() {
    char test_string[MAX_STRING_SIZE] = "Ya hochu dva za laboratornuyu";
    char string_1[] = "dva";
    char string_2[] = "pyat";
    replace(test_string, string_1, string_2);
    ASSERT_STRING("Ya hochu pyat za laboratornuyu", test_string);
}


void test_replace_2() {
    char test_string[MAX_STRING_SIZE] = "Hunter X Hunter";
    char string_1[] = "Hunter";
    char string_2[] = "Pivo";
    replace(test_string, string_1, string_2);
    ASSERT_STRING("Pivo X Pivo", test_string);
}


void test_isOrdered_1() {
    char test_string[] = "alpha beta gamma";
    int result = isOrdered(test_string);
    if (result == 1)
        printf("test_isOrdered_1 - OK\n");
    else
        printf("test_isOrdered_1 - ERROR\n");
}


void test_isOrdered_2() {
    char test_string[] = "z a";
    int result = isOrdered(test_string);
    if (result == 0)
        printf("test_isOrdered_2 - OK\n");
    else
        printf("test_isOrdered_2 - ERROR\n");
}


void test_outputWordsInReverseOrder_1() {
    char test_string[] = "March April May";
    printf("test_outputWordsInReverseOrder_1:\n%s\n", test_string);
    outputWordsInReverseOrder(test_string);
}


void test_outputWordsInReverseOrder_2() {
    char test_string[] = "Ya";
    printf("test_outputWordsInReverseOrder_2:\n%s\n", test_string);
    outputWordsInReverseOrder(test_string);
}


void test_countPalindroms_1() {
    char test_string[] = "aba,qwe,zxxz,asdf,abcdcba";
    int result = countPalindroms(test_string);
    if (result == 3)
        printf("test_countPalindroms_1 - OK\n");
    else
        printf("test_countPalindroms_1 - ERROR\n");
}


void test_countPalindroms_2() {
    char test_string[] = "abc";
    int result = countPalindroms(test_string);
    if (result == 0)
        printf("test_countPalindroms_2 - OK\n");
    else
        printf("test_countPalindroms_2 - ERROR\n");
}


void test_getMixedString_1() {
    char test_string[MAX_STRING_SIZE] = "";
    char string_1[] = "red blue";
    char string_2[] = "green";
    getMixedString(test_string, string_1, string_2);
    ASSERT_STRING("red green blue", test_string);
}


void test_getMixedString_2() {
    char test_string[MAX_STRING_SIZE] = "";
    char string_1[] = "a a a a a";
    char string_2[] = "b";
    getMixedString(test_string, string_1, string_2);
    ASSERT_STRING("a b a a a a", test_string);
}


void test_stringReverse_1() {
    char test_string[] = "first second third";
    stringReverse(test_string);
    ASSERT_STRING("third second first", test_string);
}


void test_stringReverse_2() {
    char test_string[] = "one";
    stringReverse(test_string);
    ASSERT_STRING("one", test_string);
}


void test_getWordBeforeFirstWordWithA() {
    WordDescriptor word;

    char string_1[] = "";
    assert(
        getWordBeforeFirstWordWithA(string_1, &word) == EMPTY_STRING
    );

    char string_2[] = "ABC";
    assert(
        getWordBeforeFirstWordWithA(string_2, &word) == FIRST_WORD_WITH_A
    );

    char string_3[] = "BC A";
    assert(
        getWordBeforeFirstWordWithA(string_3, &word) == WORD_FOUND
    );

    char got[MAX_STRING_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("BC", got);

    char string_4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(string_4, &word) == NOT_FOUND_A_WORD_WITH_A);
}


void tests() {
    test_removeNonLetters_1();
    test_removeNonLetters_2();
    test_removeAdjacentEqualLetters_1();
    test_removeAdjacentEqualLetters_2();
    test_numToSpace_1();
    test_numToSpace_2();
    test_replace_1();
    test_replace_2();
    test_isOrdered_1();
    test_isOrdered_2();
    test_outputWordsInReverseOrder_1();
    test_outputWordsInReverseOrder_2();
    test_countPalindroms_1();
    test_countPalindroms_2();
    test_getMixedString_1();
    test_getMixedString_2();
    test_stringReverse_1();
    test_stringReverse_2();
    test_getWordBeforeFirstWordWithA();
}


int main() {
    tests();
}