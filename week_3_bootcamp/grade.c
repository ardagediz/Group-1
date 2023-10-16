#include <stdio.h>

int main() {

int grade;

printf("Enter what grade you received: ");
scanf("%d", &grade);

if (grade >= 70)
    printf("You achieved a distinction");

else if (grade >= 50)
    printf("You achieved a pass");

else 
    printf("You have failed:/");

printf("\n");

    return 0;
}