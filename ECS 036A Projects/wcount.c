#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
This program counts the number of words in a file.
*/

int open_file(char* file_name) {
    /*
    This function opens up the fie and counts the amount of characters that are in it.
    @num_of_chars stores the ammount of characters that are in the file that is being opened.
    @returns the number of characters that is in the file.
    */

    FILE* file = fopen(file_name, "r");

    int num_of_chars = 0;
    
    char c;
    fscanf(file, "%c", &c);
    while(!feof(file)) {
        ++num_of_chars;
        fscanf(file, "%c", &c);
    }
    fclose(file);

    return num_of_chars;
}

int count_num_words_in_file(char* file_name, int num_of_chars) {
    /*
    This function counts the number of words in a file.
    @array stores the current word in the file
    @words_in_file stores all the words that are in the file.
    @word_count stores the number of words that are in the file.
    @returns the word count of the file.
    */

    FILE* file = fopen(file_name, "r");

    char* array = (char*)calloc(num_of_chars + 1, sizeof(char));
    char* words_in_file = (char*)calloc(num_of_chars + 1, sizeof(char));
    int word_count = 0;

    fscanf(file, "%c", array); 
    while(!feof(file)) {
        strcat(words_in_file, array);
        fscanf(file, "%c", array);
    }
    fclose(file);

    free(array);

    for (int i = 0; i < num_of_chars - 1; ++i) {
        if ((isspace(words_in_file[i])) && (!isspace(words_in_file[i + 1]))) {
            ++word_count;
        }
    }
    if (num_of_chars != 0) {
        ++word_count;
    }

    free(words_in_file);

    return word_count;
}

void display_num_words_in_file(int word_count) {
    /*
    This function displays the number of words in the file for the user to see.
    */

    printf("There are %d word(s).", word_count);
}

int main(int argc, char** argv) {
    /*
    This is the main function of the program.
    @num_of_chars stores the number of characters in the file.
    @word_count stores the word count that is in the file.
    */

    int num_of_chars = open_file(argv[1]);
    int word_count = count_num_words_in_file(argv[1], num_of_chars);
    display_num_words_in_file(word_count);

    return 0;
}