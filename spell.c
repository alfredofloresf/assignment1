#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <sys/types.h>

#include "dictionary.h"

#include <ctype.h>





char *return_punctuation(char *str){

    if (str == NULL){

        return NULL;

    }

    char *originalstring =str;

    char *newstring = str + strlen(str) - 1;



    while (ispunct(*originalstring)) originalstring++;

    while (ispunct(*newstring) && originalstring < newstring) {

        *newstring = 0;

        newstring--;

    }



    for (int i = 0; i <= newstring - originalstring + 1; i++){

        str[i] = originalstring[i];

    }

    originalstring = str;



    if (strlen(originalstring) == 0){

        return NULL;

    }

    return originalstring;

}





char * str_to_lower(char *str)

{

    char *unknownstring = str;  // unknown string

    char *lowerstring = str;   // lower string



    if(str != NULL) //NULL

    {

        if(strlen(str) != 0) //"" ?

        {

            while(*unknownstring)

            {

                *lowerstring = tolower(*unknownstring);

                ++lowerstring;

                ++unknownstring;

            }

            *lowerstring = '\0';



            return str;

        }

    }

    return "";

}





/**

Array misspelled is populated with words that are misspelled. Returns the length of misspelled.

 */

int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[]) {

    char *position = 0;

    char *position_character;

    int num_misspelled = 0;   //set int num_misspelled to 0

    char string[80];



    if (fp == NULL) {

        exit(5);

    }



    while (fgets(string, 160, fp) != NULL) {

        if ((position = strchr(string, '\n')) != NULL) {

            *position = '\0';

        }

        position_character = strtok(string, " ");



        if (position_character != NULL && strlen(position_character) > LENGTH) {

            position_character = NULL;

        }



        position_character = return_punctuation(position_character);



        while (position_character != NULL) {

            if (check_word(position_character, hashtable)) {

                position_character = strtok(NULL, " ");

                position_character = return_punctuation(position_character);

            }

            else if (check_word(str_to_lower(position_character), hashtable)) {

                position_character = strtok(NULL, " ");

                position_character = return_punctuation(position_character);

            }

            else {

                if (num_misspelled < MAX_MISSPELLED) {

                    misspelled[num_misspelled] = (char *) malloc((LENGTH + 1) * sizeof(char));

                    strncpy(misspelled[num_misspelled], position_character, (LENGTH + 1));

                    num_misspelled++;

                    position_character = strtok(NULL, " ");

                    position_character = return_punctuation(position_character);

                }

                else {

                    return num_misspelled;

                }

            }

        }



    }

    return num_misspelled;

}







bool check_word(const char* word, hashmap_t hashtable[])

{

    int bucket = hash_function(word);       // Set int bucket to the output of hash_function(word).

    node * cursor = hashtable[bucket];     // /Set hashmap_t cursor equal to hashmap[bucket].

    while (cursor != NULL) {

        if (strcmp(word, cursor->word) == 0) {    //If word equals cursor->word:

            return true;

        }

        else

            cursor = cursor->next;

    }

    return false;

}





/**

 * Loads dictionary into memory.  Returns true if successful else false.

 */

bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])

{

    FILE* the_dictionary;

    char *line_buff = NULL;

    char *position = 0;

    int bucket = 0;

    size_t line_buff_size = 0;

    ssize_t line_size;



    the_dictionary = fopen(dictionary_file, "r");

    if (the_dictionary == NULL){

        printf("Failed to load dictionary");

        return false;

    }



    line_size = getline(&line_buff, &line_buff_size, the_dictionary);



    if ((position = strchr(line_buff, '\n')) !=NULL){

        *position = '\0';

    }



    while(line_size>=0){

        if (line_size > LENGTH+1){

            line_size = getline(&line_buff, &line_buff_size, the_dictionary);

            if ((position = strchr(line_buff, '\n'))!=NULL){

                *position = '\0';

            }

            continue;

        }



        bucket = hash_function(line_buff);



        struct node *cursor = (struct node*) malloc(sizeof(struct node));

        strncpy(cursor->word, line_buff, LENGTH+1);

        cursor->next = hashtable[bucket];

        hashtable[bucket]=cursor;



        line_size = getline(&line_buff, &line_buff_size, the_dictionary);

        if ((position = strchr(line_buff, '\n')) != NULL){

            *position = '\0';

        }

    }





    free(line_buff);

    fclose(the_dictionary);

    return true;

}

