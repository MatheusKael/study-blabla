#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

 if(argc == 1 || argc > 2) {
        printf("Number of command lines arguments invalid!\n");
        return 1;
     }

    string arg_string = argv[1];
    int arg_string_len = strlen(arg_string);
    for(int i = 1; i < arg_string_len; i++) {
        if(isdigit(arg_string[i]) == 0) {
            printf("Usage: ./caesar key\n");
        return 1;
        }
    }
        int key = atoi(argv[1]);



    string string = get_string("plaintext:  ");

    int string_len = strlen(string);
    char *new_string = malloc(string_len + 1 + 1);

    for(int i = 0; i < string_len; i++) {
        if(isupper(string[i]) ) {
            char ch = ((int)string[i] + key - 65) % 26 + 65;
            strcpy(new_string, new_string);
            new_string[i] = ch;
            new_string[i + 1] = '\0';

        } else if(islower(string[i])) {
            char ch = ((int)string[i] + key - 97) % 26 + 97;
            strcpy(new_string, new_string);
            new_string[i] = ch;
            new_string[i + 1] = '\0';

        } else {
            new_string[i] = string[i];
        }

    }


    printf("ciphertext: %s\n", new_string);
}