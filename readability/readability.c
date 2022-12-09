#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number_of_letters =0 ;
    int number_of_sentences= 0;
    int index;

    string s = get_string("");

    int s_length = strlen(s);

    for(int i = 0; i < s_length; i++) {
        if(s[i] == 46 || s[i] == 33 || s[i] == 63) {
            ++number_of_sentences;
        } else if() {}
    }

    index = 0.0588 * number_of_letters - 0.296 * number_of_sentences - 15.8;
    printf("%i", number_of_sentences);
    printf("\n");
}