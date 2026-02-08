#include<stdio.h>   // For printf output and scanf input functions
#include<math.h>    // For sqrt mathematical function

int main(){

    /* The file includes calculations of some rectangle
    like area, perimeter and diagonal  */

    // local variables definition:
    float length, width, area, perimeter, diagonal;

    // input data:
    printf("Enter length of rectangle: ");
    scanf("%f", &length);

    printf("Enter width of rectangle: ");
    scanf("%f", &width);

    // output data:
    printf("\nArea of rectangle: %0.1f", length * width);
    printf("\nPerimeter of rectangle: %0.1f", 2 * (length + width));
    printf("\nDiagonal of rectangle: %0.1f", sqrt(length * length + width * width));
    return 0;
}