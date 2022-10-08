#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Set all variables
    long new_num = 0;
    long alt_sum = 0;
    int i = 0;
    int first_nums = 0;
    //Get user input for card number
    long card_num = get_long("What is your card number? ");

    //Obtain every other digit starting from 2nd-to-last
    while (card_num > 1)
    {
        //Gives you last digit
        int result = card_num % 10;
        i++;
        //Take last digit off of card number itself
        card_num = card_num / 10;
        //For every other digit starting from 2nd to last (even #'s)
        if (i % 2 == 0)
        {
            //For single digit results
            if (result < 5)
            {
                new_num += result * 2;
            }
            //For double digit results
            else
            {
                result = (result * 2);
                //First digit of any value 5 or greater x 2 will always be 1
                new_num += (result % 10) + 1;
            }
        }
        else
        {
            alt_sum += result;
        }
        //Get first 2 digits of credit card # to keep track for identifying card
        if (card_num >= 10 && card_num <= 99)
        {
            first_nums += card_num;
        }
    }
    int final_value = alt_sum + new_num;

    //If last digit in sum is 0, credit number is VALID
    if (final_value % 10 == 0)
    {
        if (first_nums / 10 == 4 && (i == 13 || i == 16))
        {
            printf("VISA\n");
        }
        else if ((first_nums == 34 || first_nums == 37) && (i == 15))
        {
            printf("AMEX\n");
        }
        else if ((first_nums >= 51 && first_nums <= 55) && (i == 16))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //If last digit in sum is NOT 0, credit number is INVALID
    else
    {
        printf("INVALID\n");
    }
}
