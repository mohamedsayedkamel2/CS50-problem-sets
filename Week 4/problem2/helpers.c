#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    //This nested loop will iterate over each pixle in the image
    //Each pixle has 3 values RED and GREEN and BLUE
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            average = 0;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float originalRed = 0;
    float originalBlue = 0;
    float originalGreen = 0;
    
    //The first loop will iterate over each row in the image
    for (int i = 0; i < height; i++)
    {
        //The second loop will iterate over each pixple in the image
        for (int j = 0; j < width; j++)
        {
            //First step: store each pixle's original state before we apply the formula to it
            originalRed = image[i][j].rgbtRed;
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;
            //Convert the float value into an integer and check if it's higher than 255 if yes then make the value = 255
            //Do this for all colors
            int newRedColor = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (newRedColor > 255)
            {
                newRedColor = 255;
            }
            image[i][j].rgbtRed = newRedColor;

            int newGreenColor = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (newGreenColor > 255)
            {
                newGreenColor = 255;
            }
            image[i][j].rgbtGreen = newGreenColor;
            
            int newBlueColor = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (newBlueColor > 255)
            {
                newBlueColor = 255;
            }
            image[i][j].rgbtBlue = newBlueColor;
        }
    }
}

/* Reflect image horizontally
/This function is built upon the idea of switching items in an array
Another approach which can be taken is two pointers*/
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //Store the jth pixple in temp variable
            temp = image[i][j];
            //Swap the width - j + 1th pixle with the jth pixle
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalBlue = 0, totalGreen = 0;
            float counter = 0.00;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;
                    
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    counter++;
                }
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
}
