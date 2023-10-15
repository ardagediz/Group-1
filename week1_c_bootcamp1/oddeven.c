#include <stdio.h>
int main() {
    int number;
    
    printf("Enter a whole number here: ");
    scanf("%d", &number);
    
    if (number % 2 == 0) {
    printf("You entered a even number!"); 
    }  else {
    printf("You have a odd number!");
    }

    return 0;
}