//Input numerical key for shifting of characters, prompts user for plaintext, outputs ciphertext (plaintext shifted key # of times)

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string k);
char rotate(char c, int i);

int main(int argc, string argv[])
{
    //CHECK KEY VAILDITY
    //If user provides no arguments OR more than 2, send error code & return 1
    if ((argc == 1) || (argc > 2))
    {
        printf("Usage: ./ caesar key\n");
        return 1;
    }
    //If user provides single argument, return 0 i.e. program is working
    else if (argc == 2)
    {
        //Check if argument (string) is composed of only digits 0-9
        bool argument = only_digits(argv[1]);
        if (argument == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // ACTUAL CIPHER TEXT
            // After converting argv[1] to int from string, we get the user to provide the plaintext
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext:  ");

            int plain_index = 0;
            int plain_length = strlen(plaintext);
            //create array for ciphertext that will hold as many characters as the length of the plaintext
            char ciphertext[plain_length];
            //Begin adding characters to the array by calling on the rotate function so long as the index is less than the length of the plaintext
            while (plain_index < plain_length)
            {
                ciphertext[plain_index] = rotate(plaintext[plain_index], key);
                plain_index++;
            }
            //For loop cycles through each character in the array, and prints out a string
            printf("ciphertext: ");
            for (int q = 0; q < plain_length; q++)
            {
                printf("%c", ciphertext[q]);
            }
        }
        printf("\n");
    }
}


bool only_digits(string k)
{
//For for loops, so long as you declare the variables OUTSIDE the loop, they will retain their value (at least thats what it seems like)
    int index, length, counter;
    //Returns TRUE if string has digits 0 - 9, else returns FALSE
    for (index = 0, length = strlen(k), counter = 0; index < length; index++)
    {
        if (isdigit(k[index]))
        {
            counter++;
        }
        else
        {
            counter += 0;
        }
    }
    // if the value of the counter is NOT equal to the length of the key, that means that not all of the characters of the key are digits, and therefore we return FALSE
    if (counter == length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char rotate(char c, int i)
{
    //if the character of the plaintext at the given index is alphabetical, if its capital we rotate it through the capitals vs. same thing for lowercase
    if (isalnum(c))
    {
        if (isupper(c))
        {
            c = ((((c - 65) + i) % 26) + 65);
        }
        else if (islower(c))
        {
            c = ((((c - 97) + i) % 26) + 97);
        }
    }
    else
        //if the character of the plaintext if anything OTHER than an alphabetical character, we simply return the same character back to main
    {
        return c;
    }
    return c;
}
