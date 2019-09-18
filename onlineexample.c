#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
}



typedef struct node
{
    bool is_word;
    struct node* children[27];
}node;

node* first;

int word_count = 0;
int get_index(char c);
node* create_init_node();
bool unload_helper(node* node_ptr);
// returns true if word is in dictionary else false
bool check (const char *word)
{
    node* node_ptr = first;
    for (int i = 0, len = strlen(word); i <= len; i++)
    {
        if (word[i]=='\0')
        {
            if (node_ptr->is_word == true)
                return true;
            else
                return false;
        }
        int index =get_index(word[i]);
        if (node_ptr->children[index]== NULL)
            return false;
        node_ptr = node_ptr->children[index];
    }
    return false;
}

// Loads dictionary into memory. Returns true if successful else false
bool load (const char *dictionary)
{
    FILE* dict_ptr = fopen(dictionary, "r");
    if (dict_ptr == NULL)
    {
        fprintf(stderr, "File does not exit!\n");
        return false;
    }
    // Initialize c to get a char from dictionary and check until we reach
    first = create_init_node();

    node* node_ptr = first;
    for (char c = fgetc(dict_ptr); c!=EOF; c= fgetc(dict_ptr))
    {
        //if the letter is not a newline char then we need to load this letter
        if (c != '\n')
        {
            index = get_index(c);
            if (node_ptr->children[index]==NULL)
            {
                node_ptr->children[index] = create_init_node();
            }
            node_ptr = node_ptr->children[index];

        }
        else
        {
            //mark the end of the word
            node_ptr->is_word = true;
            //increment word_count coz we found a complete word from dictionary
            word_count ++;
            //go back to homebase
            node_ptr - first;
        }
    }
    return false;
}

int get_index(char c)
{
    if (c== '\'')
        return 26;
    else if (c >='a' && c <= 'z')
        return c - 'a';
    else if (c >='A' && c <= 'Z')
        return c - 'A';
    return -1;
}
/* Returns a pointer to a node with initial values: false and all NULL values*/
node* create_init_node()
{
    node* node_ptr = malloc(sizeof(node));
    node_ptr->is_word = false;
    for (int i = 0; i<27; i++)
    {
        node_ptr->children[i]= NULL;
    }
    return node_ptr;
}

//Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

//Unloads dictionary from memory. Returns true if successful else false
bool unload(void)
{
    if (unload_helper(first))
        return true;

    return false;
}
bool unload_helper(node* node_ptr)
{
    for (int i = 0; i<27; i++)
    {
        if (node_ptr->children[i] != NULL)
        {
            unload_helper(node_ptr->children[i]);
        }
    }
    free(node_ptr);
    return true;
}
