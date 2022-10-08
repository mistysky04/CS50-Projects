//Applies grayscale, sepia, reflect, and blur filters to provided image files via "$ ./filter -g/s/r/b INFILE.bmp OUTFILE.bmp"

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through every row in picture
    for (int i = 0; i < height; i++)
    {
        //Loop through every pixel across each row
        for (int j = 0; j < width; j++)
        {
            //Calculate average of all RGB values for each pixel
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
            //Set this average as the RGB values for each pixel
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through every row in picture
    for (int i = 0; i < height; i++)
    {
        //Loop through every pixel across each row
        for (int j = 0; j < width; j++)
        {
            //Calculate sepia RGB values using formula
            int sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            //If sepia colours are > 255, cap the value at 255 inclusive
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
    //Loop through every row in picture
    for (int i = 0; i < height; i++)
    {
        //Loop through every pixel across each row
        for (int j = 0; j < (round(width/2)); j++)
        {
            //Name of array = pointer to first element of array (holds address of first element)
            //Create buffer to hold pointer to first pixel
            RGBTRIPLE *ptr = &image[i][j];
            RGBTRIPLE temp = *ptr;
            //Create variable to hold pointer to last pixel
            RGBTRIPLE *ptrLast = &image[i][width - (j + 1)];
            //Replace 1st pixel with last pixel and last pixel with 1st stored in temp variable
             *ptr = *ptrLast;
             *ptrLast = temp;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create array to hold copy of original image
    RGBTRIPLE copy[height][width];
    //Copy each pixel from original image into copy array pixel-by-pixel
    //Go through each row
    for(int i = 0; i < height; i++)
    {
        //Go through every pixel in each row
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image [i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Variables to keep track of total RGB values from each pixel
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            //Counter will keep track of valid pixels
            int counter = 0;

            //For each pixel, get RGB values from neighbouring pixels
            for (int row = -1; row < 2; row++)
            {
                for (int column = -1; column < 2; column++)
                {
                    int currentRow = i + row;
                    int currentColumn = j + column;

                    //Check if valid
                    if (currentRow < 0 || currentRow >= height|| currentColumn < 0 || currentColumn >= width)
                    {
                        continue;
                    }
                    //Get image value
                    totalRed += copy[currentRow][currentColumn].rgbtRed;
                    totalGreen += copy[currentRow][currentColumn].rgbtGreen;
                    totalBlue += copy[currentRow][currentColumn].rgbtBlue;

                    counter++;

                    //calculate average of neighouring pixels
                    copy[i][j].rgbtRed = round(totalRed/counter);
                    copy[i][j].rgbtGreen = round(totalGreen/counter);
                    copy[i][j].rgbtBlue = round(totalBlue/counter);
                }
            }
            //Copy new pixels into original image
            for (int k = 0; k < height; k++)
            {
                for (int l = 0; l < width; l++)
                {
                    image[k][l].rgbtRed = copy[k][l].rgbtRed;
                    image[k][l].rgbtGreen = copy[k][l].rgbtGreen;
                    image[k][l].rgbtBlue = copy[k][l].rgbtBlue;
                }
            }
        }
    }
    return;
}
