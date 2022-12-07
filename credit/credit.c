#include <cs50.h>
#include <stdio.h>

// American Express StartNumbers (findStartNumbers) with 34 or 37 -> Valid number 371844824216560
// MasterCard StartNumbers with 51, 52, 53, 54, or 55
// Visa StartNumbers with 4. -> 4003600000000014

int check_if_number_is_two_digits(int number, int checksum);
int find_start_numbers(long number);
void check_credit_type(int number);

int main(void)
{
    long number = get_long("Number: ");

    int checksum = 0;
    int checksum_second = 0;
    long second_to_last_digit = number;
    long first_to_last_digit = number;
    long start_numbers = find_start_numbers(number);

    int count = 0;
    do
    {
        // 4003600000000014 -> 1.4 -> 4
         long first_digit_result = (first_to_last_digit % 100) % 10;
        // printf("%li | ", first_digit_result);

        // 4003600000000014 -> 1.4 -> 1 * 2 = 2
        // 369421438430814
        // 4062901840
        long second_digit_result = ((second_to_last_digit % 100) / 10) * 2;
        checksum_second +=first_digit_result;
        checksum = check_if_number_is_two_digits(second_digit_result, checksum) ;
        printf("checksum %i", checksum);
        printf("checksum_second %i \n", checksum_second);
        first_to_last_digit /= 100;
        second_to_last_digit /= 100;

        count++;
    } while (count < 20);

    if (checksum % 10 == 0)
    {
        check_credit_type(start_numbers);
    }
    else
    {
        printf("INVALID\n");
    }
}

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

void check_credit_type(int number)
{



    if (number / 10 == 4)
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

int find_start_numbers(long number)
{
    do
    {
        number = number / 10;

    } while (number >= 100);

    return number;
}