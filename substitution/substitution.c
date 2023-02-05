#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
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

    string plaintext = get_string("plaintext: ");
    int plaintext_len = strlen(plaintext);
    char *ciphertext = malloc(plaintext_len+ 1 + 1);

    for (int i = 0; i < plaintext_len; i++)
    {

        char ch = plaintext[i];
        if (islower(ch) != 0)
        {
            int pos = ch - 97;
            ciphertext[i] = key[pos];
            ciphertext[i + 1] = '\0';
        }else {
            ciphertext[i] = key[i];
        }
        printf("ciphertext: %s\n", ciphertext);
    }
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