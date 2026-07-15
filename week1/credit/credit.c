#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variable to identify the number's possition
    int position = 0;

    // Prompt user for a card number
    long number = get_long("Number: ");
    // Copy of the original card, once the while's over, number = 0
    long original = number;
    long first = number;
    int checksum = 0;
    int length = 0;

    // Luhn's algorithm
    while (number > 0)
    {
        // Gives the last digit of the card number
        long digit = number % 10;
        // Remove the last digit
        number /= 10;
        // Multiply by 2, one number no and another yes
        if (position % 2 != 0)
        {
            digit *= 2;
            // Accumulates the value of the multiplied numbers
            checksum += (digit % 10) + (digit / 10);
        }
        else
        {
            // Accumulates the value of the not multiplied numbers
            checksum += digit;
        }
        // Move to the next digit from right to left
        position++;
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // Calculate length
        while (original > 0)
        {
            original /= 10;
            length++;
        }
        // Get two first numbers
        while (first >= 100)
        {
            first /= 10;
        }
        int first_digit = first / 10;
        // Check if it's AMEX
        if (length == 15 && (first == 37 || first == 34))
        {
            printf("AMEX\n");
        }
        // Check if it's MASTERCARD
        else if (length == 16 && (first >= 51 && first <= 55))
        {
            printf("MASTERCARD\n");
        }
        // Check if it's VISA
        else if ((length == 13 || length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
