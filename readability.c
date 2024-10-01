#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(char *text); // Function prototypes
int words(char *text);
int sentences(char *text);

int main(void)
{
    string text = get_string("Enter text: \n"); // Gettting user input text paragraph

    float l = letters(text);
    float w = words(text);
    float s = sentences(text);

    float L = (l / w) * 100; // letters pers 100 words in Coleman-Liau index
    float S = (s / w) * 100; // sentences pers 100 words in Coleman-Liau index

    int index = round((0.0588 * L) - (0.296 * S) - 15.8); // Coleman-Liau index formulea

    if (index < 1) // conditionals to print grade respective to the index
    {
        printf("Before Grade 1\n");
    }
    else if (1 <= index && index <= 15)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int letters(char *text) // inputs user text as arg and outputs no of letters in it.
{
    int sum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            sum += 1;
        }
    }
    return sum;
}

int words(char *text) // inputs user text as arg and outputs no of words in it.
{
    int sum = 0;
    int blank = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            blank += 1;
        }
    }
    return blank + 1;
}

int sentences(char *text) // inputs user text as arg and outputs no of sentences in it.
{
    int sum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.')
        {
            sum += 1;
        }
        else if (text[i] == '!')
        {
            sum += 1;
        }
        else if (text[i] == '?')
        {
            sum += 1;
        }
    }
    return sum;
}
