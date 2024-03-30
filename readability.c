#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int compute_letters(string s);
int compute_words(string s);
int compute_sentences(string s);

int main(void)
{
    string input = get_string("Type your sentence: ");
    int words = compute_words(input);
    int sentences = compute_sentences(input);
    int letters = compute_letters(input);

    float L = (float)letters/words * 100;
    float S = (float)sentences/words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int compute_letters(string s)
{
    int n = 0;
    int letters = 0;
    while(s[n] != '\0')
    {
        if(isalpha(s[n]) != 0)
        {
            letters++;
        }
        n++;
    }
    return letters;
}

int compute_words(string s)
{
    int n = 0;
    int words = 0;
    while(s[n] != '\0')
    {
        if(isspace(s[n]) != 0)
        {
            words++;
        }
        n++;
    }
    return words + 1;
}

int compute_sentences(string s)
{
    int n = 0;
    int sentences = 0;
    while(s[n] != '\0')
    {
        if(s[n] == 46 || s[n] == 63 || s[n] == 33)
        {
            sentences++;
        }
        n++;
    }
    return sentences;
}
