#include<stdio.h>   // For printf output and scanf input functions

/************************************************************************* 
 * Program that calculates sum of fractions from 1/2 to N/(N+1).         *
 *************************************************************************/

/************************************************************************ 
Part I: caclulation of nominator and denomintor of the result for the sum.
    
    NOT RELEVANT FOR THE SPECIFIC TASK, BUT ADDED FOR COMPLETENESS. 
*************************************************************************/

// Function to calculate Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate Least Common Multiple (LCM)
long long lcm(int a, int b) {
    return ((long long)a * b) / gcd(a, b);
}

// Function to calculate LCM of numbers 2 to n+1 (denominators)
long long lcmRange(int n) {
    long long result = 2;
    for (int i = 3; i <= n + 1; i++) {
        result = lcm(result, i);
    }
    return result;
}

// Function to calculate sum as fraction (numerator/denominator)
void calculateFractionSum(int n, long long *numerator, long long *denominator) {
    *denominator = lcmRange(n);
    *numerator = 0;
    
    for (int i = 1; i <= n; i++) {
        *numerator += (*denominator * i) / (i + 1);
    }
    
    // Simplify the fraction
    long long commonDivisor = gcd(*numerator, *denominator);
    *numerator /= commonDivisor;
    *denominator /= commonDivisor;
}


/************************************************************************ 
Part II: calculation of the sum as a fraction (numerator/denominator) 
            using two different ways: with and without recursion.  
            
                    RELEVANT FOR THE SPECIFIC TASK.  
*************************************************************************/

// Function to calculate sum using recursion
double sumWithRecursion(int n) {
    if (n == 1) {
        return 1.0/2.0;  // Base case: 1/2
    }
    return (double)n/(n+1) + sumWithRecursion(n - 1);  // Recursive call
}

// Function to calculate sum of fractions without recursion (iterative)
double sumWithoutRecursion(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)i/(i+1);
    }
    return sum;
}

/************************************************************************/


int main() {
    
    /* Program that calculates sum of fractions from 1/2 to N/(N+1)
       using both recursive and non-recursive methods */

    int number=9;   //The relevant variable value for the specific task.
    double recursiveResult, iterativeResult;
    
    // Get user input (NOT RELEVANT FOR THE SPECIFIC TASK, BUT ADDED FOR COMPLETENESS)
    do {
        printf("Enter the number of fractions to sum (positive integer): ");
        scanf("%d", &number);
        
        if (number <= 0) {
            printf("Error: Please enter a positive integer.\n");
        }
    } while (number <= 0);
    
    // Calculate sum using both methods
    recursiveResult = sumWithRecursion(number);
    iterativeResult = sumWithoutRecursion(number);
    
    // Display results (RELEVANT FOR THE SPECIFIC TASK)
    if (number == 1) {
        printf("\nSum of %d fraction (1/2):\n", number);
    } else if (number == 2) {
        printf("\nSum of first %d fractions (1/2 + 2/3):\n", number);
    } else {
        printf("\nSum of first %d fractions (1/2 + 2/3 + ... + %d/%d):\n", number, number, number+1);
    }
    printf("Using recursion: %.2f\n", recursiveResult);
    printf("Using iteration (without recursion): %.2f\n", iterativeResult);
    
    // Calculate and display as regular fraction (NOT RELEVANT FOR THE SPECIFIC TASK)
    long long numerator, denominator;
    calculateFractionSum(number, &numerator, &denominator);
    
    // Display the calculation breakdown for clarity (NOT RELEVANT FOR THE SPECIFIC TASK)
    printf("\nCalculation breakdown: ");
    for (int i = 1; i <= number; i++) {
        printf("%d/%d", i, i+1);
        if (i < number) {
            printf(" + ");
        }
    }
    printf(" = %lld/%lld\n", numerator, denominator);
    
    return 0;
}
