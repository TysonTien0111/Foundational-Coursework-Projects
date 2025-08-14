#include <stdio.h>
#include <stdlib.h>

/*
This function calculates pi by using the monte carlo's simulation method.
*/

double random_double(double low, double high) {
  /*
  Generate a random double between low and high inclusive.
  @low: the lowest possible double that can be generated.
  @high: the highest possible double that can be generated.
  @returns: a random number between low and high.
  */

  return low + ((double) rand()) / ((double) RAND_MAX / (high - low));
}

double points_generator(int user_number_of_iterations) {
  /*
  This function generates the x and y points.
  @total_points_generated_in_circle stores the total points generated in the circle.
  @total_points_generated stores the total points generated.
  @x_value stores the x-coordinate.
  @y_value stores the y-coordinate.
  @distance_from_the_origin stores the distance from the origin.
  @return the total_points_generated_in_circle divided by total_points_generated.
  */

  double total_points_generated_in_circle;
  double total_points_generated;
  double x_value;
  double y_value;
  double distance_from_the_origin;

  for (int i = 0; i < user_number_of_iterations; ++i) {
    x_value = random_double(-1, 1);
    y_value = random_double(-1, 1);
    distance_from_the_origin = (x_value * x_value) + (y_value * y_value);

    if (distance_from_the_origin <= 1) {
      total_points_generated_in_circle += 1;
    }

    total_points_generated += 1;
  }

  return (total_points_generated_in_circle / total_points_generated);
}

double solve_for_pi(int user_number_of_iterations) {
  /*
  This function solves for pi.
  @return the output of the function, points_generator, multiplied by 4.
  */

  return points_generator(user_number_of_iterations) * 4;
}

int main() {
  /*
  This is the main function of the program.
  @user_seed stores the user input for the seed.
  @user_number_of_iterations stores the user input for the number of iterations.
  @pi_solved stores the final calculated answer of pi.
  */

  int user_seed;
  int user_number_of_iterations;
  double pi_solved;

  printf("Enter the seed for the random number generator: ");
  scanf(" %d", &user_seed);
  srand(user_seed);

  printf("Enter the number of iterations to run: ");
  scanf(" %d", &user_number_of_iterations);

  pi_solved = solve_for_pi(user_number_of_iterations);

  printf("The value of pi is %.2lf.", pi_solved);

  return 0;
}
