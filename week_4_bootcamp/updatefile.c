#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("numbers.dat", "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return 1;
    }

    fprintf(file, "21.5\n");
    fprintf(file, "3.14159265\n");
    fclose(file);

    file = fopen("numbers.dat", "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return 1;
    }

    char line[50];
    float sum = 0;
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        float num = atof(line);
        sum += num;
        count++;
    }
    fclose(file);

    float average = sum / count;

    file = fopen("numbers.dat", "a");
    if (file == NULL) {
        perror("Failed to open file for appending");
        return 1;
    }

    fprintf(file, "%.6f\n", average);
    fclose(file);

    printf("Average %.6f has been appended to the file.\n", average);

    return 0;
}

