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
            if (image[i][j].rgbtBlue < 50)
            {
                image[i][j].rgbtRed = 0x20;
                image[i][j].rgbtGreen = 0x20;
                image[i][j].rgbtBlue = 0x20;
                printf("%i |", image[i][j].rgbtBlue);
            }
            else if (image[i][j].rgbtBlue > 200)
            {

                image[i][j].rgbtRed = 0xff;
                image[i][j].rgbtGreen = 0xff;
                image[i][j].rgbtBlue = 0xff;
            } else  {

                image[i][j].rgbtRed = 0xa1;
                image[i][j].rgbtGreen = 0xa1;
                image[i][j].rgbtBlue = 0xa1;
            }
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
