#include <stdio.h>
#include <assert.h>
#include "..\matrix\matrix.c"
#include "..\files\file_lib.c"

// Вам дано положительное целое число n, указывающее, что изначально 
// у нас есть целочисленная матрица n x n, заполненная нулями.
// Вам также дан двумерный целочисленный массив query. Для 
// каждого необходимо выполнить следующую операцию: query[i] = 
// [row1i, col1i, row2i, col2i]
typedef struct coord {
    int row1;
    int col1;
    int row2;
    int col2;
} coord;


void fill_matrix(const char* filename) {
    FILE* file = f_safetyOpen(filename, "rb");
    int n;
    fread(&n, sizeof(int), 1, file);

    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m.values[i][j] = 0;

    coord c;
    while(fread(&c, sizeof(coord), 1, file) == 1)
        for (int i = c.row1; i <= c.row2; i++)
            for (int j = c.col1; j <= c.col2; j++)
                m.values[i][j]++;

    fclose(file);

    file = f_safetyOpen(filename, "wb");
    fwrite(&n, sizeof(int), 1, file);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fwrite(&m.values[i][j], sizeof(int), 1, file);

    freeMemMatrix(&m);
    fclose(file);
}


void test_fill_matrix_1_empty_file() {
    const char filename[] = "test_files/task_1_test_1.txt";
    FILE* file = f_safetyOpen(filename, "wb");
    int n = 0;
    fwrite(&n, sizeof(int), 1, file);
    fclose(file);

    fill_matrix(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fclose(file);

    assert(n == 0);
}


void test_fill_matrix_2_unit_matrix() {
    const char filename[] = "test_files/task_1_test_2.txt";
    FILE* file = f_safetyOpen(filename, "wb");
    int n = 1;
    fwrite(&n, sizeof(int), 1, file);

    coord c = {.row1=0, .col1=0, .row2=0, .col2=0};
    fwrite(&c, sizeof(coord), 1, file);
    fclose(file);

    fill_matrix(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);

    int x;
    fread(&x, sizeof(int), 1, file);
    fclose(file);

    assert(n == 1);
    assert(x == 1);
}


void test_fill_matrix_3_more_matrix_element() {
    const char filename[] = "test_files/task_1_test_3.txt";
    FILE* file = f_safetyOpen(filename, "wb");
    int n = 3;
    fwrite(&n, sizeof(int), 1, file);

    coord c1 = {.row1=1, .col1=1, .row2=2, .col2=2};
    coord c2 = {.row1=0, .col1=0, .row2=1, .col2=1};
    fwrite(&c1, sizeof(coord), 1, file);
    fwrite(&c2, sizeof(coord), 1, file);
    fclose(file);

    fill_matrix(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fread(&m.values[i][j], sizeof(int), 1, file);
    matrix check = createMatrixFromArray((int[]) {1, 1, 0,
                                                1, 2, 1,
                                                0, 1, 1}, 3, 3);
    assert(n == 3);
    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
    fclose(file);
}


void test_fill_matrix() {
    test_fill_matrix_1_empty_file();
    test_fill_matrix_2_unit_matrix();
    test_fill_matrix_3_more_matrix_element();
}


void tests() {
    test_fill_matrix();
}


int main() {
    tests();
}