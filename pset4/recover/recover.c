#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    int image_count= 0;
    if (argc != 2) //confirming only 2 cli arguments were provided
    {
        printf("Enter only two CLI arguments");
        return 1;
    }
    FILE *card= fopen(argv[1], "r"); //opening the card
    if (card== NULL)
    {
        return 1;
    }

    char file_name[8];
    file_name[7]= '\0';

    sprintf(file_name, "%03i.jpg", image_count);
    FILE *image= fopen(file_name , "w");
    if (image== NULL)
    {
        fclose(card);
        return 1;
    }

    BYTE chunk[512];
    

    while (fread(chunk, sizeof(BYTE), 512, card))
    {
        if ((chunk[0]!= 0xff || chunk[1]!= 0xd8 || chunk[2]!=0xff || (chunk[3] & 0xf0) != 0xe0) && image_count==0)
        {
            continue;
        }
        //confirming that the chunk is the start of the first image
        else if (chunk[0]== 0xff && chunk[1]== 0xd8 && chunk[2]==0xff && (chunk[3] & 0xf0) == 0xe0) 
        {
        
            if (image_count== 0)
            {
                // sprintf(file_name, "%03i.jpg\n", image_count);
                // FILE *image= fopen(file_name,"w");
                fwrite(chunk, sizeof(BYTE), 512, image);
                image_count++;
            }
            else
            {
                // fclose(image);
                
                sprintf(file_name, "%03i.jpg", image_count);
                
                image= fopen(file_name,"w");
                fwrite(chunk, sizeof(BYTE), 512, image);

                image_count++;
            }
        
        }
        else
        {
            fwrite(chunk, sizeof(BYTE), 512, image);
        }

    }
    fclose(image);
    fclose(card);
}
