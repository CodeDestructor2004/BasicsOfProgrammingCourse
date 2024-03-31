#include <stdio.h>
#include "../string_.c"


void test_strlen_1() {
    printf("test_strlen_1\n");
    char str_test[] = "\tHello\t";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %u\n", strlen_(str_test));
    printf("\n");
}


void test_strlen_2() {
    printf("test_strlen_2\n");
    char str_test[] = "Ya hochu piccu";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %u\n", strlen_(str_test));
    printf("\n");
}


void test_strlen_3() {
    printf("test_strlen_3\n");
    char str_test[] = "Amo\0gus";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %u\n", strlen_(str_test));
    printf("\n");
}


void test_strlen() {
    test_strlen_1();
    test_strlen_2();
    test_strlen_3();
}


void test_find_1() {
    printf("test_find_1\n");
    char str_test[] = "Hello";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *find(&str_test[0], &str_test[4], (int) 'l'), 
        find(&str_test[0], &str_test[4], (int) 'l')
    );
    printf("\n");
}


void test_find_2() {
    printf("test_find_2\n");
    char str_test[] = "Kak delya?";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *find(&str_test[0], &str_test[9], (int) 'x'), 
        find(&str_test[0], &str_test[9], (int) 'x')
    );
    printf("\n");
}


void test_find_3() {
    printf("test_find_3\n");
    char str_test[] = "Horm\0al'no";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *find(&str_test[0], &str_test[9], (int) 'a'), 
        find(&str_test[0], &str_test[9], (int) 'a')
    );
    printf("\n");
}


void test_find() {
    test_find_1();
    test_find_2();
    test_find_3();
}


void test_findNonSpace_1() {
    printf("test_findNonSpace_1\n");
    char str_test[] = "\t\t\t\t\t\t\t\t\tZachem???";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findNonSpace(&str_test[0]), 
        findNonSpace(&str_test[0])
    );
    printf("\n");
}


void test_findNonSpace_2() {
    printf("test_findNonSpace_2\n");
    char str_test[] = "Postav'te 5 pozhaluista";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findNonSpace(&str_test[0]), 
        findNonSpace(&str_test[0])
    );
    printf("\n");
}


void test_findNonSpace() {
    test_findNonSpace_1();
    test_findNonSpace_2();
}


void test_findSpace_1() {
    printf("test_findSpace_1\n");
    char str_test[] = "\t\t\t\t\t\t\t\t\tZachem???";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findSpace(&str_test[0]), 
        findSpace(&str_test[0])
    );
    printf("\n");
}


void test_findSpace_2() {
    printf("test_findSpace_2\n");
    char str_test[] = "Postav'te 5 pozhaluista";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findSpace(&str_test[0]), 
        findSpace(&str_test[0])
    );
    printf("\n");
}


void test_findSpace() {
    test_findSpace_1();
    test_findSpace_2();
}


void test_findNonSpaceReverse_1() {
    printf("test_findNonSpaceReverse_1\n");
    char str_test[] = "ABCD\t\t\t\t\t\t\t\t";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findNonSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            ), 
        findNonSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            )
    );
    printf("\n");
}


void test_findNonSpaceReverse_2() {
    printf("test_findNonSpaceReverse_2\n");
    char str_test[] = "    This is Elon Musk";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findNonSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            ), 
        findNonSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            )
    );
    printf("\n");
}


void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_1();
    test_findNonSpaceReverse_2();
}


void test_findSpaceReverse_1() {
    printf("test_findSpaceReverse_1\n");
    char str_test[] = "ABCD\t\t\t\t\t\t\t\t";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            ), 
        findSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            )
    );
    printf("\n");
}


void test_findSpaceReverse_2() {
    printf("test_findSpaceReverse_2\n");
    char str_test[] = "    This is Elon Musk";

    printf("Test string: \"%s\"\n", str_test);
    printf("Answer: %c (address: %p)\n ", 
        *findSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            ), 
        findSpaceReverse(
            &str_test[strlen_(str_test) - 1], &str_test[0]
            )
    );
    printf("\n");
}


void test_findSpaceReverse() {
    test_findSpaceReverse_1();
    test_findSpaceReverse_2();
}


void test_strAreEqual_1() {
    printf("test_strAreEqual_1\n");

    char str_test_1[] = "These strings are equal";
    printf("Test string 1: \"%s\"\n", str_test_1);

    char str_test_2[] = "These strings are equal";
    printf("Test string 2: \"%s\"\n", str_test_2);

    printf("Answer: %d\n", strAreEqual(str_test_1, str_test_2));
    printf("\n");
}


void test_strAreEqual_2() {
    printf("test_strAreEqual_2\n");

    char str_test_1[] = "These strings are not equal";
    printf("Test string 1: \"%s\"\n", str_test_1);

    char str_test_2[] = "These strings are not equal-";
    printf("Test string 2: \"%s\"\n", str_test_2);

    printf("Answer: %d\n", strAreEqual(str_test_1, str_test_2));
    printf("\n");
}


void test_strAreEqual_3() {
    printf("test_strAreEqual_3\n");

    char str_test_1[] = "These strings are equal?\t";
    printf("Test string 1: \"%s\"\n", str_test_1);

    char str_test_2[] = "These strings are equal?";
    printf("Test string 2: \"%s\"\n", str_test_2);

    printf("Answer: %d\n", strAreEqual(str_test_1, str_test_2));
    printf("\n");
}


void test_strAreEqual() {
    test_strAreEqual_1();
    test_strAreEqual_2();
    test_strAreEqual_3();
}


void test_copy_1() {
    printf("test_copy_1\n");

    char str_test_1[20] = "Copy this string";
    printf("Test string 1: \"%s\"\n", str_test_1);

    char str_test_2[20] = "";
    printf("Test string 2: \"%s\"\n", str_test_2);

    copy(&str_test_1[0], &str_test_1[strlen_(str_test_1)], &str_test_2[0]);

    printf("Paste into test string 2: \"%s\"\n", str_test_2);
    printf("\n");
}


void test_copy() {
    test_copy_1();
}


int copyIf_predicate(char symbol) {
    return symbol <= (int) 'M'; 
}


void test_copyIf_1() {
    printf("test_copyIf_1\n");

    char str_test_1[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Test string 1: \"%s\"\n", str_test_1);

    char str_test_2[30] = "";
    printf("Test string 2: \"%s\"\n", str_test_2);

    copyIf(&str_test_1[0], &str_test_1[strlen_(str_test_1)], &str_test_2[0], copyIf_predicate);

    printf("Paste into test string 2: \"%s\"\n", str_test_2);
    printf("\n");
}


void test_copyIf() {
    test_copyIf_1();
}


void test_copyIfReverse_1() {
    printf("test_copyIfReverse_1\n");

    char str_test_1[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Test string 1: \"%s\"\n", str_test_1);

    char str_test_2[30] = "";
    printf("Test string 2: \"%s\"\n", str_test_2);

    copyIfReverse(&str_test_1[strlen_(str_test_1) - 1], &str_test_1[0], &str_test_2[0], copyIf_predicate);

    printf("Paste into test string 2: \"%s\"\n", str_test_2);
    printf("\n");
}


void test_copyIfReverse() {
    test_copyIfReverse_1();
}


void tests() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strAreEqual();
    test_copy();
    test_copyIf();
    test_copyIfReverse();

}


int main() {
    tests();
}