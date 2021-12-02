// Implements a dictionary's functionality
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// gloabal variable for the total number of words in dictionary
unsigned int word_counter= 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_value = hash(word);
    node *cursor= table[hash_value];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) ==0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int i = tolower(word[0])%N;
    return i;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file= fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    node *temp= NULL;
    char *line= malloc(LENGTH + 1);
    if (line== NULL)
    {
        return false;
    }

    unsigned int hash_pointer_index; //determing hash value for the string

    while(fscanf(file, "%s", line) != EOF)
    {
        word_counter++;
        node *n= malloc(sizeof(node));
        if (n== NULL)
        {
            return false;
        }
        strcpy(n->word, line);
        n->next= NULL;
        
        hash_pointer_index=  hash(line);

        temp= table[hash_pointer_index];

        table[hash_pointer_index]= n;
        n->next= temp;

        // free(n);

    }
    fclose(file);
    free(line);
    // free(n);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor= NULL;
    for (int i=0; i<26; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            node * temp= cursor->next;
            free(cursor);
            cursor= temp;
        }
    }
    return true;
}
