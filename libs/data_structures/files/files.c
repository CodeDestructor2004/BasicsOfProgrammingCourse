#include <stdio.h>
#include <stdlib.h>
#include "..\matrix\matrix.c"
#include "..\string\string_.c"
#include "file_lib.c"

// В текстовом файле хранятся целочисленные квадратные матрицы
// следующим образом: сначала целое число n – порядок матрицы, а
// затем ее элементы по строкам. Преобразовать файл так, чтобы
// элементы матрицы хранились по столбцам.
int task_19_1(const char *str_1) {
    FILE *input_file = fopen(str_1, "r");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file =
    fopen("buffer_file.txt", "w");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    int n;
    while (fscanf(input_file, "%d", &n) == 1) {
        int matrix[n][n];
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                fscanf(input_file, "%d", &matrix[i][j]);
            
        fprintf(output_file, "%d ", n);

        for (int j = 0; j < n; j++) 
            for (int i = 0; i < n; i++) 
                fprintf(output_file, "%d ", matrix[i][j]);
    }

    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt",
    str_1);
    return 0;
}


void test_task_19_1() {
    printf("test_task_19_1 - ");
    const char *str_1 =
        "task_1.txt";
    const char *str_2 =
        "task_1_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_1(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}

// В текстовом файле записаны вещественные числа в форме с
// фиксированной точкой. Преобразовать файл, представив каждое
// число в форме с плавающей точкой, сохранив две цифры после точки
// в мантиссе.
int task_19_2(const char *str) {
    FILE *input_file = fopen(str, "r");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }
    
    FILE *output_file = fopen("buffer_file.txt", "w");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    double number;

    while (fscanf(input_file, "%lf", &number) == 1) {
        fprintf(output_file, "%.2f ", number);
    }

    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt",
    str);
    return 0;
}


void test_task_19_2() {
    printf("test_task_19_2 - ");
    const char *str_1 =
        "task_2.txt";
    const char *str_2 =
        "task_2_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_2(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}


// Дан текстовый файл, представляющий собой запись
// арифметического выражения, операндами которого являются
// однозначные числа. Число операций в выражении не больше двух.
// Вычислить значение этого выражения и дописать его в конец этого
// файла.
int task_19_3(const char *str) {
    FILE *input_file = fopen(str, "r+");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    char operator;
    int operand1, operand2, result;

    fscanf(input_file, "%d %c %d", &operand1, &operator, &operand2);

    if (operator == '+') 
        result = operand1 + operand2;
    else if (operator == '-') 
        result = operand1 - operand2;
    else if (operator == '*') 
        result = operand1 * operand2;
    else if (operator == '/')
        result = operand1 / operand2;
    else {
        printf("Unsupported operation\n");
        fclose(input_file);
        return 1;
    }

    fprintf(input_file, "\nResult: %d", result);
    fclose(input_file);
    return 0;
}

void test_task_19_3() {
    printf("test_task_19_3 - ");
    const char *str_1 =
        "task_3.txt";
    const char *str_2 =
        "task_3_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_3(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}

// Дан текстовый файл. Сохранить в файле только те слова, которые
// содержат данную последовательность символов
int task_19_4(const char *str, char sequence[20]) {
    FILE *input_file = fopen(str, "r+");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "w");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    char word[MAX_WORD_SIZE];

    while (fscanf(input_file, "%s", word) != EOF) {
        if (strstr(word, sequence) != NULL) 
            fprintf(output_file, "%s ", word);
    }

    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt", str);
    return 0;
}


void test_task_19_4() {
    printf("test_task_19_4 - ");
    const char *str_1 =
        "task_4.txt";
    const char *str_2 =
        "task_4_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_4(str_1, "hi");
    printf("%d\n", assert_txt(str_1, str_2));
}

// Дан текстовый файл. Преобразовать его, оставив в каждой строке
// только самое длинное слово.
int task_19_5(const char *str) {
    FILE *input_file = fopen(str, "r+");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "w");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    char line[1000], longest_word[MAX_WORD_SIZE];
    int max_len = 0;

    while (fgets(line, sizeof(line), input_file)) {
        char *token = strtok(line, " ");

        while (token != NULL) {
            if (strlen(token) > max_len) {
                max_len = strlen(token);
                strcpy(longest_word, token);
            }
            token = strtok(NULL, " ");
        }

        fprintf(output_file, "%s\n", longest_word);

        max_len = 0;
        longest_word[0] = '\0';
    }
    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt", str);
    return 0;
}


