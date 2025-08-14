'''This program takes in a file from the user and prints out the number
    of top occurring words the user wants to see.'''


def user_input_name_of_file():
    '''This function takes in the file name that the
        user inputted.'''

    user_file_name = input('Enter the name of the file: ')
    return user_file_name


def user_input_top_words_occurring():
    '''This function takes in the number of top
        occurring words the user wants to see.'''

    user_num_of_top_words = int(input('Enter how many top words you want to see: '))
    return user_num_of_top_words


def read_user_file():
    '''This function reads the file that the user has inputted'''

    user_file = open(user_input_name_of_file(), 'r')
    top_most_occurring_words_dict = {}
    set = {'a', 'an', 'and', 'in', 'is', 'the'}

    for line in user_file:
        list = line.split()
        for word in list:
            word = word.lower()
            if word in set:
                continue
            else:
                word = word.rstrip(',.:;"|\!@#$%^&*()_+-=[]{}<>?/~`\'')
                word = word.lstrip(',.:;"|\!@#$%^&*()_+-=[]{}<>?/~`\'')

                if word in top_most_occurring_words_dict:
                    top_most_occurring_words_dict[word] += 1
                else:
                    top_most_occurring_words_dict[word] = 1

    return top_most_occurring_words_dict


def display_most_to_least_occurring_words():
    '''This function shows us the number of top occurring words the user wants to see'''

    the_top_most_occurring_words = read_user_file()
    user_num_of_top_words = user_input_top_words_occurring()
    sorted_keys_with_same_value = sort_dictionary(the_top_most_occurring_words)

    if len(sorted_keys_with_same_value) < user_num_of_top_words:
        for key, value in sorted_keys_with_same_value:
            if len(value) > 1:
                value.sort()
                print(f"The following words appeared {key} times each: {', '.join(value)}")
            else:
                print(f"The following words appeared {key} times each: {''.join(value)}")
    else:
        for key, value in sorted_keys_with_same_value[0:user_num_of_top_words]:
            if len(value) > 1:
                value.sort()
                print(f"The following words appeared {key} times each: {', '.join(value)}")
            else:
                print(f"The following words appeared {key} times each: {''.join(value)}")


def sort_dictionary(the_top_most_occurring_words_dict):
    '''This function sorts the reversed dictionary'''

    reverse_dict = reverse_key_and_values(the_top_most_occurring_words_dict)

    return sorted(reverse_dict.items(), reverse=True)


def reverse_key_and_values(top_most_occurring_words_dict):
    '''This function reverses the dictionary'''

    reversed_dictionary = {}

    for key, value in top_most_occurring_words_dict.items():
        list = []
        if top_most_occurring_words_dict[key] in reversed_dictionary:
            reversed_dictionary[value] += key.split()
            continue
        else:
            list.append(key)
            reversed_dictionary[value] = list

    return reversed_dictionary


display_most_to_least_occurring_words()
