#include <stdio.h>   // For printf output and scanf input functions

int main(){
    /* The file includes calculations of some bills' count*/

    // local variables definition:
    int sum, bills_20, bills_10, bills_5, bills_1;

    // input data:
    printf("Enter the sum of money: ");
    scanf("%d", &sum);
    
    // calculate the needed data:
    bills_20 = sum / 20;
    sum %= 20;
    bills_10 = sum / 10;
    sum %= 10;
    bills_5 = sum / 5;
    sum %= 5;
    bills_1 = sum;

    // output data:
    printf("\ntwenty - %d\n", bills_20);
    printf("ten - %d\n", bills_10);
    printf("five - %d\n", bills_5);
    printf("one - %d\n", bills_1);
    return 0;
}