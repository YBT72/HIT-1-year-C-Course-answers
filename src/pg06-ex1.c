#include <stdio.h>  // For printf output and scanf input functions

int arraySize = 0; // Global variable to store actual array size

// Function to input array values from user with validation
void inputArray(int arr[]) {
    int i;
    int value;
    
    printf("Enter %d integers (each must be between 0 and 100):\n", arraySize);
    for (i = 0; i < arraySize; i++) {
        do {
            printf("Enter number %d (0-100): ", i + 1);
            scanf("%d", &value);
            
            if (value < 0 || value > 100) {
                printf("Error: Please enter a number between 0 and 100.\n");
            }
        } while (value < 0 || value > 100);
        
        // Store valid input in array
        arr[i] = value;
    }
}

// Function to print array elements
void printArray(int arr[]) {
    int i;
    
    printf("\nArray elements:\n [");

    for (i = 0; i < arraySize; i++) {
        printf(" %d", arr[i]);  /*  This row can't include a comma because after 
                                    the last element there shouldn't be a comma. */
        if (i < arraySize - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}

// Function to calculate average of array elements
double calculateAverage(int arr[]) {
    double sum = 0.0;
    int i;

    for (i = 0; i < arraySize; i++) {
        sum += arr[i];
    }
    
    return sum / arraySize;
}

// Function to print values greater than average
void printGreaterThanAverage(int arr[], double average) {
    int i;
    int found = 0;  // Counter to check if any value is found
    
    printf("Values greater than average (%.2f): ", average);
    for (i = 0; i < arraySize; i++) {
        if (arr[i] > average) {
            if (found > 0) printf(", ");
            printf("%d", arr[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("None");
    }
    printf("\n");
}

// Function to count values less than average
int countLessThanAverage(int arr[], double average) {
    int i;
    int count = 0;
    
    for (i = 0; i < arraySize; i++) {
        if (arr[i] < average) {
            count++;
        }
    }
    
    return count;
}

int main() {
    
    double average;
    int lessThanAverageCount;
    
    // First, get the array size from user
    printf("Enter the number of elements: ");
    scanf("%d", &arraySize);
    
    int numbers[arraySize]; // Variable-length array

    // Get array values from user
    inputArray(numbers);
    
    // Print the array elements
    printArray(numbers);
    
    // Calculate average using function
    average = calculateAverage(numbers);
    
    // Count values less than average
    lessThanAverageCount = countLessThanAverage(numbers, average);
    
    // Print results as required
    printf("\nResults:\n");
    printf("Average value: %.2f\n", average);
    printGreaterThanAverage(numbers, average);
    printf("Count of values less than average: %d\n", lessThanAverageCount);
    
    return 0;
}
