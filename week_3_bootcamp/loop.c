#include <stdio.h>

int main() {
    int number;

    printf("Enter a number (or -1 to terminate): ");
    scanf("%d", &number);

    if (number == -1) {
        printf("Termination value entered.\n");
    } else {

        if (number >= 0 && number <= 100) {
            printf("The number %d is within the range of 0 to 100.\n", number);
             main();  
        } else {
            printf("The number %d is out of the range (0-100).\n", number);
             main();  
        }
    }

    return 0;
}
