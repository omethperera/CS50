#include <cs50.h>
#include <stdio.h>

void divide25(int n); // Function prototypes
void divide10(int x, int *q2, int *r2);
void divide5(int y, int *q3, int *r3);

int main(void)
{
    int n, q2, r2, q3, r3;
    do
    {
        n = get_int(
            "How much change is owed in cents ? "); // Prompting user until get correct input
    }
    while (n < 0);

    divide25(n);
}

void divide25(int n)
{
    int q1 = n / 25; // Quotient after dividing by 25
    int r1 = n % 25; // Remainder after dividing by 25

    if (r1 == 0)
    {
        printf("%i\n", q1);
    }
    else if (r1 > 0)
    {
        int q2, r2;
        divide10(r1, &q2, &r2);
        if (r2 == 0)
        {
            printf("%i\n", q1 + q2);
        }
        else if (r2 > 0)
        {
            int q3, r3;
            divide5(r2, &q3, &r3);
            if (r3 == 0)
            {
                printf("%i\n", q1 + q2 + q3);
            }
            else
            {
                printf("%i\n", q1 + q2 + q3 + r3);
            }
        }
    }
}

void divide10(int x, int *q2,
              int *r2) // Function which divides by 10, pointers are used to remember q1 and r2
{
    *q2 = x / 10; // Quotient after dividing by 10
    *r2 = x % 10; // Remainder after dividing by 10
}

void divide5(int y, int *q3,
             int *r3) // Function which divides by 5, pointers are used to remember q3 and r3
{
    *q3 = y / 5; // Quotient after dividing by 5
    *r3 = y % 5; // Remainder after dividing by 5
}
