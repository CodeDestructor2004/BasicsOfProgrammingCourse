#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>
#include <signal.h>
#include <conio.h>
#include "..\string\string_.c"
#include "..\matrix\matrix.c"
#include "..\files\file_lib.c"
#include "..\vector\vector.c"

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


void pushDomainInDomains(domains* ds, domain* d) {
    ds->data[ds->size].amount = d->amount;
    copy(d->name, d->name + strlen_(d->name) + 1, ds->data[ds->size].name);
    ds->size++;
}


void mergeEqualDomains(domains* ds) {
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


void getDomains_(char* s, domains* ds) {
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

        pushDomainInDomains(ds, &d);
    }

    freeBag(&_bag);
}


void getDomains(const char* filename) {
    FILE* file = f_safetyOpen(filename, "r");

    domains ds = {.size = 0};
    while (fgets(_string_buffer, 256, file)) {
        getDomains_(_string_buffer, &ds);
        freeString(_string_buffer);
    }
    mergeEqualDomains(&ds);
    fclose(file);

    file = f_safetyOpen(filename, "w");
    for (int i = 0; i < ds.size; i++) {
        if (ds.data[i].amount >= 0)
            fprintf(file, "%d %s\n", ds.data[i].amount, ds.data[i].name);
    }
    fclose(file);
}


void test_getDomains_1_empty_file() {
    const char filename[] = "test_files/task_4_test_1.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fclose(file);

    getDomains(filename);

    file = f_safetyOpen(filename, "r");
    char dest[100] = "";
    fscanf(file, "%s", dest);

    fclose(file);

    assert(strcmp_(dest, "") == 0);
}


void test_getDomains_2_one_domain() {
    const char filename[] = "test_files/task_4_test_2.txt";
    FILE* file = f_safetyOpen(filename, "w");
    char s[100] = "900 discuss.codeforces.com";
    fprintf(file, "%s\n", s);
    fclose(file);

    getDomains(filename);

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


void test_getDomains_3_more_domain() {
    const char filename[] = "test_files/task_4_test_3.txt";
    FILE* file = f_safetyOpen(filename, "w");
    char s1[100] = "900 discuss.codeforces.com";
    char s2[100] = "69 mail.com";
    fprintf(file, "%s\n", s1);
    fprintf(file, "%s\n", s2);
    fclose(file);

    getDomains(filename);

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


void test_getDomains() {
    test_getDomains_1_empty_file();
    test_getDomains_2_one_domain();
    test_getDomains_3_more_domain();
}


// Дана m x n двоичная матрица matrix, верните количество подматриц , в 
// которых все единицы
int getSubmatrix(matrix mat) {
    int m = mat.rows;
    int n = mat.cols;
    int res = 0;

    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat.values[i][j])
                mat.values[i][j] += mat.values[i - 1][j];

    for (int i = 0; i < m; i++) {
        int stack[n];
        int top = -1;
        int sums[n + 1];
        sums[0] = 0;

        for (int j = 0; j < n; j++) {
            while (top != -1 && mat.values[i][stack[top]] >= mat.values[i][j])
                top--;
            if (top != -1) {
                int k = stack[top];
                sums[j + 1] = sums[k + 1] + mat.values[i][j] * (j - k);
            } else
                sums[j + 1] = mat.values[i][j] * (j + 1);
            stack[++top] = j;
        }

        for (int j = 0; j <= n; j++)
            res += sums[j];
    }
    return res;
}


void test_getSubmatrix_1_empty_matrix() {
    matrix m = createMatrixFromArray((int[]) {}, 0, 0);
    int result = getSubmatrix(m);

    freeMemMatrix(&m);

    assert(result == 0);
}


void test_getSubmatrix_2_unit_matrix() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);
    int result = getSubmatrix(m);

    freeMemMatrix(&m);

    assert(result == 1);
}


void test_getSubmatrix_3_more_element() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                            1, 1, 0,
                                            1, 1, 0}, 3, 3);
    int result = getSubmatrix(m);

    freeMemMatrix(&m);

    assert(result == 13);
}


void test_getSubmatrix() {
    test_getSubmatrix_1_empty_matrix();
    test_getSubmatrix_2_unit_matrix();
    test_getSubmatrix_3_more_element();
}

// Вам дан строковый шаблон длины n с нулевым индексом, состоящий 
// из символов «I», означающих увеличение, и «D», означающих 
// уменьшение.
// Строка num с нулевым индексом длины n + 1 создается с 
// использованием следующих условий:
// • num состоит из цифр '1'до '9', где каждая цифра используется не 
// более одного раза.
// • Если pattern[i] == 'I', то num[i] < num[i + 1].
// • Если pattern[i] == 'D', то num[i] > num[i + 1].
// Возвращает лексикографически наименьшую возможную строку num, 
// соответствующую условиям.
#define ASCII_SHIFT 48

