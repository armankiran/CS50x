// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// number of words
int text_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int head = hash(word);
    node *cursor = table[head];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
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
    // TODO: Improve this hash function
    char initial = word[0];
    int ascii = tolower(initial);
    ascii = ascii - 97;
    return ascii;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return 1;
    }
    // allocate memory
    char s[LENGTH + 1];
    // read file
    while (fscanf(file, "%s", s) == 1)
    {
        // allocate memory and check the hash

        node *n = malloc(sizeof(node));
        strcpy(n->word, s);
        int index = hash(n->word);
        // check hash table and insert
        if (table[index] == NULL)
        {
            table[index] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        text_size += 1;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (text_size > 0)
    {
        return text_size;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
