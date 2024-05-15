#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>
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

// . Согласно статье в Википедии : « Игра жизни» , также известная просто 
// как «Жизнь », представляет собой клеточный автомат, изобретенный 
// британским математиком Джоном Хортоном Конвеем в 1970 году.
// Доска состоит из m x nсетки ячеек, где каждая ячейка имеет 
// начальное состояние: живое (обозначается значком 1) или 
// мертвое (обозначается значком 0). Каждая ячейка 
// взаимодействует со своими восемью соседями 
// (горизонтальными, вертикальными, диагональными), используя 
// следующие четыре правила
int is_point_alive(matrix *m, int i, int j) {
    bool is_alive = m->values[i][j];

    int left_i = i > 0 ? i - 1 : i;
    int right_i = i < m->rows - 1 ? i + 1 : i;
    int left_j = j > 0 ? j - 1 : j;
    int right_j = j < m->cols - 1 ? j + 1 : j;

    int amount_units = 0;
    for (int row_i = left_i; row_i <= right_i; row_i++)
        for (int col_j = left_j; col_j <= right_j; col_j++)
            if (m->values[row_i][col_j] && (row_i != i || col_j != j))
                amount_units++;

    if (is_alive && (amount_units < 2))
        return 0;

    if (is_alive && (amount_units == 2 || amount_units == 3))
        return 1;

    if (is_alive && amount_units > 3)
        return 0;

    if (!is_alive && amount_units == 3)
        return 1;

    return 0;
}


void game_life(const char* filename) {
    FILE* file = fopen(filename, "rb");
    int n, m;
    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    matrix mat = getMemMatrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fread(&mat.values[i][j], sizeof(int), 1, file);

    matrix res_mat = getMemMatrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res_mat.values[i][j] = is_point_alive(&mat, i, j);

    fclose(file);


    file = fopen(filename, "wb");

    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fwrite(&res_mat.values[i][j], sizeof(int), 1, file);

    freeMemMatrix(&mat);
    freeMemMatrix(&res_mat);

    fclose(file);
}


void test_game_life_1_empty_file() {
    const char filename[] = "test_files/task_2_test_1.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 0;
    int m = 0;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);
    fclose(file);

    game_life(filename);
    file = f_safetyOpen(filename, "rb");
    if (file == NULL)
        return;

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    assert(n == 0);
    assert(m == 0);

    fclose(file);
}


void test_game_life_2_unit_file() {
    const char filename[] = "test_files/task_2_test_2.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 1;
    int m = 1;
    int x = 0;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);
    fwrite(&x, sizeof(int), 1, file);
    fclose(file);

    game_life(filename);
    file = f_safetyOpen(filename, "rb");

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);
    fread(&x, sizeof(int), 1, file);

    assert(n == 1);
    assert(m == 1);
    assert(x == 0);

    fclose(file);
}


void test_game_life_3_more_elements() {
    const char filename[] = "test_files/task_2_test_3.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 4;
    int m = 3;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);
    matrix mat = createMatrixFromArray((int[]) {0, 1, 0,
                                                0, 0, 1,
                                                1, 1, 1,
                                                0, 0, 0}, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fwrite(&mat.values[i][j], sizeof(int), 1, file);
    fclose(file);

    game_life(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);
    matrix res = getMemMatrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fread(&res.values[i][j], sizeof(int), 1, file);
    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                1, 0, 1,
                                                0, 1, 1,
                                                0, 1, 0}, n, m);
    assert(n == 4);
    assert(m == 3);
    assert(areTwoMatricesEqual(&res, &check));

    freeMemMatrix(&mat);
    freeMemMatrix(&res);
    freeMemMatrix(&check);
    fclose(file);
}


void test_game_life() {
    test_game_life_1_empty_file();
    test_game_life_2_unit_file();
    test_game_life_3_more_elements();
}


