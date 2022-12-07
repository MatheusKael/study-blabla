#include <cs50.h>
#include <stdio.h>

// American Express StartNumbers (findStartNumbers) with 34 or 37 -> Valid number 371844824216560
// MasterCard StartNumbers with 51, 52, 53, 54, or 55
// Visa StartNumbers with 4. -> 4003600000000014

int check_if_number_is_two_digits(int number, int checksum);
int find_start_numbers(long number);
void check_credit_type(int number, int number_of_digits);

int main(void)
{
    long number = get_long("Number: ");

    int checksum = 0;
    long second_to_last_digit = number;
    long first_to_last_digit = number;
    long start_numbers = find_start_numbers(number);
    int number_of_digits = 0;

    do
    {
        number /= 10;
        ++number_of_digits;
    }
    while (number != 0);

    int count = 0;
    do
    {
        // 4003600000000014 -> 1.4 -> 4
        long first_digit_result = (first_to_last_digit % 100) % 10;
        // 4003600000000014 -> 1.4 -> 1 * 2 = 2
        long second_digit_result = ((second_to_last_digit % 100) / 10) * 2;

        checksum = check_if_number_is_two_digits(second_digit_result, checksum) + first_digit_result;
        first_to_last_digit /= 100;
        second_to_last_digit /= 100;

        count++;
    }
    while (count < number_of_digits);

    if (checksum % 10 == 0)
    {
        check_credit_type(start_numbers, number_of_digits);
    }
    else
    {
        printf("INVALID\n");
    }
}

int validate_card_number(int initial_checksum,)

int check_if_number_is_two_digits(int number, int checksum)
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

void check_credit_type(int number, int number_of_digits)
{

    if (number / 10 == 4 & number_of_digits == 16 || number_of_digits == 13)
    {
        printf("VISA");
    }
    else if (number == 34 || number == 37 & number_of_digits == 15)
    {
        printf("AMEX");
    }
    else if (number > 50 & number < 56 & number_of_digits == 16)
    {
        printf("MASTERCARD");
    }
    else
    {
        printf("INVALID");
    }

    printf("\n");
}

int find_start_numbers(long number)
{
    do
    {
        number = number / 10;

    }
    while (number >= 100);

    return number;
}