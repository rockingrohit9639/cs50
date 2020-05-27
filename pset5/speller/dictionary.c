// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

unsigned int num_words = 0;
bool is_loaded_dic = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char copy[strlen(word)];
    strcpy(copy , word);
    for (int i = 0; copy[i] != '\0'; i++)
    {
        copy[i] = tolower(copy[i]);
    }

    int index = hash(copy);
    if (table[index] != NULL)
    {
        for (node *nodeptr = table[index]; nodeptr != NULL; nodeptr = nodeptr ->next)
            if (strcmp(nodeptr -> word, copy) == 0)
                return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int n;
    for (int i=0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
            n = word[i] - 'a' + 1;
        else
            n = 27;

        hash = ((hash << 3) + n) % N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *infile = fopen(dictionary,"r");
    if (infile == NULL)
        return false;

    for (int i = 0; i < N; i++)
        table[i] = NULL;

    char word[LENGTH + 1];
    node *new_nodeptr;
    while(fscanf(infile, "%s", word) != EOF)
    {
        num_words++;
        do
        {
            new_nodeptr = malloc(sizeof(node));
            if (new_nodeptr == NULL)
                free(new_nodeptr);
        }
        while(new_nodeptr == NULL);

        strcpy(new_nodeptr -> word, word);
        int index = hash(word);
        //if (table[index] == NULL)
        //{
        //    new_nodeptr = NULL;
        //    table[index] = new_nodeptr;
        //}
        //else
        //{
            new_nodeptr -> next = table[index];
            table[index] = new_nodeptr;
        //}
    }

    fclose(infile);
    is_loaded_dic = true;
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!is_loaded_dic)
        return 0;

    return num_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!is_loaded_dic)
        return false;

    for(int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *ptr = table[i];
            while(ptr != NULL)
            {
                node *predptr = ptr;
                ptr = ptr -> next;
                free(predptr);
            }
        }
    }
    return true;
}
