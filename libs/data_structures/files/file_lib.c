#include "file_lib.h"


void copyFileContent(const char* source_file, const char* destination_file) {
    FILE *source, *destination;
    char ch;

    source = f_safetyOpen(source_file, "r");
    if (source == NULL)
        return;

    destination = f_safetyOpen(destination_file, "w");
    if (destination == NULL) {
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
    FILE *f1 = f_safetyOpen(file1, "r");
    FILE *f2 = f_safetyOpen(file2, "r");

    if (f1 == NULL || f2 == NULL)
        return 0;

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


FILE* f_safetyOpen(const char *path, const char *mode) {
    FILE *output;
    if (mode == "r" || mode == "w" || mode == "a" 
    || mode == "rb" || mode == "wb" || mode == "ab" 
    || mode == "r+" || mode == "w+" || mode == "a+" 
    || mode == "r+b" || mode == "w+b" || mode == "a+b" 
    || mode == "rt" || mode == "wt" || mode == "at" 
    || mode == "r+t" || mode == "w+t" || mode == "a+t") {
        output = fopen(path, mode);
        if (output == NULL)
            printf("Error: '%s' - not aviable in mode %s", path, mode);
    }
    else {
        printf("Error: incorrect mode: %s\n", mode);
        output = NULL;
    }

    return output;
}