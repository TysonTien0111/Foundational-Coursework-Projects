#include "user_input.h"
#include "setup.h"
#include "play_game.h"
#include "clean_up.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
This program is a take on the popular game connect 4 but this time the user chooses
the dimensions of the board and the number of pieces in a row that is needed to win the game.
*/

int main(int argc, char** argv) {
    /*
    This is the main functio of the program.
    @num_rows stores the number of rows.
    @num_cols stores the number of columns.
    @number_of_pieces_to_win stores the number of pieces in a row that is needed to win.
    @blank_char stores an asterik.
    @board stores the board with the dimensions of num_rows * num_cols.
    @starting_player_turn stores the integer of the starting player turn which is zero.
    @player_pieces stores the player pieces, X for player 1, O for player 2.
    @number_of_players stores the number 2 for 2 players.
    */

    int num_rows;
    int num_cols;
    int number_of_pieces_to_win;
    char blank_char = '*';
    char** board;
    int starting_player_turn;
    char* player_pieces; 
    int number_of_players = 2;
    
    input(argc, argv, &num_rows, &num_cols, &number_of_pieces_to_win);
    setup(num_rows, num_cols, blank_char, &board, &starting_player_turn, &player_pieces);
    play_game(board, num_rows, number_of_pieces_to_win, num_cols, blank_char, 
    player_pieces, starting_player_turn, number_of_players);
    clean_up(&board, num_rows, &player_pieces);

    return 0;
}
