#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Number:  ");
    }
    while (n <= 0);

    int h = n - 1;
    int v = n - h;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < h; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < v; k++)
        {
            printf("#");
        }

        printf("\n");

        h--;
        v++;
    }

}
