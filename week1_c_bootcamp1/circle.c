#include <stdio.h>
int main() {
    float pi, radius, area;

    printf("What is the radius of your circle: ");
    scanf("%f", &radius);
    pi = 3.142;
    area = pi * radius * radius;
    printf("The area is %.2f\n", area);

    return 0;

}