#include <stdio.h>  // For printf output and scanf input functions

// Recursive function to calculate sum of squares: 1² + 2² + ... + n² - RELEVANT to task
long long sumSquaresRecursive(int n) {
    if (n == 1) {
        return 1;  // Base case: 1² = 1
    }
    return n * n + sumSquaresRecursive(n - 1);
}

// Iterative function to calculate sum of squares: 1² + 2² + ... + n² - IRRELEVANT to task
long long sumSquaresIterative(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

// Mathematical formula: sum = n(n+1)(2n+1)/6 - IRRELEVANT to task
long long sumSquaresFormula(int n) {
    return (long long)n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    int n;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Calculate using all three methods
    long long recursiveResult = sumSquaresRecursive(n);
    long long iterativeResult = sumSquaresIterative(n);
    long long formulaResult = sumSquaresFormula(n);
    
    // Display results
    printf("\nSum of squares from 1² to %d²:\n", n);
    printf("===================================\n");
    
    // Show the series
    printf("Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d²", i);
        if (i < n) printf(" + ");
    }
    printf("\n\n");
    
    printf("Recursive method:  %lld\n", recursiveResult);
    printf("Iterative method:  %lld\n", iterativeResult);
    printf("Formula method:    %lld\n", formulaResult);
    
    // Verify all methods give the same result
    if (recursiveResult == iterativeResult && iterativeResult == formulaResult) {
        printf("\n✓ All methods produce the same result!\n");
    } else {
        printf("\n✗ Methods produce different results - check implementation!\n");
    }
    
    // Show the mathematical formula
    printf("\nUsing formula: n(n+1)(2n+1)/6 = %d×%d×%d/6 = %lld\n", 
           n, n+1, 2*n+1, formulaResult);
    
    return 0;
}
