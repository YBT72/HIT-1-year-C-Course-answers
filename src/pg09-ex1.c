#include <stdio.h>  // For printf output function

/**
 * Function to calculate word length using pointer arithmetic
 * Finds length from start pointer to next space or end of string
 * 
 * @param word_start - pointer to beginning of word
 * @return length of the word in characters
 */
int calculate_word_length(char *word_start) {
    if (word_start == NULL) {
        return 0;
    }
    
    char *current = word_start;
    int length = 0;
    
    // Count characters until space or end of string using pointer arithmetic
    while (*current != ' ' && *current != '\0') {
        length++;
        current++;
    }
    
    return length;
}

/**
 * Function to print a word of specified length using pointer arithmetic
 * Prints characters from start pointer for given length
 * 
 * @param word_start - pointer to beginning of word
 * @param length - number of characters to print
 */
void print_word(char *word_start, int length) {
    if (word_start == NULL || length <= 0) {
        return;
    }
    
    // Use precision specifier %.*s to print exact number of characters
    // %.*s means: print string with precision specified by argument
    printf("  %.*s\n", length, word_start);
}

/**
 * Function to find and print words starting with a specific letter
 * Uses pointer arithmetic to process the string word by word
 * Case insensitive comparison for the first letter
 * 
 * @param str - input string containing words separated by spaces
 * @param letter - target letter to search for (case insensitive)
 */
void find_words_starting_with_letter(char *str, char letter) {
    // Check for NULL pointer
    if (str == NULL) {
        printf("Error: NULL string provided\n");
        return;
    }
    
    // Convert target letter to lowercase for consistent comparison
    // ASCII difference between uppercase and lowercase letters is 32
    // 'A'=65, 'a'=97 -> 97-65=32, 'B'=66, 'b'=98 -> 98-66=32, etc.
    // Adding 32 to uppercase letter converts it to lowercase
    char target_lower = (letter >= 'A' && letter <= 'Z') ? letter + 32 : letter;
    
    printf("Words starting with '%c' (case insensitive):\n", letter);
    
    char *current = str;  // Current position in string
    int found_words = 0;  // Counter for found words
    
    // Process string using pointer arithmetic
    while (*current != '\0') {
        
        // Skip leading spaces using pointer arithmetic
        while (*current == ' ' && *current != '\0') {
            current++;
        }
        
        // Check if we reached end of string
        if (*current == '\0') {
            break;
        }
        
        // Check if first character matches target letter (case insensitive)
        char first_char = *current;
        char first_lower = (first_char >= 'A' && first_char <= 'Z') ? first_char + 32 : first_char;
        
        // Calculate word length using dedicated function
        int word_length = calculate_word_length(current);
        
        if (first_lower == target_lower) {
            // Print the word using dedicated function  
            print_word(current, word_length);
            found_words++;
        }

        // Move current pointer to end of word
        current = current + word_length;
    }
    
    // Print summary
    if (found_words == 0) {
        printf("  No words found starting with '%c'\n", letter);
    } else {
        printf("Total words found: %d\n", found_words);
    }
    printf("\n");
}

/**
 * Main function to test the word finding functionality
 * Tests the example from the problem and additional cases
 */
int main(void) {
    printf("=== Word Finder Using Pointer Arithmetic ===\n\n");
    
    // Test case from the problem
    char test1[] = "Rony Goodman got a good mark";
    char target1 = 'g';
    
    printf("Test 1: \"%s\" with letter '%c'\n", test1, target1);
    find_words_starting_with_letter(test1, target1);
    
    // Additional test cases
    char test2[] = "Programming in C language";
    char target2 = 'C';
    
    printf("Test 2: \"%s\" with letter '%c'\n", test2, target2);
    find_words_starting_with_letter(test2, target2);
    
    char test3[] = "Apple banana Cherry date Elderberry chrome";
    char target3 = 'c';
    
    printf("Test 3: \"%s\" with letter '%c'\n", test3, target3);
    find_words_starting_with_letter(test3, target3);
    
    // Test with no matches
    char test4[] = "Hello World Programming";
    char target4 = 'x';
    
    printf("Test 4: \"%s\" with letter '%c'\n", test4, target4);
    find_words_starting_with_letter(test4, target4);
    
    // Test with empty string
    char test5[] = "";
    char target5 = 'a';
    
    printf("Test 5: \"%s\" (empty) with letter '%c'\n", test5, target5);
    find_words_starting_with_letter(test5, target5);
    
    return 0;
}
