#include <stdio.h>
#include "../string_.c"

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
    char s1[] = "amo3gus!1!";

    numToSpace(s1);

    ASSERT_STRING("amo   gus! !", s1);
}


void test_numToSpace_2() {
    char s1[] = "1van";

    numToSpace(s1);

    ASSERT_STRING(" van", s1);
}


void tests() {
    test_removeNonLetters_1();
    test_removeNonLetters_2();
    test_removeAdjacentEqualLetters_1();
    test_removeAdjacentEqualLetters_2();
    test_numToSpace_1();
    test_numToSpace_2();
}


int main() {
    tests();
}