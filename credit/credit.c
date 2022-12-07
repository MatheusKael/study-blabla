#include <cs50.h>
#include <stdio.h>

// American Express numbers start with 34 or 37 -> Valid number 371844824216560
// MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa numbers start with 4. -> 4003600000000014

int check_if_result_is_bigger(int number, int checksum);
int findStartNumbers(long number);
void checkCreditCardType(int number);

int main(void)
{
    long number = get_long("Number: ");

    int checksum = 0;
    long second_to_last_digit = number;
    long start_numbers = findStartNumbers(number);

    int count = 0;
    do
    {

        long digit_result = ((second_to_last_digit % 100) / 10) * 2;


        checksum = check_if_result_is_bigger(digitResult, checksum);
        second_to_last_digit /= 100;

        printf("%i |", checksum);
        count++;
    } while (count < 20);

    checkCreditCardType(start_numbers);
}

int check_if_result_is_bigger(int number, int checksum)
{

    if (number >= 10)
    {
        checksum += number / 10;
        checksum += number % 10;
    }
    else
    {

        checksum += number;
    }

    return checksum;
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