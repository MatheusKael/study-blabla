// Implements a dictionary's functionality

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    char *dictionary_path = malloc(sizeof(dictionary) + 2);
    dictionary_path[0] = '.';
    dictionary_path[1] = '/';

    for (int i = 0; i < strlen(dictionary); i++)
    {
        dictionary_path[i + 2] = dictionary[i];
    }
    printf("%s\n", dictionary_path);
    // dictionary output -> dictionaries/large
    FILE *dic_dir = fopen(dictionary_path, "rb");

    if (dic_dir == NULL)
    {

        printf("dic_dir not found!");
        return false;
    }

    __uint8_t data[sizeof(dic_dir)];

    fread(&data, sizeof(__uint8_t),sizeof(dic_dir) , dic_dir);
    printf("%s", data);

    // printf("%s\n", dictionary);

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
