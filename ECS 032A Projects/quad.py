'''Calculates the variables a, b, and c to solve for real solutions using the quadratic formula.'''

import math

def how_many_solutions(solution_one, solution_two, does_solution_one_exist, does_solution_two_exist):
    '''Checks the conditions of the if statements to see whether or not it matches
    and spits out a return statement of the amount of solutions there are'''
    if solution_one == None and solution_two == None:
        return 'There are no real solutions'

    if solution_one < 0 or solution_one > 0:
        does_solution_one_exist = True
    else:
        does_solution_one_exist = False

    if solution_two < 0 or solution_two > 0:
        does_solution_two_exist = True
    else:
        does_solution_two_exist = False

    if does_solution_one_exist == True and does_solution_two_exist == True:
        if solution_one == solution_two:
            return 'There is one real solution: ' '{:.2f}'.format(solution_one)
        else:
            print('There are 2 real solutions')
            print('Solution 1:', '{:.2f}'.format(solution_one))
            return 'Solution 2: ' '{:.2f}'.format(solution_two)
    elif does_solution_one_exist == True and does_solution_two_exist == False:
        return 'There is one real solution: ' '{:.2f}'.format(solution_one)
    else:
        return 'There is one real solution: ' '{:.2f}'.format(solution_two)

def solve_square_root_part_of_formula(num_a, num_b, num_c):
    '''Solves for the square root part of the quadratic formula'''
    answer = math.pow(num_b, 2) - (4 * num_a * num_c)
    if answer < 0:
        return None
    else:
        solved = math.sqrt(answer)
        return solved

def solve_addition_part_of_formula(num_a, num_b, num_c):
    '''Solves the addtion part of the quadratic formula.'''
    if solve_square_root_part_of_formula(num_a, num_b, num_c) == None:
        return None
    else:
        solution_for_addition_part = (-num_b + solve_square_root_part_of_formula(num_a, num_b, num_c)) / (2 * num_a)
        return solution_for_addition_part

def solve_subtraction_part_of_formula(num_a, num_b, num_c):
    '''Solves the subtraction part of the quadratic formula.'''
    if solve_square_root_part_of_formula(num_a, num_b, num_c) == None:
        return None
    else:
        solution_for_subtraction_part = (-num_b - solve_square_root_part_of_formula(num_a, num_b, num_c)) / (2 * num_a)
        return solution_for_subtraction_part

print('Given a quadratic equation of the form a*x^2 + b * x + c')
num_a = float(input('Please enter a: '))
num_b = float(input('Please enter b: '))
num_c = float(input('Please enter c: '))
solution_one = solve_addition_part_of_formula(num_a, num_b, num_c)
solution_two = solve_subtraction_part_of_formula(num_a, num_b, num_c)
does_solution_one_exist = False
does_solution_two_exist = False
amount_of_solutions = how_many_solutions(solution_one, solution_two, does_solution_one_exist, does_solution_two_exist)

print(amount_of_solutions)