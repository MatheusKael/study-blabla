#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Verify if pixel is high, and turn it high too
            long decimalnum, quotient, remainder;

            while (quotient != 0)
            {
                remainder = quotient % 16;
                if (remainder < 10)
                    hexadecimalnum[j++] = 48 + remainder;
                else
                    hexadecimalnum[j++] = 55 + remainder;
                quotient = quotient / 16;
            }
            int average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            printf("%i |", average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
