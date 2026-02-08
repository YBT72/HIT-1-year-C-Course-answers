#include<stdio.h>   // For printf output and scanf input functions
#include<math.h>    // For pow, cos, fabs mathematical functions and M_PI constant

// Function to calculate factorial using recursion.
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;

    } else {
        return n * factorial(n - 1);
    }
}

// cosine function using Taylor series:
double cosine(double x, int n) {
    double sum = 1.0; // First term of the series (x^0 / 0! = 1)
    int i; // Taylor series term index

    for (i = 1; i < n; i++) {

        // Calculate term: (-1)^i * x^(2i) / (2i)!
        double term = pow(x, 2*i); // Calculate x^(2i)
        int j;

        // Apply (-1)^i and divide by (2i)!
        if (i % 2 == 1) {
            term = -term;
        }
        term = term / factorial(2 * i);
        
        sum += term; // Add term to sum
    }

    return sum;
}

int main() {
    double angle;
    int terms;

    // Input angle in radians
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    // Input number of terms
    printf("Enter number of terms for approximation: ");
    scanf("%d", &terms);

    // Calculate cosine using Taylor series
    double result = cosine(angle*M_PI/180, terms);
    
    // Calculate cosine using built-in math.h function
    double math_result = cos(angle*M_PI/180);

    // Display the results
    printf("Cosine of %.2f using %d terms is: %.2f\n", angle, terms, result);
    printf("Cosine of %.2f using math.h cos(): %.2f\n", angle, math_result);
    printf("Difference: %.2f\n", fabs(result - math_result));

    return 0;
}