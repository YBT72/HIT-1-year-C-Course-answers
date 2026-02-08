#include<stdio.h>   // For printf output and scanf input functions

int main() {
    
    /* Program that calculates the sum of digits and count of digits 
       of the entered number */

    // Declare variables
    int number, digit, sum = 0, count = 0;
    
    // Get user input with validation for negative numbers
    do {
        printf("Enter a positive number (or 0): ");
        scanf("%d", &number);
        
        if (number < 0) {
            printf("Error: Negative numbers are not allowed. Please try again.\n");
        }
    } while (number < 0);
    
    // Handle special case of 0
    if (number == 0) {
        sum = 0;
        count = 1;
    } else {
        // Calculate sum and count of digits
        int temp = number;  // Use temporary variable to preserve original number
        while (temp > 0) {
            digit = temp % 10;  // Extract last digit
            sum += digit;       // Add digit to sum
            count++;            // Increment digit count
            temp /= 10;         // Remove last digit
        }
    }
    
    // Display results
    printf("Number: %d\n", number);
    printf("Sum of digits: %d\n", sum);
    printf("Count of digits: %d\n", count);
    
    return 0;
}
