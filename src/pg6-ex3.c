#include <stdio.h>  // For printf output and scanf input functions

int main() {
    int arr[10];
    int size;
    int i, j;
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
        scanf("%d", &arr[i]);
    }
    
    // Print original array
    printf("\nOriginal array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Remove duplicates
    int newSize = 0;
    int isDuplicate;
    
    for (i = 0; i < size; i++) {
        isDuplicate = 0;
        
        // Check if current element already exists in the new array
        for (j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        // If not duplicate, keep it
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    
    // Print array after removing duplicates
    printf("Array after removing duplicates: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Original size: %d, New size: %d\n", size, newSize);
    
    return 0;
}
