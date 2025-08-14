#include "play_game.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*
This part of the program simulates the playing of connectn.
*/

void display_board(char** board, int num_rows, int num_cols) {
    /*
    This function displays the board to the user.
    */

    for (int i = 1; i < (num_rows + 1); ++i) {
        printf("%d ", (num_rows - i));
        for (int j = 0; j < num_cols; ++j) {
            printf("%c ", board[i - 1][j]);
        }
        printf("\n");
    }

    printf(" ");

    for (int i = 0; i < num_cols; ++i) {
        printf(" %d", i);
    }
    
    printf(" ");
    printf("\n");
}

bool is_the_game_over(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, char blank_char) {
    /*
    This function checks if the game is over, the game is over if there is a winner or tie.
    @returns true or false depending on whether or not the game is over.
    */

    return winner(board, num_rows, number_of_pieces_to_win, num_cols) || 
    tie(board, num_rows, number_of_pieces_to_win, num_cols, blank_char);
}

void curr_player_takes_their_turn(char** board, char blank_char, int num_cols, char cur_player_piece, int num_rows) {
    /*
    This function tells the current player to take their turn.
    @col_to_play_in stores the user's input for which column they would like to play in.
    */

    int col_to_play_in =  get_valid_input_from_player(board, blank_char, num_cols);
    place_player_piece(board, blank_char, col_to_play_in, cur_player_piece, num_rows);
}

void place_player_piece(char** board, char blank_char, int col_to_play_in, char cur_player_piece, int num_rows) {
    /*
    This function places either player 1's piece or player 2's piece on the board, depending on
    who's turn it is.
    */

    for (int i = num_rows - 1; i >= 0; --i) {
        if (board[i][col_to_play_in] == blank_char) {
            board[i][col_to_play_in] = cur_player_piece;
            break;
        }
    }
}

int get_valid_input_from_player(char** board, char blank_char, int num_cols) {
    /*
    This input gets the valid input from player.
    @num_args_read stores the number of arguments read from the user input.
    @col_to_play_in stores the user's input for which column they would like to play in.
    @returns the col_to_play_in
    */

    int num_args_read;
    int col_to_play_in;

    do {
        printf("Enter a column between %d and %d to play in: ", 0, num_cols - 1);
        num_args_read = scanf(" %d", &col_to_play_in);
    } while (!valid_input(board, col_to_play_in, blank_char, num_args_read, num_cols));

    return col_to_play_in;
}

bool is_valid_format(int num_args_read, int num_args_needed) {
    /*
    This function checks if the user's input format is valid.
    @is_format_good is assigned with true or false depending on whether or not num_args_read is
    equal to num_args_needed. 
    @should_be_newline stores the last character that the user has entered.
    @returns true or false depending on whether or not the format is good.
    */

    bool is_format_good = num_args_read == num_args_needed;
    char should_be_newline;

    do {
        scanf("%c", &should_be_newline);
        if (!isspace(should_be_newline)) {
            is_format_good = false;
        }
    } while (should_be_newline != '\n');

    return is_format_good;
}

bool valid_input(char** board, int col_to_play_in, char blank_char, int num_args_read, int num_cols) {
    /*
    This function checks if the input is valid.
    @num_args_needed is set to 1.
    @returns true or false depending on whether or not the user's input was valid.
    */

    int num_args_needed = 1;

    if (!is_valid_format(num_args_read, num_args_needed)) {
        return false; 
    }
    else if ((col_to_play_in >= 0) && (col_to_play_in <= (num_cols - 1))) {
        if (!is_col_full(board, col_to_play_in, blank_char)) {
            return true;
        }
    }

    return false;
}

bool is_col_full(char** board, int col_to_play_in, char blank_char) {
    /*
    This function checks if the column is full.
    @returns true or false depending on whether or not the column is full.
    */

    if (board[0][col_to_play_in] == blank_char) {
        return false;
    } else {
        return true;
    }
}

void switch_to_next_player(int* cur_player_turn, int number_of_players) {
    /*
    This function switches to the next player.
    */

    *cur_player_turn = (*cur_player_turn + 1) % number_of_players;
}

