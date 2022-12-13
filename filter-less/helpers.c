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
            long quotient, remainder;
            int hexadecimalnum;
            int k = 0;

            int average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            quotient = average;
            while (quotient != 0)
            {
                remainder = quotient % 16;
                if (remainder < 10)
                    hexadecimalnum = 48 + remainder;
                else
                    hexadecimalnum = 55 + remainder;
                quotient = quotient / 16;
            }

            image[i][j].rgbtRed = hexadecimalnum;
            image[i][j].rgbtGreen = hexadecimalnum;
            image[i][j].rgbtBlue = hexadecimalnum;
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
