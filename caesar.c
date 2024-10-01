#include <cs50.h> // header files
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int outputkey(char *string); // function prototypes
char *ciphering(int key, char *plaintxt);

char caps[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // alphebetical index for cap letters
char simp[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // alphebetical index for simple letters

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        int key = outputkey(argv[1]); // calling output key fucntion
        printf("key = %i\n", key);

        string plaintxt = get_string("Plaintext: ");
        string ciphertxt = ciphering(key, plaintxt); // calling ciphering function

        printf("Ciphertext: %s\n", ciphertxt);
    }
}

int outputkey(char *string) // This takes the 2nd arg of the cmd line arguments and outputs the key(int) to cipher.
{
    int length = strlen(string);
    char *digitstring = malloc(length + 1); // allocates memmory for the digit string array of the key
    digitstring[length + 1] = '\0';

    for (int i = 0; i < length; i++)
    {
        if (isdigit(string[i])) // check if the arg entered by user is a digit
        {
            digitstring[i] = string[i];
        }
        else
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }
    int digiint = atoi(digitstring); // convert the string of the user entered digit to an int
    return digiint;
    free(digitstring);
}

char *ciphering(int key, char *plaintxt) // takes the key and users plaintxt as args and outputs the ciphered text array
{
    int length = strlen(plaintxt);
    char *ciphertxt = malloc(length + 1); // allocate memmory for the ciphered text
    ciphertxt[length + 1] = '\0'; // declaring the last index of the ciphertxt array is null so as to imply its a string

    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintxt[i])) // checks if each character of the user entered plaintxt is alphabetical
        {
            if (isupper(plaintxt[i])) // checks if each character of the user entered plaintxt is uppercase
            {
                // ci = (pi + key) % 26
                ciphertxt[i] = caps[(((plaintxt[i] - 'A') + key) % 26)]; // replaces the cipher text ith character with the corresponding shifted alphabetical index acoording to the key provided
            }
            else if (islower(plaintxt[i])) // checks if each character of the user entered plaintxt is lowercase
            {
                ciphertxt[i] = simp[(((plaintxt[i] - 'a') + key) % 26)]; // replaces the cipher text ith character with the corresponding shifted alphabetical index acoording to the key provided
            }
        }
        else
        {
            ciphertxt[i] = plaintxt[i]; // if any non alphabetical letter is promped return it as it is
        }

    }
    return ciphertxt;
    free(ciphertxt);
}








