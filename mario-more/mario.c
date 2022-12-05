#include <cs50.h>
#include <stdio.h>

void make_bricks(int quantity_of_bricks);

int main(void)
{
    int height;

    do
    {

        height = get_int("Height: ");

    } while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        make_bricks(i);
        printf("  ");
        make_bricks(i);

        printf("\n");
    }
}

void make_bricks(int quantity_of_bricks)
{

    for (int j = 0; j <= quantity_of_bricks; j++)
    {
        printf("#");
    }
}