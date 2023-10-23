#include <stdio.h>
#include <string.h>

int string_length(char string[])
{
    return strlen(string);
}

int main()
{
    char entry[100]; // assuming a max length of 99 characters + 1 for null terminator

    printf("Enter your string here: ");
    scanf("%99s", entry); // Read up to 99 characters to avoid overflow

    printf("Your string length is %d", str_len(entry));

    return 0;
}