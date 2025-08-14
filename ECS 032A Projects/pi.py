import random

def main():
    user_seed = input('Enter the seed for the random number generator: ')
    user_seed = int(user_seed)
    random.seed(user_seed)

    user_number_of_iterations = input('Enter the number of iterations to run: ')
    user_number_of_iterations = int(user_number_of_iterations)
    while user_number_of_iterations < 0:
        user_number_of_iterations = input('Enter the number of iterations to run: ')
    user_number_of_iterations = int(user_number_of_iterations)

    solve_for_pi(user_number_of_iterations)


def solve_for_pi(user_number_of_iterations):
    pi_solved = probability_inside_circle(user_number_of_iterations) * 4
    print(f'The value of pi is {pi_solved:.2f}.')


def probability_inside_circle(user_number_of_iterations):
    total_points_in_circle = 0
    total_points_generated = 0
    for iterations in range(user_number_of_iterations):
        x_axis = random.uniform(-1, 1)
        y_axis = random.uniform(-1, 1)
        distance_from_origin = (x_axis ** 2) + (y_axis ** 2)

        if distance_from_origin <= 1:
            total_points_in_circle += 1

        total_points_generated += 1

    return total_points_in_circle / total_points_generated


main()
