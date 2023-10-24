#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("squares.dat", "r");
    if (file == NULL) {
        perror("The action has failed");
        return 1;
    }

    char lines[100];
    int sumofsquares = 0;
    int counteroflines = 0;

    while (fgets(lines, sizeof(lines), file)) {  
        char *ptr = lines;
        while (*ptr != '=') {
            ptr++; 
        }
        
        ptr += 2;
        int square = atoi(ptr);  
        sumofsquares += square;  
        counteroflines++;  
    }
    fclose(file);

    float average = (float)sumofsquares / counteroflines;  
    printf("The average of the sum of squares is %.2f\n", average);

    return 0;
}
