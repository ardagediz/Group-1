#include <stdio.h>

int main() {

int arr[6];
int i, j;

printf("Enter 6 integers here with one or two repeats: ");

for (i = 0; i < 6; i ++)
{
    scanf("%d", &arr[i]);
}

printf("\n");

printf("Duplicate elements are: ");
for (i = 0; i < 6; i++) {
    for (j = i + 1; j < 6; j++) {
        if (arr[i] == arr[j]) {
            printf("%d ", arr[i]);
            break;
        }
    }
}

    return 0;
}