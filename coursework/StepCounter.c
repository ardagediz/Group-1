#include "FitnessDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    char choice;
    char filename[filename_length] = "FitnessData_2023.csv";
    FILE *file; // Declare file here for use in multiple cases

    while (1) {
        printf("\nMenu:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");

        printf("Enter your choice: ");
        choice = getchar();

        // Clear the input buffer
        while ((getchar()) != '\n');

        switch (choice) {
            case 'A':
                printf("Please enter the name of the data file: ");
                fgets(filename, filename_length, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline character
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: could not open file\n");
                    return 1;
                } else {
                    printf("File '%s' opened successfully.\n", filename);
                }
                fclose(file);
                break;

            case 'B':
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: could not open file\n");
                    return 1;
                }

                int recordCount = 0;
                char line[filename_length];

                while (fgets(line, filename_length, file) != NULL) {
                    recordCount++;
                }           

                fclose(file);
                printf("The record count is %d\n", recordCount);
                break;

            case 'C': {
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: could not open file\n");
                    return 1;
                }

                FITNESS_DATA record, minRecord;
                int minSteps = 1000000; // Initialize to a large number
                int isFirstRecord = 1; // Flag to check if it's the first record

                char line[filename_length];
                while (fgets(line, filename_length, file) != NULL) {
                    tokeniseRecord(line, ",", record.date, record.time, line);
                    record.steps = atoi(line); // Convert steps to integer

                if (isFirstRecord || record.steps < minSteps) {
                    minSteps = record.steps;
                    minRecord = record;
                    isFirstRecord = 0;
                }
            }

        fclose(file);

        if (!isFirstRecord) {
            printf("Fewest steps: %s %s\n", minRecord.date, minRecord.time);
        } else {
            printf("No records found.\n");
        }
        break;
        }
    }

}

    return 0;
}
