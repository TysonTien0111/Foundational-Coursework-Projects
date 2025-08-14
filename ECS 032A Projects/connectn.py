'''This is a program based off of the game Connect 4, but this time the size of the board and the pieces conncted in a row to win is controlled by the user.'''


def connect_n():
    '''This function calls the function game_setup'''

    game_setup()


def user_input_num_of_rows():
    '''This function takes in the number of rows that the user wants'''

    while True:
        try:
            user_input_rows = int(input('Enter the number of rows: '))
            assert (user_input_rows > 0)
        except (AssertionError, TypeError, ValueError):
            pass
        else:
            return user_input_rows


def user_input_num_of_cols():
    '''This function takes in the number of columns that the user wants'''

    while True:
        try:
            user_input_cols = int(input('Enter the number of columns: '))
            assert (user_input_cols > 0)
        except (AssertionError, TypeError, ValueError):
            pass
        else:
            return user_input_cols


def user_input_num_of_pieces_connected_to_win():
    '''This function takes in the number of pieces connected in a row to win from the user.'''

    while True:
        try:
            user_input_num_of_pieces_to_win = int(input('Enter the number of pieces in a row to win: '))
            assert (user_input_num_of_pieces_to_win > 0)
        except (AssertionError, TypeError, ValueError):
            pass
        else:
            return user_input_num_of_pieces_to_win


def game_setup():
    '''This function sets up the board with the dimensions that were inputted by the user, declares the player one and player two piece, and calls in the gameplay function.'''

    board = board_setup()
    num_of_pieces_connected_to_win = user_input_num_of_pieces_connected_to_win()
    player_one_piece = 'X'
    player_two_piece = 'O'

    gameplay(board, num_of_pieces_connected_to_win, player_one_piece, player_two_piece)


def board_setup():
    '''This function sets up the board with the dimensions that the user has inputted.'''

    num_of_rows = user_input_num_of_rows()
    num_of_cols = user_input_num_of_cols()
    board = []
    num_of_cols_list = [' ', ]
    num_of_cols_list.extend(range(num_of_cols))
    board.append(num_of_cols_list, )

    for row in range(num_of_rows - 1, -1, -1):
        row = [row, ]
        for col in range(num_of_cols):
            row.append('*')
        board.append(row)

    return board


def print_game_board(game_board):
    '''This function prints the game board for the user to see.'''

    for the_row in game_board:
        for element in range(len(the_row)):
            if element == (len(the_row) - 1):
                print(the_row[element])
            else:
                print(the_row[element], end=' ')


def gameplay(board, num_of_pieces_connected_to_win, player_one_piece, player_two_piece):
    '''This function is how the game is played'''

    game_board = board

    while not is_board_filled(game_board) and not is_there_a_winner(game_board, num_of_pieces_connected_to_win,
                                                                    player_one_piece, player_two_piece):
        print_game_board(game_board)
        player_one_input = get_player_one_input(game_board)

        while is_column_full_player_one(game_board, player_one_input):
            player_one_input = get_player_one_input(game_board)
        else:
            put_player_one_piece_in_column(game_board, player_one_input, player_one_piece)
            if did_player_one_win(game_board, num_of_pieces_connected_to_win, player_one_piece):
                print_game_board(game_board)
                who_is_the_winner(game_board, num_of_pieces_connected_to_win, player_one_piece)
                break
            elif is_board_filled(game_board):
                print_game_board(game_board)
                print('Tie Game')
                break
            else:
                print_game_board(game_board)

        player_two_input = get_player_two_input(game_board)

        while is_column_full_player_two(game_board, player_two_input):
            player_two_input = get_player_two_input(game_board)
        else:
            put_player_two_piece_in_column(game_board, player_two_input, player_two_piece)
            if did_player_two_win(game_board, num_of_pieces_connected_to_win, player_two_piece):
                print_game_board(game_board)
                who_is_the_winner(game_board, num_of_pieces_connected_to_win, player_one_piece)
            elif is_board_filled(game_board):
                print_game_board(game_board)
                print('Tie Game')


def get_player_one_input(game_board):
    '''This function takes in the column that player one wants to play in.'''

    while True:
        try:
            player_one_input = int(input('Enter the column you want to play in: '))
            assert (int(player_one_input) >= 0) and (int(player_one_input < (len(game_board[0]) - 1)))
        except (AssertionError, TypeError, ValueError):
            pass
        else:
            return player_one_input


