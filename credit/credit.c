#include <cs50.h>
#include <stdio.h>

// American Express numbers start with 34 or 37 -> Valid number 371844824216560
// MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa numbers start with 4.

int main(void)
{
    long number = get_long("Number: ");

    int first_digits = number;

    do
    {
        first_digits = first_digits % 10;

    } while (first_digits < 100);

    printf("%i\n", first_digits);
}