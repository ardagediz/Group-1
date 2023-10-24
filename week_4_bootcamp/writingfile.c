#include <stdio.h>

int main()
{
    FILE *file = fopen("squares.dat", "w");
    if (file == NULL){
        perror("The action has failed");
        return 1;
    }

    int n;
    printf("Enter your number here: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        int square = i * i;
        fprintf(file, "The square of %d = %d\n", i, square);
    }
    return 0;
}



