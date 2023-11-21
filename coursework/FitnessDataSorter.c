#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

int main() {
    char filename[100], newFilename[104];
    FitnessData data[1000];
    int count = 0;

    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: invalid file\n");
        return 1;
    }

    while (fscanf(file, "%10[^,],%5[^,],%d\n", data[count].date, data[count].time, &data[count].steps) == 3) {
        count++;
    }

    if (feof(file) == 0) { // Check if end of file was reached or if there was an error
        printf("Error: invalid data in file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    // Simplified sorting using double for loop
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (data[i].steps < data[j].steps) {
                FitnessData temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    strcpy(newFilename, filename);
    strcat(newFilename, ".tsv");
    file = fopen(newFilename, "w");
    if (!file) {
        printf("Error writing to file\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(file);

    printf("Data sorted and written to %s\n", newFilename);

    return 0;
}
