#include <stdio.h>

int isPrime(int number)
{
if (number <= 1) return 0;
if (number == 2) return 1;
if (number == 3) return 1;

if (number % 2 == 0 || number % 3 == 0) return 0;

else if ((number + 1) / 6 == 0 || (number - 1) / 6 == 0) return 1;

}

int main()
{
int num;

printf("Enter your prime number here: ");
scanf("%d", &num);

if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
}
