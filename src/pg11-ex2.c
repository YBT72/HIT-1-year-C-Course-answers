#include <stdio.h>  // For printf output function

// Define the student structure
typedef struct student {
    char name[30];      // Student's name
    int id_card;        // Student's ID card number
    int grade;          // Grade received by the student on the exam
} student;

// Function that processes the array of students
void process_students(student students[], int size, int *below_average_count) {
    int total_grade = 0;
    float average;
    
    // Calculate the total of all grades
    for (int i = 0; i < size; i++) {
        total_grade += students[i].grade;
    }
    
    // Calculate the average grade
    average = (float)total_grade / size;
    
    printf("Average grade: %.2f\n\n", average);
    
    // Find and display students with grade above average
    printf("Students with grade above average:\n");
    printf("Name\t\tID Card\t\tGrade\n");
    printf("----------------------------------------\n");
    
    int above_average_count = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].grade > average) {
            printf("%-15s\t%d\t\t%d\n", students[i].name, students[i].id_card, students[i].grade);
            above_average_count++;
        }
    }
    
    if (above_average_count == 0) {
        printf("No students have grades above average.\n");
    }
    
    printf("\nTotal students above average: %d\n\n", above_average_count);
    
    // Find and display students with grade below average
    printf("Students with grade below average:\n");
    printf("Name\t\tID Card\t\tGrade\n");
    printf("----------------------------------------\n");
    
    *below_average_count = 0;  // Initialize the counter
    for (int i = 0; i < size; i++) {
        if (students[i].grade < average) {
            printf("%-15s\t%d\t\t%d\n", students[i].name, students[i].id_card, students[i].grade);
            (*below_average_count)++;
        }
    }
    
    if (*below_average_count == 0) {
        printf("No students have grades below average.\n");
    }
    
    printf("\nTotal students below average: %d\n", *below_average_count);
}

int main() {
    // Create an array of students with test data
    student students[] = {
        {"Alice", 123456, 85},
        {"Bob", 234567, 78},
        {"Charlie", 345678, 92},
        {"Diana", 456789, 67},
        {"Eve", 567890, 88},
        {"Frank", 678901, 74},
        {"Grace", 789012, 95},
        {"Henry", 890123, 82}
    };
    
    int size = sizeof(students) / sizeof(students[0]);
    int below_average_count;
    
    printf("Student Grade Analysis\n");
    printf("======================\n\n");
    
    // Display all students
    printf("All students:\n");
    printf("Name\t\tID Card\t\tGrade\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-15s\t%d\t\t%d\n", students[i].name, students[i].id_card, students[i].grade);
    }
    printf("\n");
    
    // Process the students array
    process_students(students, size, &below_average_count);
    
    return 0;
}
