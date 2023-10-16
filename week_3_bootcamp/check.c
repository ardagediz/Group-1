#include <stdio.h>

int main() {
int number;

printf("Enter your positive, zero or negative number here: ");
scanf("%d", &number);

if (number > 0 )
    printf("Your number is positive");

else if (number < 0)
    printf("Your number is negative");

else
    printf("Your number is zero");

printf("\n");

    return 0;
}