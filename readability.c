//Prompts user for sentence, outputs reading grade of given input based on amount of letters, words, and sentences using Coleman-Liau index

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string w);
int count_words(string t);
int count_sentences(string u);

int main(void)
{
    string text = get_string("Text: ");
    int numlet = count_letters(text);
    int numword = count_words(text);
    int numsent = count_sentences(text);

    // printf("%i letters\n", numlet);
    // printf("%i words\n", numword);
    // printf("%i sentences\n", numsent);

//Have to not only put "float" before variable, but must also change one of the variable IN THE CALCULATION to a float
//When dividing integers, the answer will also be an INT unless one variable is a float
    float L = (float) numlet / numword * 100;
    float S = (float) numsent / numword * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((index >= 1) && (index <= 16))
    {
        printf("Grade %i\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}


int count_letters(string w)
{
    //Initialize 2 variables, one is to keep track of the character indicies in the given string, the other will keep track of the # of letters
    int index_let;
    int counter_let;
    //While the character at x indicie in the string s is not NULL i.e. haven't reached the end of the string
    //We go through an if else statement
    //Finally, we move onto the next character in the string by adding 1 to the indice variable
    for (index_let = 0, counter_let = 0; w[index_let] != '\0'; index_let++)
    {
        //If the character at indice x is a letter, we will add 1 to our letter counter
        if (isalpha(w[index_let]))
        {
            counter_let++;
        }
        //Else, we do not change the counter
        else
        {
            counter_let += 0;
        }
    }
    //We return the counter score to the main function as this will tell us the # of letters in the given string
    return counter_let;
}


int count_words(string t)
{
    //Initialize 2 variables, similar to counting letters, one is to keep track of character indicies in the given string and the other is to count the # of words
    int index_word;
    int counter_word;
    //For statement is same as that for Letters, we need to go through each character via it's indice and to determine whether or not it's a word, we use an if/else statement
    for (index_word = 0, counter_word = 0; t[index_word] != '\0'; index_word++)
    {
        //If the character at indice x is a space, that means there was a word before it
        //The instructions also state to assume there are no spaces before the first word OR multiple spaces one after another
        //Alternatively, if the character at indice x+1 is null i.e. we've reached the end of the sentence, there was also a word before it
        //We have to use "NUL" in this case since the instructions say to assume that there are no spaces after the last word
        if ((t[index_word] == ' ') || (t[index_word + 1] == '\0'))
        {
            counter_word++;
        }
        //If there is no space or nul character after x+1, we do not add anything to the word counter
        else
        {
            counter_word += 0;
        }
    }
    //We will return the value of the counter to the main function as it identifies the # of words in the given string
    return counter_word;
}


int count_sentences(string u)
{
    //Everything same as above except If statement
    int index_sent;
    int counter_sent;
    for (index_sent = 0, counter_sent = 0; u[index_sent] != '\0'; index_sent++)
    {
        //In this case, we're saying if the character at indice x has a ., !, or ? then this would indicate the end of a sentence
        //Therefore, we would add 1 to the sentence counter
        if ((u[index_sent] == '.') || (u[index_sent] == '!') || (u[index_sent] == '?'))
        {
            counter_sent++;
        }
        else
        {
            counter_sent += 0;
        }
    }
    return counter_sent;
}