void generateNums(const char* filename) {
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FILE* file = f_safetyOpen(filename, "r");

    char res[10] = "";
    char s[10] = "";
    fscanf(file, "%s", s);
    fclose(file);

    unsigned int len_s = strlen_(s);
    char* rec_ptr = res;
    char* read_ptr = s;
    unsigned int i_ind = 0;
    unsigned int d_ind = len_s;

    while (i_ind != d_ind) {
        if (*read_ptr == 'I') {
            *rec_ptr = (char) (num[i_ind] + ASCII_SHIFT);
            i_ind++;
        } else {
            *rec_ptr = (char) (num[d_ind] + ASCII_SHIFT);
            d_ind--;
        }

        read_ptr++;
        rec_ptr++;
    }

    *rec_ptr = (char) (num[i_ind] + ASCII_SHIFT);
    file = f_safetyOpen(filename, "w");
    fprintf(file, "%s", res);

    fclose(file);
}


void test_generateNums_1_empty_file() {
    const char filename[] = "test_files/task_6_test_1.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fclose(file);

    generateNums(filename);
    file = f_safetyOpen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 1);
}


void test_generateNums_2_unit_length() {
    const char filename[] = "test_files/task_6_test_2.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fprintf(file, "I");
    fclose(file);

    generateNums(filename);
    file = f_safetyOpen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 12);
}


void test_generateNums_3_average_length() {
    const char filename[] = "test_files/task_6_test_3.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fprintf(file, "IIID");
    fclose(file);

    generateNums(filename);
    file = f_safetyOpen(filename, "r");

    int nums;
    fscanf(file, "%d", &nums);

    fclose(file);

    assert(nums == 12354);
}


void test_generateNums() {
    test_generateNums_1_empty_file();
    test_generateNums_2_unit_length();
    test_generateNums_3_average_length();
}

// Вам дан целочисленный массив nums без дубликатов. Максимальное 
// двоичное дерево можно построить рекурсивно, nums используя 
// следующий алгоритм:
// 1. Создайте корневой узел, значение которого является 
// максимальным значением в nums.
// 2. Рекурсивно постройте левое поддерево на префиксе 
// подмассива слева от максимального значения .
// 3. Рекурсивно постройте правое поддерево на суффиксе 
// подмассива справа от максимального значения.
// Верните максимальное двоичное дерево, построенное из nums
int getMaxVector(vector* vec) {
    if (vec->size == 0)
        return (int) -1e4;

    int max = getVectorValue(vec, 0);
    for (int i = 1; i < vec->size; i++) {
        int x = getVectorValue(vec, i);
        if (max < x)
            max = x;
    }

    return max;
}


int getIndexVector(vector* vec, int x) {
    int i = -1;
    for (int j = 0; j < vec->size; j++)
        if (getVectorValue(vec, j) == x)
            i = j;
    return i;
}


void generateTree_(vector* nums, vector* result) {
    if (nums->size == 0) {
        pushBack(result, -1);
        return;
    } else if (nums->size == 1) {
        int x = getVectorValue(nums, 0);
        pushBack(result, x);
        return;
    }

    int mx = getMaxVector(nums);
    int ind = getIndexVector(nums, mx);
    pushBack(result, mx);

    vector left = createVector(ind + 1);
    for (int i = 0; i < ind; i++)
        pushBack(&left, getVectorValue(nums, i));

    vector right = createVector(nums->size - ind + 1);
    for (int i = ind + 1; i < nums->size; i++)
        pushBack(&right, getVectorValue(nums, i));

    generateTree_(&left, result);
    generateTree_(&right, result);

    deleteVector(&left);
    deleteVector(&right);
}


vector generateTree(vector* v) {
    vector result = createVector(32);
    generateTree_(v, &result);

    return result;
}


void test_generateTree_1_empty_file() {
    vector v = createVector(12);
    v = generateTree(&v);

    assert(getVectorValue(&v, 0) == -1);

    deleteVector(&v);
}


void test_generateTree_2_one_element() {
    vector v = createVector(12);
    pushBack(&v, 3);
    v = generateTree(&v);

    assert(getVectorValue(&v, 0) == 3);

    deleteVector(&v);
}


void test_generateTree_3_random_element() {
    vector v = createVector(12);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    pushBack(&v, 6);
    pushBack(&v, 0);
    pushBack(&v, 5);

    v = generateTree(&v);

    assert(getVectorValue(&v, 0) == 6);
    assert(getVectorValue(&v, 1) == 3);
    assert(getVectorValue(&v, 2) == -1);
    assert(getVectorValue(&v, 3) == 2);
    assert(getVectorValue(&v, 4) == -1);
    assert(getVectorValue(&v, 5) == 1);
    assert(getVectorValue(&v, 6) == 5);
    assert(getVectorValue(&v, 7) == 0);
    assert(getVectorValue(&v, 8) == -1);

    deleteVector(&v);
}


