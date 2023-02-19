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

RGBTRIPLE kernelx3(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE kernel[3][3];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-2, 0, 1}};
    for (int k = i - 1, count_i = 0; k <= i + 1; k++, count_i++)
    {
        for (int y = j - 1, count_j = 0; y <= j + 1; y++, count_j++)
        {

            if (y >= 0 && k >= 0)
            {
                kernel[count_i][count_j].rgbtRed = image[k][y].rgbtRed;
                kernel[count_i][count_j].rgbtBlue = image[k][y].rgbtBlue;
                kernel[count_i][count_j].rgbtGreen = image[k][y].rgbtGreen;
                // printf("%i", image[k][y].rgbtRed);
                continue;
            }
            kernel[count_i][count_j].rgbtRed = 0;
            kernel[count_i][count_j].rgbtBlue = 0;
            kernel[count_i][count_j].rgbtGreen = 0;
        }
        // printf("\n");
    }

    int green_sum = 0;
    int blue_sum = 0;
    int red_sum = 0;
    int green_sumY = 0;
    int blue_sumY = 0;
    int red_sumY = 0;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            // printf(" (%i) *", kernel[row][col].rgbtBlue);
            // printf("(%i) ", Gx[row][col]);
            // printf("( %i %i | %i %i )", i, j, row, col);
            // printf(" (%i)", Gx[row][col]);
            red_sum = red_sum + (kernel[row][col].rgbtRed * Gx[row][col]);
            red_sumY = red_sumY + (kernel[row][col].rgbtRed * Gx[col][row]);
            // printf("(%i)", copy[k][y].rgbtBlue);

            blue_sum = blue_sum + (kernel[row][col].rgbtBlue * Gx[row][col]);
            blue_sumY = blue_sumY + (kernel[row][col].rgbtBlue * Gx[col][row]);

            green_sum = green_sum + (kernel[row][col].rgbtGreen * Gx[row][col]);
            green_sumY = green_sumY + (kernel[row][col].rgbtGreen * Gx[col][row]);
        }
        // printf("\n");
    }

    int red_value = round(sqrt(pow(red_sum, 2) + pow(red_sumY, 2)));
    int blue_value = round(sqrt(pow(blue_sum, 2) + pow(blue_sumY, 2)));
    int green_value = round(sqrt(pow(green_sum, 2) + pow(green_sumY, 2)));
    image[i][j].rgbtRed = red_value > 0 ? red_value: 0;
    image[i][j].rgbtBlue = blue_value > 0 ? blue_value : 0;
    image[i][j].rgbtGreen = green_value > 0 ? green_value : 0;
    // printf("  %i  ", red_value);
    return image[i][j];
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    grayscale(height, width, image);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
   for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = kernelx3(i, j, height, width, copy);
        }
    }
   return;
}
