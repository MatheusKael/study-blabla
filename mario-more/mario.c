#include <cs50.h>
#include <stdio.h>

void make_bricks(int quantity_of_bricks);

int main(void)
{
    int height = get_int("Height: ");

    for (int i = 0; i < height; i++)
    {
        make_bricks(i);
        printf("  ");
        make_bricks(i);
        printf("\n");
    }
    printf("\n");
}

void make_bricks(int quantity_of_bricks)
{
        printf(" ");
    for (int j = 0; j <= quantity_of_bricks; j++)
    {
        printf("#");
    }
}