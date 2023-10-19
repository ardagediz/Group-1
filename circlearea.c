#include <stdio.h>

float circle_area(float pi, float radius)
{
    int cir_area = (pi * radius * radius);
    return cir_area;
}

float rad;

int main(){
printf("Enter the radius of your circle here: ");
scanf("%f", &rad);

printf("Your area is %f", circle_area(3.14, rad));

return 0;
}