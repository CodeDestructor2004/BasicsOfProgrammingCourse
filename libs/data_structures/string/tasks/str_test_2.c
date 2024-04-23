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
}


int main() {
    tests();
}