#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get the inpur from the user
    int n = get_int("Enter the number of blocks: ");
    //User input validation: checks if the value is positive and it's in the rage from 1 to 8 only
    while (n < 1 || n > 8)
    {
        n = get_int("Enter the number of blocks: ");
    }
    //This loop creates lines with n number of # with a space before each hash
    for (int i = 0; i < n; i++)
    {
        //This loop creates n - 1 number of hashes and it iterates as long as k's value is larger than i
        for (int k = n - 1; k > i ; k--)
        {
            printf(" ");
        }
        //Prints a set of hashes of number n on the left side
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //Creates an empty space bettwen the two sets of hashes in the same line
        for (int empty = 0; empty < 2; empty++)
        {
            printf(" ");
        }
        //Prints a set of hashes of number n on the right side
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //Creates a new line at the end of each iteration of the for (int i=0; i<n; i++) loop
        printf("\n");
    }
}
//Another approach which can be taken is that we can seperate the code in a function but I'm lazy to do that