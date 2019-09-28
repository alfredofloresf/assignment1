#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <check.h>
#include "dictionary.h"
#include <ctype.h>
//#include "spell.c"

int main() {
    hashmap_t hashtable[HASH_SIZE];
    int num_misspelled;
    char *misspelled[MAX_MISSPELLED];
    FILE *filepointer;
    if (load_dictionary("wordlist.txt", hashtable)) {
        printf("dictionary loaded \n");
        //root

    } else { printf("couldnt load"); }


    filepointer = fopen("test.txt", "r");
   // printf("filepointer", 'filepointer');

    //char testword[100];
    num_misspelled = check_words(filepointer, hashtable, misspelled);

    printf("the number of misspelled words is ---- %d \n", num_misspelled);
    printf("hashtables values and  index are  433 and  %s\n", hashtable[433]->word);

    printf("These are the misspelled words \n");
    for (int i = 0; i < num_misspelled; i++) {
        printf(" %s \n", misspelled[i]);
    }
    fclose(filepointer);
    return 0;
}



