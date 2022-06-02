#include "helpers.h"
#include "math.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    // loop through pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate sepia values
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // correct values bigger than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // correct colors
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp_red;
    int tmp_blue;
    int tmp_green;
    int end;
    for (int i = 0; i < height; i++)
    {
        end = width - 1;
        for (int j = 0, n = width / 2; j < n; j++)
        {
            tmp_red = image[i][j].rgbtRed;
            tmp_blue = image[i][j].rgbtBlue;
            tmp_green = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = image[i][end].rgbtRed;
            image[i][j].rgbtBlue = image[i][end].rgbtBlue;
            image[i][j].rgbtGreen = image[i][end].rgbtGreen;
            image[i][end].rgbtRed = tmp_red;
            image[i][end].rgbtBlue = tmp_blue;
            image[i][end].rgbtGreen = tmp_green;
            end -= 1;
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
            // left top corner
            if (i == 0 && j == 0)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i][j + 1].rgbtRed +
                                            image[i + 1][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed) /
                                           4.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i][j + 1].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen) /
                                             4.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i][j + 1].rgbtBlue +
                                             image[i + 1][j + 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue) /
                                            4.0);
            }
            // right top corner
            else if (i == 0 && j == width - 1)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i + 1][j].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed +
                                            image[i][j - 1].rgbtRed) /
                                           4.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i + 1][j].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen +
                                              image[i][j - 1].rgbtGreen) /
                                             4.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i + 1][j].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue +
                                             image[i][j - 1].rgbtBlue) /
                                            4.0);
            }
            // left bottom corner
            else if (i == height - 1 && j == 0)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i][j + 1].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed +
                                            image[i - 1][j].rgbtRed) /
                                           4.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i][j + 1].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen +
                                              image[i - 1][j].rgbtGreen) /
                                             4.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i][j + 1].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue) /
                                            4.0);
            }
            // right bottom corner
            else if (i == height - 1 && j == width - 1)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i][j - 1].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed +
                                            image[i - 1][j].rgbtRed) /
                                           4.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i][j - 1].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen +
                                              image[i - 1][j].rgbtGreen) /
                                             4.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i][j - 1].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue) /
                                            4.0);
            }
            // bottom
            else if (i == height - 1)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i][j + 1].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed +
                                            image[i - 1][j].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed +
                                            image[i][j - 1].rgbtRed) /
                                           6.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i][j + 1].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen +
                                              image[i - 1][j].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen +
                                              image[i][j - 1].rgbtGreen) /
                                             6.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i][j + 1].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue +
                                             image[i][j - 1].rgbtBlue) /
                                            6.0);
            }
            // right corner
            else if (j == width - 1)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i + 1][j].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed +
                                            image[i][j - 1].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed +
                                            image[i - 1][j].rgbtRed) /
                                           6.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i + 1][j].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen +
                                              image[i][j - 1].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen +
                                              image[i - 1][j].rgbtGreen) /
                                             6.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i + 1][j].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue +
                                             image[i][j - 1].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue) /
                                            6.0);
            }
            else if (i == 0)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i][j + 1].rgbtRed +
                                            image[i + 1][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed +
                                            image[i][j - 1].rgbtRed) /
                                           6.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i][j + 1].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen +
                                              image[i][j - 1].rgbtGreen) /
                                             6.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i][j + 1].rgbtBlue +
                                             image[i + 1][j + 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue +
                                             image[i][j - 1].rgbtBlue) /
                                            6.0);
            }
            else if (j == 0)
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i - 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed +
                                            image[i][j + 1].rgbtRed +
                                            image[i + 1][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed) /
                                           6.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i - 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen +
                                              image[i][j + 1].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen) /
                                             6.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i - 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue +
                                             image[i][j + 1].rgbtBlue +
                                             image[i + 1][j + 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue) /
                                            6.0);
            }
            else
            {
                //red
                copy[i][j].rgbtRed = round((image[i][j].rgbtRed +
                                            image[i - 1][j].rgbtRed +
                                            image[i - 1][j + 1].rgbtRed +
                                            image[i][j + 1].rgbtRed +
                                            image[i + 1][j + 1].rgbtRed +
                                            image[i + 1][j].rgbtRed +
                                            image[i + 1][j - 1].rgbtRed +
                                            image[i][j - 1].rgbtRed +
                                            image[i - 1][j - 1].rgbtRed) /
                                           9.0);
                //green
                copy[i][j].rgbtGreen = round((image[i][j].rgbtGreen +
                                              image[i - 1][j].rgbtGreen +
                                              image[i - 1][j + 1].rgbtGreen +
                                              image[i][j + 1].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen +
                                              image[i + 1][j - 1].rgbtGreen +
                                              image[i][j - 1].rgbtGreen +
                                              image[i - 1][j - 1].rgbtGreen) /
                                             9.0);
                //blue
                copy[i][j].rgbtBlue = round((image[i][j].rgbtBlue +
                                             image[i - 1][j].rgbtBlue +
                                             image[i - 1][j + 1].rgbtBlue +
                                             image[i][j + 1].rgbtBlue +
                                             image[i + 1][j + 1].rgbtBlue +
                                             image[i + 1][j].rgbtBlue +
                                             image[i + 1][j - 1].rgbtBlue +
                                             image[i][j - 1].rgbtBlue +
                                             image[i - 1][j - 1].rgbtBlue) /
                                            9.0);
            }
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = copy[k][l].rgbtRed;
            image[k][l].rgbtGreen = copy[k][l].rgbtGreen;
            image[k][l].rgbtBlue = copy[k][l].rgbtBlue;
        }
    }
    return;
}
