'''This program takes an integer that is greater than or equal to the value of 2 from the user
and checks for any prime values from 2 to the user's input'''


def main():
    '''Stores user input in the variable user_number and passes it off to the function prime_number_checker'''
    user_number = check_user_input()
    prime_number_checker(user_number)


def check_user_input():
    '''Takes in user input and checks whether the input is valid'''
    while True:
        try:
            user_input = int(input('Enter the maximum value to check primes up to: '))
            assert (user_input >= 2)
        except ValueError:
            continue
        except AssertionError:
            continue
        else:
            return user_input


def prime_number_checker(user_number):
    '''This function checks for any prime numbers starting from 2 and going
    all the way to the user's input value. It works by using a nested for loop
    that checks if the remainder of the number being divided by x will not equal
    to 0. If the remainder is not equal to 0 for all the values in prime_number_list,
    the number gets added to the prime_number_list afterwards. Else, the if-else statement
    would break and move on to the next number. The loop will continue until the user's inputted
    number is reached'''

    prime_number_list = [2]
    flag = False

    for prime_values in range(3, (user_number + 1)):
        for x in prime_number_list:
            if (prime_values % x) != 0:
                flag = True
            else:
                flag = False
                break

        if flag:
            prime_number_list.append(prime_values)
            flag = False

    prime_number_list = ', '.join(str(numbers_to_string) for numbers_to_string in prime_number_list)
    print(f'The primes from 2 to {user_number} are: {prime_number_list}')


main()
