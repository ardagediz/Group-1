#include <stdio.h>

float fahr_celcius(float fahr_temp)
{
    float cel_temp;
    cel_temp = (fahr_temp - 32)/1.8;
    return cel_temp;
}

float fahr_kelvin(float fahr_temp)
{
    float kel_temp;
    kel_temp = fahr_celcius(fahr_temp) + 273.15;
    return kel_temp;
}

int main()
{
    float fahrenheit;
    char option;
    
    printf("This is a calculator to convert from either fahrenheit to celcius or fahrenheit to kelvin\n");
    printf("Enter your fahrenheit here: ");
    scanf("%f", &fahrenheit);

    printf("\n");
    printf("Enter 'A' to convert fahrenheit to celcius\n");
    printf("Enter 'B' to convert in to kelvin\n");
    printf("Enter 'Q' to quit\n");

    scanf(" %c", &option);

    switch(option)
    {
        case 'A': printf("Your farenheit, %f, converted to celcius is %f", fahrenheit, fahr_celcius(fahrenheit));
                  break;
        case 'B': printf("Your farenheit, %f, converted to kelvin is %f", fahrenheit, fahr_celcius(fahrenheit));
                  break;
        case 'Q': break;
        default: break;
}
return 0;
}