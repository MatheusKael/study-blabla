#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number_of_letters =0 ;
    int number_of_sentences= 0;
    int number_of_words = 0;
    double average_number_of_letters = 0;
    double average_number_of_sentences = 0;
    double index;

    string s = get_string("");

    int s_length = strlen(s);

    for(int i = 0; i < s_length; i++) {
        if(s[i] == 46 || s[i] == 33 || s[i] == 63) {
            ++number_of_sentences;
        } else if( s[i] != 32) {
            ++number_of_letters;
        } else if (s[i] == 32 & i != 0) {
            ++number_of_words;
        }
    }

    // Congratulations! Today is your day. You're off to Great Places! You're off and away!
    // Adding +1 to numbers of words.
    ++number_of_words;
    printf("%i\n", number_of_words);

    // Average number of sentences per 100 words.
    average_number_of_sentences = number_of_sentences / number_of_words * 100.0;
    printf("%i\n", number_of_sentences);
    // Average number of letteers per 100 words.
    average_number_of_letters = number_of_letters / number_of_words * 100.0;

    index = 0.0588 * average_number_of_letters - 0.296 * average_number_of_sentences - 15.8;
    printf("%f", index);
    printf("\n");
}