#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    // Prompt the user for change owed, in cents
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (cents >= 25)
    {
        cents -= 25;
        quarters++;
    }
    // Calculate how many dimes you should give customer
    int dimes = 0;
    while (cents >= 10)
    {
        cents -= 10;
        dimes++;
    }
    // Calculate how many nickels you should give customer
    int nickels = 0;
    while (cents >= 5)
    {
        cents -= 5;
        nickels++;
    }
    // Calculate how many pennies you should give customer
    int pennies = 0;
    while (cents >= 1)
    {
        cents -= 1;
        pennies++;
    }
    // Sum the number of quarters, dimes, nickels, and pennies used
    int change = quarters + dimes + nickels + pennies;
    // Print that sum
    printf("%i\n", change);
}
