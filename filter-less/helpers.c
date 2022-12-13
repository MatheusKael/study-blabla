#include "helpers.h"
#include <stdio.h>
#include <math.h>

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
            int hexadecimalNumber;
            int k = 0;

            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            // printf("%i", hexadecimalNumber);
            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    //  sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    //   sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    //   sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float newRed = (.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue);
            float newGreen = (.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue);
            float newBlue = (.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue);

            if (newRed > 255)
            {
                printf("%f |", newRed);
                newRed = 255;
            }
            else if (newGreen > 255)
            {
                printf("%f |", newGreen);
                newGreen = 255;
            }
            else if (newBlue > 255)
            {
                printf("%f |", newBlue);
                newBlue = 255;
            }

            image[i][j].rgbtRed = round(newRed);
            image[i][j].rgbtGreen = round(newGreen);
            image[i][j].rgbtBlue = round(newBlue);
        }
    }

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
