#include "user_input.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
This part of the program takes in the user input.
*/

bool is_format_valid(int argc) {
    /*
    This function checks if the format of the input is valid.
    */

    if (argc == 4) {
        return true;
    } else if (argc < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    } else {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
}

bool if_parameters_are_valid(int argc, char** argv, int* *out_number_list) {
    /*
    This function checks if the parameters of the input are valid.
    @number_list stores the parameters of the input that the user has typed in the command line.
    @num_args_read stores the number of arguments read from the command line.
    @should_be_empty stores either a newline or a character that the user has inputted. 
    */

	int* number_list = (int*)calloc(3, sizeof(int));
    int num_args_read;
    char should_be_empty;

    for (int i = 1; i < argc; ++i) {
        num_args_read = sscanf(argv[i], "%d %c", &number_list[i - 1], &should_be_empty);
        if (num_args_read != 1) {
            printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
            exit(0);
        }
    }

    *out_number_list = number_list;

    return true;
}

bool if_parameters_are_greater_than_zero(char** argv) {
    /*
    This function checks if the parameter's integers are greater than zero.
    */

    for (int i = 1; i < 4; ++i) {
        if ((*argv)[i] <= 0) {
            printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
            exit(0);
        }
    }

    return true;
}

void input(int argc, char** argv, int *out_num_rows, int *out_num_cols, int *out_number_of_pieces_to_win) {
    /*
    This function is the main function for taking in the user command line arguments input.
    @number_list stores the parameters in a list.
    @num_rows stores the user's number of rows.
    @num_cols stores the user's number of columns.
    @number_of_pieces_to_win stores the user's number of pieces needed in a row to win.
    @out_num_rows sends the num_rows variable out.
    @out_num_cols sends the num_cols variable out.
    @out_number_of_pieces_to_win sends the number_of_pieces_to_win variable out.
    */

    int* number_list;
    int num_rows;
    int num_cols;
    int number_of_pieces_to_win;

    if (is_format_valid(argc) && if_parameters_are_valid(argc, argv, &number_list) && 
    if_parameters_are_greater_than_zero(argv)) {
        num_rows = number_list[0];
        num_cols = number_list[1];
        number_of_pieces_to_win = number_list[2];
    }
    
    *out_num_rows = num_rows;
    *out_num_cols = num_cols;
    *out_number_of_pieces_to_win = number_of_pieces_to_win;

    free(number_list);
}