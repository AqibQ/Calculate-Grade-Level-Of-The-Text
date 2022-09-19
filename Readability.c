#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Getting user input
    string text = get_string("Text: ");

    // Counting letters
    int w = count_letters(text);

    // Counting words
    int p = count_words(text);

    // Counting sentences
    int h = count_sentences(text);

    // Calculating average per 100 words
    int L = (float)w / p * 100;
    int S = (float)h / p * 100;

    // Putting all togethar in Coleman's Liau Formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Rounding to the nearest int
    int X = round(index);

    // Printing the output
    if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (X > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", X);
    }
}

// count_letters function
int count_letters(string text)
{
    int len = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) || islower(text[i]) || isupper(text[i]))
        {
            len++;
        }
    }
    return len;
}

// count_words Function
int count_words(string txt)
{
    int wrd = 1;
    for (int j = 0, m = strlen(txt); j < m; j++)
    {
        if (isspace(txt[j]))
        {
            wrd++;
        }
    }
    return wrd;
}

// count_sentences Function
int count_sentences(string sent)
{
    int sen = 0;
    for (int o = 0, k = strlen(sent); o < k; o++)
    {
        if (sent[o] == '.' || sent[o] == '!' || sent[o] == '?')
        {
            sen++;
        }
    }
    return sen;
}
