#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number_of_letters = 0;
    int number_of_sentences = 0;
    int number_of_words = 0;
    double average_number_of_letters = 0;
    double average_number_of_sentences = 0;
    double index;

    string s = get_string("");

    int s_length = strlen(s);

    for (int i = 0; i < s_length; i++)
    {
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            ++number_of_sentences;
        }
        else if (s[i] != 32)
        {
            ++number_of_letters;
        }
        else if (s[i] == 32 & i != 0)
        {
            ++number_of_words;
        }
    }

    // Congratulations! Today is your day. You're off to Great Places! You're off and away!
    // Adding +1 to numbers of words.
    ++number_of_words;
    // Average number of sentences per 100 words.
    average_number_of_sentences = (float)number_of_sentences / (float)number_of_words * 100.0;
    // Average number of letteers per 100 words.
    average_number_of_letters = (float)number_of_letters / (float)number_of_words * 100;

    index = 0.0588 * (float)average_number_of_letters - 0.296 * (float)average_number_of_sentences - 15.8;
    printf("grade %i", (int) index);
    printf("\n");
}