void display_results(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, int cur_player_turn) {
    /*
    This function displays the results of the game.
    Displays a winner if there is one or a tie game if there is no winner.
    */

    if (winner(board, num_rows, number_of_pieces_to_win, num_cols)) {
        if (cur_player_turn == 0) {
            printf("Player 1 Won!");
        } else {
            printf("Player 2 Won!");
        }
    } else {
        printf("Tie game!");
    }
}

bool winner(char** board, int num_rows, int number_of_pieces_to_win, int num_cols) {
    /*
    This function checks for a winner if there is a horizontal, veritcal, or diagonal
    win.
    @returns true or false depending on whether or not there is a horizontal, veritcal, or diagonal
    win.
    */

    return horizontal_win(board, num_rows, number_of_pieces_to_win, num_cols) || 
    vertical_win(board, num_rows, number_of_pieces_to_win, num_cols) || 
    diagonal_win(board, num_rows, num_cols, number_of_pieces_to_win);
}

int all_same(char* board, int num_cols, int number_of_pieces_to_win) {
    /*
    This function checks if the pieces are all the same characters in a row and
    sees if it matches the number of pieces needed to win the game.
    @num_player_one_pieces stores the number of player one pieces in a row.
    @num_player_two_pieces stores the number of player two pieces in a row.
    @returns num_player_one_pieces, num_player_two_pieces or 0 depending on
    whether or not any of the player's pieces in a row is equal to the
    number of pieces needed to win the game.
    */

    int num_player_one_pieces = 0;
    int num_player_two_pieces = 0;

    for (int i = 0; i < num_cols; ++i) {
        if (board[i] == 'X') {
            num_player_one_pieces += 1;
            if (num_player_one_pieces == number_of_pieces_to_win) {
                return num_player_one_pieces;
            }
        } else {
            num_player_one_pieces = 0;
        }
    }

    for (int i = 0; i < num_cols; ++i) {
        if (board[i] == 'O') {
            num_player_two_pieces += 1;
            if (num_player_two_pieces == number_of_pieces_to_win) {
                return num_player_two_pieces;
            }
        } else {
            num_player_two_pieces = 0;
        }
    }
    
    return 0;
}

bool horizontal_win(char** board, int num_rows, int number_of_pieces_to_win, int num_cols) {
    /*
    This function checks if there is a horizontal win.
    @returns true or false depending on whether or not there is a horizontal win.
    */

    for (int i = 0; i < num_rows; ++i) {
        if (all_same(board[i], num_cols, number_of_pieces_to_win) == number_of_pieces_to_win) {
            return true;
        }
    }

    return false;
}

char* get_column(char** board, int num_rows, int col) {
    /*   
    This function gets the column.
    @column stores the board's column.
    @returns the board's column.
    */

    char* column = (char*)calloc(num_rows, sizeof(char));

    for (int i = 0; i < num_rows; ++i) {
        column[i] = board[i][col];
    }

    return column;
}

