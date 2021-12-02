#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int sentence_count(string s);
int * char_word_count(string s);


int main(void)
{    // Heart of the function
    string s= get_string("Enter a string: ");
    int *counts;
    int num_sentences= sentence_count(s);
    counts= char_word_count(s);
    int num_letters= counts[0], num_words= counts[1];
    
    
    float L, S;
    L= 100*(float) num_letters/num_words;
    S= 100*(float) num_sentences/num_words;
    int grade= round(0.0588 * L - 0.296 * S - 15.8);
    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade< 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
    
}


int sentence_count(string s)
{
    int sentence_count= 0;
    for (int i=0, n= strlen(s); i< n; i++)
    {
        if (s[i]== '.' || s[i]== '?' || s[i]== '!')
        {
            sentence_count++;
        }
    }
    return sentence_count;    
}

int * char_word_count(string s)
{
    static int count[]= {0 , 1};
    for (int i=0, n= strlen(s); i< n; i++)
    {
        if (isalpha(s[i]))
        {
            count[0]++;
        }
        else if (s[i]== ' ')
        {
            count[1]++;
        }
    }
    return count;
}
