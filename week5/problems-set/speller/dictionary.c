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

bool is_loaded = false;
int count;
char full_path[100] = "./";

// TODO: Choose number of buckets in hash table
const unsigned int N = 286123;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    unsigned int index = hash(word);

    node *ptr = table;
    while(table[index] == NULL)
    {
        return false;
    }

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int halval = 0;
    const unsigned char *p = (const unsigned char *)word;

    while (*p != '\0')
    {
        halval = (halval * 31 + *p) % N;
        ++p;
    }

    return halval;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    strcat(full_path, dictionary);
    FILE *dic_dir = fopen(full_path, "rb");

    if (dic_dir == NULL)
    {

        printf("dic_dir not found!");
        fclose(dic_dir);
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char word[LENGTH + 1];
    count = 0;
    while (fscanf(dic_dir, "%s", word) != EOF)
    {
        count++;
        unsigned int index = hash(word);

        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            printf("Error allocating memory for new_node!");
            fclose(dic_dir);
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
    }

    fclose(dic_dir);
    is_loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (is_loaded == false)
    {
        return 0;
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {

        node *ptr = table[i];

        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }

    return true;
}
