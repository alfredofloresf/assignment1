#include <stdio.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdbool.h>
#include <dictionary.c>


/**
 * Array misspelled is populated with words that are misspelled. Returns the length of misspelled.
 */
int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[]);

{
//Set int num_misspelled to 0.
int num_misspelled = 0;
//While line in fp is not EOF (end of file):
while( (character = fgetc(file)) != EOF)
{




/**
    Read the line.
    Split the line on spaces.
    For each word in line:
        If not check_word(word):
            Append word to misspelled.

            */
    //Increment num_misspelled.
    num_misspelled++;
}
//Return num_misspelled.
return num_misspelled;
}



bool check_word(string word, hashmap hashtable[])
{
   // Set int bucket to the output of hash_function(word).
    int bucket = hash_function(word);
    //Set hashmap_t cursor equal to hashmap[bucket].
    node* cursor = hashtable[bucket];
    // While cursor is not NULL:
    while (cursor != NULL) {
        //If word equals cursor->word:
        if (strcmp(word, cursor->word) == 0) {
            return true;
        } else if (strcmp(lower_word, cursor->word) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}



/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
   //Initialize all values in hash table to NULL.
    for(int i = 0; i < HASH_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    //Open dict_file from path stored in dictionary.
    //If dict_file is NULL:
      //  return false.
    FILE* the_dictionary;
    the_dictionary = fopen(wordlist.txt, "r");
    if (the_dictionary == NULL)
    {
        printf("Failed to load dictionary");
        return false;
    }
    char buffer[LENGTH+1];
    while (fscanf(the_dictionary, "%s", buffer) > 0)
    {
        node* new_node = malloc(sizeof(node));
        new_node->next = NULL;
        strcpy(new_node->word, buffer);
        int bucket = hash_function(new_node->word);
        if (hashtable[bucket] == NULL)
        {
            hashtable[bucket] = new_node;
        }
        else
        {
            new_node->next = hashtable[bucket];
            hashtable[bucket] = new_node;
        }
        number_of_words++;
    }
    fclose(the_dictionary);
    return true;
}