// Медианный фильтр — это метод обработки цифровых изображений, 
// который используется для уменьшения шума на изображении. Для 
// применения медианного фильтра к массиву, необходимо выполнить 
// следующие шаги
int cmp(const void* a, const void* b) {
    return *(const unsigned int *) a - *(const unsigned int *) b;
}


int get_median_in_area(matrix* m, const int i, const int j, const int filter) {
    int border = filter * 2 + 1;
    int *temp = (int *) malloc((border * border) * sizeof(int));
    int size = 0;

    for (int row_i = i - filter; row_i <= i + filter; row_i++)
        for (int col_j = j - filter; col_j <= j + filter; col_j++)
            if (row_i != i || col_j != j) {
                temp[size] = m->values[row_i][col_j];
                size++;
            }

    qsort(temp, size, sizeof(int), cmp);
    int result = (temp[size / 2 - 1] + temp[size / 2]) / 2;

    free(temp);
    return result;
}


void median_filter(const char* filename) {
    FILE* file = f_safetyOpen(filename, "rb");

    int n, filter;
    fread(&n, sizeof(int), 1, file);
    fread(&filter, sizeof(int), 1, file);

    filter /= 2;

    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fread(&m.values[i][j], sizeof(int), 1, file);

    for (int i = filter; i < n - filter; i++)
        for (int j = filter; j < n - filter; j++)
            m.values[i][j] = get_median_in_area(&m, i, j, filter);

    fclose(file);

    file = f_safetyOpen(filename, "wb");
    filter = filter * 2 + 1;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&filter, sizeof(int), 1, file);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fwrite(&m.values[i][j], sizeof(int), 1, file);

    freeMemMatrix(&m);
    fclose(file);
}


void test_median_filter_1_empty_file() {
    const char filename[] = "test_files/task_3_test_1.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 0;
    int filter = 7;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&filter, sizeof(int), 1, file);
    fclose(file);

    median_filter(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fread(&filter, sizeof(int), 1, file);

    fclose(file);

    assert(n == 0);
    assert(filter == 7);
}


void test_median_filter_2_unit_file() {
    const char filename[] = "test_files/task_3_test_2.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 1;
    int x = 10;
    int filter = 7;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&filter, sizeof(int), 1, file);
    fwrite(&x, sizeof(int), 1, file);
    fclose(file);

    median_filter(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fread(&filter, sizeof(int), 1, file);
    fread(&x, sizeof(int), 1, file);

    fclose(file);

    assert(n == 1);
    assert(filter == 7);
    assert(x == 10);
}


void test_median_filter_3_average_matrix() {
    const char filename[] = "test_files/task_3_test_3.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 5;
    int filter = 5;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&filter, sizeof(int), 1, file);
    matrix mat = createMatrixFromArray((int[]) {10, 20, 30, 40, 50,
                                                15, 24, 16, 17, 56,
                                                34, 54, 12, 56, 78,
                                                14, 45, 34, 47, 56,
                                                17, 15, 24, 56, 62}, n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fwrite(&mat.values[i][j], sizeof(int), 1, file);

    fclose(file);
    median_filter(filename);

    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fread(&filter, sizeof(int), 1, file);
    matrix res = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fread(&res.values[i][j], sizeof(int), 1, file);
    matrix check = createMatrixFromArray((int[]) {10, 20, 30, 40, 50,
                                                15, 24, 16, 17, 56,
                                                34, 54, 34, 56, 78,
                                                14, 45, 34, 47, 56,
                                                17, 15, 24, 56, 62}, n, n);

    fclose(file);

    assert(n == 5);
    assert(filter == 5);
    assert(areTwoMatricesEqual(&res, &check));

    freeMemMatrix(&mat);
    freeMemMatrix(&res);
    freeMemMatrix(&check);
}


void test_median_filter() {
    test_median_filter_1_empty_file();
    test_median_filter_2_unit_file();
    test_median_filter_3_average_matrix();
}

void tests() {
    test_fill_matrix();
    test_game_life();
    test_median_filter();
}


int main() {
    tests();
}