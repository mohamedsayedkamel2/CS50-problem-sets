#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

//Function declration that tells the compiler that there is a function called compute_score exists
int compute_score(string word);

//This solution uses two pointer strategy
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner if player 1 has greater score than player 2 than player 1 is the winner and vice versa
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
        printf("Tie!\n");
    }
}
//Will do the computations
int compute_score(string word)
{
    int score = 0;
    //First step make every char an uppercase
    for (int i = 0, string_len = strlen(word); i < string_len; i++)
    {
        word[i] = toupper(word[i]);
    }
    
    for (int i = 0, string_len = strlen(word); i < string_len; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (word[i] == chars[j])
            {
                score += POINTS[j];
                break;
            }
        }
    }
    return score;
}
