#include <stdio.h>  // For printf output and fgets input functions
#include <string.h> // For strcpy function

#define MAX_LENGTH 100

// Function to swap the content of two strings
void swap_strings(char *str1, char *str2) {
    // Create a temporary string of sufficient size
    char temp[MAX_LENGTH];
    
    // Save the first string to temporary
    strcpy(temp, str1);
    
    // Copy the second string to the first
    strcpy(str1, str2);
    
    // Copy the temporary string (original first) to the second
    strcpy(str2, temp);
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    
    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    
    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    
    printf("\nBefore swap:\n");
    printf("First string: %s", str1);
    printf("Second string: %s", str2);
    
    // Call the swap function
    swap_strings(str1, str2);
    
    printf("\nAfter swap:\n");
    printf("First string: %s", str1);
    printf("Second string: %s", str2);
    
    return 0;
}
