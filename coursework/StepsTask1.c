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

    // Declare an array of char (string) to store each line from the file
char line[100];

// Declare an integer variable to count the number of records read
int record_count = 0;

// Declare an array of FITNESS_DATA structures to store the data
FITNESS_DATA data[1000];

// Loop through each line in the file until the end of the file is reached
while (fgets(line, sizeof(line), file)) {
    // Remove the newline character at the end of each line
    line[strcspn(line, "\n")] = 0;
    // Declare variables to store date, time, and steps after tokenizing the line
    char date[11], time[6], steps[5];
    // Call a function to tokenize the line and populate date, time, and steps
    tokeniseRecord(line, ",", date, time, steps);
    // Copying the date, time and steps into the correct field of the current record in the 'data' array
    strcpy(data[record_count].date, date);
    strcpy(data[record_count].time, time);
    data[record_count].steps = atoi(steps);

    // Increment the record count
    record_count++;
}

    fclose(file);

    // Outputting the number of records
    printf("Number of records in file: %d\n", record_count);

    // Outputting the first three records without extra spaces or newlines
    for (int i = 0; i < 3; i++) {
        printf("\n%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}