def get_player_two_input(game_board):
    '''This function takes in the column that player two wants to play in.'''

    while True:
        try:
            player_two_input = int(input('Enter the column you want to play in: '))
            assert ((player_two_input >= 0) and (player_two_input < (len(game_board[0]) - 1)))
        except (AssertionError, TypeError, ValueError):
            pass
        else:
            return player_two_input


def is_column_full_player_one(game_board, player_one_input):
    '''This function checks if the column that player one chose is full.'''

    if game_board[1][player_one_input + 1] == '*':
        return False
    else:
        return True


def is_column_full_player_two(game_board, player_two_input):
    '''This function checks if the column that player two chose is full.'''

    if game_board[1][player_two_input + 1] == '*':
        return False
    else:
        return True


def put_player_one_piece_in_column(game_board, player_one_input, player_one_piece):
    '''This function puts the player one piece in the column that they selected.'''

    for row_index in range((len(game_board) - 1), 0, -1):
        if game_board[row_index][player_one_input + 1] == '*':
            game_board[row_index].pop((player_one_input + 1))
            game_board[row_index].insert(player_one_input + 1, player_one_piece)
            break
        else:
            continue

    return game_board


def put_player_two_piece_in_column(game_board, player_two_input, player_two_piece):
    '''This function puts in the player two piece in the column that they selected.'''

    for row_index in range((len(game_board) - 1), 0, -1):
        if game_board[row_index][player_two_input + 1] == '*':
            game_board[row_index].pop((player_two_input + 1))
            game_board[row_index].insert(player_two_input + 1, player_two_piece)
            break
        else:
            continue

    return game_board


def is_horizontal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks if there is a horizontal win from player one.'''

    for row in range(len(game_board) - 1, 0, -1):
        num_of_player_one_pieces = 0
        for col in range(1, len(game_board[0])):
            if game_board[row][col] == player_one_piece:
                num_of_player_one_pieces += 1
                if num_of_player_one_pieces == num_of_pieces_connected_to_win:
                    return True
            else:
                num_of_player_one_pieces = 0

    return False


def is_vertical_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks if there is a vertical row win from player one.'''

    vertical_board = get_column_list(game_board)

    for row in vertical_board:
        num_of_player_one_pieces = 0
        for col in range(len(row)):
            if row[col] == player_one_piece:
                num_of_player_one_pieces += 1
                if num_of_player_one_pieces == num_of_pieces_connected_to_win:
                    return True
            else:
                num_of_player_one_pieces = 0

    return False


def is_diagonal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks if there is a diagonal row win from player one.'''

    return (is_left_diagonal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece)) or (
        is_right_diagonal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece))


def is_left_diagonal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks if there is a left diagonal row that is filled by player one.'''

    num_of_player_one_piece_connected = 0

    for row_index in range(1, len(game_board)):
        for col_index in range(1, len(game_board[0])):
            index1 = row_index
            index2 = col_index
            if len(game_board[0]) > len(game_board):
                if game_board[index1][index2] == player_one_piece:
                    num_of_player_one_piece_connected += 1
                    if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_one_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_one_piece_connected = 0
                                break
                            else:
                                if index2 == (len(game_board[0]) - 1):
                                    num_of_player_one_piece_connected = 0
                                    break
                                index1 += 1
                                index2 += 1
                                if index2 == (len(game_board[0]) - 1):
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_one_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_one_piece_connected = 0
                                        break
            elif len(game_board) == len(game_board[0]):
                if game_board[index1][index2] == player_one_piece:
                    num_of_player_one_piece_connected += 1
                    if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_one_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_one_piece_connected = 0
                                break
                            else:
                                if index2 == (len(game_board[0]) - 1):
                                    num_of_player_one_piece_connected = 0
                                    break
                                index1 += 1
                                index2 += 1
                                if index2 == (len(game_board[0]) - 1):
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_one_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_one_piece_connected = 0
                                        break
            else:
                if game_board[index1][index2] == player_one_piece:
                    num_of_player_one_piece_connected += 1
                    if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_one_piece_connected = 0
                        return True
                    else:
                        for _ in range(col_index, len(game_board[0])):
                            if _ == (len(game_board[0]) - 1):
                                num_of_player_one_piece_connected = 0
                                break
                            else:
                                if index1 == (len(game_board) - 1):
                                    num_of_player_one_piece_connected = 0
                                    break
                                index1 += 1
                                index2 += 1
                                if index1 == (len(game_board) - 1):
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_one_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_one_piece_connected = 0
                                        break

        continue

    return False


