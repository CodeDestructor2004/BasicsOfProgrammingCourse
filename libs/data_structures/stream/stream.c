#include <stdio.h>
#include "..\matrix\matrix.c"


int** addOneToMatrix(size_t size, int** queries, int num_queries) {
    int **matrix = (int**) malloc(size * sizeof(int*));

    for (size_t i = 0; i < size; i++) {
        matrix[i] = (int*) calloc(size, sizeof(int));
    }

    for (size_t i = 0; i < num_queries; i++) {
        int row1 = queries[i][0];
        int col1 = queries[i][1];
        int row2 = queries[i][2];
        int col2 = queries[i][3];

        for (size_t x = row1; x <= row2; x++) {
            for (size_t y = col1; y <= col2; y++) {
                matrix[x][y]++;
            }
        }
    }

    return matrix;
}


void test_for_task_1() {
    printf("test_for_task_1: ");
    int n = 3;
    int num_queries = 2;
    int **queries;

    queries = (int **)malloc(num_queries * sizeof(int *));
    for (int i = 0; i < num_queries; i++) {
        queries[i] = (int *)malloc(4 * sizeof(int));
    }

    queries[0][0] = 1; queries[0][1] = 1; queries[0][2] = 2; queries[0][3] = 2;
    queries[1][0] = 0; queries[1][1] = 0; queries[1][2] = 1; queries[1][3] = 1;

    int **matrix_task_1 = addOneToMatrix(n, queries, num_queries);

    int **matrix_t;

    matrix_t = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix_t[i] = (int *)calloc(n, sizeof(int));
    }
    matrix_t[0][0] = 1; matrix_t[0][1] = 1; matrix_t[0][2] = 0;
    matrix_t[1][0] = 1; matrix_t[1][1] = 2; matrix_t[1][2] = 1;
    matrix_t[2][0] = 0; matrix_t[2][1] = 1; matrix_t[2][2] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(matrix_task_1[i][j] == matrix_t[i][j]);
        }
    }

    printf("OK\n");
}


void tests() {
    test_for_task_1();
}


int main() {
    tests();
}