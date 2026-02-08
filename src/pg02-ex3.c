#include <stdio.h>   // For printf output and scanf input functions

int main() {
    
    /* Program that receives 3 integer numbers and compares them */

    // Declare variables
    float num1, num2, num3;
    
    // Get user input
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Enter third number: ");
    scanf("%f", &num3);
    
    // Compare numbers and print appropriate message
    if (num1 == num2 && num2 == num3) {
        printf("All numbers are equal\n");
    }
    else if (num1 == num2 || num1 == num3 || num2 == num3) {
        printf("Two numbers are equal\n");
    }
    else {
        printf("All numbers are different\n");
    }
    
    return 0;
}