def is_right_diagonal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks if there is a right diagonal row filled by player one.'''

    num_of_player_one_piece_connected = 0

    for row_index in range(1, len(game_board)):
        for col_index in range(len(game_board[0]) - 1, 0, -1):
            index1 = row_index
            index2 = col_index
            if len(game_board[0]) > len(game_board):
                if game_board[index1][index2] == player_one_piece:
                    num_of_player_one_piece_connected += 1
                    if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_one_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_one_piece_connected = 0
                                break
                            else:
                                if index2 == 1:
                                    num_of_player_one_piece_connected = 0
                                    break
                                index1 += 1
                                index2 -= 1
                                if index2 == 1:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_one_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_one_piece_connected = 0
                                        break
            elif len(game_board) == len(game_board[0]):
                if game_board[index1][index2] == player_one_piece:
                    num_of_player_one_piece_connected += 1
                    if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_one_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_one_piece_connected = 0
                                break
                            else:
                                if index2 == 1:
                                    num_of_player_one_piece_connected = 0
                                    break
                                index1 += 1
                                index2 -= 1
                                if index2 == 1:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_one_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_one_piece_connected = 0
                                        break
            else:
                if game_board[index1][index2] == player_one_piece:
                    num_of_player_one_piece_connected += 1
                    if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_one_piece_connected = 0
                        return True
                    else:
                        for _ in range(col_index, 0, -1):
                            if _ == 1:
                                num_of_player_one_piece_connected = 0
                                break
                            else:
                                if index1 == (len(game_board) - 1):
                                    num_of_player_one_piece_connected = 0
                                    break
                                index1 += 1
                                index2 -= 1
                                if index1 == (len(game_board) - 1):
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_one_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_one_piece:
                                        num_of_player_one_piece_connected += 1
                                        if num_of_player_one_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_one_piece_connected = 0
                                        break

        continue

    return False


def get_column_list(game_board):
    '''This function gets all the vertical rows from the game board.'''

    column_list = []

    for col_index in range(1, len(game_board[0])):
        col = []
        for row_index in range(len(game_board) - 1, 0, -1):
            col.append(game_board[row_index][col_index])
        column_list.append(col)

    return column_list


def is_horizontal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece):
    '''This function checks if there is a horizontal win from player two.'''

    for row in range(len(game_board) - 1, 0, -1):
        num_of_player_two_pieces = 0
        for col in range(1, len(game_board[0])):
            if game_board[row][col] == player_two_piece:
                num_of_player_two_pieces += 1
                if num_of_player_two_pieces == num_of_pieces_connected_to_win:
                    return True
            else:
                num_of_player_two_pieces = 0

    return False


def is_vertical_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece):
    '''This function checks if there is a vertical win from player two.'''

    vertical_board = get_column_list(game_board)

    for row in vertical_board:
        num_of_player_two_pieces = 0
        for col in range(len(row)):
            if row[col] == player_two_piece:
                num_of_player_two_pieces += 1
                if num_of_player_two_pieces == num_of_pieces_connected_to_win:
                    return True
            else:
                num_of_player_two_pieces = 0

    return False


def is_diagonal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece):
    '''This function checks if there is diagonal win from player two.'''
    return (is_left_diagonal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece)) or (is_right_diagonal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece))


def is_left_diagonal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece):
    '''This function checks if there is a left diagonal row that is filled by player two.'''

    num_of_player_two_piece_connected = 0

    for row_index in range(1, len(game_board)):
        for col_index in range(1, len(game_board[0])):
            index1 = row_index
            index2 = col_index
            if len(game_board[0]) > len(game_board):
                if game_board[index1][index2] == player_two_piece:
                    num_of_player_two_piece_connected += 1
                    if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_two_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_two_piece_connected = 0
                                break
                            else:
                                if index2 == (len(game_board[0]) - 1):
                                    num_of_player_two_piece_connected = 0
                                    break
                                index1 += 1
                                index2 += 1
                                if index2 == (len(game_board[0]) - 1):
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_two_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_two_piece_connected = 0
                                        break
            elif len(game_board) == len(game_board[0]):
                if game_board[index1][index2] == player_two_piece:
                    num_of_player_two_piece_connected += 1
                    if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_two_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_two_piece_connected = 0
                                break
                            else:
                                if index2 == (len(game_board[0]) - 1):
                                    num_of_player_two_piece_connected = 0
                                    break
                                index1 += 1
                                index2 += 1
                                if index2 == (len(game_board[0]) - 1):
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_two_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_two_piece_connected = 0
                                        break
            else:
                if game_board[index1][index2] == player_two_piece:
                    num_of_player_two_piece_connected += 1
                    if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_two_piece_connected = 0
                        return True
                    else:
                        for _ in range(col_index, len(game_board[0])):
                            if _ == (len(game_board[0]) - 1):
                                num_of_player_two_piece_connected = 0
                                break
                            else:
                                if index1 == (len(game_board) - 1):
                                    num_of_player_two_piece_connected = 0
                                    break
                                index1 += 1
                                index2 += 1
                                if index1 == (len(game_board) - 1):
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_two_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_two_piece_connected = 0
                                        break

        continue

    return False


def is_right_diagonal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece):
    '''This function checks if there is a right diagonal row filled by player two.'''

    num_of_player_two_piece_connected = 0

    for row_index in range(1, len(game_board)):
        for col_index in range(len(game_board[0]) - 1, 0, -1):
            index1 = row_index
            index2 = col_index
            if len(game_board[0]) > len(game_board):
                if game_board[index1][index2] == player_two_piece:
                    num_of_player_two_piece_connected += 1
                    if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_two_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_two_piece_connected = 0
                                break
                            else:
                                if index2 == 1:
                                    num_of_player_two_piece_connected = 0
                                    break
                                index1 += 1
                                index2 -= 1
                                if index2 == 1:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_two_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_two_piece_connected = 0
                                        break
            elif len(game_board) == len(game_board[0]):
                if game_board[index1][index2] == player_two_piece:
                    num_of_player_two_piece_connected += 1
                    if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_two_piece_connected = 0
                        return True
                    else:
                        for _ in range(row_index, len(game_board)):
                            if _ == (len(game_board) - 1):
                                num_of_player_two_piece_connected = 0
                                break
                            else:
                                if index2 == 1:
                                    num_of_player_two_piece_connected = 0
                                    break
                                index1 += 1
                                index2 -= 1
                                if index2 == 1:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_two_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_two_piece_connected = 0
                                        break
            else:
                if game_board[index1][index2] == player_two_piece:
                    num_of_player_two_piece_connected += 1
                    if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                        num_of_player_two_piece_connected = 0
                        return True
                    else:
                        for _ in range(col_index, 0, -1):
                            if _ == 1:
                                num_of_player_two_piece_connected = 0
                                break
                            else:
                                if index1 == (len(game_board) - 1):
                                    num_of_player_two_piece_connected = 0
                                    break
                                index1 += 1
                                index2 -= 1
                                if index1 == (len(game_board) - 1):
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            num_of_player_two_piece_connected = 0
                                            break
                                else:
                                    if game_board[index1][index2] == player_two_piece:
                                        num_of_player_two_piece_connected += 1
                                        if num_of_player_two_piece_connected == num_of_pieces_connected_to_win:
                                            return True
                                        else:
                                            continue
                                    else:
                                        num_of_player_two_piece_connected = 0
                                        break
        continue

    return False

def is_there_a_winner(game_board, num_of_pieces_connected_to_win, player_one_piece, player_two_piece):
    '''This function checks if there is a winner.'''

    if did_player_one_win(game_board, num_of_pieces_connected_to_win, player_one_piece):
        return True
    elif did_player_two_win(game_board, num_of_pieces_connected_to_win, player_two_piece):
        return True
    else:
        return False


def who_is_the_winner(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks who is the winner.'''

    if did_player_one_win(game_board, num_of_pieces_connected_to_win, player_one_piece):
        print('Player 1 won!')
    else:
        print('Player 2 won!')


def did_player_one_win(game_board, num_of_pieces_connected_to_win, player_one_piece):
    '''This function checks if player one won.'''

    return ((is_horizontal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece)) or (
        is_vertical_row_filled_player_one(game_board, num_of_pieces_connected_to_win,
                                          player_one_piece)) or (
                is_diagonal_row_filled_player_one(game_board, num_of_pieces_connected_to_win, player_one_piece)))


def did_player_two_win(game_board, num_of_pieces_connected_to_win, player_two_piece):
    '''This function checks if player two won.'''

    return ((is_horizontal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece)) or (
        is_vertical_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece)) or (
                is_diagonal_row_filled_player_two(game_board, num_of_pieces_connected_to_win, player_two_piece)))


def is_board_filled(game_board):
    '''This function checks if the board is filled.'''

    board_filled = False

    for col in range(1, len(game_board[1])):
        if game_board[1][col] != '*':
            board_filled = True
            continue
        else:
            board_filled = False
            break

    return board_filled


connect_n()
