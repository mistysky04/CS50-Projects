#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}


int get_cents(void)
{
    // prompt user for amount of coins they wish to give
    // code will continuously prompt until positive value is provided
    int cents;
    do
    {
        cents = get_int("How many cents are you giving?: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // The amount of quarters depends on how many times the input value can be subtracted from 25 while the remaining value is greater than or equal to that of a quarter i.e. 25
    // Cents will update with the new value after each iteration (i.e. each time, we will subtract the value of cents from 25)
    int quarters;
    for (quarters = 0; cents >= 25; quarters++)
    {
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Same rules as above and for the following, except with different coin values
    int dimes;
    for (dimes = 0; cents >= 10; dimes++)
    {
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickles;
    for (nickles = 0; cents >= 5; nickles++)
    {
        cents = cents - 5;
    }
    return nickles;
}

int calculate_pennies(int cents)
{
    int pennies;
    for (pennies = 0; cents >= 1; pennies++)
    {
        cents = cents - 1;
    }
    return pennies;
}
