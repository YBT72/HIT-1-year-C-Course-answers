#include <stdio.h>  // For printf output function

/**
 * Function to check if a string is a palindrome using two pointers
 * Uses pointer arithmetic to move from ends towards center
 * No auxiliary arrays or string reversal needed
 * 
 * @param str - string array to check for palindrome
 * @return 1 if string is palindrome, 0 otherwise
 */
int is_palindrome_two_pointers(char *str) {
    // Check for NULL pointer
    if (str == NULL) {
        return 0;
    }
    
    // Calculate string length using pointer arithmetic (elegant version)
    int len;
    for (len = 0; *(str + len); len++);  // Compact: increment until null terminator
    
    // Empty string or single character is considered a palindrome
    if (len <= 1) {
        return 1;
    }
    
    // Initialize two pointers: one at start, one at end
    char *left = str;              // Pointer starting from beginning
    char *right = str + len - 1;   // Pointer starting from end (before null terminator)
    
    // Move pointers towards center, comparing characters
    while (left < right) {
        // Compare characters at current positions
        if (*left != *right) {
            return 0;  // Characters don't match - not a palindrome
        }
        
        // Move pointers towards center using pointer arithmetic
        left++;   // Move left pointer forward
        right--;  // Move right pointer backward
    }
    
    // If we've checked all pairs successfully, it's a palindrome
    return 1;
}


/**
 * Main function to test the palindrome checking fnction
 * Tests examples from problem statement and additional cases
 */
int main(void) {
    printf("=== Palindrome Check Using Two Pointers ===\n\n");
    
    // Test cases from the problem
    char test1[] = "abcba";
    printf("Test 1: \"%s\" -> Result: %d\n", test1, is_palindrome_two_pointers(test1));
    
    char test2[] = "abcdea";
    printf("Test 2: \"%s\" -> Result: %d\n", test2, is_palindrome_two_pointers(test2));
    
    // Additional test cases
    char test3[] = "racecar";
    printf("Test 3: \"%s\" -> Result: %d\n", test3, is_palindrome_two_pointers(test3));
    
    char test4[] = "hello";
    printf("Test 4: \"%s\" -> Result: %d\n", test4, is_palindrome_two_pointers(test4));
    
    char test5[] = "madam";
    printf("Test 5: \"%s\" -> Result: %d\n", test5, is_palindrome_two_pointers(test5));
    
    char test6[] = "abcdef";
    printf("Test 6: \"%s\" -> Result: %d\n", test6, is_palindrome_two_pointers(test6));
    
    char test7[] = "a";
    printf("Test 7: \"%s\" -> Result: %d\n", test7, is_palindrome_two_pointers(test7));
    
    char test8[] = "";
    printf("Test 8: \"%s\" -> Result: %d\n", test8, is_palindrome_two_pointers(test8));
    
    return 0;
}
