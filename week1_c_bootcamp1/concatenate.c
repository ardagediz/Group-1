#include <stdio.h>

int main() {
    int arr1[3], arr2[3], result[6];
    int i;

    printf("Enter 3 integers for the first array: ");
    for (i = 0; i < 3; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 3 integers for the second array: ");
    for (i = 0; i < 3; i++) {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < 3; i++) {
        result[i] = arr1[i];          
        result[i + 3] = arr2[i];     

    printf("Concatenated array: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
