#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size = 0;
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    } while (start_size < 9);

    int end_size = 0;

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    } while (end_size < start_size);

    if (start_size == end_size)
    {
        printf("Years: 1\n");
        return 1;
    }
    // TODO: Calculate number of years until we reach threshold

    int new_born = 0;
    int dead = 0;
    int number_of_years = 0;

    do
    {
        new_born = start_size / 3;
        dead = start_size / 4;

        start_size = start_size + new_born - dead;
        number_of_years++;
    } while (start_size < end_size);

    // TODO: Print number of years

    printf("Years: %i\n", number_of_years);
}
