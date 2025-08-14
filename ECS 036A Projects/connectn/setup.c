#include "setup.h"

#include <stdlib.h>
#include <string.h>

/*
This part of the program sets up the game.
*/

char** create_board(int num_rows, int num_cols, char blank_char) {
    /*
    This function creates the game board.
    @board stores the 2d array game board.
    @returns the game board.
    */

    char** board = (char**)calloc(num_rows, sizeof(char*));

    for (int i = 0; i < num_rows; ++i) {
        board[i] = (char*)calloc(num_rows, sizeof(char));
        for (int j = 0; j < num_cols; ++j) {
            board[i][j] = blank_char;
        }
    }

    return board;
}

int get_starting_player_turn() {
    /*
    This function gets the starting player_turn.
    returns the integer 0.
    0 means First player.
    1 means Second player.
    */

    return 0;
}

char* get_player_pieces() {
    /*
    This function gets the player pieeces.
    @player_pieces stores the string "XO" and a null character at the end.
    'X' will represent player 1.
    'O' will represent player 2.
    */

    char* player_pieces = (char*)calloc(3, sizeof(char));
    strcpy(player_pieces, "XO");

    return player_pieces;
}

void setup(int num_rows, int num_cols, char blank_char, char** *out_board, int *out_starting_player_turn, 
char* *out_player_pieces) {
    /*
    This function sets up the game.
    @board stores the game board.
    @starting_player_turn stores the starting player turn.
    @player_pieces stores "XO" as the player pieces.
    @out_board sends the board out.
    @out_starting_player_turn sends the starting_player_turn out.
    @out_player_pieces sends the player_pieces out.
    */
    
    char** board = create_board(num_rows, num_cols, blank_char);
    int starting_player_turn = get_starting_player_turn();
    char* player_pieces = get_player_pieces();

    *out_board = board;
    *out_starting_player_turn = starting_player_turn;
    *out_player_pieces = player_pieces;
}