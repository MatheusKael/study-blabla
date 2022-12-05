#include <cs50.h>
#include <stdio.h>

void make_bricks(int quantity_of_bricks);

int main(void)
{
    int height;
    do {

     height = get_int("Height: ");

    } while ( height > 8 );

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j <= height * 2 - i; j++)
        {
            printf(" ");
        }
        make_bricks(i);
        make_bricks(i);

        printf("\n");
    }
    printf("\n");
}

void make_bricks(int quantity_of_bricks)
{

    for (int j = 0; j <= quantity_of_bricks + 1; j++)
    {

        if (j == quantity_of_bricks + 1)
        {
            printf("  ");
        }
        else
        {

            printf("#");
        }
    }
}