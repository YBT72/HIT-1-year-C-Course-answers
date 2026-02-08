#include <stdio.h>	// For fgets input and printf output functions
#include <stdlib.h>	// For malloc and free memory management functions
#include <string.h>	// For strlen string length function

/**
 * Normalizes spaces in a string by removing consecutive spaces
 * and replacing them with a single space between words.
 * 
 * @param source - source string to normalize
 * @return pointer to newly allocated normalized string, or NULL on error
 */
static char *normalize_spaces(const char *source) {
	size_t i = 0;           // Iterator for source string
	size_t new_len = 0;     // Length of normalized string
	int in_space = 0;       // Flag to track if we're currently processing spaces

	// Handle null input
	if (source == NULL) {
		return NULL;
	}

	// First pass: calculate the length of normalized string
	while (source[i] != '\0') {     //'\0' is an symbol for the end of the string
		if (source[i] == ' ') {
			// Only count first space in a sequence
			if (!in_space) {
				new_len += 1;
				in_space = 1;
			}
		} else {
			// Regular character - always count
			new_len += 1;
			in_space = 0;
		}
		i++;
	}

	// Allocate memory for normalized string (+1 for null terminator)
	char *dest = (char *)malloc(new_len + 1);
	if (!dest) {        // Memory allocation verification
		return NULL;    // Memory allocation failed
	}

	// Second pass: copy characters to destination with normalized spaces
	i = 0;                 // Reset source iterator
	size_t j = 0;          // Destination iterator
	in_space = 0;          // Reset space flag
	while (source[i] != '\0') {
		if (source[i] == ' ') {
			// Only copy first space in a sequence
			if (!in_space) {
				dest[j++] = ' ';    // Copy single space
				in_space = 1;       // Set space flag to indicate we're in a sequence of spaces
			}
		} else {
			// Copy regular characters
			dest[j++] = source[i];  // Copy current character
			in_space = 0;           // Reset space flag when we encounter a non-space character
		}
		i++;        // Move to next character in source
	}
	dest[j] = '\0';        // Null-terminate the result
	return dest;
}

/**
 * Main function: reads a line from stdin, normalizes spaces, and prints result
 */
int main(void) {
	char buffer[1024];     // Buffer to store input line

	// Read line from standard input
	if (!fgets(buffer, sizeof(buffer), stdin)) {
		return 0;          // EOF or read error
	}

	// Remove trailing newline character if present
	size_t len = strlen(buffer);    // Calculate length of input string
	if (len > 0 && buffer[len - 1] == '\n') {
		buffer[len - 1] = '\0';
	}

	// Normalize spaces in the input string
	char *normalized = normalize_spaces(buffer);
	if (!normalized) {
		return 1;          // Memory allocation failed
	}

	// Print the normalized string and clean up
	printf("%s\n", normalized);
	free(normalized);      // Free allocated memory for normalized string
	return 0;
}
