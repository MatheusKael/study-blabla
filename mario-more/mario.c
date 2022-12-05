#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");

    for (int i = 0; i < height; i++)
    {
        int bricks_quantity = i;
        for (int j = 0; j <= bricks_quantity; j++)
        {

            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= bricks_quantity; j++)
        {

            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}