#include <stdio.h>
#include "..\matrix\matrix.c"

// Вам дано положительное целое число n, указывающее, что изначально 
// у нас есть целочисленная матрица n x n, заполненная нулями.
// Вам также дан двумерный целочисленный массив query. Для 
// каждого необходимо выполнить следующую операцию: query[i] = 
// [row1i, col1i, row2i, col2i]
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

// Доска состоит из m x n сетки ячеек, где каждая ячейка имеет 
// начальное состояние: живое (обозначается значком 1) или 
// мертвое (обозначается значком 0). Каждая ячейка 
// взаимодействует со своими восемью соседями 
// (горизонтальными, вертикальными, диагональными), используя 
// следующие четыре правила:
int countNeighbors(int** board, size_t rows, size_t cols, int row, int col) {
    int liveNeighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int r = row + i, c = col + j;
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                liveNeighbors += board[r][c];
            }
        }
    }
}

void nextGeneration(int** board, size_t rows, size_t cols) {
    int **next_board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        next_board[i] = (int *)malloc(cols * sizeof(int));
    }
    

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(board, rows, cols, i, j);

            if (board[i][j] == 1) 
                next_board[i][j] = ((neighbors < 2) || (neighbors > 3)) ? 0 : 1;
            else
                next_board[i][j] = (neighbors == 3) ? 1 : 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        free(board[i]);
        board[i] = next_board[i];
        next_board[i] = NULL;
    }
    free(next_board);
}


void test_for_task_2() {
    printf("test_for_task_2: \n");
    int cols_amount = 3;
    int rows_amount = 4;
    int **board = (int **)malloc(rows_amount * sizeof(int *));
    for (int i = 0; i < rows_amount; i++) {
        board[i] = (int *)malloc(cols_amount * sizeof(int));
    }
    
    board[0][0] = 0; board[0][1] = 1; board[0][2] = 0;
    board[1][0] = 0; board[1][1] = 0; board[1][2] = 1;
    board[2][0] = 1; board[2][1] = 1; board[2][2] = 1;
    board[3][0] = 0; board[3][1] = 0; board[3][2] = 0;

    nextGeneration(board, rows_amount, cols_amount);
    int **board_t = (int **)malloc(rows_amount * sizeof(int *));
    for (int i = 0; i < rows_amount; i++) {
        board_t[i] = (int *)malloc(cols_amount * sizeof(int));
    }

    board_t[0][0] = 0; board_t[0][1] = 0; board_t[0][2] = 0;
    board_t[1][0] = 1; board_t[1][1] = 0; board_t[1][2] = 1;
    board_t[2][0] = 0; board_t[2][1] = 1; board_t[2][2] = 1;
    board_t[3][0] = 0; board_t[3][1] = 1; board_t[3][2] = 0;

    for (int i = 0; i < rows_amount; ++i) {
        for (int j = 0; j < cols_amount; ++j) {
            assert(board[i][j] == board_t[i][j]);
        }
    }

    printf("OK\n");
}


void tests() {
    test_for_task_1();
    test_for_task_2();
}


int main() {
    tests();
}