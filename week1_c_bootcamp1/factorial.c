#include <stdio.h>
int main() {
    int number, start = 1, x;
    printf("Enter your whole postive number here: ");
    scanf("%d", &number);

    for (x=1; x<=number; x++);
    start = start * number;

    printf("The factorial is %d is: %d", number, start);

    return 0;

}