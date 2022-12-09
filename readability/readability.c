#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

// input = Congratulations! Today is your day. You're off to Great Places! You're off and away!

int count_letters(string s);
int count_sentences(string s);
int count_words(string s);

int main(void)
{

    double average_number_of_letters = 0;
    double average_number_of_sentences = 0;
    double index;

    string s = get_string("Text: ");

    int s_length = strlen(s);

    // Adding +1 to numbers of words.
    int number_of_letters = count_letters(s);
    int number_of_sentences = count_sentences(s);
    int number_of_words = count_words(s);

    // Average number of sentences per 100 words.
    average_number_of_sentences = (float)number_of_sentences / (float)number_of_words * 100.0;
    // Average number of letteers per 100 words.
    average_number_of_letters = (float)number_of_letters / (float)number_of_words * 100;

    index = 0.0588 * (float)average_number_of_letters - 0.296 * (float)average_number_of_sentences - 15.8;

    int final_result = (int)round(index);
    if (final_result >= 16)
    {
        printf("Grade 16+");
    }
    else if (final_result < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("grade %i", final_result);
    }

    printf("\n");
}

int count_words(string s)
{
    int s_length = strlen(s);
    int number_of_words = 0;

    for (int i = 0; i < s_length; i++)
    {

        if (s[i] == 32 & i != 0)
        {
            ++number_of_words;
        }
    }

    ++number_of_words;

    return number_of_words;
}

int count_sentences(string s)
{
    int s_length = strlen(s);
    int number_of_sentences = 0;
    for (int i = 0; i < s_length; i++)
    {
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            ++number_of_sentences;
        }
    }
    return number_of_sentences;
}

int count_letters(string s)
{
    int s_length = strlen(s);
    int number_of_letters = 0;
    for (int i = 0; i < s_length; i++)
    {

        if (isalpha(s[i]))
        {
            ++number_of_letters;
        }
    }

    return number_of_letters;
}