#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number_of_letters =0 ;
    int number_of_sentences= 0;

    string s = get_string("");

    int s_length = strlen(s);

    for(int i = 0; i < s_length; i++) {
        if(s[i] == 46) {
            ++number_of_sentences;
        }
    }

    printf("%i", number_of_sentences);
    printf("\n");
}