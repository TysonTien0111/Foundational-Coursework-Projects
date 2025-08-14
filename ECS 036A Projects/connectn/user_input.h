#ifndef USER_INPUT_H
    #define USER_INPUT_H
    #include <stdbool.h>
    bool is_format_valid(int argc);
    bool if_parameters_are_valid(int argc, char** argv, int* *out_number_list);
    bool if_parameters_are_greater_than_zero(char** argv);
    void input(int argc, char** argv, int *out_num_rows, int *out_num_cols, int *out_number_of_pieces_to_win);
#endif 
    