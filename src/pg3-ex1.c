#include<stdio.h>   // For printf output and scanf input functions

int main() {
    
    /* Program that receives two numbers and an arithmetic operator 
       and performs the calculation using switch-case */

    // Declare variables
    float num1, num2;
    char operator;
    
    // Get user input
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%f", &num2);
    
    // Perform calculation using switch-case
    switch(operator) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("Error: Division by zero is not allowed!\n");
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
    }
    
    return 0;
}
