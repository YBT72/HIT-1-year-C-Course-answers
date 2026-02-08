#include <stdio.h>   // For printf output and scanf input functions

int main() {
    
    /* Program that receives a character and prints a message 
       according to the input character type. */

    // Declare variable
    char ch;
    
    // Get user input
    printf("Enter a character: ");
    scanf("%c", &ch);
    
    // Check character type and print appropriate message
    if (ch >= 'a' && ch <= 'z') {
        printf("This is a small letter.\n");
    }
    else if (ch >= 'A' && ch <= 'Z') {
        printf("This is a big letter\n");
    }
    else if (ch >= '0' && ch <= '9') {
        printf("This is a digit.\n");
    }
    else {
        printf("This is another character\n");
    }

    return 0;
}