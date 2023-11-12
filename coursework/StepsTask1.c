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
    // Open the fitness data CSV file
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        perror("Failed\n");
        return 1;
    }


// Declare variables for line reading and record counting
char line[100];
int record_count = 0;
// Declare an array to store the fitness data
FITNESS_DATA data[1000];

// Read and tokenize each line in the file
while (fgets(line, sizeof(line), file)) {
    // Tokenize the line and populate the data array
    tokeniseRecord(line, ",", data[record_count].date, data[record_count].time, line);
    data[record_count].steps = atoi(line);
        
    // Increment the record counter
    record_count++;
}

// Close the file
fclose(file);

// Output the number of records read from the file
printf("Number of records in file: %d\n", record_count);

// Output the first three records in the required format
for (int i = 0; i < 3; i++) {
    printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
}

return 0;
}
