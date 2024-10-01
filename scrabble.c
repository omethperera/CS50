#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // Points declaring array

char *convrtup(char *word); // Function prototypes
int score(char *word);

int main()
{
    string word1 = get_string("Player 1: ");
    char *capw1 = convrtup(word1);
    int player1_sum = score(capw1);

    string word2 = get_string("Player 2: ");
    char *capw2 = convrtup(word2);
    int player2_sum = score(capw2);

    if (player1_sum > player2_sum)
    {
        printf("Player 1 wins !\n");
    }
    else if (player1_sum < player2_sum)
    {
        printf("Player 2 wins !\n");
    }
    else
    {
        printf("Tie !\n");
    }

    free(capw1);
    free(capw2);
}

char *convrtup(char *word) // This function takes an string user input and returns the pointer to a
                           // character array capword which is allocated in stack
{
    int length = strlen(word);

    char *capword = malloc(length + 1); // Allocate memmeory for the capword string in stack

    if (capword == NULL)
    {
        printf("Memmory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < length; i++)
    {
        capword[i] = toupper(word[i]);
    }
    capword[length + 1] = '\0';

    return capword;
}

int score(char *word) // compute the score of the word
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            sum = sum + points[word[i] - 'A'];
        }
    }
    return sum;
}
