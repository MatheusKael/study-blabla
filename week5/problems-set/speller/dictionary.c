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

char *dictionary_data;
int dictionary_length;

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
        fclose(dic_dir);
        return false;
    }

    fseek(dic_dir, 0, SEEK_END);
    dictionary_length = ftell(dic_dir);
    fseek(dic_dir, 0, SEEK_SET);

    dictionary_data = malloc(dictionary_length);
    if(dictionary_data == NULL) {

        printf("Error allocating dictionary data!\n");
        fclose(dic_dir);
        free(dictionary_data);
        return false;
    }

    fread(dictionary_data, 1, dictionary_length, dic_dir);


    // printf("%s", dictionary_data);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int count = 0;

    for(int i = 0; i < dictionary_length; i++) {
        if(dictionary_data[i] == '\n') {
            count++;
        }
    }
    printf("%i", count);
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    free(dictionary_data);

    return true;
}
