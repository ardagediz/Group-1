#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// This is your helper function. Do not change it in any way.
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) strcpy(date, token);
    token = strtok(NULL, delimiter);
    if (token != NULL) strcpy(time, token);
    token = strtok(NULL, delimiter);
    if (token != NULL) strcpy(steps, token);
    free(inputCopy);
}

int main() {
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        perror("Failed\n");
        return 1;
    }

char line[100];
int record_count = 0;
FITNESS_DATA data[1000];

while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = 0;
        
    tokeniseRecord(line, ",", data[record_count].date, data[record_count].time, line);
    data[record_count].steps = atoi(line);
        
    record_count++;
}

fclose(file);
printf("Number of records in file: %d", record_count);

for (int i = 0; i < 3; i++) {
    printf("\n%s/%s/%d", data[i].date, data[i].time, data[i].steps);
}

return 0;
}
