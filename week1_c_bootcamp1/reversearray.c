#include <stdio.h>
#include <string.h>

int main() {
int arr[5];
int temp;

printf("Enter 5 numbers to be reversed: ");

for (int i = 0; i <5; i ++)
{
    scanf("%d", &arr[i]);
}

for (int i = 0; i < 2; i ++)
{
    temp = arr[i];
    arr[i] = arr[4 - i];
    arr[4 - i] = temp;
}

printf("The reversed array is: ");
for (int i = 0; i < 5; i++) 
{
    printf("%d ", arr[i]);
}
    return 0;
}