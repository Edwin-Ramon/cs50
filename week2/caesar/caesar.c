#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];

        if (isalpha(letter))
        {
            if (isupper(letter))
            {
                int new_upper_letter = ((letter - 'A') + k) % 26 + 'A';
                printf("%c", new_upper_letter);
            }
            else
            {
                int new_lower_letter = ((letter - 'a') + k) % 26 + 'a';
                printf("%c", new_lower_letter);
            }
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
}
