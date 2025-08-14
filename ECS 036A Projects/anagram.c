#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
This program checks if two strings are an anagram of each other.
*/

void sort_list_from_least_to_greatest(int length_of_first_string, int length_of_second_string,
 int ascii_list_for_first_string[length_of_first_string + 1], int ascii_list_for_second_string[length_of_second_string + 1]) {
    /*
    This function sorts both the first string ascii values list and second string ascii values list
    from least to greatest values.
    */

    for (int i = 0; i < length_of_first_string; ++i) {
        for (int j = i + 1; j < length_of_first_string; ++j) {
            if (ascii_list_for_first_string[i] > ascii_list_for_first_string[j]) {
                int temp_value = ascii_list_for_first_string[i];
                ascii_list_for_first_string[i] = ascii_list_for_first_string[j];
                ascii_list_for_first_string[j] = temp_value;
            }
        }
    }

    for (int i = 0; i < length_of_second_string; ++i) {
        for (int j = i + 1; j < length_of_second_string; ++j) {
            if (ascii_list_for_second_string[i] > ascii_list_for_second_string[j]) {
                int temp_value = ascii_list_for_second_string[i];
                ascii_list_for_second_string[i] = ascii_list_for_second_string[j];
                ascii_list_for_second_string[j] = temp_value;
            }
        }
    }
}

bool compare_both_strings(char user_first_string[21], char user_second_string[21]) {
    /*
    This function compares the two strings that the user entered.
    @length_of_first_string stores the length of the first string.
    @length_of_second_string stores the length of the second string.
    @ascii_list_for_first_string stores the list of ascii values for the first string.
    @ascii_list_for_second_string stores the list of ascii values for the second string.
    @returns false if the lengths of the two string are different or if the values in the list aren't
    the same.
    @returns true if none of the above occurs.
    */
    
    int length_of_first_string = strlen(user_first_string);
    int length_of_second_string = strlen(user_second_string);
    int ascii_list_for_first_string[length_of_first_string + 1];
    int ascii_list_for_second_string[length_of_second_string + 1];

    for (int i = 0; i < length_of_first_string; ++i) {
        ascii_list_for_first_string[i] = tolower(user_first_string[i]);
    }

    for (int i = 0; i < length_of_second_string; ++i) {
        ascii_list_for_second_string[i] = tolower(user_second_string[i]);
    }
    
    sort_list_from_least_to_greatest(length_of_first_string, length_of_second_string, ascii_list_for_first_string,
    ascii_list_for_second_string);

    if (length_of_first_string == length_of_second_string) {
        for (int i = 0; i < length_of_first_string; ++i) {
            if (ascii_list_for_first_string[i] != ascii_list_for_second_string[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }

}

void display_result(char user_first_string[21], char user_second_string[21]){
    /*
    This function displays a specific result of the two strings depending on whether or not
    the function compare_both_strings() evaluates to true. 
    */

    if (compare_both_strings(user_first_string, user_second_string)) {
        printf("%s is an anagram of %s", user_first_string, user_second_string);
    } else {
        printf("%s is NOT an anagram of %s", user_first_string, user_second_string);
    }
}

int main() {
    /*
    This is the main function of the program.
    @user_first_string stores the user's first string.
    @user_second_string stores the user's second string.
    */

    char user_first_string[21];
    char user_second_string[21];

    printf("Please enter the first word: ");
    scanf(" %s", user_first_string);

    printf("Please enter the second word: ");
    scanf(" %s", user_second_string);

    display_result(user_first_string, user_second_string);

    return 0;
}