#include <stdio.h>  // For printf output function

/*
 * Why we can't calculate array size inside functions using references/pointers:
 * 
 * When an array is passed to a function as a parameter (e.g., student students[]),
 * it undergoes "array decay" - it's automatically converted to a pointer to the
 * first element. This means the function receives only the memory address, not
 * the size information of the original array.
 * 
 * Inside the function:
 * - sizeof(students) returns size of pointer (typically 8 bytes on 64-bit systems)
 * - sizeof(students[0]) returns size of one element (e.g., 38 bytes for student struct)
 * - Result: 8/38 = 0 (incorrect!)
 * 
 * The macro below works only in the same scope where the array is declared,
 * where sizeof() can access the actual array size information.
 */

// Macro to calculate number of elements in a statically allocated array
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * Define student structure containing:
 * - name: student's name (max 30 characters)
 * - id_card: student's ID card number  
 * - grade: student's grade
 */
typedef struct student {    // Define a structure named 'student'
    char name[30];          // Student's name
    int id_card;            // Student's ID card number
    int grade;              // Student's grade
} student;                  // Define a type alias 'student' for the structure

/**
 * Function to print information about students
 * Displays name, ID card, and grade for each student in the array
 * 
 * @param students - array of student structures (passed by reference)
 * @param count - number of students in the array
 */
void print_students_info(student students[], int count) {
    printf("Students Information:\n");
    printf("====================\n");
    
    // Iterate through all students in the array
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", students[i].name);
        printf("  ID Card: %d\n", students[i].id_card);
        printf("  Grade: %d\n", students[i].grade);
        printf("\n");
    }
}

/**
 * Function to calculate average grade using reference parameter
 * 
 * @param students - array of student structures
 * @param count - number of students in the array
 * @param average_ref - pointer to store the calculated average (passed by reference)
 */
void calculate_average_grade(student students[], int count, float *average_ref) {
    if (count == 0) {
        *average_ref = 0.0;
        return;
    }
    
    int total_grade = 0;
    
    // Sum up all grades
    for (int i = 0; i < count; i++) {
        total_grade += students[i].grade;
    }
    
    // Calculate average and store in reference parameter
    *average_ref = (float)total_grade / count;
}

/**
 * Function to print students with grades above average
 * 
 * @param students - array of student structures
 * @param count - number of students in the array
 * @param average - the average grade to compare against
 */
void print_above_average_students(student students[], int count, float average) {
    printf("Students with grades ABOVE average (%.2f):\n", average);
    printf("==========================================\n");
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].grade > average) {
            printf("Name: %s, ID: %d, Grade: %d\n", 
                   students[i].name, students[i].id_card, students[i].grade);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found with grades above average.\n");
    }
    printf("\n");
}

/**
 * Function to print students with grades below average
 * 
 * @param students - array of student structures
 * @param count - number of students in the array
 * @param average - the average grade to compare against
 */
void print_below_average_students(student students[], int count, float average) {
    printf("Students with grades BELOW average (%.2f):\n", average);
    printf("==========================================\n");
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].grade < average) {
            printf("Name: %s, ID: %d, Grade: %d\n", 
                   students[i].name, students[i].id_card, students[i].grade);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students found with grades below average.\n");
    }
    printf("\n");
}

/**
 * Main function demonstrating student grade analysis
 * Shows students above/below average using reference parameters
 */
int main(void) {
    // Create array of sample students
    student students[] = {
        {"Alice Johnson", 12345, 85},
        {"Bob Smith", 23456, 92},
        {"Carol Brown", 34567, 78},
        {"David Wilson", 45678, 88},
        {"Emma Davis", 56789, 95},
        {"Frank Miller", 67890, 72},
        {"Grace Lee", 78901, 89}
    };
    
    // Calculate number of students using macro
    int student_count = ARRAY_SIZE(students);
    
    printf("=== Student Grade Analysis ===\n\n");
    
    // Display all students information first
    print_students_info(students, student_count);
    
    // Calculate average grade using reference parameter
    float average_grade;
    calculate_average_grade(students, student_count, &average_grade);
    
    // Display the calculated average
    printf("Average grade: %.2f\n\n", average_grade);
    
    // Print students with grades above average
    print_above_average_students(students, student_count, average_grade);
    
    // Print students with grades below average
    print_below_average_students(students, student_count, average_grade);
    
    return 0;
}
