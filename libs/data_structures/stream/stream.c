#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>
#include "..\string\string_.c"
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


void fillMatrix(const char* filename) {
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


void test_fillMatrix_1_empty_file() {
    const char filename[] = "test_files/task_1_test_1.txt";
    FILE* file = f_safetyOpen(filename, "wb");
    int n = 0;
    fwrite(&n, sizeof(int), 1, file);
    fclose(file);

    fillMatrix(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fclose(file);

    assert(n == 0);
}


void test_fillMatrix_2_unit_matrix() {
    const char filename[] = "test_files/task_1_test_2.txt";
    FILE* file = f_safetyOpen(filename, "wb");
    int n = 1;
    fwrite(&n, sizeof(int), 1, file);

    coord c = {.row1=0, .col1=0, .row2=0, .col2=0};
    fwrite(&c, sizeof(coord), 1, file);
    fclose(file);

    fillMatrix(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);

    int x;
    fread(&x, sizeof(int), 1, file);
    fclose(file);

    assert(n == 1);
    assert(x == 1);
}


void test_fillMatrix_3_more_matrix_element() {
    const char filename[] = "test_files/task_1_test_3.txt";
    FILE* file = f_safetyOpen(filename, "wb");
    int n = 3;
    fwrite(&n, sizeof(int), 1, file);

    coord c1 = {.row1=1, .col1=1, .row2=2, .col2=2};
    coord c2 = {.row1=0, .col1=0, .row2=1, .col2=1};
    fwrite(&c1, sizeof(coord), 1, file);
    fwrite(&c2, sizeof(coord), 1, file);
    fclose(file);

    fillMatrix(filename);
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


void test_fillMatrix() {
    test_fillMatrix_1_empty_file();
    test_fillMatrix_2_unit_matrix();
    test_fillMatrix_3_more_matrix_element();
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
int isPointAlive(matrix *m, int i, int j) {
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


void gameLife(const char* filename) {
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
            res_mat.values[i][j] = isPointAlive(&mat, i, j);

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


void test_gameLife_1_empty_file() {
    const char filename[] = "test_files/task_2_test_1.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 0;
    int m = 0;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);
    fclose(file);

    gameLife(filename);
    file = f_safetyOpen(filename, "rb");
    if (file == NULL)
        return;

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    assert(n == 0);
    assert(m == 0);

    fclose(file);
}


void test_gameLife_2_unit_file() {
    const char filename[] = "test_files/task_2_test_2.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 1;
    int m = 1;
    int x = 0;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);
    fwrite(&x, sizeof(int), 1, file);
    fclose(file);

    gameLife(filename);
    file = f_safetyOpen(filename, "rb");

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);
    fread(&x, sizeof(int), 1, file);

    assert(n == 1);
    assert(m == 1);
    assert(x == 0);

    fclose(file);
}


void test_gameLife_3_more_elements() {
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

    gameLife(filename);
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


void test_gameLife() {
    test_gameLife_1_empty_file();
    test_gameLife_2_unit_file();
    test_gameLife_3_more_elements();
}


// Медианный фильтр — это метод обработки цифровых изображений, 
// который используется для уменьшения шума на изображении. Для 
// применения медианного фильтра к массиву, необходимо выполнить 
// следующие шаги
int cmp(const void* a, const void* b) {
    return *(const unsigned int *) a - *(const unsigned int *) b;
}


int getMedianInArea(matrix* m, const int i, const int j, const int filter) {
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


void medianFilter(const char* filename) {
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
            m.values[i][j] = getMedianInArea(&m, i, j, filter);

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


void test_medianFilter_1_empty_file() {
    const char filename[] = "test_files/task_3_test_1.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 0;
    int filter = 7;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&filter, sizeof(int), 1, file);
    fclose(file);

    medianFilter(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fread(&filter, sizeof(int), 1, file);

    fclose(file);

    assert(n == 0);
    assert(filter == 7);
}


void test_medianFilter_2_unit_file() {
    const char filename[] = "test_files/task_3_test_2.txt";
    FILE* file = f_safetyOpen(filename, "wb");

    int n = 1;
    int x = 10;
    int filter = 7;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&filter, sizeof(int), 1, file);
    fwrite(&x, sizeof(int), 1, file);
    fclose(file);

    medianFilter(filename);
    file = f_safetyOpen(filename, "rb");
    fread(&n, sizeof(int), 1, file);
    fread(&filter, sizeof(int), 1, file);
    fread(&x, sizeof(int), 1, file);

    fclose(file);

    assert(n == 1);
    assert(filter == 7);
    assert(x == 10);
}


void test_medianFilter_3_average_matrix() {
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
    medianFilter(filename);

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


void test_medianFilter() {
    test_medianFilter_1_empty_file();
    test_medianFilter_2_unit_file();
    test_medianFilter_3_average_matrix();
}


// Домен веб-сайта "discuss.codeforces.com"состоит из различных 
// поддоменов. На верхнем уровне у нас есть "com", на следующем 
// уровне " codeforces.com" и на самом низком уровне "discuss. 
// codeforces.com". 
// Когда мы посещаем такой домен "discuss. codeforces.com" , мы также 
// неявно посещаем родительские домены ." codeforces.com" и "com"
// Счетно -парный домен — это домен, который имеет один из двух 
// форматов "rep d1.d2.d3"или "rep d1.d2"где rep— количество посещений 
// домена и d1.d2.d3— сам домен.
// Например, "9001 discuss.codeforces.com"это домен с парным счетчиком 
// , который указывает количество discuss.leetcode.com посещений 9001.
// Учитывая массив доменов с парным счетчиком cpdomains , верните 
// массив доменов с парным счетчиком для каждого поддомена во 
// входных данных . Вы можете вернуть ответ в любом порядке.
#define MAX_LENGTH_DOMAIN 128
#define MAX_DOMAIN 64


typedef struct domain {
    char name[MAX_LENGTH_DOMAIN];
    int amount;
} domain;


typedef struct domains {
    domain data[MAX_DOMAIN];
    size_t size;
} domains;


int getWordToDot(char* begin_search, WordDescriptor* word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return 0;

    size_t len = strlen_(begin_search);
    word->end = find(word->begin, word->begin + len, '.');

    if (word->end == word->begin + len || *word->end == '\n')
        word->end -= 2;

    return 1;
}


void push_domain_in_domains(domains* ds, domain* d) {
    ds->data[ds->size].amount = d->amount;
    copy(d->name, d->name + strlen_(d->name) + 1, ds->data[ds->size].name);
    ds->size++;
}


void merge_equal_domains(domains* ds) {
    for (int i = 0; i < ds->size; i++)
        for (int j = i + 1; j < ds->size; j++) {
            if (strcmp_(ds->data[i].name, ds->data[j].name) == 0 
            && ds->data[i].amount >= 0 
            && ds->data[j].amount >= 0) {
                ds->data[i].amount += ds->data[j].amount;
                ds->data[j].amount = -1;
            }

        }
}


void _get_domains(char* s, domains* ds) {
    char* read_ptr = s;

    WordDescriptor amount_as_text, name_domain;
    getWordWithoutSpace(read_ptr, &amount_as_text);
    read_ptr = amount_as_text.end + 1;
    getWordWithoutSpace(read_ptr, &name_domain);

    int k = 1;
    int amount = 0;
    read_ptr = amount_as_text.end;
    while (read_ptr >= amount_as_text.begin) {
        amount += k * (*read_ptr - '0');
        k *= 10;
        read_ptr--;
    }

    read_ptr = name_domain.begin;
    _bag.size = 0;
    while (getWordToDot(read_ptr, &_bag.words[_bag.size])) {
        read_ptr = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    for (int i = 0; i < _bag.size; i++) {
        domain d = {.amount = amount};

        char* begin = d.name;
        begin = copy(_bag.words[i].begin, _bag.words[i].end + 1, begin);
        for (int j = i + 1; j < _bag.size; j++)
            begin = copy(_bag.words[j].begin, _bag.words[j].end + 1, begin);

        push_domain_in_domains(ds, &d);
    }

    freeBag(&_bag);
}


void get_domains(const char* filename) {
    FILE* file = f_safetyOpen(filename, "r");

    domains ds = {.size = 0};

    while (fgets(_string_buffer, 256, file)) {
        _get_domains(_string_buffer, &ds);
        freeString(_string_buffer);
    }

    merge_equal_domains(&ds);

    fclose(file);


    file = f_safetyOpen(filename, "w");

    for (int i = 0; i < ds.size; i++) {
        if (ds.data[i].amount >= 0)
            fprintf(file, "%d %s\n", ds.data[i].amount, ds.data[i].name);
    }

    fclose(file);
}


void test_get_domains_1_empty_file() {
    const char filename[] = "test_files/task_4_test_1.txt";

    FILE* file = f_safetyOpen(filename, "w");
    fclose(file);

    get_domains(filename);


    file = f_safetyOpen(filename, "r");

    char dest[100] = "";
    fscanf(file, "%s", dest);

    fclose(file);

    assert(strcmp_(dest, "") == 0);
}


void test_get_domains_2_one_domain() {
    const char filename[] = "test_files/task_4_test_2.txt";

    FILE* file = f_safetyOpen(filename, "w");

    char s[100] = "900 discuss.codeforces.com";
    fprintf(file, "%s\n", s);

    fclose(file);


    get_domains(filename);


    file = f_safetyOpen(filename, "r");

    char dest1[100] = "";
    char dest2[100] = "";
    char dest3[100] = "";
    fgets(dest1, sizeof(dest1), file);
    fgets(dest2, sizeof(dest2), file);
    fgets(dest3, sizeof(dest3), file);

    fclose(file);

    assert(strcmp_(dest1, "900 discuss.codeforces.com\n") == 0);
    assert(strcmp_(dest2, "900 codeforces.com\n") == 0);
    assert(strcmp_(dest3, "900 com\n") == 0);
}


void test_get_domains_3_more_domain() {
    const char filename[] = "test_files/task_4_test_3.txt";

    FILE* file = f_safetyOpen(filename, "w");

    char s1[100] = "900 discuss.codeforces.com";
    char s2[100] = "69 mail.com";
    fprintf(file, "%s\n", s1);
    fprintf(file, "%s\n", s2);

    fclose(file);


    get_domains(filename);


    file = f_safetyOpen(filename, "r");

    char dest1[100] = "";
    char dest2[100] = "";
    char dest3[100] = "";
    char dest4[100] = "";
    fgets(dest1, sizeof(dest1), file);
    fgets(dest2, sizeof(dest2), file);
    fgets(dest3, sizeof(dest3), file);
    fgets(dest4, sizeof(dest4), file);

    fclose(file);

    assert(strcmp_(dest1, "900 discuss.codeforces.com\n") == 0);
    assert(strcmp_(dest2, "900 codeforces.com\n") == 0);
    assert(strcmp_(dest3, "969 com\n") == 0);
    assert(strcmp_(dest4, "69 mail.com\n") == 0);
}


void test_get_domains() {
    test_get_domains_1_empty_file();
    test_get_domains_2_one_domain();
    test_get_domains_3_more_domain();
}


void tests() {
    test_fillMatrix();
    test_gameLife();
    test_medianFilter();
    test_get_domains();
}


int main() {
    tests();
}