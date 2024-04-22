#include <stdio.h>
#include "../string_.c"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)


void test_removeNonLetters_1() {
    char test_string[] = "ab1 1";
    
    removeNonLetters(test_string);
    printf("%d\n", strcmp_("ab11", test_string));
    
    ASSERT_STRING("ab11", test_string);
}


void test_removeNonLetters_2() {
    char test_string[] = "qwe r  ty";
    
    removeNonLetters(test_string);
    printf("%d\n", strcmp_("qwerty", test_string));
    
    ASSERT_STRING("qwerty", test_string);
}


void tests() {
    test_removeNonLetters_1();
    test_removeNonLetters_2();
}

int main() {
    tests();
}