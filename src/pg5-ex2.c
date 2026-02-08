#include <stdio.h>  // For printf output function
#include <math.h>   // For pow mathematical function

// Function to check if a number is the sum of cubes of its digits
int isSumOfCubesOfDigits(int number) {
    int original = number;
    int sum = 0;
    
    while (number > 0) {
        int digit = number % 10;
        sum += pow(digit, 3); // digit³
        number /= 10;
    }
    
    return sum == original;
}

int main() {
    printf("Three-digit numbers equal to sum of cubes of their digits:\n");
    
    // Loop through all three-digit numbers (100-999)
    for (int number = 100; number <= 999; number++) {
        if (isSumOfCubesOfDigits(number)) {
            printf("%d, ", number);
        }
    }
    
    return 0;
}
