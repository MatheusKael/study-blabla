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
            int quotient;
            int temp;
            char hexadecimalNumber[100];
            int k = 0;

            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            quotient = average;
            while (quotient != 0)
            {
                temp = quotient % 16;
                if (temp < 10)
                    temp = temp + 48;
                else
                    temp = temp + 55;
                hexadecimalNumber[i++] = temp;
                quotient = quotient / 16;
            }

            image[i][j].rgbtRed = hexadecimalNumber[j];
            image[i][j].rgbtGreen = hexadecimalNumber[j];
            image[i][j].rgbtBlue = hexadecimalNumber[j];
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
