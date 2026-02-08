#include<stdio.h>   // For printf output and scanf input functions

// Factorial functions
// Recursive factorial
long long factorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: 0! = 1! = 1
    }
    return n * factorialRecursive(n - 1);
}

// Non-recursive (iterative) factorial
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Sum of squares functions
// Recursive sum of squares
long long sumSquaresRecursive(int n) {
    if (n == 1) {
        return 1;  // Base case: 1² = 1
    }
    return n * n + sumSquaresRecursive(n - 1);
}

// Non-recursive (iterative) sum of squares
long long sumSquaresIterative(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    
    /* Program that calculates factorial and sum of squares
       using both recursive and non-recursive methods */

    int num;
    long long factorialRec, factorialIter, sumSquaresRec, sumSquaresIter;
    
    // Get user input
    do {
        printf("Enter a positive integer: ");
        scanf("%d", &num);
        
        if (num <= 0) {
            printf("Error: Please enter a positive integer.\n");
        }
    } while (num <= 0);
    
    // Calculate using both methods
    factorialRec = factorialRecursive(num);
    factorialIter = factorialIterative(num);
    sumSquaresRec = sumSquaresRecursive(num);
    sumSquaresIter = sumSquaresIterative(num);
    
    // Display results
    printf("\nResults for num = %d:\n", num);
    printf("=====================================\n");
    
    printf("\nFactorial (%d!):\n", num);
    printf("Using recursion: %lld\n", factorialRec);
    printf("Using iteration: %lld\n", factorialIter);
    
    printf("\nSum of squares (1² + 2² + ... + %d²):\n", num);
    printf("Using recursion: %lld\n", sumSquaresRec);
    printf("Using iteration: %lld\n", sumSquaresIter);
    
    // Display calculation breakdown
    printf("\nCalculation breakdown:\n");
    printf("Factorial: %d! = ", num);
    for (int i = 1; i <= num; i++) {
        printf("%d", i);
        if (i < num) printf(" × ");
    }
    printf(" = %lld\n", factorialRec);
    
    printf("Sum of squares: ");
    for (int i = 1; i <= num; i++) {
        printf("%d²", i);
        if (i < num) printf(" + ");
    }
    printf(" = %lld\n", sumSquaresRec);
    
    return 0;
}
