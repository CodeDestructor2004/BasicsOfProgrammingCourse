#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

int maxValue(int value1, int value2);

int minValue(int value1, int value2);

int findMax(int* array, int size);

int findMin(int* array, int size);

bool isSet(const long long* array, int size);

long long getSum(const int* array, int size);

int countUniques(long long* array, int size);

bool isNonDescending(const int* array, int size);

int countValues(const int* array, int size, int value);

#endif //UTIL_H
