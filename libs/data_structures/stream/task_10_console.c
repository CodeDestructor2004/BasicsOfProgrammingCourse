#include "stream.c"


void main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("Too many arguments supplied.\n");
        return;
    }
    else if (argc < 3) {
        printf("Some arguments expected.\n");
        return;
    }

    char filename[100];
    strcpy(filename, argv[1]);
    const int argument_value = (int) argv[2];
    printf("File path: %s\n", filename);
    printf("Argument: %d\n", argument_value);

    FILE* file = f_safetyOpen(filename, "w");

    pariallyOutputFile(filename, argument_value);
    fclose(file);

    return;
}