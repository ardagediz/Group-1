#include <stdio.h>

int main() {
int number;

printf("Enter your number here: ");
scanf("%d", &number);


if (number % 4 == 0 && number % 5 == 0)
    printf("Your number is divisible by 4 and 5!");

else
    printf("Your number is not divisble by 4 and 5!");

printf("\n");

    return 0;
}