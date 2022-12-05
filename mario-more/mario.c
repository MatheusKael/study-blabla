#include <cs50.h>
#include <stdio.h>

void make_bricks(int quantity_of_bricks);

int main(void)
{
    int height = get_int("Height: ");
    for (int i = 0; i < height; i++)
    {
        printf("     ");
        make_bricks(i);
        make_bricks(i);
        printf("\n");
    }
    printf("\n");
}

void make_bricks(int quantity_of_bricks)
{

  int plus_one = quantity_of_bricks + 1;

    for (int j = 0; j <= plus_one; j++)
    {
        int test = plus_one ;
        printf("%i", test);
        // if (j == )
        // {
        //     printf("  ");
        // }
        // else
        // {
        //     printf("#");
        // }
    }
}