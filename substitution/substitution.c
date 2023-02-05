#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string key = argv[1];

    if (strlen(key) > 26 || strlen(key) < 26)
    {

        printf("Key needs 26 characters!\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key contains a non alphabetical character!\n");
            return 1;
        }
    }

    // not containing each letter exactly once
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            printf("%c == %c", key[i], key[j]);
            if (key[i] == key[j] && i != j)
            {
                printf("%c == %c", key[i], key[j]);
                return 1;
            }
        }
    }
}