#include "helpers.h"
#include <math.h>
#include <stdio.h> 
// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int grey;
    for (int i= 0; i< height; i++)
    {
        for (int j= 0; j< width; j++)
        {
            
            grey = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);

            // printf("%i", grey);
            image[i][j].rgbtBlue= grey;
            image[i][j].rgbtGreen= grey;
            image[i][j].rgbtRed= grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    double sepiaRed, sepiaGreen, sepiaBlue;
    // int ;
    for (int i=0; i< height; i++)
    {
        for (int j=0; j< width; j++)
        {
            sepiaRed= .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            if (sepiaRed>255)
            {
                sepiaRed= 255;
            } 
            if (sepiaGreen>255)
            {
                sepiaGreen= 255;
            } 
            if (sepiaBlue>255)
            {
                sepiaBlue= 255;
            }
            
            image[i][j].rgbtRed = (int) round(sepiaRed);
            image[i][j].rgbtGreen = (int) round(sepiaGreen);
            image[i][j].rgbtBlue = (int) round(sepiaBlue);
        }
        
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w= (int) (width/2);
    int temp_red, temp_green, temp_blue; 
    for (int i=0; i< height; i++)
    {
        for (int j=0; j< w; j++)
        {
            
            temp_red= image[i][j].rgbtRed;
            temp_green= image[i][j].rgbtGreen;
            temp_blue= image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][j].rgbtGreen= image[i][width-j-1].rgbtGreen; 
            image[i][j].rgbtBlue= image[i][width-j-1].rgbtBlue;

            image[i][width-j-1].rgbtRed = temp_red;
            image[i][width-j-1].rgbtGreen = temp_green;
            image[i][width-j-1].rgbtBlue = temp_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edited[height][width];
    float blur_r, blur_g, blur_b; 
    int num_pixel;
    
    for (int h=0; h< height; h++)
    {
        for (int w=0; w< width; w++)
        {
            num_pixel= 0;
            blur_r= 0., blur_g= 0., blur_b= 0.;
            
            for (int i= -1; i<2; i++)
            {
                for (int j= -1; j<2; j++)
                {
                    if ((h+i<0) || (h+i)> height-1)
                    {
                        continue; //skip
                    }
                    if ((j+w<0) || (j+w)> width-1)
                    {
                        continue; //skip
                    }
                    blur_r += image[i+h][j+w].rgbtRed;
                    blur_g += image[i+h][j+w].rgbtGreen;
                    blur_b += image[i+h][j+w].rgbtBlue;
                    num_pixel++;
                }
            }
            edited[h][w].rgbtRed = (int) round(blur_r/num_pixel);
            edited[h][w].rgbtGreen = (int) round(blur_g/num_pixel);
            edited[h][w].rgbtBlue = (int) round(blur_b/num_pixel);

        }
            
    }
    for (int h= 0; h< height; h++)
    {
        for (int w=0; w< width; w++)
        {
            image[h][w].rgbtRed = edited[h][w].rgbtRed;
            image[h][w].rgbtGreen= edited[h][w].rgbtGreen;
            image[h][w].rgbtBlue= edited[h][w].rgbtBlue;
        }
    }
    return;
}    

