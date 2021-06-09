#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int coins = 0;
    float owed = -1;

    while (owed < 0) // Checks if value entered is positive.
    {
        owed = get_float("Change owed: ");
    }
    
    owed = round(owed * 100); // Rounds coins to nearest penny.
    int leftover = (int) owed; // Acts as a "dump" for remaining coins after.

    coins += owed / 25; // Evaluates quarters.
    leftover %= 25;

    coins += leftover / 10; // Evaluates dimes.
    leftover %= 10;

    coins += leftover / 5; // Evaluates nickels.
    leftover %= 5;

    coins += leftover; // Since pennies are the smallest value, there is no need for a modulo.

    printf("%i\n", coins);
}
