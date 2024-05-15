#ifndef FILE_LIB_H
#define FILE_LIB_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 100
#define MAX_FILE_SIZE 1024

// Копирует содержимое файла по адресу source_file в файл по адресу destination_file
void copyFileContent(const char* source_file, const char* destination_file);

// Сравнивает содержимое файла по адресу file1 с файлом по адресу file2
int assert_txt(const char *file1, const char *file2);

// Безопасно открывает файл по адерсу path в режиме mode
FILE* f_safetyOpen(const char *path, const char *mode);

#endif