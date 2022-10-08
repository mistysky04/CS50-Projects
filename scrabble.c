//Prompts user to provide words for 2 unique players, outputs winner based on scrabble score of inputted words

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    //Compare scores and see if one is bigger/same to print correct winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie.\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //Initialize final score variable
    int total_score;
    total_score = 0;

    //Go through each letter in given words
    for (int i = 0; i < strlen(word); i++)
    {
        //Check if characters are alphabetical
        if isalpha(word[i])
        {
            //If Character is alphabetical; will have numerical score
            //For Uppercase letters, subtract 65 from ASCII value to get value between 0-25 for points array
            if isupper(word[i])
            {
                total_score += POINTS[word[i] - 65];
            }
            //For Lowercase letters, subtract 97 from ASCII value to get value between 0-25 for points array
            else if islower(word[i])
            {
                total_score += POINTS[word[i] - 97];
            }
        }
        else
        {
            //If Character is NOT alphabetical; will add 0 to total score
            total_score += 0;
        }
    }
    return total_score;
}
