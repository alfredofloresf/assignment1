#include <stdio.h>
#include "dictionary.h"
#include <stdbool.h>


/**
 * Array misspelled is populated with words that are misspelled. Returns the length of misspelled.
 */
int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[]);

{
    //Set int num_misspelled to 0.
    int num_misspelled = 0;

    //While line in fp is not EOF (end of file):
    char ch;
    while (ch=getc(fp)) != EOF)
    {


     /**

        Read the line.
        Split the line on spaces.
        For each word in line:
            If not check_word(word):
                Append word to misspelled.


    */
    // Increment num_misspelled.
        num_misspelled++;
    }
    //Return num_misspelled
    return num_misspelled;
}








bool check_word(const char* word, hashmap_t hashtable[])
{
    /**
    Remove punctuation from beginning and end of word.
    Set int bucket to the output of hash_function(word).
    Set hashmap_t cursor equal to hashmap[bucket].
    While cursor is not NULL:
        If word equals cursor->word:
            return True.
        Else if lower_case(word) equals curosr->word:
            return True.
        Set curosr to cursor->next.
    return False.
    */
}



/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    // Initialize each value in hash table to NULL.
    for(int i = 0; i < HASH_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
    // Open the dictionary text file.
    FILE* the_dictionary;
    the_dictionary = fopen(dictionary_file,"r");

    // Check if dictionary opened correctly.
    if (the_dictionary == NULL)
    {
        printf("Failed to load dictionary");
        return false;
    }

    //While cursor is not NULL:
    while(int c = fgetc(the_dictionary); c != EOF; c = fgetc(the_dictionary))
    { {
            //if the letter is not a newline char then we need to load this letter
            if (c != '\n')
            {
                index = get_index(c);
                if (node_ptr->next[index]==NULL)
                {
                    node_ptr->next[index] = create_init_node();
                }
                node_ptr = node_ptr->next[index];

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
    }
}

