import random
from typing import TypedDict, TypeVar
T = TypeVar('T')


class GameState(TypedDict):
    board: list[list[str]]
    blank_char: str
    player_pieces: list[str]
    cur_player_turn: int

def represents_a_positive_int(string:str)->bool:
    return string.strip().isdigit()

def represents_an_negative_int(string:str)->bool:
    string = string.strip()
    return len(string) > 0 and string[0] == '-' and represents_a_positive_int(string[1:])

def represents_an_int(string:str)->bool:
    return represents_a_positive_int(string) or represents_an_negative_int(string)




def make_board(dimensions: int, blank_char: str) -> list[list[str]]:
    """
    Create a dimensions by dimensions board filled with blank characters
    :param dimensions:
    :param blank_char:
    :return:
    """
    board = []
    for row_num in range(dimensions):
        row = []
        for col_num in range(dimensions):
            row.append(blank_char)
        board.append(row)
    return board

def print_board(board:list[list[str]])->None:
    # print the header
    print(end = '  ')
    for header in range(len(list(board))):
        print(header, end = ' ')
    print()
    for row_index, row in enumerate(board):
        print(row_index, ' '.join(row))




def pick_who_goes_first() -> int:
    """
    Pick which player goes first.
    Currently, chosen randomly
    :return: a 1 if player 1 goes first and a 2 if player 2 goes first
    """
    return random.randint(1, 2)


def is_valid_piece(piece: str, player_pieces: list[str], blank_char: str) -> bool:
    """
    Checks if a player's chosen piece is valid.
    A piece is valid if
    - it is not whitespace
    - it is one character long
    - it isn't the other players piece
    - it isn't the blank character
    :param piece:
    :return:
    """
    if piece.isspace():
        return False
    elif len(piece) != 1:
        return False
    elif piece in player_pieces:
        return False
    elif piece == blank_char:
        return False
    else:
        return True


def get_valid_piece_from_player(player_num: int, player_pieces: list[str], blank_char: str) -> str:
    """
    Get a valid piece from a player. Keep asking for one until they input one.
    A piece is valid if
    - it is not whitespace
    - it is one character long
    - it isn't the other players piece
    - it isn't the blank character
    :param player_num: The player we are asking a piece from
    :param player_pieces: The pieces of all the players in the game
    :param blank_char: The character used to represent a blank character on the board
    :return: The first valid piece the player enters
    """
    piece = input(f'Player {player_num} please enter your piece: ').strip()
    while not is_valid_piece(piece, player_pieces, blank_char):
        piece = input(f'Player {player_num} please enter your piece: ').strip()
    return piece


def players_pick_pieces(blank_char: str) -> list[str]:
    """
    Get pieces from the players to use in the game
    :return: The pieces the players picked
    """
    pieces = []
    for player in range(1, 2 + 1):
        player_piece = get_valid_piece_from_player(player, pieces, blank_char)
        pieces.append(player_piece)
    return pieces


def setup_the_game(dimensions: int, blank_char: str) -> GameState:
    """
    Set up the game of tic-tac-toe
    :param dimensions: The dimensions of the board
    :param blank_char: The character to used to represent a blank spot on the board
    :return: A setup game of tic-tac-toe
    """
    board = make_board(dimensions, blank_char)
    player_turn = pick_who_goes_first()
    player_pieces = players_pick_pieces(blank_char)
    return {
        'board': board,
        'blank_char': blank_char,
        'cur_player_turn': player_turn,
        'player_pieces': player_pieces
    }


def are_all_the_same(values:list[T])->bool:
    for value in values:
        if value != values[0]:
            return False
    return True


def won_horizontally(game_state:GameState)->bool:
    for row in game_state['board']:
        if row[0] != game_state['blank_char'] and are_all_the_same(row):
            return True

    return False
    # for row_index in range(len(game_state['board'])):
    #     for col_index in range(len(game_state['board'][0])):
    #         if game_state['board'][row_index][col_index] != game_state['board'][0][col_index]:
    #             break
    #     else:
    #         return True
    # return False




def get_column(col_index:int, board:list[list[str]])->list[str]:
    column = []
    num_rows = len(board)
    for row_index in range(num_rows):
        column.append(board[row_index][col_index])
    return column


def won_vertically(game_state:GameState)->bool:
    num_cols = len(game_state['board'][0])
    for col_index in range(num_cols):
        column = get_column(col_index, game_state['board'])
        if column[0] != game_state['blank_char'] and are_all_the_same(column):
            return True
    return False

