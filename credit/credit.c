#include <cs50.h>
#include <stdio.h>

// American Express numbers start with 34 or 37 -> Valid number 371844824216560
// MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa numbers start with 4.

int findStartNumbers(long number);

void checkCreditCardType(int number);

int main(void)
{
    long number = get_long("Number: ");

    int checksum = 0;
    long second_to_last_digit = number;
    long start_numbers = findStartNumbers(number);
    do
    {

        second_to_last_digit =second_to_last_digit / 10;
        printf("%li |", second_to_last_digit);
        checksum++;
    } while (checksum <= 10);

    checkCreditCardType(start_numbers);
}

void checkCreditCardType(int number)
{
    if (number < 10)
    {
        printf("Visa.");
    }
    else if (number > 10 & number < 50)
    {
        printf("American Express.");
    }
    else
    {
        printf("MasterCard.");
    }
    printf("\n");
}

int findStartNumbers(long number)
{
    do
    {
        number = number / 10;

    } while (number >= 100);

    return number;
}