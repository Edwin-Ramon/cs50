#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Prompt user for Height
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print row
    for (int i = 0; i < height; i++)
    {
        // print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // print bricks left size
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        // print bricks right size
        for (int a = 0; a < i + 1; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}
