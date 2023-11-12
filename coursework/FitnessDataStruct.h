#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

// Define the struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Decalre the helper funtion
void tokeniseRecord(const char *input, const char *delimiter,char *date, char *time, char *steps);

#endif