#include <stdio.h>

float sphere_area(float radius, float pi)
{
    int sph_area;
    sph_area = 4 * pi * radius * radius;
    return sph_area;
}

float rad;

int main()
{
printf("Enter your radius here: ");
scanf("%f", &rad);

printf("Your area is %f", sphere_area(rad, 3.14));

return 0;
}