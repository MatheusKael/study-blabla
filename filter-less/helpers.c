#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// check50 cs50/problems/2022/x/filter/less
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

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

            if (round(newRed) > 255)
            {
                newRed = 255;
            }
            if (round(newGreen) > 255)
            {
                newGreen = 255;
            }

            image[i][j].rgbtRed = round(newRed);
            image[i][j].rgbtGreen = round(newGreen);
            image[i][j].rgbtBlue = round(newBlue);
            // printf("%i %i", image[i][j].rgbtRed, image[i][j].rgbtGreen);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE tmp = image[0][0];

    for (int i = 0; i < height; i++)
    {

        int start = 0;
        int end = width - 1;

        while (start < end)
        {
            tmp = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = tmp;

            start++;
            end--;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    float average = 0;
    int count_average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = 0;
            count_average = 0;
            for (int k = i - 1; k <= i + 1 && k < height; k++)
            {
                for (int y = j - 1; y <= j + 1 && y < width; y++)
                {

                    if (k < height && y < width && y >= 0)
                    {
                        average = average + (image[k][y].rgbtRed + image[k][y].rgbtGreen + image[k][y].rgbtBlue);
                        count_average++;
                        // printf(" (%i, %i | %i, %i) ", k, y, i, j);
                    }
                }
                // printf("\n");
            }
            copy[i][j].rgbtRed = average / count_average;
            copy[i][j].rgbtBlue = average / count_average;
            copy[i][j].rgbtGreen = average / count_average;
            // printf("\n");
            // printf("\n");
            // printf("\n");
            // printf("\n");
        }
    }

    return;
}
