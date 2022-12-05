#include <cs50.h>
#include <stdio.h>

void make_bricks(int quantity_of_bricks, int height, bool right_side);

int main(void)
{
    int height = get_int("Height: ");
    for (int i = 0; i < height; i++)
    {
        // printf("      ");
        for (int j = 1; j <= height * 2 - (2 * i); j++)
        {
            printf(" ");
        }
        make_bricks(i, height, true);
        make_bricks(i, height, false);
        printf("\n");
    }
    printf("\n");
}

void make_bricks(int quantity_of_bricks, int height, bool right_side)
{

    for (int j = 0; j <= quantity_of_bricks + 1; j++)
    {

        if (j == quantity_of_bricks + 1)
        {
            for (int k = 1; k <= height * 2 - (2 * j); k++)
            {
                printf(" ");
            }
        }
        else
        {

            printf("#");
        }
    }
}