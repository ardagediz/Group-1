#include <stdio.h>

int main() {
int temp;

printf("What is the temperature: ");
scanf("%d", &temp);

if (temp >= -10 && temp <= 40)
printf("Your temperature is within the range of -10 to 40 degrees Celsius");

else 
printf("You are not valid!");

printf("\n");

    return 0;
}