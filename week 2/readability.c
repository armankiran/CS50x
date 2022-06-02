#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    //turn counts to floats
    float letters = (float) count_letters(text);
    float words = (float) count_words(text);
    float sentences = (float) count_sentences(text);
    float L = letters / words * 100;
    float S = sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    //print grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//iterate through letters
int count_letters(string text)
{
    int l = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count if letter
        if (isalpha(text[i]))
        {
            l += 1;
        }
    }
    return l;
}

//iterate through words
int count_words(string text)
{
    int w = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count if space
        if (isspace(text[i]))
        {
            w += 1;
        }
    }
    return w + 1;
}

//iterate through sentences
int count_sentences(string text)
{
    int s = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count if sentence
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            s += 1;
        }
    }
    return s;
}