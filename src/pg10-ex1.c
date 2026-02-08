#include <stdio.h>      // For printf output and fgets input functions
#include <stdlib.h>     // For malloc, realloc, free memory management functions
#include <string.h>     // For strlen and strcspn string functions

// Function that receives a string and returns a new dynamic string
// with the same content but with consecutive spaces reduced to single spaces
// Note: assumes that the first and last characters are not spaces
char* trim_spaces(char *original) {
    if (original == NULL) {
        return NULL;
    }
    
    int len = strlen(original);
    if (len == 0) {     // If the original string is empty, return an empty string
        char *result = (char*)malloc(1);    // Allocate memory for an empty string
        if (result != NULL) {
            result[0] = '\0';
        }
        return result;
    }
    
    // Allocate memory for the new string (maximum same size as original)
    char *new_string = (char*)malloc(len + 1);    // Allocate memory for the new string
    if (new_string == NULL) {       // Check if memory allocation was successful
        return NULL;
    }
    
    int i = 0;  // Index for original string
    int j = 0;  // Index for new string
    
    while (i < len) {
        if (original[i] == ' ') {
            // Add one space to the new string
            new_string[j++] = ' ';

            // Skip all consecutive spaces in the original string
            while (i < len && original[i] == ' ') {
                i++;
            }
        } else {
            // Copy non-space character
            new_string[j++] = original[i++];
        }
    }
    
    // Null terminate the new string
    new_string[j] = '\0';
    
    // Reallocate to exact size needed
    char *final_result = (char*)realloc(new_string, j + 1);
    if (final_result != NULL) {
        return final_result;
    } else {
        return new_string;  // Return original allocation if realloc fails
    }
}

int main() {
    char original_str[200];
    
    printf("Enter a string: ");
    fgets(original_str, sizeof(original_str), stdin);
    
    // Remove newline character that fgets() includes at the end of the string
    // This is necessary to avoid double line breaks in output and ensure clean string processing
    original_str[strcspn(original_str, "\n")] = '\0';
    
    printf("Original string: \"%s\"\n", original_str);
    
    // Call the function to trim spaces
    char *compacted = trim_spaces(original_str);
    
    if (compacted != NULL) {
        printf("Compacted string: \"%s\"\n", compacted);
        
        // Free the dynamically allocated memory to prevent memory leaks
        free(compacted);
    } else {
        printf("Error: Failed to allocate memory\n");
    }
    
    return 0;
}
