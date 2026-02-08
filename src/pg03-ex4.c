#include <stdio.h>   // For printf output and scanf input functions

int main() {
    
    /*********************************************************** 
        Program that receives type, symbol, and base number
        and displays the symbol pattern according to the type,
        using matrix presentation method.
    ***********************************************************/

    int type, base;
    char symbol;
    
    // Get user input
    printf("Enter type: ");
    scanf("%d", &type);
    
    printf("Enter symbol: ");
    scanf(" %c", &symbol);  // Space before %c to ignore whitespace
    
    printf("Enter base: ");
    scanf("%d", &base);
    
    printf("\n");
    
    // Display pattern based on type
    if (type == 1) {
        // Type 1: Left-aligned triangle
        for (int i = 1; i <= base; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%c", symbol);
            }
            printf("\n");
        }
    }
    else if (type == 2) {
        // Type 2: Right-aligned triangle
        for (int i = 1; i <= base; i++) {
            // Print spaces for right alignment
            for (int j = 1; j <= base - i; j++) {
                printf(" ");
            }
            // Print symbols
            for (int j = 1; j <= i; j++) {
                printf("%c", symbol);
            }
            printf("\n");
        }
    }
    else {
        printf("Error: Invalid type. Please enter 1 or 2.\n");
    }
    
    return 0;
}
