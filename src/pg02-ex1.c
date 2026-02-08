#include <stdio.h>   // For printf output and scanf input functions
#include <math.h>    // For sqrt mathematical function

int main() {

    /* The function calculates quadratic equation solutions. */

    // Declare variables
    float a, b, c, discriminant, denominator,vertex_of_parabola, shift_from_vertex, re, im;  
    // Get user input
    printf("Enter coefficient a: ");
    scanf("%f", &a); 
    printf("Enter coefficient b: ");
    scanf("%f", &b);
    printf("Enter coefficient c: ");
    scanf("%f", &c);

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;

    // Calculate and display roots based on the discriminant
    if (a != 0){
        //Basic values:
        denominator = 2 * a;
        vertex_of_parabola = -b / denominator;

        // Calculate roots based on the discriminant value:
        if (discriminant > 0) {
            // Calculate shift from vertex:
            shift_from_vertex = sqrt(discriminant) / denominator;

            // Real and different roots case:
            printf("Roots are real and different.\n");
            printf("x_1 = %.2f\n", vertex_of_parabola + shift_from_vertex);
            printf("x_2 = %.2f\n", vertex_of_parabola - shift_from_vertex); 
        }
        else if (discriminant == 0) {
            // Real and same roots case:
            printf("Roots are real and the same.\n");
            printf("x_1 = x_2 = %.2f\n", vertex_of_parabola);
        }
        else {
            // Complex roots case:
            re = vertex_of_parabola;
            im = sqrt(-discriminant) / denominator;

            printf("Roots are complex and different.\n");
            printf("x_1 = %.2f + %.2fi\n", re, im);
            printf("x_2 = %.2f - %.2fi\n", re, im);
        }
    }else{
        // Linear equation case: bx + c = 0:
        if (b != 0) {
            printf("Linear equation detected.\n");
            printf("x = %.2f\n", -c/b);
        } else {
            if (c != 0) {
                printf("No solution exists.\n");
            } else {
                printf("Infinite solutions exist.\n");
            }
        }
    }
    return 0;
}