void test_generateTree() {
    test_generateTree_1_empty_file();
    test_generateTree_2_one_element();
    test_generateTree_3_random_element();
}


// Вам даны строка s и целочисленный массив indices одинаковой длины. 
// Строка s будет перетасована таким образом, что символ в позиции [i] 
// переместится в перетасованную строку indices[i] 
// Верните перетасованную строку
void rearrangeString_(const char* s, char* res, const int a[], const int n) {
    for (int i = 0; i < n; i++)
        res[i] = s[a[i]];
}


void rearrangeString(const char* filename) {
    FILE* file = f_safetyOpen(filename, "r");

    char s[1024] = "";
    fscanf(file, "%s", s);
    size_t len = strlen_(s);
    int* numbers = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
        fscanf(file, "%d", numbers + i);
    fclose(file);

    char res[1024] = "";
    rearrangeString_(s, res, numbers, len);

    file = f_safetyOpen(filename, "w");

    fprintf(file, "%s", res);
    fclose(file);

    free(numbers);
}


void test_rearrangeString_1_empty_file() {
    const char filename[] = "test_files/task_8_test_1.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fclose(file);

    rearrangeString(filename);

    file = f_safetyOpen(filename, "r");
    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "") == 0);
}


void test_rearrangeString_2_one_element() {
    const char filename[] = "test_files/task_8_test_2.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fprintf(file, "s\n");
    fprintf(file, "0");
    fclose(file);

    rearrangeString(filename);

    file = f_safetyOpen(filename, "r");
    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "s") == 0);
}


void test_rearrangeString_3_more_element() {
    const char filename[] = "test_files/task_8_test_3.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fprintf(file, "abap\n");
    fprintf(file, "0 3 2 1");
    fclose(file);

    rearrangeString(filename);

    file = f_safetyOpen(filename, "r");
    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "apab") == 0);
}


void test_rearrangeString() {
    test_rearrangeString_1_empty_file();
    test_rearrangeString_2_one_element();
    test_rearrangeString_3_more_element();
}


// В файле записана последовательность целых чисел. Создать файл, 
// состоящий из чисел данного файла, значения которых меньше N. 
// Имена файлов и величина N задаются в командной строке. 
void filterNums(const char* filename, const int n) {
    FILE* file = f_safetyOpen(filename, "r");

    int x;
    vector v = createVector(16);
    while (fscanf(file, "%d ", &x) == 1)
        if (x < n)
            pushBack(&v, x);

    fclose(file);

    file = f_safetyOpen(filename, "w");
    for (int i = 0; i < v.size; i++) {
        x = getVectorValue(&v, i);
        fprintf(file, "%d ", x);
    }
    fprintf(file, "\n");

    fclose(file);
}


void test_filterNums_1_empty_file() {
    const char filename[] = "test_files/task_9_test_1.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fclose(file);

    filterNums(filename, 5);

    file = f_safetyOpen(filename, "r");
    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "") == 0);
}


void test_filterNums_2_unit_file() {
    const char filename[] = "test_files/task_9_test_2.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fprintf(file, "1");
    fclose(file);

    filterNums(filename, 5);

    file = f_safetyOpen(filename, "r");
    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "1") == 0);
}


void test_filterNums_3_sequence_file() {
    const char filename[] = "test_files/task_9_test_3.txt";
    FILE* file = f_safetyOpen(filename, "w");
    fprintf(file, "3 4 1 2 5 6 7");
    fclose(file);

    filterNums(filename, 5);

    file = f_safetyOpen(filename, "r");
    char res[100] = "";
    
    fscanf(file, "%s", res);
    assert(strcmp_(res, "3") == 0);
    fscanf(file, "%s", res);
    assert(strcmp_(res, "4") == 0);
    fscanf(file, "%s", res);
    assert(strcmp_(res, "1") == 0);
    fscanf(file, "%s", res);
    assert(strcmp_(res, "2") == 0);

    fclose(file);
}


void test_filterNums() {
    test_filterNums_1_empty_file();
    test_filterNums_2_unit_file();
    test_filterNums_3_sequence_file();
}


// Написать программу, выдающую на экран содержимое файла 
// порциями по N строк: каждая последующая порция выдается после 
// нажатия клавиш Ctrl+C. Имя файла и величина N задаются в 
// командной строке.
void pariallyOutputFile(const char* filename, const int n) {
    FILE *file = f_safetyOpen(filename, "r");
    char line[127];
    size_t count = 0;

    while (fgets(line, 127, file) != NULL) {
        printf("%s", line);
        count++;

        if (count == n){
            printf("Please, press Ctrl+C\n");
            while (getch() != 3);
        }
    }

    fclose(file);
}


