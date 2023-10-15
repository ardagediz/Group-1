#include <stdio.h>
int main() {

    int arr[5];
    int sum = 0;

    printf("Enter 5 integers: ");

    for (int i = 0; i < 5; i ++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i ++)
    {
        sum += arr[i];
    }

    printf("Sum of all elements is equal to: %d\n", sum);

    return 0;

}