#include <stdio.h>  // For printf output function
#include <string.h> // For strlen function

/**
 * Function to find the last occurrence of a character in a string
 * Uses pointer arithmetic and searches from the end of string backwards
 * More efficient than searching from beginning for last occurrence
 * 
 * @param str - input string to search in
 * @param letter - character to find
 * @return position of last occurrence (0-based), or -1 if not found
 */
int find_last_occurrence(char *str, char letter) {
    // Check for NULL pointer
    if (str == NULL) {
        return -1;
    }
    
    // Find the end of string using strlen() and point to last character before '\0'.
    char *current = str + strlen(str) - 1;
    
    // Search backwards from end to beginning using pointer arithmetic
    // Note: We use *current to access the VALUE at the memory address (the character)
    // and we use current (without *) to work with the ADDRESS itself for comparisons and arithmetic
    while (current >= str) {
        if (*current == letter) {
            // Found! Calculate position using pointer arithmetic
            return current - str;  // Distance from beginning = position
        }
        current--;  // Move backwards
    }
    
    // Character not found
    return -1;
}

/**
 * Main function to test the last occurrence finding functionality
 * Tests the example from the problem and additional cases
 */
int main(void) {
    // Test case from the problem: "abcadeaxy" with character 'a'
    char test1[] = "abcadeaxy";
    char target1 = 'a';
    
    printf("String: \"%s\", searching for '%c'\n", test1, target1);
    int result1 = find_last_occurrence(test1, target1);
    printf("Result: %d\n", result1);
    
    // Additional test case
    char test2[] = "programming";
    char target2 = 'g';
    
    printf("String: \"%s\", searching for '%c'\n", test2, target2);
    int result2 = find_last_occurrence(test2, target2);
    printf("Result: %d\n", result2);
    
    // Test with character not found
    char test3[] = "hello world";
    char target3 = 'x';
    
    printf("String: \"%s\", searching for '%c'\n", test3, target3);
    int result3 = find_last_occurrence(test3, target3);
    printf("Result: %d\n", result3);
    
    return 0;
}
