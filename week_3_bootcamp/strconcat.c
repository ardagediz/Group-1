#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatStrings(const char* str1, const char* str2){
    size_t length1 = strlen(str1);
    size_t length2 = strlen(str2);

    char* result = (char*)malloc(length1  + length2 + 1);

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main()
{
    char *str1 = "Hello, ";
    char *str2 = "world!";

    char *concatenated = concatStrings(str1, str2);
    printf("%s\n", concatenated);

    free(concatenated);

    return 0;
}