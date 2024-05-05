#include "file_lib.h"


void copyFileContent(const char* source_file, const char* destination_file) {
    FILE *source, *destination;
    char ch;

    source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Error: source file couldn't be opened\n");
        return;
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        printf("Error: destination file couldn't be opened\n");
        fclose(source);
    return;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
}


int assert_txt(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Error\n");
        return 0;
    }

    char buffer1[MAX_FILE_SIZE];
    char buffer2[MAX_FILE_SIZE];

    while (fgets(buffer1, MAX_FILE_SIZE, f1) != NULL && fgets(buffer2,
    MAX_FILE_SIZE, f2) != NULL) {
        if (strcmp(buffer1, buffer2) != 0) {
            fclose(f1);
            fclose(f2);
            return 0;
        }
    }
    fclose(f1);
    fclose(f2);
    return 1;
}