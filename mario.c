#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do // Get the user input repetedly until the required condition is fulfilled
    {
        n = get_int("Enter a height from 1 to 8\n");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++) // For printing the rows
    {
        for (int k = 1; k <= (n - i) - 1; k++) // For printing the spaces
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) // For printing the Columns respective to each row
        {
            printf("#");
        }
        printf("\n");
    }
}
