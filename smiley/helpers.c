#include "helpers.h"
#include <stdio.h>


void colorize(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%i", image[height][width].rgbtBlue);
        }
    }
}