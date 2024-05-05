#include <stdio.h>
#include <stdlib.h>
#include "..\matrix\matrix.c"
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
        answer = task_19_1(str_1);
    printf("%d\n", assert_txt(str_1, str_2));
}


void tests() {
    test_task_19_1();
    test_task_19_2();
}


int main() {
    tests();
}