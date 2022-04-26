#include <cs50.h>
#include <stdio.h>

/*
This program validates the Credit Card the user inputs and then output the type of the card if it's valid and output INVALID if the card is incorrect
This prgram heavely relies on the modulo operator and the knowledge of number system
It also uses Luhn's Algorithm
*/

//I was lazy coding this that's why this code lacks functions
int main(void)
{
//Creating essential variables that we will use later
//If you are curious they are the placeholders for the card
    int card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13, card14, card15, card16;

//First step prompt the user for input
    long long card = get_long_long("Enter your card: ");

    while (card < 0)
    {
        card = get_long("Enter your card: ");
    }

//Second step
    card1 = ((card % 100) / 10) * 2;
    card2 = ((card % 10000) / 1000) * 2;
    card3 = ((card % 1000000) / 100000) * 2;
    card4 = ((card % 100000000) / 10000000) * 2;
    card5 = ((card % 10000000000) / 1000000000) * 2;
    card6 = ((card % 1000000000000) / 100000000000) * 2;
    card7 = ((card % 100000000000000) / 10000000000000) * 2;
    card8 = ((card % 10000000000000000) / 1000000000000000) * 2;
//Third step
    card1 = (card1 % 10) / 10 + (card1 % 10);
    card2 = (card2 % 10) / 10 + (card2 % 10);
    card3 = (card3 % 10) / 10 + (card3 % 10);
    card4 = (card4 % 10) / 10 + (card4 % 10);
    card5 = (card5 % 10) / 10 + (card5 % 10);
    card6 = (card6 % 10) / 10 + (card6 % 10);
    card7 = (card7 % 10) / 10 + (card7 % 10);
    card8 = (card8 % 10) / 10 + (card8 % 10);
//Fourth step
    card9 = (card % 10);
    card10 = (card % 1000) / 100;
    card11 = (card % 100000) / 10000;
    card12 = (card % 10000000) / 1000000;
    card13 = (card % 1000000000) / 100000000;
    card14 = (card % 100000000000) / 10000000000;
    card15 = (card % 10000000000000) / 1000000000000;
    card16 = (card % 1000000000000000) / 100000000000000;

    long long sum1, sum2;
    sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;
    sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

    if (((sum1 + sum2) % 10) != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("VALID\n");
    }

    long visa = card, mastercard = card, americancard = card;
    //gets the card length
    short length = 0;
    while (card > 0)
    {
        card /= 10;
        length++;
    }
    //Checks if it's visa
    if (length == 13 || length == 16)
    {
        while (visa >= 10)
        {
            visa /= 10;
        }
        if (visa == 4)
        {
            printf("VISA\n");
            return 0;
        }
    }
    //Checks if it's American card
    else if (length == 15)
    {
        while (americancard >= 10000000000000)
        {
            americancard /= 10000000000000;
        }
        if (americancard == 34 || americancard == 37)
        {
            printf("AMEX\n");
            return 0;
        }
    }
    //Checks if it's a mastercard
    else if (length == 16)
    {
        while (mastercard >= 100000000000)
        {
            mastercard /= 100000000000;
        }
        if (mastercard >= 51 && mastercard <= 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }
}