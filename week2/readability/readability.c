#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string characters);
int count_words(string words);
int count_sentences(string sentences);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int Index = round(index);

    // Print the grade level
    if (Index >= 1 && Index <= 16)
    {
        printf("Grade %i\n", Index);
    }
    else if (Index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Index > 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string characters)
{
    int letters_counter = 0;
    for (int i = 0, n = strlen(characters); i < n; i++)
    {
        if (isalpha(characters[i]) != 0)
        {
            letters_counter++;
        }
    }
    return letters_counter;
}

int count_words(string words)
{
    int words_counter = 1;
    for (int i = 0, n = strlen(words); i < n; i++)
    {
        if (words[i] == ' ')
        {
            words_counter++;
        }
    }
    return words_counter;
}

int count_sentences(string sentences)
{
    int sentences_counter = 0;
    for (int i = 0, n = strlen(sentences); i < n; i++)
    {
        if (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?')
        {
            sentences_counter++;
        }
    }
    return sentences_counter;
}
