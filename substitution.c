#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    //If no key provided or more than 1 key provided, let user know & return error
    if ((argc == 1) || (argc > 2))
    {
        printf("Please provide SINGLE key.\n");
        return 1;
    }
    //If proper key is provided, continue
    else if (argc == 2)
    {
        //If key is anything other than 26 characters, return error
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (strlen(key) == 26)
        {
            //Check if key is only made of alphabetical characters, otherwise return error
            for (int i = 0; i < strlen(key); i++)
            {
                //String = array of chars, can loop through each chara and check if it's alphabetical
                //If character at position i = 0, it is NOT ALPHABETICAL
                if (isalpha(key[i]) == 0)
                {
                    printf("Key must only contain alphabetical characters\n");
                    return 1;
                }
                //Check if any letters are repeated more than once
                //Initialize variable to keep track of repeated characters
                int check = 0;
                for (int k = 0; k < strlen(key); k++)
                {
                    for (int l = k + 1; l < strlen(key); l++)
                    {
                        if (toupper(key[k]) == toupper(key[l]))
                        {
                            check += 1;
                        }
                        else
                        {
                            check += 0;
                        }
                    }
                }
                if (check > 0)
                {
                    printf("Key should contain each alphabetical character only ONCE.\n");
                    return 1;
                }
            }

            //Obtain plaintext from user
            string plaintext = get_string("Plaintext: ");
            //Create array for ciphertext containing characters & is the length of plaintext
            char ciphertext [strlen(plaintext)];
            //Go through each char in plaintext
            for (int i = 0; i <= strlen(plaintext); i++)
            {
                //If plaintext character is NOT alphabeticaL, do not change in ciphertext
                if (isalpha(plaintext[i]) == 0)
                {
                    ciphertext[i] = plaintext[i];
                }
                //If plaintext is uppercase, -65 to match position in key
                else if (isupper(plaintext[i]) != 0)
                {
                    //If key is already uppercase, ciphertext can automatically be made, otherwise must convert ciphertext to uppercase
                    if (isupper(key[plaintext[i] - 65]) != 0)
                    {
                        ciphertext[i] = key[plaintext[i] - 65];
                    }
                    else
                    {
                        ciphertext[i] = toupper(key[plaintext[i] - 65]);
                    }
                }
                //If lowercase, -97 to match position in key
                else if (islower(plaintext[i]) != 0)
                {
                    //If key is already lowercase, ciphertext can automatically be made, otherwise must convert ciphertext to lowercase
                    if (islower(key[plaintext[i] - 97]) != 0)
                    {
                        ciphertext[i] = key[plaintext[i] - 97];
                    }
                    else
                    {
                        ciphertext[i] = tolower(key[plaintext[i] - 97]);
                    }
                }
            }
            //Print final result of ciphertext & return 0 to quit program
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
    }
}