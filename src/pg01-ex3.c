#include <stdio.h>   // For printf output and scanf input functions

int main() {

    /* The function calculates the cost of fuel for a trip, 
       given the price per liter of fuel, the distance, and the car's efficiency. */

    // Declare variables
    float price_per_liter, distance_km, efficiency_km_per_liter, total_cost;

    // Get user input
    printf("Enter fuel price (shekels per liter): ");
    scanf("%f", &price_per_liter); 
    printf("Enter the distance (km) : ");
    scanf("%f", &distance_km);
    printf("Enter the car efficiency (km per liter): ");
    scanf("%f", &efficiency_km_per_liter);

    // Calculate total cost
    total_cost = (distance_km / efficiency_km_per_liter) * price_per_liter;
    
    // Display the result
    printf("Total cost of fuel will be : %.2f shekels.\n", total_cost);
    
    return 0;
}