bool vertical_win(char** board, int num_rows, int number_of_pieces_to_win, int num_cols) {
    /*
    This function checks if there is a vertical win.
    @col stores the column of the board.
    @returns true or false depending on whether or not there is a vertical win.
    */

    for (int i = 0; i < num_cols; ++i) {
        char* col = get_column(board, num_rows, i);
        if (all_same(col, num_cols, number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(col);
            return true;
        }
        free(col);
    }

    return false; 
}

bool diagonal_win(char** board, int num_rows, int num_cols, int number_of_pieces_to_win) {
    /*
    This function checks if there is a diagonal win by seeing if there was either a left or 
    right diagonal win.
    @returns true or false depending on whether or not there was a diagonal win.
    */

    return left_diagonal_win(board, num_rows, num_cols, number_of_pieces_to_win) || 
    right_diagonal_win(board, num_rows, num_cols, number_of_pieces_to_win);
}

bool check_even_array_left_diagonal(char** board, int num_rows, int num_cols, 
int number_of_pieces_to_win) {
    /*
    This function checks if there is a left diagonal win on a board with even dimensions.
    @diagonal stores the diagonal of the board.
    @returns true or false depending on whether or not there is a left diagonal win on a 
    board with even dimensions.
    */

    for (int i = num_rows - 1; i >= 0; --i) {
        char* diagonal = (char*)calloc((num_rows - i), sizeof(char));
        for (int j = 0, x = i; j < (num_rows - i); ++j, ++x) {
            diagonal[j] = board[x][j];
        }
        if (all_same(diagonal, (num_cols - i), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    for (int i = 1; i < num_cols; ++i) {
        char* diagonal = (char*)calloc((num_rows - i), sizeof(char));
        for (int j = 0, x = i; j < (num_rows - i); ++j, ++x) {
            diagonal[j] = board[j][x];
        }
        if (all_same(diagonal, (num_cols - i), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    return false;
}

bool check_more_rows_array_left_diagonal(char** board, int num_rows, int num_cols, 
int number_of_pieces_to_win) {
    /*
    This function checks if there is a left diagonal win on a board with more rows than columns.
    @diagonal stores the diagonal of the board.
    @returns true or false depending on whether or not there is a left diagonal win on a board 
    with more rows than columns.
    */

    for (int i = num_rows - 1, k = num_cols - (num_cols - 1); i >= 0; --i) {
        int j = 0;
        char* diagonal = (char*)calloc(k, sizeof(char));
        for (int x = i; j < k; ++j, ++x) {
            diagonal[j] = board[x][j];
        }
        if (j != num_cols) {
                ++k;
            }
        if (all_same(diagonal, k, number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    for (int i = 1; i < num_cols; ++i) {
        char* diagonal = (char*)calloc((num_cols - i), sizeof(char));
        for (int j = 0, x = i; j < (num_cols - i); ++j, ++x) {
            diagonal[j] = board[j][x];
        }
        if (all_same(diagonal, (num_cols - i), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    return false;
}

bool check_more_cols_array_left_diagonal(char** board, int num_rows, int num_cols, 
int number_of_pieces_to_win) {
    /*
    This function checks if there is a left diagonal win on a board with more columns
    than rows.
    @diagonal stores the diagonal of the board.
    @returns true or false if there is a left diagonal win on a board with more columns 
    than rows.
    */

    for (int i = num_rows - 1; i >= 0; --i) {
        char* diagonal = (char*)calloc((num_rows - i), sizeof(char)); 
        for (int j = 0, x = i; j < (num_rows - i); ++j, ++x) {
            diagonal[j] = board[x][j];
        }
        if (all_same(diagonal, (num_cols - i), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    for (int i = 1, k = num_rows; i <= num_cols - 1; ++i) {
        int x = i, j = 0;
        char* diagonal = (char*)calloc(k, sizeof(char));
        for (; j < k; ++j, ++x) {
            diagonal[j] = board[j][x];
            // if ((x == (num_cols - 1)) && (j < k)) {
            //     --k;
            // }
        }
        if (all_same(diagonal, k, number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        if ((x == (num_cols - 1)) && (j < k)) {
                --k;
        }
        free(diagonal);
    }

    return false;
}

bool left_diagonal_win(char** board, int num_rows, int num_cols, 
int number_of_pieces_to_win) {
    /*
    This function checks if there is left diagonal win.
    @returns true or false depending on whether or not there was a left diagonal win.
    */

    if (num_rows == num_cols) {
        return check_even_array_left_diagonal(board, num_rows, num_cols, 
        number_of_pieces_to_win);
    } else if (num_rows > num_cols) {
        return check_more_rows_array_left_diagonal(board, num_rows, num_cols, 
        number_of_pieces_to_win);
    } else {
        return check_more_cols_array_left_diagonal(board, num_rows, num_cols, 
        number_of_pieces_to_win);
    }
}

bool check_even_array_right_diagonal(char** board, int num_rows, int num_cols, int number_of_pieces_to_win) {
    /*
    This function checks if there is a right diagonal win on a board with even dimensions.
    @diagonal stores the diagonal of the board.
    @returns true or false depending on whether or not there was a right diagonal win on a board with
    even dimensions.
    */

    for (int i = num_rows - 1; i >= 0; --i) {
        char* diagonal = (char*)calloc((num_rows - i), sizeof(char));
        for (int j = num_cols - 1, x = i, y = 0; j >= i; --j, ++x, ++y) {
            diagonal[y] = board[x][j];
        }
        if (all_same(diagonal, (num_rows - i), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true; 
        }
        free(diagonal);
    }

    for (int i = num_cols - 2; i >= 0; --i) {
        char* diagonal = (char*)calloc((i + 1), sizeof(char));
        for (int j = 0, x = i; j <= i; ++j, --x) {
            diagonal[j] = board[j][x];
        }
        if (all_same(diagonal, (i + 1), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    return false;
}

bool check_more_rows_array_right_diagonal(char** board, int num_rows, int num_cols, int number_of_pieces_to_win) {
    /*
    This function checks if there was a right diagonal win on a board with more rows than columns.
    @diagonal stores the diagonal of the board.
    @returns true or false depending on whether or not there was a right diagonal win on the board
    with more rows than columns.
    */

    for (int i = num_rows - 1, k = 1; i >= 0; --i) {
        int  j = num_cols - 1;
        char* diagonal = (char*)calloc(k, sizeof(char));
        for (int x = i, y = 0, s = k; s > 0; --s, ++x, ++y, --j) {   
            diagonal[y] = board[x][j];
            if (s == 1) {
                break;
            }
        }
        if (all_same(diagonal, k, number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        if (j != 0) {
            ++k;
        } else {
            k = num_cols;
        }
        free(diagonal);
    }
    
    for (int i = num_cols - 2, k = num_cols - 1; i >= 0; --i, --k) {
        char* diagonal = (char*)calloc(k, sizeof(char));
        for (int j = 0, x = i; j < k; ++j, --x) {
            diagonal[j] = board[j][x];
        }
        if (all_same(diagonal, k, number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    return false;    
}

bool check_more_cols_array_right_diagonal(char** board, int num_rows, int num_cols, int number_of_pieces_to_win) {
    /*
    This function checks if there is a right diagonal win where the board has more columns
    than rows.
    @diagonal stores the diagonal of the baord.
    @returns true or false depending on whether or not there was a right diagonal win on the
    board that has more columns than rows.
    */

    for (int i = num_rows - 1; i >= 0; --i) {
        char* diagonal = (char*)calloc((num_rows - i), sizeof(char));
        for (int j = num_cols - 1, x = i, k = num_rows, y = 0; k > i; --j, ++x, --k, ++y) {
            diagonal[y] = board[x][j];
        }
        if (all_same(diagonal, (num_rows - i), number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    for (int i = num_cols - 2, k = num_rows; i >= 0; --i) {
        int x = i;
        char* diagonal = (char*)calloc(k, sizeof(char));
        for (int j = 0; j < k; ++j, --x) {
            diagonal[j] = board[j][x];
            if ((x == 0) && (j < k)) {
                --k;
            }
        }
        if (all_same(diagonal, k, number_of_pieces_to_win) == number_of_pieces_to_win) {
            free(diagonal);
            return true;
        }
        free(diagonal);
    }

    return false;
}

bool right_diagonal_win(char** board, int num_rows, int num_cols, int number_of_pieces_to_win) {
    /*
    This function checks if there is a right diagonal win.
    @returns true or false depending on whether or not there was a right diagonal win in the board.
    */

    if (num_rows == num_cols) {
        return check_even_array_right_diagonal(board, num_rows, num_cols, number_of_pieces_to_win);
    } else if (num_rows > num_cols) {
        return check_more_rows_array_right_diagonal(board, num_rows, num_cols, number_of_pieces_to_win);
    } else {
        return check_more_cols_array_right_diagonal(board, num_rows, num_cols, number_of_pieces_to_win);
    }
}

bool tie(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, char blank_char) {
    /*
    This function checks if there is a tie.
    @returns true or false depending on whether or not there was a tie.
    */

    if (winner(board, num_rows, number_of_pieces_to_win, num_cols)) {
        return false;
    }

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            if (board[i][j] == blank_char) {
                return false;
            }
        }
    }

    return true;
}

void play_game(char** board, int num_rows, int number_of_pieces_to_win, int num_cols, char blank_char, 
char* cur_player_piece, int cur_player_turn, int number_of_players) {
    /*
    This function simulates the game play of connectn.
    */
    
    while (!is_the_game_over(board, num_rows, number_of_pieces_to_win, num_cols, blank_char)) {
        display_board(board, num_rows, num_cols);
        curr_player_takes_their_turn(board, blank_char, num_cols, cur_player_piece[cur_player_turn], num_rows);
        if (!winner(board, num_rows, number_of_pieces_to_win, num_cols)) {
            switch_to_next_player(&cur_player_turn, number_of_players);
        }
    }
    display_board(board, num_rows, num_cols);
    display_results(board, num_rows, number_of_pieces_to_win, num_cols, cur_player_turn);
}