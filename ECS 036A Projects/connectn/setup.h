#ifndef SETUP_H
    #define SETUP_H
    char** create_board(int num_rows, int num_cols, char blank_char);
    int get_starting_player_turn();
    char* get_player_pieces();
    void setup(int num_rows, int num_cols, char blank_char, char** *out_board, int *out_starting_player_turn, 
    char* *out_player_pieces);
#endif