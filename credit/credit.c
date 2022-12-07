#include <cs50.h>
#include <stdio.h>

// American Express StartNumbers (findStartNumbers) with 34 or 37 -> Valid number 371844824216560
// MasterCard StartNumbers with 51, 52, 53, 54, or 55
// Visa StartNumbers with 4. -> 4003600000000014

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

        long first_digit_result = (second_to_last_digit % 100) % 10;
        long second_digit_result = ((second_to_last_digit % 100) / 10) * 2;

        checksum = check_if_result_is_bigger(second_digit_result, checksum) + first_digit_result;
        first_digit_result /= 100;
        second_to_last_digit /= 100;

        count++;
    } while (count < 20);

    if (checksum % 10 == 0)
    {
        checkCreditCardType(start_numbers);
    }
    else
    {
        printf("INVALID\n");
    }
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
        printf("VISA");
    }
    else if (number > 10 & number < 50)
    {
        printf("AMEX");
    }
    else
    {
        printf("MASTERCARD");
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