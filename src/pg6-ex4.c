#include <stdio.h>  // For printf output and scanf input functions

// Function to calculate sum of all elements in a 2D array
int calculateSum(int arr[][10], int rows, int cols) {
    int sum = 0;
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    
    return sum;
}

// Function to print the 2D array
void printArray(int arr[][10], int rows, int cols) {
    int i, j;
    
    printf("\nThe 2D array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[10][10];
    int rows, cols;
    int i, j;
    int sum;
    
    // Input dimensions
    printf("Enter number of rows (max 10): ");
    scanf("%d", &rows);
    printf("Enter number of columns (max 10): ");
    scanf("%d", &cols);
    
    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
        printf("Invalid dimensions. Please enter values between 1 and 10.\n");
        return 1;
    }
    
    // Input array elements
    printf("\nEnter elements for the %dx%d array:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    // Print the array
    printArray(arr, rows, cols);
    
    // Calculate and print the sum
    sum = calculateSum(arr, rows, cols);
    printf("\nSum of all elements: %d\n", sum);
    
    return 0;
}
