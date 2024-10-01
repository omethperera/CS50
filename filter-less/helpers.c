#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0;
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sep_red = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            if (sep_red <= 255)
            {
                image[i][j].rgbtRed = sep_red;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            int sep_green = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);

            if (sep_green <= 255)
            {
                image[i][j].rgbtGreen = sep_green;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            int sep_blue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sep_blue <= 255)
            {
                image[i][j].rgbtBlue = sep_blue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red_sum = 0, green_sum = 0, blue_sum = 0, total_pixels = 0;
            for (int updated_row = i - 1; updated_row < i + 2; updated_row++)
            {
                for (int updated_column = j - 1; updated_column < j + 2; updated_column++)
                {
                    if (updated_row >= 0 && updated_row < height && updated_column >= 0 &&
                        updated_column < width)
                    {
                        red_sum = red_sum + image[updated_row][updated_column].rgbtRed;
                        green_sum = green_sum + image[updated_row][updated_column].rgbtGreen;
                        blue_sum = blue_sum + image[updated_row][updated_column].rgbtBlue;
                        total_pixels = total_pixels + 1;
                    }
                }
            }
            copy[i][j].rgbtRed = round(red_sum / total_pixels);
            copy[i][j].rgbtGreen = round(green_sum / total_pixels);
            copy[i][j].rgbtBlue = round(blue_sum / total_pixels);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
