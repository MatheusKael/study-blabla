#include "helpers.h"
#include <math.h>
#include <stdio.h>

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
    float green_average = 0;
    float blue_average = 0;
    float red_average = 0;
    int count_average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            green_average = 0;
            blue_average = 0;
            red_average = 0;
            count_average = 0;

            for (int k = i - 1; k <= i + 1 && k < height; k++)
            {
                for (int y = j - 1; y <= j + 1 && y < width; y++)
                {

                    if (k < height && y < width && y >= 0 && k >= 0)
                    {
                        red_average = red_average + copy[k][y].rgbtRed;
                        blue_average = blue_average + copy[k][y].rgbtBlue;
                        green_average = green_average + copy[k][y].rgbtGreen;

                        count_average++;
                    }
                }
            }
            image[i][j].rgbtRed = round(red_average / count_average);
            image[i][j].rgbtBlue = round(blue_average / count_average);
            image[i][j].rgbtGreen = round(green_average / count_average);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    float green_sum = 0;
    float blue_sum = 0;
    float red_sum = 0;
    float green_sumY = 0;
    float blue_sumY = 0;
    float red_sumY = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            green_sum = 0;
            blue_sum = 0;
            red_sum = 0;
            green_sumY = 0;
            blue_sumY = 0;
            red_sumY = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (k < height && y < width && y >= 0 && k >= 0)
                    {
                        red_sum = red_sum + (copy[k][y].rgbtRed * Gx[k][y]);
                        red_sumY = red_sumY + (copy[k][y].rgbtRed * Gx[y][k]);
                        // printf("(%i)", copy[k][y].rgbtBlue);
                        blue_sum = blue_sum + (copy[k][y].rgbtBlue * Gx[k][y]);
                        blue_sumY = blue_sumY + (copy[k][y].rgbtBlue * Gx[y][k]);

                        green_sum = green_sum + (copy[k][y].rgbtGreen * Gx[k][y]);
                        green_sumY = green_sumY + (copy[k][y].rgbtGreen * Gx[y][k]);
                        continue;
                    }
                    else
                    {
                        image[i][j].rgbtRed = 0;
                        image[i][j].rgbtBlue = 0;
                        image[i][j].rgbtGreen = 0;
                    }
                }
            }

            int red_value = round(sqrt(pow(red_sum, 2) + pow(red_sumY, 2)));
            int blue_value = round(sqrt(pow(blue_sum, 2) + pow(blue_sumY, 2)));
            int green_value = round(sqrt(pow(green_sum, 2) + pow(green_sumY, 2)));
            image[i][j].rgbtRed = red_value > 255 ? 255 : red_value;
            image[i][j].rgbtBlue = blue_value > 255 ? 255 : blue_value;
            image[i][j].rgbtGreen = green_value > 255 ? 255 : green_value;
        }
    }

    return;
}
