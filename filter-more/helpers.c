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

typedef struct
{
    float red_sum;
    float blue_sum;
    float green_sum;
} colors;

colors convolution(int height, int width, int row, int col, int kernel[3][3], RGBTRIPLE image[height][width])
{
    float red_sum = 0;
    float blue_sum = 0;
    float green_sum = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (i + row < 0 || i + row >= height)
            {
                continue;
            }
            if (j + col < 0 || j + col >= width)
            {
                continue;
            }

            // printf("%i", image[row + i][col + j].rgbtRed );
            // if (row >= 0 && col >= 0)
            // {
            red_sum = red_sum + image[i + row][j + col].rgbtRed * kernel[i][j];
            green_sum = green_sum + image[i + row][j + col].rgbtGreen * kernel[i][j];
            blue_sum = blue_sum + image[i + row][j + col].rgbtBlue * kernel[i][j];
            //     continue;
            // }
        }
        // printf("\n");
    }
    colors sums;
    sums.red_sum = red_sum > 255 ? 255 : red_sum;
    sums.blue_sum = blue_sum > 255 ? 255 : blue_sum;
    sums.green_sum = green_sum > 255 ? 255 : green_sum;

    return sums;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{

    
    int mx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};
    int my[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}};
    // grayscale(height, width, image);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // convolution(height, width, i, j, mx, copy);
            colors sumsx = convolution(height, width, i, j, mx, image);

            colors sumsy = convolution(height, width, i, j, my, image);

            image[i][j].rgbtRed = round(sqrt(sumsx.red_sum * sumsx.red_sum + sumsy.red_sum * sumsy.red_sum));
            image[i][j].rgbtBlue = round(sqrt(sumsx.blue_sum * sumsx.blue_sum + sumsy.blue_sum * sumsy.blue_sum));
            image[i][j].rgbtGreen = round(sqrt(sumsx.green_sum * sumsx.green_sum + sumsy.green_sum * sumsy.green_sum));
        }
    }
    return;
}
