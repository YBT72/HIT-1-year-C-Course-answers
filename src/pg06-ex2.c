#include <stdio.h>  // For printf output and scanf input functions

int main() {
    int numbers[10];  // Array to store numbers
    int size;
    int i;
    int temp;
    
    // Input array size
    printf("Enter the size of the array (max 10): ");
    scanf("%d", &size);
    
    if (size <= 0 || size > 10) {
        printf("Invalid size. Please enter a number between 1 and 10.\n");
        return 1;
    }
    
    // Input array elements
    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    // Print original array
    printf("\nOriginal array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Move each element to the next place (circular shift right)
    // Save the last element
    temp = numbers[size - 1];
    
    // Shift all elements one position to the right
    for (i = size - 1; i > 0; i--) {
        numbers[i] = numbers[i - 1];
    }
    
    // Put the last element in the first position
    numbers[0] = temp;
    
    // Print result array
    printf("Array after shifting: ");
    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
