#include "clean_up.h"

#include <stdlib.h>

/*
This part of the program cleans up the board and the player pieces.
*/

void delete_board(char** *board, int num_rows) {
    /*
    This function deletes the game board.
    */

    for (int i = 0; i < num_rows; ++i) {
        free((*board)[i]);
    }

    free(*board);
}

void clean_up(char** *board, int num_rows, char* *player_pieces) {
    /*
    This function cleans up the board and the player pieces. 
    */

    delete_board(board, num_rows);
    free(*player_pieces);
}