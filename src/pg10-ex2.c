#include <stdio.h>  // For printf output function
#include <stdlib.h> // For malloc, realloc, free memory management functions

// Function to print an array
void print_array(int *array, int size, const char *name) {
    printf("%s: ", name);               // Print the name of the array
    for (int i = 0; i < size; i++) {    // Loop through the array and print each element
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Function to separate even and odd numbers from the original array
void separate_even_odd(int *original, int original_size, 
                      int **even_array, int *even_count,
                      int **odd_array, int *odd_count) {
    
    // Allocate memory for maximum possible size (worst case: all even or all odd)
    *even_array = (int*)malloc(original_size * sizeof(int));
    *odd_array = (int*)malloc(original_size * sizeof(int));
    
    // Check if memory allocation was successful
    if (*even_array == NULL || *odd_array == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    
    // Initialize counters
    *even_count = 0;
    *odd_count = 0;
    
    // Single loop to fill both arrays
    for (int i = 0; i < original_size; i++) {
        if (original[i] % 2 == 0) {
            (*even_array)[(*even_count)++] = original[i];   // Add even number to even_array and increment even_count after assignment
        } else {
            (*odd_array)[(*odd_count)++] = original[i];     // Add odd number to odd_array and increment odd_count after assignment 
        }
    }
    
    // Optimize memory usage by reallocating to actual size
    *even_array = (int*)realloc(*even_array, *even_count * sizeof(int));
    *odd_array = (int*)realloc(*odd_array, *odd_count * sizeof(int));
}

int main() {
    // Original array A from the example
    int A[] = {6, 57, 14, 21, 11, 3, 22, 42, 9, 15};
    int size_A = sizeof(A) / sizeof(A[0]);  // Size of the original array
    
    // Variables for the new dynamic arrays
    int *even_numbers = NULL;
    int *odd_numbers = NULL;
    int even_count = 0;
    int odd_count = 0;
    
    // Print the original array
    print_array(A, size_A, "Original array A");
    
    // Separate even and odd numbers
    separate_even_odd(A, size_A, &even_numbers, &even_count, &odd_numbers, &odd_count);
    
    // Print the results
    if (even_numbers != NULL && odd_numbers != NULL) {
        print_array(even_numbers, even_count, "Even numbers");
        print_array(odd_numbers, odd_count, "Odd numbers");
        
        // Free the dynamically allocated memory
        free(even_numbers);
        free(odd_numbers);
        
        printf("\nMemory successfully freed.\n");
    }
    
    return 0;
}
