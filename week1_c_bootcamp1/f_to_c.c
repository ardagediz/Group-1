#include <stdio.h>

int main() {
float farenheit, celcius;
printf("Enter your farenheit here: ");
scanf("%f", &farenheit);

celcius = (farenheit - 32) * 5 / 9;

printf("Converted is: %.2f\n", celcius);

return 0;
}
