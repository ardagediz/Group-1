#include <stdio.h>

float arithmetic_calculator(float num1, float num2, char operation) {
    if (operation == '+') {
        return num1 + num2;
    } else if (operation == '-') {
        return num1 - num2;
    } else if (operation == '*') {
        return num1 * num2;
    } else if (operation == '/') {
        if (num2 != 0) { // Check for division by zero
            return num1 / num2;
        } else {
            printf("Cannot divide by zero\n");
            return 0;
        }
    } else {
        printf("Invalid operation\n");
        return 0;
    }
}

int main() {
    float number1, number2;
    char option;

    printf("This is an arithmetic calculator for division, multiplication, addition, subtraction\n");

    printf("Enter your first number here: \n");
    scanf("%f", &number1);

    printf("Enter your second number here: ");
    scanf("%f", &number2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &option); 

    float result;

    switch(option) {
        case '+':
            result = arithmetic_calculator(number1, number2, '+');
            printf("The result of adding is: %.2f\n", result);
            break;
        case '-':
            result = arithmetic_calculator(number1, number2, '-');
            printf("The result of subtracting is: %.2f\n", result);
            break;
        case '*':
            result = arithmetic_calculator(number1, number2, '*');
            printf("The result of multiplying is: %.2f\n", result);
            break;
        case '/':
            result = arithmetic_calculator(number1, number2, '/');
            if (number2 != 0) {
                printf("The result of dividing is: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operation selected.\n");
            break;
    }

    return 0;
}
