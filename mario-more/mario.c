#include <cs50.h>
#include <stdio.h>

void make_bricks(int quantity_of_bricks, bool right_side);

int main(void)
{
    int height = get_int("Height: ");
    for (int i = 0; i < height; i++)
    {
        // printf("      ");
        for (int o = height; o >= 0; o--)
        {
            printf(" ");
        }
        make_bricks(i, true);
        make_bricks(i, false);
        printf("\n");
    }
    printf("\n");
}

void make_bricks(int quantity_of_bricks, bool right_side)
{

    for (int j = 0; j <= quantity_of_bricks + 1; j++)
    {

        if (j == quantity_of_bricks + 1)
        {
            printf("  ");
        }
        else
        {
            if (quantity_of_bricks == 0 & j == 0 & right_side == true)
            {
                printf(" ");
            }

            printf("#");
        }
    }
}