// Дан словарь из N различных слов, состоящих из строчных английских 
// букв. Вам приходит Q запросов, i-й из которых состоит из строки pi из 
// строчных английских букв и числа ki. В ответ на i-й запрос вы должны 
// вывести ki-е в лексикографическом порядке слово из словаря среди слов, 
// имеющих pi в качестве префикса. 
#define MAX_REQUEST 128


typedef struct request {
    WordDescriptor sequence;
    int position;
} request;


typedef struct requests {
    request request[MAX_REQUEST];
    size_t size;
} requests;


void freeRequests(requests* rs) {
    for (int i = 0; i < rs->size; i++) {
        rs->request[i].position = 0;
        rs->request[i].sequence.begin = NULL;
        rs->request[i].sequence.end = NULL;
    }

    rs->size = 0;
}


void autoCompletion(const char* filename) {
    FILE* file = f_safetyOpen(filename, "r");

    long long int n, q;
    fscanf(file, "%lld", &n);
    fscanf(file, "%lld", &q);

    _bag.size = 0;
    char* begin = _string_buffer;
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", begin);
        getWordWithoutSpace(begin, &_bag.words[_bag.size]);
        begin = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    requests rs = {.size = 0};
    for (int i = 0; i < q; i++) {
        fscanf(file, "%d", &rs.request[i].position);
        fscanf(file, "%s", begin);
        getWordWithoutSpace(begin, &rs.request[i].sequence);
        begin = rs.request[i].sequence.end + 1;
        rs.size++;
    }

    fclose(file);

    file = f_safetyOpen(filename, "w");

    for (int i = 0; i < q; i++) {
        int amount = 0;
        for (int j = 0; j < n; j++) {
            if (isSubWord(rs.request[i].sequence, _bag.words[j])) {
                amount++;
                if (amount == rs.request[i].position)
                    fprintf(file,"%d\n", j + 1);
            }
        }
        if (amount < rs.request[i].position)
            fprintf(file,"-1\n");
    }

    fclose(file);

    freeString(_string_buffer);
    freeBag(&_bag);
    freeRequests(&rs);
}


void test_autoCompletion_1_empty_file() {
    const char filename[] = "test_files/task_11_test_1.txt";
    FILE* file = fopen(filename, "w");
    int n = 0;
    int q = 0;
    fprintf(file, "%d %d \n", n, q);
    fclose(file);

    autoCompletion(filename);

    file = fopen(filename, "r");
    char res[100] = "";
    fgets(res, 100, file);
    fclose(file);

    assert(strcmp_(res, "") == 0);
}


void test_autoCompletion_2_zero_q() {
    const char filename[] = "test_files/task_11_test_2.txt";
    FILE* file = fopen(filename, "w");
    int n = 3;
    int q = 0;
    fprintf(file, "%d %d \n", n, q);
    fprintf(file, "aa\n");
    fprintf(file, "d\n");
    fprintf(file, "mamama\n");
    fclose(file);

    autoCompletion(filename);

    file = fopen(filename, "r");
    char res[100] = "";
    fgets(res, 100, file);
    fclose(file);

    assert(strcmp_(res, "") == 0);
}


void test_autoCompletion_3_different_element() {
    const char filename[] = "test_files/task_11_test_3.txt";
    FILE* file = fopen(filename, "w");
    int n = 10;
    int q = 3;
    fprintf(file, "%d %d \n", n, q);
    fprintf(file, "aa    \n");
    fprintf(file, "aaa   \n");
    fprintf(file, "aab   \n");
    fprintf(file, "ab    \n");
    fprintf(file, "abc   \n");
    fprintf(file, "ac    \n");
    fprintf(file, "ba    \n");
    fprintf(file, "daa   \n");
    fprintf(file, "dab   \n");
    fprintf(file, "dadba \n");
    fprintf(file, "4 a   \n");
    fprintf(file, "2 da  \n");
    fprintf(file, "4 da  \n");
    fclose(file);

    autoCompletion(filename);

    file = fopen(filename, "r");
    int n1, n2, n3;
    fscanf(file, "%d\n", &n1);
    fscanf(file, "%d\n", &n2);
    fscanf(file, "%d\n", &n3);
    fclose(file);

    assert(n1 == 4);
    assert(n2 == 9);
    assert(n3 == -1);
}


void test_autoCompletion() {
    test_autoCompletion_1_empty_file();
    test_autoCompletion_2_zero_q();
    test_autoCompletion_3_different_element();
}


void tests() {
    test_fillMatrix();
    test_gameLife();
    test_medianFilter();
    test_getDomains();
    test_getSubmatrix();
    test_generateNums();
    test_generateTree();
    test_rearrangeString();
    test_filterNums();
    test_autoCompletion();
}