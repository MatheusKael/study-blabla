#include "helpers.h"
#include <stdio.h>


void colorize(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < sizeof(BYTE); i++)
    {
        for (int j = 0; j < sizeof(BYTE); j++)
        {
            printf("%i", image[height][width].rgbtBlue);

        }
        printf("\n");
    }
}