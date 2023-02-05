#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc == 1)
    {
        printf("Executed without any command-line arguments or with more than one command-line argument");
        return 1;
    }
    string key = argv[1];

    if (strlen(key) > 26 || strlen(key) < 26)
    {

        printf("Key needs 26 characters!");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) != 0)
        {
            printf("Key contains a not alphabetical character!");
            return 1;
        }
    }
}