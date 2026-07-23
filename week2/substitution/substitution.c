#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // command line validation and Key validation
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    {
        int n = strlen(argv[1]);
        if (n != 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            char letter = toupper(argv[1][i]);
            if (!isalpha(letter))
            {
                printf("Key must only contain alphabetic characters\n");
                return 1;
            }

            for (int j = 0; j < i; j++)
            {
                char review = toupper(argv[1][j]);
                if (review == letter)
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
            }
        }
    }
    // Promtp plaintext
    string plaintext = get_string("Plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char character = plaintext[i];

        if (!isalpha(character))
        {
            printf("%c", character);
        }
        else
        {
            if (!isupper(character))
            {
                int new_lower_letter = (character - 'a');
                char encrypted_lower = tolower(argv[1][new_lower_letter]);
                printf("%c", encrypted_lower);
            }
            else
            {
                int new_upper_letter = (character - 'A');
                char encrypted_upper = toupper(argv[1][new_upper_letter]);
                printf("%c", encrypted_upper);
            }
        }
    }
    printf("\n");
}
