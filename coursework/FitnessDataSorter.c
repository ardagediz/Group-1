#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int compareFitnessData(const void *a, const void *b) {
    FitnessData *dataA = (FitnessData *)a;
    FitnessData *dataB = (FitnessData *)b;
    return dataB->steps - dataA->steps; // Sort in descending order
}

int main() {
    char filename[100];
    printf("Enter Filename: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: invalid file\n");
        return 1;
    }

    FitnessData data[1000]; // Adjust size as needed
    int count = 0;
    char line[100];
    
    while (fgets(line, sizeof(line), file)) {
        tokeniseRecord(line, ',', data[count].date, data[count].time, &data[count].steps);

        if (strcmp(data[count].date, "") == 0 || strcmp(data[count].time, "") == 0 || data[count].steps <= 0) {
            printf("Error: invalid data in file\n");
            fclose(file);
            return 1;
        }
        
        
        count++;
    }

    qsort(data, count, sizeof(FitnessData), compareFitnessData);

    // Create output filename
    char outputFilename[104];
    strcpy(outputFilename, filename);
    strcat(outputFilename, ".tsv");

    FILE *outfile = fopen(outputFilename, "w");
    if (!outfile) {
        printf("Error creating output file\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outfile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(file);
    fclose(outfile);

    printf("Data sorted and written to %s\n", outputFilename);

    return 0;
}
