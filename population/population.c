#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    int end_size;

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold

    int new_born= start_size;
    int dead = start_size;
    int number_of_years = 0;

    do {
        new_born = new_born / 3;
        dead = dead / 4;

        start_size = start_size + new_born - dead;
        number_of_years++;
    } while (start_size < end_size);

    // TODO: Print number of years
    printf("Number of years %i", number_of_years);
}
