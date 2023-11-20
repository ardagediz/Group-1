#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"


void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }


int main() {
    char choice;
    char filename[filename_length];
    char line[filename_length];

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

        while ((getchar()) != '\n');

        switch (choice) {
            case 'A': 
                printf("Please specify the name of the file name to be imported: ");
                fgets(filename, filename_length, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline character
                FILE *file = fopen(filename, "r");
                if (!file) {
                    printf("Error: could not open file\n");
                    return 1;
                } else {
                    printf("File '%s' opened successfully.", filename);
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

                while (fgets(line, filename_length, file) != NULL) {
                    recordCount++;
                }           

                fclose(file);
                printf("The record count is %d", recordCount);
                break;
            

            case 'C': {
                FITNESS_DATA record = {0}, minRecord = {0};
                int minSteps = 1000000; // Initialize to a large number
                int isFirstRecord = 1; // Flag to check if it's the first record
                
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: could not open file\n");
                    return 1;
                }


                while (fgets(line, filename_length, file) != NULL) {
                    tokeniseRecord(line, ",", record.date, record.time, line);
                    record.steps = atoi(line); // Convert steps to integer
                }

                if (isFirstRecord || record.steps < minSteps) {
                    minSteps = record.steps;
                    minRecord = record;
                    isFirstRecord = 0;
                }

                if (!isFirstRecord) {
                printf("Fewest steps: %s %s", minRecord.date, minRecord.time);
                } else{
                    printf("No records found.");
                }
                
                fclose(file);
                break;
            }

            case 'D': {
                FITNESS_DATA record = {0}, maxRecord = {0};
                int maxSteps = 1;
                int isFirstRecord = 1;
                
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: File could not be opened successfully");
                    return 1;
                }


                while (fgets(line, filename_length, file) != NULL) {
                    tokeniseRecord(line, ",", record.date, record.time, line);
                    record.steps = atoi(line); // Convert steps to integer
                }

                if (isFirstRecord || record.steps > maxSteps) {
                    maxSteps = record.steps;
                    maxRecord = record;
                    isFirstRecord = 0;
                }


                if (!isFirstRecord){
                printf("Largest Steps: %s %s", maxRecord.date, maxRecord.time);
                } else {
                    printf("No records found.");
                }
                
                fclose(file);
                break;
            }
            
            case 'E': {             
                FITNESS_DATA record = {0};
                int totalSteps = 0, recordCount = 0;
                
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: File could not be opened successfully");
                    return 1;
                } 
                
                
                while (fgets(line, filename_length, file) != NULL) {
                    tokeniseRecord(line, ",", record.date, record.time, line);
                    record.steps = atoi(line); // Convert steps to integer
                    totalSteps += record.steps;
                    recordCount++;
                }

                if (recordCount > 0){
                double meanSteps = (double) totalSteps / recordCount;
                printf("The mean steps is %.2f", meanSteps);
                } else {
                     printf("No records were found to calculate the mean.");
                }
                break;
                fclose(file);
            
            }

            case 'F': {
                FITNESS_DATA record = {0}, startPeriod = {0}, endPeriod = {0};
                int maxDuration = 0;
                int currentDuration = 0;
                int periodStarted = 0;
                
                file = fopen(filename, "r");
                if (!file) {
                    printf("Error: File could not be opened successfully");
                    break;
                }


                while (fgets(line, filename_length, file) != NULL) {
                    tokeniseRecord(line, ",", record.date, record.time, line);
                    record.steps = atoi(line);       

                    if (record.steps > 500) {
                        if (!periodStarted) {
                            startPeriod = record;
                            periodStarted = 1;
                        }
                        currentDuration ++;
                    } else if(periodStarted) {
                        if (currentDuration > maxDuration) {
                        maxDuration = currentDuration;
                        endPeriod = record;
                        }
                        periodStarted = 0;
                        currentDuration = 0;
                    }
                }
                    if (periodStarted && currentDuration > maxDuration) {
                        maxDuration = currentDuration;
                        endPeriod = record;
                }

                fclose(file);

                if (maxDuration > 0) {
                printf("Longest period start: %s %s\n", startPeriod.date, startPeriod.time);
                printf("Longest period end: %s %s", endPeriod.date, endPeriod.time);
                } else {
                    printf("No continuous period above 500 steps found.\n");
                }
                break;
            }

            case 'Q': 
                printf("Exiting the program.\n");
                return 0;
            

            default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
    return 0;
}
