#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_errors(string key);

int main(int argc, string argv[])
{
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];

    if (check_errors(key) == 1)
    {
        return 1;
    }
    char s = 'a';
    char te = s - 97;

    printf("%i", te);

    // string plaintext = get_string("plaintext: ");

    // for (int i = 0; i < strlen(plaintext); i++)
    // {

    //     for (int  j= 0; j < 26; j++)
    //     {
    //         if (tolower(plaintext[i]) == tolower(key[j]) )
    //         {
    //             printf("%c == %c \n", key[i], key[j]);

    //         }
    //     }
    // }
}

int check_errors(string key)
{
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
            if (tolower(key[i]) == tolower(key[j]) && i != j)
            {
                printf("%c == %c \n", key[i], key[j]);
                return 1;
            }
        }
    }

    return 0;
}