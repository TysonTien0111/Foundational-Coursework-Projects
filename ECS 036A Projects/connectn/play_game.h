#ifndef PLAY_GAME_H
    #define PLAY_GAME_H
    #include <stdbool.h>
    void display_board(char** board, int num_rows, int num_cols);
    bool is_the_game_over(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, char blank_char);
    void curr_player_takes_their_turn(char** board, char blank_char, int num_cols, char cur_player_piece, int num_rows);
    void place_player_piece(char** board, char blank_char, int col_to_play_in, char cur_player_piece, int num_rows);
    int get_valid_input_from_player(char** board, char blank_char, int num_cols);
    bool is_valid_format(int num_args_read, int num_args_needed);
    bool valid_input(char** board, int col_to_play_in, char blank_char, int num_args_read, int num_cols);
    bool is_col_full(char** board, int col_to_play_in, char blank_char);
    void switch_to_next_player(int* cur_player_turn, int number_of_players);
    void display_results(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, int cur_player_turn);
    bool winner(char** board, int num_rows, int number_of_pieces_to_win, int num_cols);
    int all_same(char* board, int num_cols, int number_of_pieces_to_win);
    bool horizontal_win(char** board, int num_rows, int number_of_pieces_to_win, int num_cols);
    char* get_column(char** board, int num_rows, int col);
    bool vertical_win(char** board, int num_rows, int number_of_pieces_to_win, int num_cols);
    bool diagonal_win(char** board, int num_rows, int num_cols, int number_of_pieces_to_win);
    bool check_even_array_left_diagonal(char** board, int num_rows, int num_cols, 
    int number_of_pieces_to_win);
    bool check_more_rows_array_left_diagonal(char** board, int num_rows, int num_cols, 
    int number_of_pieces_to_win);
    bool check_more_cols_array_left_diagonal(char** board, int num_rows, int num_cols, 
    int number_of_pieces_to_win);
    bool left_diagonal_win(char** board, int num_rows, int num_cols, 
    int number_of_pieces_to_win);
    bool check_even_array_right_diagonal(char** board, int num_rows, int num_cols, int number_of_pieces_to_win);
    bool check_more_rows_array_right_diagonal(char** board, int num_rows, int num_cols, int number_of_pieces_to_win);
    bool check_more_cols_array_right_diagonal(char** board, int num_rows, int num_cols, int number_of_pieces_to_win);
    bool right_diagonal_win(char** board, int num_rows, int num_cols, int number_of_pieces_to_win);
    bool tie(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, char blank_char);
    void play_game(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, char blank_char, 
    char* cur_player_piece, int cur_player_turn, int number_of_players);
#endif