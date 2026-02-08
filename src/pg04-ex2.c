#include <stdio.h>  // For printf output and scanf input functions

// Function to convert and display time
void convertTime(int time) {
    int hours, minutes;
    
    // Extract hours and minutes from the input
    hours = time / 100;
    minutes = time % 100;
    
    // Check if time is valid
    if (time < 0 || hours >= 24 || minutes >= 60) {
        printf("Abnormal input!\n");
        return;
    }
    
    // Convert to 12-hour format and display
    if (hours == 0) {
        printf("The time is: %d:%02dam\n", 0, minutes);
    } else if (hours < 12) {
        printf("The time is: %d:%02dam\n", hours, minutes);
    } else if (hours == 12) {
        printf("The time is: %d:%02dpm\n", hours, minutes);
    } else {
        printf("The time is: %d:%02dpm\n", hours - 12, minutes);
    }
}

// Function to recursively read and process times
void processTime() {
    int time;
    
    printf("Please enter the time: ");
    scanf("%d", &time);
    
    convertTime(time);
    
    // Continue reading until user wants to stop
    // For this example, we'll process one time and exit
    // You can modify this to continue reading if needed
}

int main() {
    // Process multiple time inputs like in the example
    int time;
    
    printf("Enter times in HHMM format (enter -1 to exit):\n");
    
    while (1) {
        printf("Please enter the time (to end the program type -1): ");
        scanf("%d", &time);
        
        if (time == -1) {
            printf("Goodbye!\n");
            break;
        }
        
        convertTime(time);
    }
    
    return 0;
}
