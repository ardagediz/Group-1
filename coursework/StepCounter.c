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