#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Takes the input from the user
    string user_input = get_string("Enter your string: ");
    //Gets the count of letters
    int letters_score = count_letters(user_input);
    //Gets the count of words
    int words_score = count_words(user_input);
    //Gets the count of sentences
    int sentences_score = count_sentences(user_input);
    //Calc the formula
    float index = (0.0588 * letters_score / words_score * 100) - (0.296 * sentences_score / words_score * 100) - 15.8;
    //Gets the grade
    int grade = round(index);
    //Printing the grade using some logic
    if (grade <= 16 && grade > 0)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{

    if (text == NULL)
    {
        printf("Invalid Operation the input value is NULL\n");
        return 0;
    }

    int letter_count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        //Checks if the char variable is a char
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    if (text == NULL)
    {
        printf("Invalid Operation the input value is NULL\n");
        return 0;
    }

    int word_count = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        //Checks if the char is a void which means a word
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}
//Count sentences in a word function
int count_sentences(string text)
{
    if (text == NULL)
    {
        printf("Invalid Operation the input value is NULL\n");
        return 0;
    }

    int sentences_count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        //Checks if the char is equal to . or ? or ! which means a sentence
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences_count++;
        }
    }
    return sentences_count;
}