#include "util.h"
#include <stdlib.h>


int maxValue(int value1, int value2) {
    return value1 >= value2 ? value1 : value2;
}


int minValue(int value1, int value2) {
    return value1 >= value2 ? value2 : value1;
}


int getMax(int* array, int size) {
    int max_value = array[0];

    for (int i = 1; i < size; ++i) {
        max_value = maxValue(max_value, array[i]);
    }

    return max_value;
}

int getMin(int* array, int size) {
    int min_value = array[0];

    for (int i = 1; i < size; ++i) {
        min_value = minValue(min_value, array[i]);
    }

    return min_value;
}

bool isSet(const long long* array, int size) {
    for (int i = 0; i < size; ++i) {
        long long value = array[i];

        for (int j = i + 1; j < size; j++) {
            if (i == j) continue;

            if (value == array[j]) return false;
        }
    }

    return true;
}

long long getSum(const int* array, int size) {
    long long sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return sum;
}

static int compareLL(const void* left, const void* right) {
    long long left_value = *((const long long*) left);
    long long right_value = *((const long long*) right);

    if (left_value > right_value) {
        return 1;
    }

    return (left_value == right_value) ? 0 : -1;
}

int countUniques(long long* array, int size) {
    if (size == 0) {
        return 0;
    }

    qsort(array, size, sizeof(long long), compareLL);

    int count = 0;

    for (int i = 0; i < size; ++i) {
        long long value = array[i];
        bool found = false;

        for (int j = i + 1; j < size; ++j) {
            long long current = array[j];

            if (current == value) {
                found = true;
                break;
            } else if (value > current) {
                break;
            }
        }

        if (!found) {
            count++;
        }
    }

    return count;
}

bool isNonDescending(const int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (array[i + 1] < array[i]) {
            return false;
        }
    }

    return true;
}

int countValues(const int* array, int size, int value) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            count++;
        }
    }

    return count;
}