void test_task_19_5() {
    printf("test_task_19_5 - ");
    const char *str_1 =
        "task_5.txt";
    const char *str_2 =
        "task_5_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_5(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}


// В бинарном файле структур хранятся многочлены в порядке
// убывания степеней. Каждая структура содержит два поля: показатель
// степени члена и коэффициент. Члены с нулевыми коэффициентами
// не хранятся. Свободный член присутствует обязательно, даже если он
// равен нулю. Удалить из файла многочлены, для которых данное x
// является корнем.
typedef struct {
 int power;
 int coefficient;
} Polynomial;


int pow_(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }

    return result;
}


int task_19_6(const char *str, int x) {
    FILE *input_file = fopen(str, "rb");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }
    
    Polynomial poly;
    while (fread(&poly, sizeof(Polynomial), 1, input_file)) {
        if (poly.coefficient * pow_(x, poly.power) != (x * x)) 
            fwrite(&poly, sizeof(Polynomial), 1, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
    copyFileContent("buffer_file.txt", str);
    return 0;
}


void test_task_19_6() {
    printf("test_task_19_6 - ");
    const char *str_1 =
        "task_6.txt";
    const char *str_2 =
        "task_6_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_6(str_1, 2);
    printf("%d\n", assert_txt(str_1, str_2));
}


// Дан бинарный файл целых чисел. Нулевых компонент в файле нет.
// Число отрицательных компонент равно числу положительных.
// Преобразовать файл таким образом, чтобы сначала были
// положительные числа, а затем отрицательные. Порядок следования
// как положительных, так и отрицательных чисел сохранить.
int task_19_7(const char *str) {
    FILE *input_file = fopen(str, "rb");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    int positive_number;
    while (fread(&positive_number, sizeof(positive_number), 1, input_file))
        if (positive_number > 0) 
            fwrite(&positive_number, sizeof(positive_number), 1, output_file);
        
    fclose(input_file);
    input_file = fopen(str, "rb");

    int negative_number;
    while (fread(&negative_number, sizeof(negative_number), 1, input_file))
        if (negative_number < 0) 
            fwrite(&negative_number, sizeof(negative_number), 1, output_file);

    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt", str);
    return 0;
}


void test_task_19_7() {
    printf("test_task_19_7 - ");
    const char *str_1 =
        "task_7.txt";
    const char *str_2 =
        "task_7_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_7(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}


// Дан бинарный файл квадратных матриц порядка n. Преобразовать
// его, заменив каждую матрицу, не являющуюся симметричной,
// транспонированной.
int task_19_8(const char *str) {
    FILE *input_file = fopen(str, "rb");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    matrix m;
    while (fread(&m, sizeof(matrix), 1, input_file)) {
        if (!isSymmetricMatrix(&m)) {
            transposeMatrix(&m);
            fwrite(&m, sizeof(matrix), 1, output_file);
        } 
        else 
            fwrite(&m, sizeof(matrix), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt", str);
    return 0;
}


void test_task_19_8() {
    printf("test_task_19_8 - ");
    const char *str_1 =
        "task_8.txt";
    const char *str_2 =
        "task_8_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_8(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}


// В бинарном файле структур хранится информация о спортсменах:
// Ф.И.О., наилучший результат. Требуется сформировать команду из n
// лучших спортсменов. Преобразовать файл, сохранив в нем
// информацию только о членах команды.
typedef struct {
 char *initials;
 int score;
} Sportsman;


void appendS(Sportsman *a, size_t *const size, Sportsman value) {
    a[*size] = (Sportsman) value;
    (*size)++;
}


int task_19_9(const char *str, int n) {
    FILE *input_file = fopen(str, "rb");
    if (input_file == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    size_t size = 0;
    Sportsman persons[100];
    Sportsman person;

    while (fread(&person, sizeof(Sportsman), 1, input_file)) 
        appendS(persons, &size, person);
    
    for (int i = 0; i < n; ++i) {
        Sportsman temp_player = {NULL, -999};
        int idx = 0;

        for (int j = 0; j < size; ++j) {
            if (persons[j].score > temp_player.score) {
                temp_player.score = persons[j].score;
                temp_player.initials = persons[j].initials;
                idx = j;
            }
        }

        persons[idx].score = -999;
        fwrite(&temp_player, sizeof(Sportsman), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    copyFileContent("buffer_file.txt", str);
    return 0;
}


void test_task_19_9() {
    printf("test_task_19_9 - ");
    const char *str_1 =
        "task_9.txt";
    const char *str_2 =
        "task_9_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_2))
        answer = task_19_9(str_1, 2);
    printf("%d\n", assert_txt(str_1, str_2));
}


// В бинарном файле f структур хранится следующая информация о
// товарах, имеющихся на складе: наименование товара, цена единицы
// товара, общая стоимость и количество. В бинарном файле структур g
// хранится информация о заказах: наименование товара и его
// количество. Обновить файл f с учетом отпущенных товаров в
// соответствии с заказами из файла g. Если товар отпущен полностью,
// запись о нем из файла f удаляется.
typedef struct {
    char *name;
    int unit_price;
    int all_price;
    int amount;
} Goods;

typedef struct {
    char *name;
    int amount;
} OrderedGoods;

int task_19_10(const char *str_f, const char *str_g) {
    FILE *file_f = fopen(str_f, "rb");
    if (file_f == NULL) {
        printf("Error: input file f not found\n");
        return 1;
    }

    FILE *file_g = fopen(str_g, "rb");
    if (file_g == NULL) {
        printf("Error: output file g not found\n");
        return 1;
    }

    FILE *output_file = fopen("buffer_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: output file not created\n");
        return 1;
    }

    Goods stuff;
    OrderedGoods ordered_stuff;

    while (fread(&ordered_stuff, sizeof(OrderedGoods), 1, file_g)) {
        while (fread(&stuff, sizeof(Goods), 1, file_f)) {
            if (ordered_stuff.name == stuff.name) {
                int price = ordered_stuff.amount * stuff.unit_price;
                stuff.amount = stuff.amount - ordered_stuff.amount;
                stuff.all_price = stuff.all_price - price;

                if (stuff.amount > 0)
                    fwrite(&stuff, sizeof(Goods), 1, output_file);
                break;
            } 

            else
                fwrite(&stuff, sizeof(Goods), 1, output_file);
        }
    }

    fclose(file_f);
    fclose(file_g);
    fclose(output_file);

    copyFileContent("buffer_file.txt", str_f);
    return 0;
}


void test_task_19_10() {
    printf("test_task_19_10 - ");
    const char *str_1 =
        "task_10_f.txt";
    const char *str_2 =
        "task_10_g.txt";
    const char *str_3 =
        "task_10_ref.txt";
    int answer = 1;
    if (!assert_txt(str_1, str_3))
        answer = task_19_10(str_1, str_2);
    printf("%d\n", assert_txt(str_1, str_3));
}


void tests() {
    test_task_19_1();
    test_task_19_2();
    test_task_19_3();
    test_task_19_4();
    test_task_19_5();
    test_task_19_6();
    test_task_19_7();
    test_task_19_8();
    test_task_19_9();
    test_task_19_10();
}


int main() {
    tests();
}