# board = [
#          0    1    2    3
#     0  ['1', '2' , '3', 1],
#     1  ['4', '5' , '6'  2],
#     2  ['7', '8' , '9'  3],
#     3  ['7', '8' , '9'  3]
#
# ]


def get_left_diagonal(board:list[list[str]])->list[str]:
    """
    Left diagonal is this one
    X
      X
        X
    :return:
    """
    diagonal = []
    for index in range(len(board)):
        diagonal.append(board[index][index])
    return diagonal


def get_right_diagonal(board:list[list[str]])->list[str]:
    """
         X
       X
     X
    :return:
    """
    diagonal = []
    dim = len(board)
    for index in range(dim):
        diagonal.append(board[index][dim - index - 1])
    return diagonal



def won_diagonally(game_state:GameState)->bool:
    left_diagonal = get_left_diagonal(game_state['board'])
    right_digaonal = get_right_diagonal(game_state['board'])
    return (left_diagonal[0] != game_state['blank_char'] and are_all_the_same(left_diagonal)) or \
           (right_digaonal[0] != game_state['blank_char'] and are_all_the_same(right_digaonal))


def someone_won(game_state:GameState) -> bool:
    """
    Check if someone won the game
    :return: whether someone won the game or not
    """
    return won_horizontally(game_state) or won_vertically(game_state) or won_diagonally(game_state)


def is_board_full(game_state:GameState)->bool:
    for row in game_state['board']:
        for piece in row:
            if piece == game_state['blank_char']:
                return False
    return True


def tie(game_state:GameState)->bool:
    return is_board_full(game_state) and not someone_won(game_state)


def is_game_over(game_state:GameState) -> bool:
    """
    Check if the game is over
    :return: whether the game is over or not
    """
    return someone_won(game_state) or tie(game_state)


def is_valid_move(move:str, game_state:GameState)->bool:
    """
    A move is valid if
    - needs to look like row, col
    - the coordinates must be ints
    - the space must be on the board
    - space they choose is empty
    :param move:
    :return:
    """
    move = move.split(',')
    if len(move) != 2:
        return False

    row, col = move
    if not (represents_a_positive_int(row) and represents_a_positive_int(col)):
        return False

    row, col = int(row), int(col)
    dim = len(game_state['board'])

    if not (0 <= row < dim and 0 <= col < dim):
        return False

    if game_state['board'][row][col] == game_state['blank_char']:
        return True
    else:
        return False

def get_valid_move_from_player(game_state:GameState)->tuple[int,int]:
    cur_player_turn = game_state['cur_player_turn']
    prompt = f'Player {cur_player_turn} enter a move in the form row, col:'
    move = input(prompt)
    while not is_valid_move(move, game_state):
        move = input(prompt)
    row, col = move.split(',')
    row, col = int(row), int(col)
    return row, col


def take_turn(game_state: GameState)->GameState:
    """

    :param game_state:
    :return: the modified game state
    :modifies: board by placing the players piece at their chose location
    """
    row, col = get_valid_move_from_player(game_state)
    cur_player_piece = game_state['player_pieces'][game_state['cur_player_turn'] - 1]
    game_state['board'][row][col] = cur_player_piece
    return game_state


def switch_turn(game_state:GameState)->GameState:

    next_turn = (game_state['cur_player_turn'] + 1) % len(game_state['player_pieces'])

    if game_state['cur_player_turn'] == 1:
        game_state['cur_player_turn'] = 2
    else:
        game_state['cur_player_turn'] = 1
    return game_state


def play_the_game(game_state: GameState) -> GameState:
    """
    Play a game of tic-tac-toe that is already set up
    :param game_state: The starting state of the game
    :return: The state of the game after it is over
    :modifies: game_state
    """
    while not is_game_over(game_state):
        print_board(game_state['board'])
        game_state = take_turn(game_state)
        if someone_won(game_state):
            break
        game_state = switch_turn(game_state)
    print_board(game_state['board'])
    return game_state


def declare_the_results(game_state:GameState)->None:
    if someone_won(game_state):
        winner = game_state['cur_player_turn']
        print(f'Player {winner} won!')
    else:
        print('Tie Game')


def play_tic_tac_toe() -> None:
    """
    setup and play a game of tic-tac-toe
    :return:
    """
    game_state = setup_the_game(3, '_')
    play_the_game(game_state)
    declare_the_results(game_state)

play_tic_tac_toe()