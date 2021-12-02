#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float remain;
    int remain_cent, num_coins= 0;
    
    do
    {
        remain= get_float("Enter money: ");
    }
    while (remain < 0);
    
    remain_cent= round(remain*100);
    
    while (remain_cent> 0)
    {
        if (remain_cent>= 25)
        {
            remain_cent -= 25;
            num_coins+=1;
        }
        else if (remain_cent>= 10 && remain_cent< 25)
        {
            remain_cent-=10;
            num_coins+=1;
        }
        else if (remain_cent>=5 && remain_cent< 10)
        {
            remain_cent-=5;
            num_coins+=1;
        }
        else
        {
            remain_cent-=1;
            num_coins+=1;
        }

    }
    printf("%i", num_coins);
    
    
}
