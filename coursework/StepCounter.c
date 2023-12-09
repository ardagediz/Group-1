#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "FitnessDataStruct.h"

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    free(inputCopy);
}

FILE* openFile(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file\n");
        return NULL;
    }
    return file;
}

int main() {
    char choice;
    char filename[filename_length];
    char line[filename_length];
    FILE *file;

    while (1) {
        printf("\nMenu:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        printf("Enter your choice: ");
        choice = getchar();

        while ((getchar()) != '\n'); // Clear the input buffer

        switch (choice) {
            case 'A': 
                printf("Please specify the name of the file name to be imported: ");
                fgets(filename, filename_length, stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline character
                file = openFile(filename);
                if (file) {
                    printf("File '%s' opened successfully.\n", filename);
                    fclose(file);
                } else {
                    return 1;
                }
                break;

            case 'B': 
                file = openFile(filename);
                if (file) {
                    int recordCount = 0;
                    while (fgets(line, filename_length, file) != NULL) {
                        recordCount++;
                    }
                    fclose(file);
                    printf("Total records: %d\n", recordCount);
                } else {
                    return 1;
                }
                break;

            case 'C': {
                file = openFile(filename);
                if (file) {
                    FITNESS_DATA record, minRecord;
                    int minSteps = INT_MAX;
                    while (fgets(line, filename_length, file) != NULL) {
                        tokeniseRecord(line, ",", record.date, record.time, line);
                        record.steps = atoi(line);
                        if (record.steps < minSteps) {
                            minSteps = record.steps;
                            minRecord = record;
                        }
                    }
                    fclose(file);
                    if (minSteps != INT_MAX) {
                        printf("Fewest steps: %s %s\n", minRecord.date, minRecord.time);
                    } else {
                        printf("No records found.\n");
                    }
                } else {
                    return 1;
                }
                break;
            }

            case 'D': {
                file = openFile(filename);
                if (file) {
                    FITNESS_DATA record, maxRecord;
                    int maxSteps = 0;
                    while (fgets(line, filename_length, file) != NULL) {
                        tokeniseRecord(line, ",", record.date, record.time, line);
                        record.steps = atoi(line);
                        if (record.steps > maxSteps) {
                            maxSteps = record.steps;
                            maxRecord = record;
                        }
                    }
                    fclose(file);
                    if (maxSteps > 0) {
                        printf("Largest steps: %s %s\n", maxRecord.date, maxRecord.time);
                    } else {
                        printf("No records found.\n");
                    }
                } else {
                    return 1;
                }
                break;
            }

            case 'E': {
                file = openFile(filename);
                if (file) {
                    FITNESS_DATA record;
                    int totalSteps = 0, recordCount = 0;
                    while (fgets(line, filename_length, file) != NULL) {
                        tokeniseRecord(line, ",", record.date, record.time, line);
                        record.steps = atoi(line);
                        totalSteps += record.steps;
                        recordCount++;
                    }
                    fclose(file);
                    if (recordCount > 0) {
                        int meanSteps = (int) ((double) totalSteps / recordCount + 0.5); // Round to nearest integer
                        printf("Mean step count: %d\n", meanSteps);
                    } else {
                        printf("No records were found to calculate the mean.\n");
                    }
                } else {
                    return 1;
                }
                break;
            }

            case 'F': {
                file = openFile(filename);
                if (file) {
                    FITNESS_DATA record, startPeriod, endPeriod, longestStart, longestEnd;
                    int currentSteps, longestPeriod = 0, currentPeriod = 0, trackingPeriod = 0;

                    while (fgets(line, filename_length, file) != NULL) {
                        tokeniseRecord(line, ",", record.date, record.time, line);
                        currentSteps = atoi(line);

                        if (currentSteps > 500) {
                            if (!trackingPeriod) {
                                startPeriod = record;
                                trackingPeriod = 1;
                                currentPeriod = 1; // Start counting the period
                            } else {
                                currentPeriod++; // Continue the current period
                            }
                            endPeriod = record;
                        } else if (trackingPeriod) {
                            if (currentPeriod > longestPeriod) {
                                longestPeriod = currentPeriod;
                                longestStart = startPeriod;
                                longestEnd = endPeriod;
                            }   
                            trackingPeriod = 0;
                            currentPeriod = 0;
                        }
                    }

                    // Check at the end of file
                    if (trackingPeriod && currentPeriod > longestPeriod) {
                        longestStart = startPeriod;
                        longestEnd = endPeriod;
                    }

                    fclose(file);

                    if (longestPeriod > 0) {
                        printf("Longest period start: %s %s\n", longestStart.date, longestStart.time);
                        printf("Longest period end: %s %s\n", longestEnd.date, longestEnd.time);
                    } else {
                        printf("No period with steps over 500 found.\n");
                    }
                } else {
                    return 1;
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