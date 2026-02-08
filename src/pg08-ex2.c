#include <stdio.h>  // For printf output function

/**
 * Function to analyze string and count character types using pointer arithmetic
 * All results are passed by reference to demonstrate pointer usage
 * 
 * @param text - input string to analyze
 * @param small_letters_count - pointer to store total count of lowercase letters (a-z)
 * @param big_letters_count - pointer to store total count of uppercase letters (A-Z)
 * @param digits_count - pointer to store total count of digits (0-9)
 * @param other_chars_count - pointer to store count of other characters
 */
void analyze_string(char *text, 
                    int *small_letters_count, 
                    int *big_letters_count, 
                    int *digits_count, 
                    int *other_chars_count) {
    
    // Check for NULL pointers
    if (text == NULL || small_letters_count == NULL || big_letters_count == NULL || 
        digits_count == NULL || other_chars_count == NULL) {
        return;
    }
    
    // Initialize all counters by reference
    *small_letters_count = 0;
    *big_letters_count = 0;
    *digits_count = 0;
    *other_chars_count = 0;
    
    // Process string using pointer arithmetic
    char *current_char = text;
    while (*current_char != '\0') {
        
        if (*current_char >= 'a' && *current_char <= 'z') {
            (*small_letters_count)++;   // Lowercase letter - increment counter by reference

        } else if (*current_char >= 'A' && *current_char <= 'Z') {
            (*big_letters_count)++;     // Uppercase letter - increment counter by reference
            
        } else if (*current_char >= '0' && *current_char <= '9') {
            (*digits_count)++;          // Digit - increment counter by reference
            
        } else {
            (*other_chars_count)++;     // Other character (space, punctuation) - increment counter by reference
        }
        
        current_char++;                 // Move to next character using pointer arithmetic
    }
}

/**
 * Helper function to print analysis results
 * Simple statistics: total counts by character type
 * 
 * @param small_letters_count - total lowercase letters count
 * @param big_letters_count - total uppercase letters count
 * @param digits_count - total digits count
 * @param other_chars_count - total other characters count
 */
void print_analysis_results(int small_letters_count, int big_letters_count, 
                           int digits_count, int other_chars_count) {
    
    printf("=== String Analysis Results ===\n");
    printf("Lowercase letters (a-z): %d\n", small_letters_count);
    printf("Uppercase letters (A-Z): %d\n", big_letters_count);
    printf("Digits (0-9): %d\n", digits_count);
    printf("Other characters (spaces, punctuation): %d\n", other_chars_count);
    printf("\n");
}

/**
 * Main function to test the string analysis function
 * Demonstrates passing variables by reference for simple statistics
 */
int main(void) {
    printf("=== String Character Statistics with Pointer Arithmetic ===\n\n");
    
    // Test strings
    char test1[] = "Hello World 123!";
    char test2[] = "ABC abc XYZ xyz 456";
    char test3[] = "Programming in C language 2026";
    
    // Variables to store counts (passed by reference)
    int small_count, big_count, digits, others;
    
    // Test 1
    printf("Test 1: \"%s\"\n", test1);
    analyze_string(test1, &small_count, &big_count, &digits, &others);
    print_analysis_results(small_count, big_count, digits, others);
    
    // Test 2
    printf("Test 2: \"%s\"\n", test2);
    analyze_string(test2, &small_count, &big_count, &digits, &others);
    print_analysis_results(small_count, big_count, digits, others);
    
    // Test 3
    printf("Test 3: \"%s\"\n", test3);
    analyze_string(test3, &small_count, &big_count, &digits, &others);
    print_analysis_results(small_count, big_count, digits, others);
    
    // Test with empty string
    char test4[] = "";
    printf("Test 4: \"%s\" (empty string)\n", test4);
    analyze_string(test4, &small_count, &big_count, &digits, &others);
    print_analysis_results(small_count, big_count, digits, others);
    
    return 0;
}
