#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int num_lines;
    do
    {
        num_lines= get_int("Enter number of lines ");
    }
    while (num_lines> 8 || num_lines<1);

    int j;
    for (int count=1; count< num_lines+1; count++)
    {
        j=0;
        while (j< num_lines-count)
        {
            printf(".");
            j++;
        }
        int k= 0;
        while (k< count)
        {
            printf("#");
            k++;
        }
        printf("\n");
        
    }
    
    
}
