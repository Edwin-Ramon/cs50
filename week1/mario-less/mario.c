#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        // Prompt user for height
        height = get_int("Height: ");
    }
    while (height < 1);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            // Print spaces
            printf(" ");
        }
        // Print pyramid of that height
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
