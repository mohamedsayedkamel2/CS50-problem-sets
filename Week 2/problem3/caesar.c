#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //If the arugment number is greater than 2 then quit
    if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //If the user didn't input the key in the args then quit
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //If the user didn't input a valid number then quit
    string arg = argv[1];
    for (int i = 0, string_length = strlen(arg); i < string_length; i++)
    {
        if (isalpha(arg[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //Get the plain text from the user
    string plain_text = get_string("plaintext:  ");
    //create a variable to store the cipher text
    string cipher_text = plain_text;
    //Convert the arg into a number
    int key = atoi(argv[1]);
    int str_len = strlen(plain_text);
    for (int i = 0; i < str_len; i++)
    {
        if (isupper(plain_text[i]))
        {
            //If the char is an uppercase then use this forumla
            cipher_text[i] = ((((plain_text[i] - 65) + key) % 26) + 65);
        }
        else if (islower(plain_text[i]))
        {
            //If the char is an lowercase then use this forumla
            cipher_text[i] = ((((plain_text[i] - 97) + key) % 26) + 97);
        }
    }
    printf("ciphertext: %s\n", cipher_text);
    //Sucessfuly excecuted then close the program
    return 0;
}
