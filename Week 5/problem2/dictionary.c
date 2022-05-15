// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
//LENGTH is = 45
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int hash_value = 0;
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //First get he hash value using the hash function
    hash_value = hash(word);
    node *ptr = table[hash_value];
    //Iterate over the linked list and compare the input word with the nodes's word
    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        //Move the pointer forward
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    long all = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        all += tolower(word[i]);
    }
    return all % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open the file
    FILE *file_ptr = fopen(dictionary, "r");
    //If the program couldn't open the file it will exit
    if (file_ptr == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file_ptr, "%s", word) != EOF)
    {
        node *word_node = malloc(sizeof(node));
        if (word_node == NULL)
        {
            return false;
        }
        strcpy(word_node->word, word);
        hash_value = hash(word);
        word_node->next = table[hash_value];
        table[hash_value] = word_node;
        word_count++;
    }
    printf("The read word is %i\n", word_count);
    fclose(file_ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];

        while (ptr != NULL)
        {
            node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        if (ptr == NULL)
        {
            return true;
        }
    }
    return false;
}