'''This program is based off of the game hang man. The first player types in a secret word
and the second player has to guess the secret word. The second player has 7 guesses, they
win if they guessed the word before 7 tries, they lose if they don't guess the word before
7 tries.'''


def main():
    '''Stores secret word in a variable and calls the game_setup function.'''

    user_secret_word = secret_word()
    game_setup(user_secret_word)


def secret_word():
    '''Takes in user input and strips the input of white spaces both before and after the input.
    Then, checks the validity of the users input.'''
    user_secret_word_input = input('Please enter a word to be guessed\nthat does not contain ? or white space: ')
    user_secret_word_input = user_secret_word_input.lstrip()
    user_secret_word_input = user_secret_word_input.rstrip()

    while ('?' in user_secret_word_input) or (' ' in user_secret_word_input) or (len(user_secret_word_input) == 0):
        user_secret_word_input = input('Please enter a word to be guessed that does not contain ? or white space: ')

    return user_secret_word_input.lower()


def game_setup(user_secret_word):
    '''Sets up the game with the amount of guesses available and initializing the secret word into a list.
    Calls the gameplay function.'''

    how_many_guesses_left = 7
    the_secret_word = secret_word_into_list(user_secret_word)
    gameplay(the_secret_word, how_many_guesses_left, user_secret_word)


def secret_word_into_list(user_secret_word):
    '''Grabs the user's secret word and converts it into a list'''

    the_secret_word_list = []

    for each_character in user_secret_word:
        the_secret_word_list.append(each_character)

    return the_secret_word_list


def secret_word_display_list(the_secret_word):
    '''Fills a list up with ? depending on the length of the secret word'''

    the_display_list = []

    for _ in the_secret_word:
        the_display_list.append('?')

    return the_display_list


def gameplay(the_secret_word, how_many_guesses_left, user_secret_word):
    '''Stores the secret word list into a variable, stores the secret word display list into a variable,
    and stores the user's already guessed character into list. The game runs if the amount of guesses
    the guesser has left is greater than 0 and if the guesser hasn't guessed the word yet.'''

    secret_word_list = secret_word_into_list(user_secret_word)
    display_list = secret_word_display_list(the_secret_word)
    user_characters_guessed_list = []

    while (how_many_guesses_left > 0) and (display_list != the_secret_word):
        round_information_displayed(display_list, how_many_guesses_left, user_characters_guessed_list)
        the_guess_word = user_guess_input(user_characters_guessed_list)
        user_characters_guessed_list.append(the_guess_word)
        user_characters_guessed_list.sort()
        if the_guess_word in secret_word_list:
            for character in range(len(secret_word_list)):
                for correct_guessed_letter in secret_word_list[character]:
                    if correct_guessed_letter == the_guess_word:
                        display_list.pop(character)
                        display_list.insert(character, the_guess_word)
                    else:
                        continue
        else:
            how_many_guesses_left -= 1

    if display_list == the_secret_word:
        print('You correctly guessed the secret word:', ''.join(display_list))
    else:
        print(the_hanged_man(how_many_guesses_left))
        print('You failed to guess the secret word:', ''.join(secret_word_list))


def round_information_displayed(display_list, how_many_guesses_left, user_characters_guessed_list):
    '''Displays the important round information like the hanged man, the secret word progress, and the character
    guessed. '''

    the_hanged_man(how_many_guesses_left)
    print(''.join(display_list))
    the_characters_guessed(user_characters_guessed_list)


def the_hanged_man(how_many_guesses_left):
    '''Draws the different stages of the hanged man depending on how many guesses the guesser has left.'''

    if how_many_guesses_left == 6:
        print()
        print(' |')
        print()
    elif how_many_guesses_left == 5:
        print()
        print(' |')
        print(' 0')
        print()
    elif how_many_guesses_left == 4:
        print()
        print(' |')
        print(' 0')
        print(' |')
        print()
    elif how_many_guesses_left == 3:
        print()
        print(' |')
        print(' 0')
        print('/|')
        print()
    elif how_many_guesses_left == 2:
        print()
        print(' |')
        print(' 0')
        print('/|\\')
        print()
    elif how_many_guesses_left == 1:
        print()
        print(' |')
        print(' 0')
        print('/|\\')
        print('/')
        print()
    elif how_many_guesses_left == 0:
        print()
        print(' |')
        print(' 0')
        print('/|\\')
        print('/ \\')
        print()
        return ''
    else:
        print()


def the_characters_guessed(user_characters_guessed_list):
    '''Checks what characters have been guessed/inputted already by the guesser'''

    print('So far you have guessed:', (', '.join(user_characters_guessed_list)))

def user_guess_input(user_characters_guessed_list):
    '''Takes in user input and strips it of any white space before and after the word.
    Then, checks the validity of the user_input.'''

    user_input = input('Please enter your next guess: ')
    user_input = user_input.lstrip()
    user_input = user_input.rstrip()

    try:
        while (user_input in user_characters_guessed_list) or (len(user_input) > 1) or (len(user_input) == 0) or (' ' in user_input):
            if user_input in user_characters_guessed_list:
                print(f'You already guessed the character: {user_input}')
                user_input = input('Please enter your next guess: ')
                user_input = user_input.lstrip()
                user_input = user_input.rstrip()

            if len(user_input) > 1:
                print('You can only guess a single character.')
                user_input = input('Please enter your next guess: ')
                user_input = user_input.lstrip()
                user_input = user_input.rstrip()

            if (len(user_input) == 0) or (' ' in user_input):
                user_input = input('Please enter your next guess: ')
                user_input = user_input.lstrip()
                user_input = user_input.rstrip()
    except EOFError:
        pass
    else:
        return user_input.lower()


main()
