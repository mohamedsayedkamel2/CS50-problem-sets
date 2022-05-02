#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_valid(string key, int args_count);
const char UPPER_CHARS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char LOWER_CHARS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    //Passes the arg count and user argument to the function
    bool is_key_valid = is_valid(argv[1], argc);
    //If the returned value from the function is true then do this block
    if (is_key_valid == true)
    {
        string user_key = argv[1];
        string plain_text = get_string("plaintext:  ");
        int str_len = strlen(plain_text);
        //This first loop will iterate over the whole plain text which the user input
        for (int i = 0; i < str_len; i++)
        {
            //This second loop will iterate for 26 times
            for (int j = 0; j < 26; j++)
            {
                //Checks if the letter is uppercase
                if (isupper(plain_text[i]))
                {
                    if (plain_text[i] == UPPER_CHARS[j])
                    {
                        plain_text[i] = toupper(user_key[j]);
                        break;
                    }
                }

                else if (islower(plain_text[i]))
                {
                    if (plain_text[i] == LOWER_CHARS[j])
                    {
                        plain_text[i] = tolower(user_key[j]);
                        break;
                    }
                }
            }
        }
        printf("ciphertext: %s\n", plain_text);
        return 0;
    }

    else
    {
        return 1;
    }
}

//This function takes the key which is input from the user and the arugments count from the main function
bool is_valid(string key, int args_count)
{
    //If the arugment number is greater than 2 then quit
    if (args_count > 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    //If the user didn't input the key in the args then quit
    if (args_count == 1)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    //First step: check if the length of the key is 26
    int key_length = strlen(key);
    if (key_length > 26 || key_length < 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    //Second step: check if each char in the string is an alpha char
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("You can't put a non-alpha value in the key\n");
            return false;
        }
    }
    //Third step: check if there is a letter that appears more than once in the string
    for (int i = 0; i < key_length; i++)
    {
        for (int j = i + 1; j < key_length; j++)
        {
            if (key[i] == key[j])
            {
                printf("You can't make an alpha appear more than once in a string\n");
                return false;
            }
        }
    }
    return true;
}